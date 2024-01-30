#include <iostream>
#include <string>

// Existing IDatabase Interface
class IDatabase {
public:
    virtual ~IDatabase() {}
    virtual void connect() = 0;
    virtual void executeQuery(const std::string& query) = 0;
    virtual void disconnect() = 0;
};

// Web API Interface
class WebAPI {
public:
    void openConnection() { std::cout << "Open Web API Connection\n"; }
    void sendRequest(const std::string& request) { std::cout << "Web API Request: " << request << "\n"; }
    void closeConnection() { std::cout << "Close Web API Connection\n"; }
};

// Adapter Class
class WebAPIAdapter : public IDatabase {
private:
    WebAPI webAPI;

public:
    void connect() override { webAPI.openConnection(); }
    void executeQuery(const std::string& query) override { webAPI.sendRequest(query); }
    void disconnect() override { webAPI.closeConnection(); }
};

// Application Class
class Application {
public:
    void useDatabase(IDatabase& database) {
        database.connect();
        database.executeQuery("SELECT * FROM users");
        database.disconnect();
    }
};

int main() {
    WebAPIAdapter adapter;  // Create an adapter instance
    Application app;        // Create an application instance
    app.useDatabase(adapter); // Use the adapter
    return 0;
}
