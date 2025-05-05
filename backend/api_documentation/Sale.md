# API Documentation: Sales Management Endpoints

---

## 1. `/sales` (GET, POST)

### **GET: Fetch Sales Records**

#### Purpose

Retrieve all sales records, optionally filtered by a date range.

#### Query Parameters

- `start_date` (optional): Start date of the sales filter range (ISO format, e.g., `2025-01-01`).
- `end_date` (optional): End date of the sales filter range (ISO format, e.g., `2025-01-31`).

#### Example Request

```
GET /sales?start_date=2025-01-01&end_date=2025-01-31
```

#### Example Response

```json
[
    {
        "sale_id": "S001",
        "timestamp": "2025-01-10T12:34:56Z",
        "products_sold": [
            {
                "product_id": "P001",
                "quantity": 2,
                "price": 5.00
            },
            {
                "product_id": "P002",
                "quantity": 1,
                "price": 10.00
            }
        ],
        "total_amount": 20.00
    }
]
```

### **POST: Record a New Sale**

#### Purpose

Record a new sale, decrementing the stock for each product sold.

#### Request Body

```json
{
    "sale_id": "S002",
    "products_sold": [
        {
            "product_id": "P001",
            "quantity": 3
        },
        {
            "product_id": "P003",
            "quantity": 1
        }
    ]
}
```

#### Example Response

```json
{
    "message": "Sale recorded successfully!",
    "total_amount": 25.00
}
```

---

## 2. `/sales/<sale_id>` (GET, PUT, DELETE)

### **GET: Fetch Sale by ID**

#### Purpose

Retrieve details of a specific sale by its `sale_id`.

#### Example Request

```
GET /sales/S001
```

#### Example Response

```json
{
    "sale_id": "S001",
    "timestamp": "2025-01-10T12:34:56Z",
    "products_sold": [
        {
            "product_id": "P001",
            "quantity": 2,
            "price": 5.00
        },
        {
            "product_id": "P002",
            "quantity": 1,
            "price": 10.00
        }
    ],
    "total_amount": 20.00
}
```

### **PUT: Update Sale Record**

#### Purpose

Update details of an existing sale.

#### Request Body

```json
{
    "products_sold": [
        {
            "product_id": "P003",
            "quantity": 2
        }
    ]
}
```

#### Example Request

```
PUT /sales/S001
```

#### Example Response

```json
{
    "message": "Sale updated successfully!"
}
```

### **DELETE: Delete Sale Record**

#### Purpose

Delete a sale record by its `sale_id`.

#### Example Request

```
DELETE /sales/S001
```

#### Example Response

```json
{
    "message": "Sale deleted successfully!"
}
```

---

## 3. `/sales/report` (GET)

### **GET: Generate Sales Report**

#### Purpose

Retrieve a detailed sales report for a specific time range.

#### Query Parameters

- `start_date` (optional): Start date of the report range (ISO format).
- `end_date` (optional): End date of the report range (ISO format).

#### Example Request

```
GET /sales/report?start_date=2025-01-01&end_date=2025-01-31
```

#### Example Response

```json
{
    "total_sales": 150.00,
    "report": [
        {
            "sale_id": "S001",
            "timestamp": "2025-01-10T12:34:56Z",
            "products_sold": [
                {
                    "product_id": "P001",
                    "quantity": 2,
                    "price": 5.00
                }
            ],
            "total_amount": 10.00
        },
        {
            "sale_id": "S002",
            "timestamp": "2025-01-15T14:20:00Z",
            "products_sold": [
                {
                    "product_id": "P002",
                    "quantity": 1,
                    "price": 10.00
                }
            ],
            "total_amount": 10.00
        }
    ]
}
```
