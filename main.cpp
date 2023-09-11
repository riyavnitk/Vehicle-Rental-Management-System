#include <bits/stdc++.h>
using namespace std;


class Vehicle {
public:
    // Default Constructors
    Vehicle() {}
    // Parameterized Constructors
    Vehicle(string vehicleNumberPlate, string vehicleType, double vehicleRent, bool vehicleStatus) {
        this->vehicleNumberPlate = vehicleNumberPlate;
        this->vehicleType = vehicleType; 
        this->vehicleRent = vehicleRent;
        this->vehicleStatus = vehicleStatus; 
    }
    // Mutators
    void setVehicleNumberPlate(string vehicleNumberPlate) {
        this->vehicleNumberPlate = vehicleNumberPlate; 
    }
    void setVehicleType(string vehicleType) {
        this->vehicleType = vehicleType;
    }
    void setVehicleRent(double vehicleRent) {
        this->vehicleRent = vehicleRent;
    }
    void setVehicleStatus(bool vehicleStatus) {
        this->vehicleStatus = vehicleStatus;
    }
    // Accessors
    string getVehicleNumberPlate() {
        return this->vehicleNumberPlate;
    }
    string getVehicleType() {
        return this->vehicleType;
    }
    double getVehicleRent() {
        return this->vehicleRent;
    }
    bool getVehicleStatus() {
        return this->vehicleStatus;
    }
    // Destructor
    ~Vehicle() {}
private:
    string vehicleNumberPlate; // unique
    string vehicleType; // car, bike, etc.
    double vehicleRent; // per day
    bool vehicleStatus; // true if available, false if not
};

class Customer {
public:
    // Default Constructors
    Customer() {}
    // Parameterized Constructors
    Customer(int customerId, string name, string phone, string address, int age) {
        this->customerId = customerId;
        this->name = name;
        this->phone = phone;
        this->address = address;
        this->age = age;
    }
    // Mutators
    void setCustomerId(int customerId) {
        this->customerId = customerId;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPhone(string phone) {
        this->phone = phone;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void setAge(int age) {
        this->age = age;
    }
    // Accessors
    int getCustomerId() {
        return this->customerId;
    }
    string getName() {
        return this->name;
    }
    string getPhone() {
        return this->phone;
    }
    string getAddress() {
        return this->address;
    }
    int getAge() {
        return this->age;
    }
    // Destructor
    ~Customer() {}
private:
    int customerId;
    string name;
    string phone;
    string address;
    int age;
};

class Order {
public:
    // Mutators
    void setVehicle(Vehicle vehicle) {
        this->vehicle = vehicle;
    }
    void setCustomer(Customer customer) {
        this->customer = customer;
    }
    void setStartDate(string startDate) {
        this->startDate = startDate;
    }
    void setDuration(int duration) {
        this->duration = duration;
    }
    void setTotalRent(double totalRent) {
        this->totalRent = totalRent;
    }
    void setModeOfPayment(string modeOfPayment) {
        this->modeOfPayment = modeOfPayment;
    }
    void setDateOfPayment(string dateOfPayment) {
        this->dateOfPayment = dateOfPayment;
    }
    void setDiscount(int discount) {
        this->discount = discount;
    }
    // Accessors
    Vehicle getVehicle() {
        return this->vehicle;
    }
    Customer getCustomer() {
        return this->customer;
    }
    string getStartDate() {
        return this->startDate;
    }
    int getDuration() {
        return this->duration;
    }
    double getTotalRent() {
        return this->totalRent;
    }
    string getModeOfPayment() {
        return this->modeOfPayment;
    }
    string getDateOfPayment() {
        return this->dateOfPayment;
    }
    int getDiscount() {
        return this->discount;
    }
    // Destructor
    ~Order() {}
private:
    Vehicle vehicle;
    Customer customer;
    string startDate; // dd/mm/yyyy
    int duration; // in days
    double totalRent;
    string modeOfPayment;
    string dateOfPayment; // dd/mm/yyyy
    int discount;
};

class Authentication {
public:
    Authentication() {}
    bool authenticate(const string& username,const string& password) {
        if(username == this->admin_username && password == this->admin_password) {
            cout << "Authentication successful!" << endl;
            return true;
        }
        else {
            cout << "Authentication failed!" << endl;
            return false;
        }
    }
private:
    string admin_username = "admin";
    string admin_password = "admin";
};


int main() {

    // Welcome message
    cout << "--------------------------------" << endl;
    cout << "Welcome to the Car Rental System" << endl; 
    cout << "--------------------------------" << endl;
    cout << "Welcome to the Car Rental System!" << endl;
    cout << "Please authenticate yourself to continue." << endl;
    cout << "\n\n\n" << endl;

    // Admin authentication
    cout << "--------------------------------" << endl;
    cout << "      Admin Authentication      " << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter username: "; 
    string username; cin >> username;
    cout << endl;
    cout << "Enter password: ";
    string password; cin >> password;
    cout << endl;
    Authentication auth;
    if(!auth.authenticate(username, password)) {
        cout << "Incorrect username or password!" << endl;
        cout << "Exiting..." << endl;
        return 0;
    }
    
    // Admin menu
    cout << "--------------------------------" << endl;
    cout << "          Admin Menu            " << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Register a new customer" << endl;
    cout << "2. Register a new vehicle" << endl;
    cout << "3. Create an order" << endl;

    return 0;
}

