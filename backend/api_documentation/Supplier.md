# Supplier Management API Endpoints Documentation

---

## 1. `GET /suppliers` - Fetch All Suppliers

### Description

Fetch a list of all suppliers, with optional filters by supplier type or location.

### Query Parameters

- `type` (optional): The type of supplier (e.g., "raw_materials", "packaging").
- `location` (optional): The location of the supplier (e.g., city or region).

### Example Request

#### Without Filters

```http
GET /suppliers HTTP/1.1
Content-Type: application/json
```

#### With Filters

```http
GET /suppliers?type=raw_materials&location=New%20York HTTP/1.1
Content-Type: application/json
```

### Example Response

```json
[
    {
        "supplier_id": "SUP123",
        "name": "ABC Raw Materials Co.",
        "type": "raw_materials",
        "location": "New York",
        "contact": {
            "email": "contact@abcrawmaterials.com",
            "phone": "+1-555-123-4567"
        }
    }
]
```

---

## 2. `POST /suppliers` - Add a New Supplier

### Description

Add a new supplier to the database.

### Request Body

```json
{
    "supplier_id": "SUP124",
    "name": "XYZ Packaging Co.",
    "type": "packaging",
    "location": "California",
    "contact": {
        "email": "info@xyzpackaging.com",
        "phone": "+1-555-987-6543"
    }
}
```

### Example Request

```http
POST /suppliers HTTP/1.1
Content-Type: application/json

{
    "supplier_id": "SUP124",
    "name": "XYZ Packaging Co.",
    "type": "packaging",
    "location": "California",
    "contact": {
        "email": "info@xyzpackaging.com",
        "phone": "+1-555-987-6543"
    }
}
```

### Example Response

#### On Success

```json
{
    "message": "Supplier added successfully!"
}
```

#### On Error

```json
{
    "message": "Supplier with this ID already exists!"
}
```

---

## 3. `GET /suppliers/<supplier_id>` - Fetch a Supplier by ID

### Description

Fetch details of a specific supplier by their ID.

### Example Request

```http
GET /suppliers/SUP123 HTTP/1.1
Content-Type: application/json
```

### Example Response

#### On Success

```json
{
    "supplier_id": "SUP123",
    "name": "ABC Raw Materials Co.",
    "type": "raw_materials",
    "location": "New York",
    "contact": {
        "email": "contact@abcrawmaterials.com",
        "phone": "+1-555-123-4567"
    }
}
```

#### On Not Found

```json
{
    "message": "Supplier not found!"
}
```

---

## 4. `PUT /suppliers/<supplier_id>` - Update a Supplier

### Description

Update details of an existing supplier by their ID.

### Request Body

```json
{
    "location": "Chicago",
    "contact": {
        "email": "support@abcrawmaterials.com"
    }
}
```

### Example Request

```http
PUT /suppliers/SUP123 HTTP/1.1
Content-Type: application/json

{
    "location": "Chicago",
    "contact": {
        "email": "support@abcrawmaterials.com"
    }
}
```

### Example Response

#### On Success

```json
{
    "message": "Supplier updated successfully!"
}
```

#### On Not Found

```json
{
    "message": "Supplier not found!"
}
```

---

## 5. `DELETE /suppliers/<supplier_id>` - Delete a Supplier

### Description

Delete a supplier by their ID.

### Example Request

```http
DELETE /suppliers/SUP123 HTTP/1.1
Content-Type: application/json
```

### Example Response

#### On Success

```json
{
    "message": "Supplier deleted successfully!"
}
```

#### On Not Found

```json
{
    "message": "Supplier not found!"
}
```

---

## 6. `GET /suppliers/products/<supplier_id>` - Fetch Products from a Supplier

### Description

Fetch a list of all products received from a specific supplier.

### Example Request

```http
GET /suppliers/products/SUP123 HTTP/1.1
Content-Type: application/json
```

### Example Response

#### On Success

```json
[
    {
        "product_id": "PROD001",
        "name": "Steel Rod",
        "category": "raw_materials",
        "stock": 100
    }
]
```

#### On Not Found

```json
{
    "message": "No products found for supplier SUP123"
}
```

---

## 7. `GET /suppliers/contact` - Fetch Supplier Contact Details

### Description

Fetch contact details of suppliers, optionally filtered by type.

### Query Parameters

- `type` (optional): The type of supplier (e.g., "raw_materials", "packaging").

### Example Request

#### Without Filters

```http
GET /suppliers/contact HTTP/1.1
Content-Type: application/json
```

#### With Filters

```http
GET /suppliers/contact?type=packaging HTTP/1.1
Content-Type: application/json
```

### Example Response

```json
[
    {
        "supplier_id": "SUP123",
        "name": "ABC Raw Materials Co.",
        "contact": {
            "email": "contact@abcrawmaterials.com",
            "phone": "+1-555-123-4567"
        }
    }
]
```

---
