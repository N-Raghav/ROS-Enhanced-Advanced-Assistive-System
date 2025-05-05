from flask import Flask, request, jsonify
from pymongo import MongoClient
from werkzeug.security import generate_password_hash, check_password_hash
from flask_cors import CORS
from datetime import datetime

app = Flask(__name__)
CORS(app)  # Enable CORS for the app

@app.after_request
def add_csp_headers(response):
    response.headers['Content-Security-Policy'] = "default-src 'self'; img-src 'self' https://d8f0-106-222-239-135.ngrok-free.app data: https://w3.org/svg/2000;"
    return response

# MongoDB Client Connection
client = MongoClient("mongodb://localhost:27017")
db = client["inventory_management"]
products_collection = db["products"]
sales_collection = db["sales"]
suppliers_collection = db["suppliers"]
sales_users_collection = db["sales_users"]
robots_collection = db["robots"]
coordinates_collection = db["coordinates"]

class Product:
    @staticmethod
    @app.route("/products", methods=["GET", "POST"])
    def manage_products():
        if request.method == "GET":
            # Fetch all products with optional filtering (e.g., by category or stock)
            category = request.args.get("category")
            stock_status = request.args.get("stock_status")  # 'low' for low stock items
            query = {}

            if category:
                query["category"] = category
            if stock_status == "low":
                query["stock"] = {"$lt": 50}  # Example: Threshold of 50

            products = list(products_collection.find(query, {"_id": 0}))
            return jsonify(products), 200

        if request.method == "POST":
            # Add a new product
            data = request.json
            data["last_restock_date"] = datetime.utcnow().isoformat()
            if products_collection.find_one({"product_id": data["product_id"]}):
                return jsonify({"message": "Product with this ID already exists!"}), 400
            products_collection.insert_one(data)
            return jsonify({"message": "Product added successfully!"}), 201

    @staticmethod
    @app.route("/products/<product_id>", methods=["GET", "PUT", "DELETE"])
    def product_operations(product_id):
        if request.method == "GET":
            # Fetch a specific product by ID
            product = products_collection.find_one({"product_id": product_id}, {"_id": 0})
            if product:
                return jsonify(product), 200
            return jsonify({"message": "Product not found!"}), 404

        if request.method == "PUT":
            # Update a specific product
            data = request.json
            updated = products_collection.update_one({"product_id": product_id}, {"$set": data})
            if updated.matched_count:
                return jsonify({"message": "Product updated successfully!"}), 200
            return jsonify({"message": "Product not found!"}), 404

        if request.method == "DELETE":
            # Delete a specific product
            deleted = products_collection.delete_one({"product_id": product_id})
            if deleted.deleted_count:
                return jsonify({"message": "Product deleted successfully!"}), 200
            return jsonify({"message": "Product not found!"}), 404

    @staticmethod
    @app.route("/products/restock", methods=["GET"])
    def restock_notifications():
        # List products that need restocking (below threshold)
        threshold = int(request.args.get("threshold", 50))  # Default threshold is 50
        low_stock_items = list(products_collection.find({"stock": {"$lt": threshold}}, {"_id": 0}))
        return jsonify(low_stock_items), 200

    @staticmethod
    @app.route("/products/expiration", methods=["GET"])
    def check_expiring_products():
        # List products nearing expiration within X days
        days = int(request.args.get("days", 7))  # Default to 7 days
        threshold_date = datetime.utcnow().isoformat()
        expiring_products = list(products_collection.find(
            {"expiration_date": {"$lte": threshold_date}},
            {"_id": 0}
        ))
        return jsonify(expiring_products), 200

