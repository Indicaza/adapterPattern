#include <iostream>
#include <string>

// Existing IDatabase Interface
class IDatabase {
public:
    virtual void connect() = 0;
    virtual void executeQuery(const std::string& query) = 0;
    virtual void disconnect() = 0;
    virtual ~IDatabase() {}
};

// Web API Interface
class WebAPI {
public:
    void openConnection() {
        std::cout << "WebAPI Connection Opened\n";
    }
    void sendRequest(const std::string& request) {
        std::cout << "Request Sent: " << request << "\n";
    }
    void closeConnection() {
        std::cout << "WebAPI Connection Closed\n";
    }
};

// Adapter Class that adapts WebAPI to IDatabase
class WebAPIAdapter : public IDatabase {
private:
    WebAPI* webAPI;

public:
    WebAPIAdapter(WebAPI* api) : webAPI(api) {}

    void connect() override {
        webAPI->openConnection();
    }

    void executeQuery(const std::string& query) override {
        webAPI->sendRequest(query);
    }

    void disconnect() override {
        webAPI->closeConnection();
    }
};

// Application Class that uses IDatabase
class Application {
public:
    void useDatabase(IDatabase& database) {
        database.connect();
        database.executeQuery("SELECT * FROM users");
        database.disconnect();
    }
};


int main() {
    WebAPI webAPI; // Instance of the Web API
    WebAPIAdapter adapter(&webAPI); // Adapter for the Web API

    Application app;
    app.useDatabase(adapter); // Using the adapter as if it's a database

    return 0;
}
