# **Users API Endpoints Documentation**

---

### **1. `/sales_users` [GET, POST]**

#### **GET**: Fetch all sales users with optional filtering by role

- **Query Parameters:**
  - `role` (optional): Filter sales users by their role (e.g., "cashier", "manager").
- **Responses:**
  - **200 OK**: Returns a list of sales users, excluding passwords.
- **Example Usage:**

  ```bash
  GET /sales_users?role=cashier HTTP/1.1
  Host: example.com
  ```

  **Response:**

  ```json
  [
    {
      "username": "cashier1",
      "name": "John Doe",
      "role": "cashier"
    },
    {
      "username": "cashier2",
      "name": "Jane Smith",
      "role": "cashier"
    }
  ]
  ```

#### **POST**: Add a new sales user

- **Request Body:**

  ```json
  {
    "username": "manager1",
    "name": "Alice Manager",
    "role": "manager",
    "password": "securepassword"
  }
  ```

- **Responses:**
  - **201 Created**: User added successfully.
  - **400 Bad Request**: Username already exists.
- **Example Usage:**

  ```bash
  POST /sales_users HTTP/1.1
  Content-Type: application/json

  {
    "username": "manager1",
    "name": "Alice Manager",
    "role": "manager",
    "password": "securepassword"
  }
  ```

---

### **2. `/sales_users/<username>` [GET, PUT, DELETE]**

#### **GET**: Fetch details of a specific sales user

- **Path Parameter:**
  - `<username>`: Username of the sales user to fetch.
- **Responses:**
  - **200 OK**: Returns user details.
  - **404 Not Found**: Sales user not found.
- **Example Usage:**

  ```bash
  GET /sales_users/manager1 HTTP/1.1
  ```

  **Response:**

  ```json
  {
    "username": "manager1",
    "name": "Alice Manager",
    "role": "manager"
  }
  ```

#### **PUT**: Update user details or role

- **Path Parameter:**
  - `<username>`: Username of the sales user to update.
- **Request Body:**

  ```json
  {
    "role": "administrator"
  }
  ```

- **Responses:**
  - **200 OK**: User updated successfully.
  - **404 Not Found**: Sales user not found.
- **Example Usage:**

  ```bash
  PUT /sales_users/manager1 HTTP/1.1
  Content-Type: application/json

  {
    "role": "administrator"
  }
  ```

#### **DELETE**: Delete a sales user

- **Path Parameter:**
  - `<username>`: Username of the sales user to delete.
- **Responses:**
  - **200 OK**: User deleted successfully.
  - **404 Not Found**: Sales user not found.
- **Example Usage:**

  ```bash
  DELETE /sales_users/manager1 HTTP/1.1
  ```

---

### **3. `/sales_users/login` [POST]**

#### **POST**: Authenticate a user and return login status

- **Request Body:**

  ```json
  {
    "username": "manager1",
    "password": "securepassword"
  }
  ```

- **Responses:**
  - **200 OK**: Login successful.
  - **401 Unauthorized**: Invalid username or password.
- **Example Usage:**

  ```bash
  POST /sales_users/login HTTP/1.1
  Content-Type: application/json

  {
    "username": "manager1",
    "password": "securepassword"
  }
  ```

  **Response:**

  ```json
  {
    "message": "Login successful!",
    "role": "manager"
  }
  ```

---

### **4. `/sales_users/audit` [GET]**

#### **GET**: Get audit log for accountability

- **Query Parameter:**
  - `username` (optional): Fetch logs for a specific username.
- **Responses:**
  - **200 OK**: Returns a list of audit logs.
- **Example Usage:**

  ```bash
  GET /sales_users/audit?username=manager1 HTTP/1.1
  ```

  **Response:**

  ```json
  [
    {
      "username": "manager1",
      "action": "Updated inventory",
      "timestamp": "2025-01-20T10:15:30Z"
    },
    {
      "username": "manager1",
      "action": "Deleted product",
      "timestamp": "2025-01-21T12:45:00Z"
    }
  ]
  ```

---

### **5. `/sales_users/change_password/<username>` [PUT]**

#### **PUT**: Change password for a specific user

- **Path Parameter:**
  - `<username>`: Username of the sales user.
- **Request Body:**

  ```json
  {
    "new_password": "newsecurepassword"
  }
  ```

- **Responses:**
  - **200 OK**: Password changed successfully.
  - **400 Bad Request**: New password not provided.
  - **404 Not Found**: Sales user not found.
- **Example Usage:**

  ```bash
  PUT /sales_users/change_password/manager1 HTTP/1.1
  Content-Type: application/json

  {
    "new_password": "newsecurepassword"
  }
  ```

  **Response:**

  ```json
  {
    "message": "Password changed successfully!"
  }
  ```