class Sales:
    @staticmethod
    @app.route("/sales", methods=["GET", "POST"])
    def manage_sales():
        if request.method == "GET":
            # Fetch sales records with optional filtering by date range
            start_date = request.args.get("start_date")  # e.g., "2025-01-01"
            end_date = request.args.get("end_date")      # e.g., "2025-01-31"

            query = {}
            if start_date and end_date:
                query["timestamp"] = {"$gte": start_date, "$lte": end_date}

            sales = list(sales_collection.find(query, {"_id": 0}))
            return jsonify(sales), 200

        if request.method == "POST":
            # Record a new sale and decrement product stock
            data = request.json
            total_amount = 0
            products_sold = []

            for item in data["products_sold"]:
                product_id = item["product_id"]
                quantity = item["quantity"]

                product = products_collection.find_one({"product_id": product_id})
                if not product or product["stock"] < quantity:
                    return jsonify({"message": f"Insufficient stock for product {product_id}"}), 400

                # Decrement stock
                products_collection.update_one(
                    {"product_id": product_id}, {"$inc": {"stock": -quantity}}
                )
                total_amount += product["price"] * quantity
                products_sold.append({"product_id": product_id, "quantity": quantity, "price": product["price"]})

            # Add sale to database
            sale_record = {
                "sale_id": data["sale_id"],
                "timestamp": datetime.utcnow().isoformat(),
                "products_sold": products_sold,
                "total_amount": total_amount
            }
            sales_collection.insert_one(sale_record)

            return jsonify({"message": "Sale recorded successfully!", "total_amount": total_amount}), 201

    @staticmethod
    @app.route("/sales/<sale_id>", methods=["GET", "PUT", "DELETE"])
    def sale_operations(sale_id):
        if request.method == "GET":
            # Fetch specific sale by ID
            sale = sales_collection.find_one({"sale_id": sale_id}, {"_id": 0})
            if sale:
                return jsonify(sale), 200
            return jsonify({"message": "Sale not found!"}), 404

        if request.method == "PUT":
            # Update a sale record
            data = request.json
            updated = sales_collection.update_one({"sale_id": sale_id}, {"$set": data})
            if updated.matched_count:
                return jsonify({"message": "Sale updated successfully!"}), 200
            return jsonify({"message": "Sale not found!"}), 404

        if request.method == "DELETE":
            # Delete a sale record
            deleted = sales_collection.delete_one({"sale_id": sale_id})
            if deleted.deleted_count:
                return jsonify({"message": "Sale deleted successfully!"}), 200
            return jsonify({"message": "Sale not found!"}), 404

    @staticmethod
    @app.route("/sales/report", methods=["GET"])
    def sales_report():
        # Generate a sales report for a specific time range
        start_date = request.args.get("start_date")
        end_date = request.args.get("end_date")

        query = {}
        if start_date and end_date:
            query["timestamp"] = {"$gte": start_date, "$lte": end_date}

        sales = sales_collection.find(query, {"_id": 0})

        total_sales = 0
        report = []
        for sale in sales:
            total_sales += sale["total_amount"]
            report.append(sale)

        return jsonify({
            "total_sales": total_sales,
            "report": report
        }), 200

