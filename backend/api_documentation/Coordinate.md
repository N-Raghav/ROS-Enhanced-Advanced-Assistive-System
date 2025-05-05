# 📍 Coordinates API Documentation

Base URL: `http://<your-domain-or-ip>:<port>`

All responses are in `application/json`.

---

## 🔄 Endpoints Summary

| Method | Endpoint                  | Description                     |
|--------|---------------------------|---------------------------------|
| GET    | `/coordinates`            | Get all coordinate entries      |
| POST   | `/coordinates`            | Add a new coordinate entry      |
| GET    | `/coordinates/<coord_id>`| Get a specific coordinate entry |
| PUT    | `/coordinates/<coord_id>`| Update a coordinate entry       |
| DELETE | `/coordinates/<coord_id>`| Delete a coordinate entry       |

---

## 📥 POST `/coordinates`

### ➕ Create a new coordinate entry

- Accepts **any JSON structure** (flexible schema).
- You must include a unique `coord_id` field to identify the entry for future operations.

### ✅ Request Body Example

```json
{
  "coord_id": "point123",
  "latitude": 12.9716,
  "longitude": 77.5946,
  "timestamp": "2025-04-07T10:30:00Z",
  "robot_id": 1,
  "metadata": {
    "note": "Near charging station"
  }
}
```

### 🟢 Success Response

**Code:** `201 Created`  
**Body:**

```json
{
  "message": "Coordinates added successfully!"
}
```

---

## 📤 GET `/coordinates`

### 🔍 Fetch all coordinate entries

### 🟢 Success Response

**Code:** `200 OK`  
**Body:**

```json
[
  {
    "coord_id": "point123",
    "latitude": 12.9716,
    "longitude": 77.5946
  },
  ...
]
```

---

## 📤 GET `/coordinates/<coord_id>`

### 🔍 Fetch a specific coordinate entry

### 🟢 Success Response

**Code:** `200 OK`  
**Body:**

```json
{
  "coord_id": "point123",
  "latitude": 12.9716,
  "longitude": 77.5946
}
```

### 🔴 Error Response

**Code:** `404 Not Found`  
**Body:**

```json
{
  "message": "Coordinates not found!"
}
```

---

## ♻️ PUT `/coordinates/<coord_id>`

### 🔧 Update a specific coordinate entry (partial or full)

### ✅ Request Body Example

```json
{
  "latitude": 13.0827,
  "longitude": 80.2707,
  "metadata": { "note": "Updated to new location" }
}
```

### 🟢 Success Response

**Code:** `200 OK`  
**Body:**

```json
{
  "message": "Coordinates updated successfully!"
}
```

### 🔴 Error Response

**Code:** `404 Not Found`  
**Body:**

```json
{
  "message": "Coordinates not found!"
}
```

---

## ❌ DELETE `/coordinates/<coord_id>`

### 🧹 Delete a coordinate entry

### 🟢 Success Response

**Code:** `200 OK`  
**Body:**

```json
{
  "message": "Coordinates deleted successfully!"
}
```

### 🔴 Error Response

**Code:** `404 Not Found`  
**Body:**

```json
{
  "message": "Coordinates not found!"
}
```

---

Let me know if you'd like this exported as a file or need a Swagger/OpenAPI version too!
