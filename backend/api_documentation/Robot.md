# Robots API Documentation

## Base URL

```
http://localhost:5000
```

## Endpoints

### 1. Get All Robots

**Endpoint:**

```
GET /robots
```

**Description:** Fetches all robots from the database.

**Response:**

```json
[
    {"id": 1, "name": "Robot Alpha", "status": "Active", "location": "Aisle 1", "task": "Patrolling"},
    {"id": 2, "name": "Robot Beta", "status": "Idle", "location": "Entrance", "task": ""}
]
```

**Status Codes:**

- `200 OK` - Returns list of robots.

---

### 2. Add a New Robot

**Endpoint:**

```
POST /robots
```

**Description:** Adds a new robot to the database.

**Request Body:**

```json
{
    "id": 5,
    "name": "Robot Delta",
    "status": "Idle",
    "location": "Storage",
    "task": "Maintenance"
}
```

**Response:**

```json
{"message": "Robot added successfully!"}
```

**Status Codes:**

- `201 Created` - Robot added successfully.
- `400 Bad Request` - Robot with this ID already exists.

---

### 3. Get a Specific Robot

**Endpoint:**

```
GET /robots/{robot_id}
```

**Description:** Fetches a specific robot by its ID.

**Example:**

```
GET /robots/1
```

**Response:**

```json
{
    "id": 1,
    "name": "Robot Alpha",
    "status": "Active",
    "location": "Aisle 1",
    "task": "Patrolling"
}
```

**Status Codes:**

- `200 OK` - Returns robot details.
- `404 Not Found` - Robot not found.

---

### 4. Update a Robot

**Endpoint:**

```
PUT /robots/{robot_id}
```

**Description:** Updates details of an existing robot.

**Request Body:**

```json
{
    "status": "Busy",
    "task": "Stock Refill"
}
```

**Response:**

```json
{"message": "Robot updated successfully!"}
```

**Status Codes:**

- `200 OK` - Robot updated successfully.
- `404 Not Found` - Robot not found.

---

### 5. Delete a Robot

**Endpoint:**

```
DELETE /robots/{robot_id}
```

**Description:** Deletes a robot by its ID.

**Example:**

```
DELETE /robots/3
```

**Response:**

```json
{"message": "Robot deleted successfully!"}
```

**Status Codes:**

- `200 OK` - Robot deleted successfully.
- `404 Not Found` - Robot not found.