class Supplier:
    @staticmethod
    @app.route("/suppliers", methods=["GET", "POST"])
    def manage_suppliers():
        if request.method == "GET":
            # Fetch all suppliers, optionally filtered by supplier type or location
            supplier_type = request.args.get("type")  # e.g., "raw_materials", "packaging"
            location = request.args.get("location")  # e.g., city or region
            query = {}

            if supplier_type:
                query["type"] = supplier_type
            if location:
                query["location"] = location

            suppliers = list(suppliers_collection.find(query, {"_id": 0}))
            return jsonify(suppliers), 200

        if request.method == "POST":
            # Add a new supplier
            data = request.json
            if suppliers_collection.find_one({"supplier_id": data["supplier_id"]}):
                return jsonify({"message": "Supplier with this ID already exists!"}), 400
            suppliers_collection.insert_one(data)
            return jsonify({"message": "Supplier added successfully!"}), 201

    @staticmethod
    @app.route("/suppliers/<supplier_id>", methods=["GET", "PUT", "DELETE"])
    def supplier_operations(supplier_id):
        if request.method == "GET":
            # Fetch a specific supplier by ID
            supplier = suppliers_collection.find_one({"supplier_id": supplier_id}, {"_id": 0})
            if supplier:
                return jsonify(supplier), 200
            return jsonify({"message": "Supplier not found!"}), 404

        if request.method == "PUT":
            # Update a supplier's information
            data = request.json
            updated = suppliers_collection.update_one({"supplier_id": supplier_id}, {"$set": data})
            if updated.matched_count:
                return jsonify({"message": "Supplier updated successfully!"}), 200
            return jsonify({"message": "Supplier not found!"}), 404

        if request.method == "DELETE":
            # Delete a supplier
            deleted = suppliers_collection.delete_one({"supplier_id": supplier_id})
            if deleted.deleted_count:
                return jsonify({"message": "Supplier deleted successfully!"}), 200
            return jsonify({"message": "Supplier not found!"}), 404

    @staticmethod
    @app.route("/suppliers/products/<supplier_id>", methods=["GET"])
    def products_from_supplier(supplier_id):
        # Fetch products received from a specific supplier
        products_collection = db["products"]
        products = list(products_collection.find({"supplier_id": supplier_id}, {"_id": 0}))

        if not products:
            return jsonify({"message": f"No products found for supplier {supplier_id}"}), 404

        return jsonify(products), 200

    @staticmethod
    @app.route("/suppliers/contact", methods=["GET"])
    def supplier_contacts():
        # Fetch contact details of suppliers, optionally filtered by type
        supplier_type = request.args.get("type")
        query = {}

        if supplier_type:
            query["type"] = supplier_type

        suppliers = suppliers_collection.find(query, {"supplier_id": 1, "name": 1, "contact": 1, "_id": 0})
        return jsonify(list(suppliers)), 200

class SalesUsers:
    @staticmethod
    @app.route("/sales_users", methods=["GET", "POST"])
    def manage_sales_users():
        if request.method == "GET":
            # Fetch all sales users with optional role-based filtering
            role = request.args.get("role")  # e.g., "cashier", "manager"
            query = {}
            if role:
                query["role"] = role

            sales_users = list(sales_users_collection.find(query, {"_id": 0, "password": 0}))  # Exclude passwords
            return jsonify(sales_users), 200

        if request.method == "POST":
            # Add a new sales user
            data = request.json
            if sales_users_collection.find_one({"username": data["username"]}):
                return jsonify({"message": "Username already exists!"}), 400

            hashed_password = generate_password_hash(data["password"])
            data["password"] = hashed_password
            sales_users_collection.insert_one(data)
            return jsonify({"message": "Sales user added successfully!"}), 201

    @staticmethod
    @app.route("/sales_users/<username>", methods=["GET", "PUT", "DELETE"])
    def sales_user_operations(username):
        if request.method == "GET":
            # Fetch specific sales user by username
            sales_user = sales_users_collection.find_one({"username": username}, {"_id": 0, "password": 0})
            if sales_user:
                return jsonify(sales_user), 200
            return jsonify({"message": "Sales user not found!"}), 404

        if request.method == "PUT":
            # Update user details or role
            data = request.json
            updated = sales_users_collection.update_one({"username": username}, {"$set": data})
            if updated.matched_count:
                return jsonify({"message": "Sales user updated successfully!"}), 200
            return jsonify({"message": "Sales user not found!"}), 404

        if request.method == "DELETE":
            # Delete a sales user
            deleted = sales_users_collection.delete_one({"username": username})
            if deleted.deleted_count:
                return jsonify({"message": "Sales user deleted successfully!"}), 200
            return jsonify({"message": "Sales user not found!"}), 404

    @staticmethod
    @app.route("/sales_users/login", methods=["POST"])
    def login():
        # Authenticate a user and return login status
        data = request.json
        username = data["username"]
        password = data["password"]

        sales_user = sales_users_collection.find_one({"username": username})
        if sales_user and check_password_hash(sales_user["password"], password):
            # User is authenticated
            return jsonify({"message": "Login successful!", "role": sales_user["role"]}), 200
        return jsonify({"message": "Invalid username or password!"}), 401

    @staticmethod
    @app.route("/sales_users/audit", methods=["GET"])
    def audit_users():
        # Get audit log for accountability
        logs_collection = db["audit_logs"]  # Assume audit logs are stored in a separate collection
        username = request.args.get("username")
        query = {}
        if username:
            query["username"] = username

        logs = list(logs_collection.find(query, {"_id": 0}))
        return jsonify(logs), 200

    @staticmethod
    @app.route("/sales_users/change_password/<username>", methods=["PUT"])
    def change_password(username):
        # Change password for a specific user
        data = request.json
        new_password = data.get("new_password")

        if not new_password:
            return jsonify({"message": "New password is required!"}), 400

        hashed_password = generate_password_hash(new_password)
        updated = sales_users_collection.update_one({"username": username}, {"$set": {"password": hashed_password}})

        if updated.matched_count:
            return jsonify({"message": "Password changed successfully!"}), 200
        return jsonify({"message": "Sales user not found!"}), 404

