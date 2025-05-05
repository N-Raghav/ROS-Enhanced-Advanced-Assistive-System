# API Documentation: Product Management Endpoints

---

## 1. `/products` (GET, POST)

### **GET: Fetch All Products**

#### Purpose

Retrieve all products from the database, optionally filtered by category or stock status.

#### Query Parameters

- `category` (optional): Filter products by category (e.g., `electronics`, `groceries`).
- `stock_status` (optional): Set to `low` to fetch products with low stock.

#### Example Request

```
GET /products?category=groceries&stock_status=low
```

#### Example Response

```json
[
    {
        "product_id": "P001",
        "name": "Milk",
        "category": "groceries",
        "price": 2.50,
        "stock": 20,
        "expiration_date": "2025-01-27",
        "last_restock_date": "2025-01-10"
    },
    {
        "product_id": "P002",
        "name": "Bread",
        "category": "groceries",
        "price": 1.50,
        "stock": 15,
        "expiration_date": "2025-01-22",
        "last_restock_date": "2025-01-08"
    }
]
```

### **POST: Add a New Product**

#### Purpose

Add a new product to the database.

#### Request Body

```json
{
    "product_id": "P003",
    "name": "Butter",
    "category": "groceries",
    "price": 3.00,
    "stock": 100,
    "expiration_date": "2025-02-15"
}
```

#### Example Response

```json
{
    "message": "Product added successfully!"
}
```

---

## 2. `/products/<product_id>` (GET, PUT, DELETE)

### **GET: Fetch Product by ID**

#### Purpose

Retrieve details of a specific product by its `product_id`.

#### Example Request

```
GET /products/P001
```

#### Example Response

```json
{
    "product_id": "P001",
    "name": "Milk",
    "category": "groceries",
    "price": 2.50,
    "stock": 20,
    "expiration_date": "2025-01-27",
    "last_restock_date": "2025-01-10"
}
```

### **PUT: Update Product Details**

#### Purpose

Update the information of a specific product.

#### Request Body

```json
{
    "price": 2.75,
    "stock": 50
}
```

#### Example Request

```
PUT /products/P001
```

#### Example Response

```json
{
    "message": "Product updated successfully!"
}
```

### **DELETE: Remove a Product**

#### Purpose

Delete a product from the database.

#### Example Request

```
DELETE /products/P001
```

#### Example Response

```json
{
    "message": "Product deleted successfully!"
}
```

---

## 3. `/products/restock` (GET)

### **GET: List Products Needing Restock**

#### Purpose

Retrieve a list of products with stock below a specified threshold.

#### Query Parameters

- `threshold` (optional): Minimum stock level to filter products. Default is 50.

#### Example Request

```
GET /products/restock?threshold=30
```

#### Example Response

```json
[
    {
        "product_id": "P002",
        "name": "Bread",
        "category": "groceries",
        "stock": 15,
        "expiration_date": "2025-01-22",
        "last_restock_date": "2025-01-08"
    }
]
```

---

## 4. `/products/expiration` (GET)

### **GET: List Products Nearing Expiration**

#### Purpose

Retrieve a list of products whose expiration dates are within the next `X` days.

#### Query Parameters

- `days` (optional): Number of days to check for near-expiring products. Default is 7 days.

#### Example Request

```
GET /products/expiration?days=10
```

#### Example Response

```json
[
    {
        "product_id": "P001",
        "name": "Milk",
        "category": "groceries",
        "expiration_date": "2025-01-27"
    }
]
```

---
