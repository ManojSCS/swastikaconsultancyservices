#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <ctime>

// Simple C++ Backend Server for Swastika Consultancy
// Note: This is a simplified example. For production, use frameworks like:
// - Beast (HTTP library)
// - Drogon (Web framework)
// - cpp-httplib (Simple HTTP library)

using namespace std;

// User Structure
struct User {
    int id;
    string name;
    string email;
    string phone;
    string password;
    string registeredDate;
};

// Order Structure
struct Order {
    int id;
    int userId;
    string packageName;
    double amount;
    string status; // pending, completed, cancelled
    string orderDate;
};

// Database (In-memory for demo)
class Database {
public:
    vector<User> users;
    vector<Order> orders;
    int nextUserId = 1;
    int nextOrderId = 1001;
    
    // User Management
    bool registerUser(const string& name, const string& email, const string& phone, const string& password) {
        // Check if user already exists
        for (const auto& user : users) {
            if (user.email == email) {
                return false; // User already exists
            }
        }
        
        User newUser;
        newUser.id = nextUserId++;
        newUser.name = name;
        newUser.email = email;
        newUser.phone = phone;
        newUser.password = password; // In production, hash the password!
        newUser.registeredDate = getCurrentDate();
        users.push_back(newUser);
        return true;
    }
    
    User* loginUser(const string& email, const string& password) {
        for (auto& user : users) {
            if (user.email == email && user.password == password) {
                return &user;
            }
        }
        return nullptr;
    }
    
    User* getUserById(int id) {
        for (auto& user : users) {
            if (user.id == id) {
                return &user;
            }
        }
        return nullptr;
    }
    
    // Order Management
    Order* createOrder(int userId, const string& packageName, double amount) {
        Order newOrder;
        newOrder.id = nextOrderId++;
        newOrder.userId = userId;
        newOrder.packageName = packageName;
        newOrder.amount = amount;
        newOrder.status = "pending";
        newOrder.orderDate = getCurrentDate();
        orders.push_back(newOrder);
        return &orders.back();
    }
    
    vector<Order> getUserOrders(int userId) {
        vector<Order> userOrders;
        for (const auto& order : orders) {
            if (order.userId == userId) {
                userOrders.push_back(order);
            }
        }
        return userOrders;
    }
    
private:
    string getCurrentDate() {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt);
    }
};

// Authentication Service
class AuthService {
public:
    AuthService(Database& db) : database(db) {}
    
    bool registerUser(const string& name, const string& email, const string& phone, const string& password) {
        // Validation
        if (name.empty() || email.empty() || phone.empty() || password.empty()) {
            return false;
        }
        if (password.length() < 6) {
            return false; // Password too short
        }
        return database.registerUser(name, email, phone, password);
    }
    
    User* login(const string& email, const string& password) {
        return database.loginUser(email, password);
    }
    
private:
    Database& database;
};

// Order Service
class OrderService {
public:
    OrderService(Database& db) : database(db) {}
    
    Order* createOrder(int userId, const string& packageName, double amount) {
        // Validate package
        if (!isValidPackage(packageName)) {
            return nullptr;
        }
        return database.createOrder(userId, packageName, amount);
    }
    
    vector<Order> getOrders(int userId) {
        return database.getUserOrders(userId);
    }
    
private:
    Database& database;
    
    bool isValidPackage(const string& packageName) {
        return packageName == "Starter" || packageName == "Professional" || packageName == "Enterprise";
    }
};

// Main Server
class Server {
public:
    Server() : authService(database), orderService(database) {}
    
    void start() {
        cout << "Swastika Consultancy Services - Backend Server" << endl;
        cout << "Server running on localhost:8000" << endl;
        // In production, set up HTTP endpoints here
        // using a library like Beast or cpp-httplib
    }
    
    AuthService& getAuthService() { return authService; }
    OrderService& getOrderService() { return orderService; }
    Database& getDatabase() { return database; }
    
private:
    Database database;
    AuthService authService;
    OrderService orderService;
};

int main() {
    Server server;
    server.start();
    
    // Demo: Register and create order
    AuthService& auth = server.getAuthService();
    OrderService& orderSvc = server.getOrderService();
    
    // Register a user
    if (auth.registerUser("John Doe", "john@example.com", "9876543210", "password123")) {
        cout << "User registered successfully!" << endl;
        
        // Login
        User* user = auth.login("john@example.com", "password123");
        if (user) {
            cout << "Login successful! User ID: " << user->id << endl;
            
            // Create an order
            Order* order = orderSvc.createOrder(user->id, "Professional", 12000);
            if (order) {
                cout << "Order created! Order ID: " << order->id << endl;
            }
        }
    }
    
    return 0;
}