class Robot:
    @staticmethod
    @app.route("/robots", methods=["GET", "POST"])
    def manage_robots():
        if request.method == "GET":
            # Fetch all robots
            robots = list(robots_collection.find({}, {"_id": 0}))
            return jsonify(robots), 200

        if request.method == "POST":
            # Add a new robot
            data = request.json
            if robots_collection.find_one({"id": data["id"]}):
                return jsonify({"message": "Robot with this ID already exists!"}), 400
            robots_collection.insert_one(data)
            return jsonify({"message": "Robot added successfully!"}), 201

    @staticmethod
    @app.route("/robots/<int:robot_id>", methods=["GET", "PUT", "DELETE"])
    def robot_operations(robot_id):
        if request.method == "GET":
            # Fetch a specific robot by ID
            robot = robots_collection.find_one({"id": robot_id}, {"_id": 0})
            if robot:
                return jsonify(robot), 200
            return jsonify({"message": "Robot not found!"}), 404

        if request.method == "PUT":
            # Update a specific robot
            data = request.json
            updated = robots_collection.update_one({"id": robot_id}, {"$set": data})
            if updated.matched_count:
                return jsonify({"message": "Robot updated successfully!"}), 200
            return jsonify({"message": "Robot not found!"}), 404

        if request.method == "DELETE":
            # Delete a specific robot
            deleted = robots_collection.delete_one({"id": robot_id})
            if deleted.deleted_count:
                return jsonify({"message": "Robot deleted successfully!"}), 200
            return jsonify({"message": "Robot not found!"}), 404

class Coordinates:
    @staticmethod
    @app.route("/coordinates", methods=["GET", "POST"])
    def manage_coordinates():
        if request.method == "GET":
            # Fetch all coordinate entries
            coordinates = list(coordinates_collection.find({}, {"_id": 0}))
            return jsonify(coordinates), 200

        if request.method == "POST":
            # Add a new coordinate entry (accept any structure)
            data = request.json
            coordinates_collection.insert_one(data)
            return jsonify({"message": "Coordinates added successfully!"}), 201

    @staticmethod
    @app.route("/coordinates/<coord_id>", methods=["GET", "PUT", "DELETE"])
    def coordinate_operations(coord_id):
        if request.method == "GET":
            # Fetch a specific coordinate entry by custom 'coord_id'
            coord = coordinates_collection.find_one({"coord_id": coord_id}, {"_id": 0})
            if coord:
                return jsonify(coord), 200
            return jsonify({"message": "Coordinates not found!"}), 404

        if request.method == "PUT":
            # Update a coordinate entry (partial/full)
            data = request.json
            updated = coordinates_collection.update_one({"coord_id": coord_id}, {"$set": data})
            if updated.matched_count:
                return jsonify({"message": "Coordinates updated successfully!"}), 200
            return jsonify({"message": "Coordinates not found!"}), 404

        if request.method == "DELETE":
            # Delete a coordinate entry
            deleted = coordinates_collection.delete_one({"coord_id": coord_id})
            if deleted.deleted_count:
                return jsonify({"message": "Coordinates deleted successfully!"}), 200
            return jsonify({"message": "Coordinates not found!"}), 404

# Main Entry
if __name__ == "__main__":
    app.run(debug=True)