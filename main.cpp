#include <bits/stdc++.h>
using namespace std;

// Date class
class Date {
public:
    // Default Constructor
    Date() : day(1), month(1), year(2023) {}
    // Parameterized Constructor
    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    // Mutators
    void setDay(int day) { 
        this->day = day;
    }
    void setMonth(int month) {
        this->month = month;
    }
    void setYear(int year) {
        this->year = year;
    }

    // Accessors
    int getDay() {
        return this->day;
    }
    int getMonth() {
        return this->month;
    }
    int getYear() {
        return this->year;
    }

    // Operator overloading to get difference between two dates
    int operator-(Date& date) {
        const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        int difference = 0;
        long int n1 = this->year * 365 + this->day;
        for (int i = 0; i < this->month - 1; i++)
            n1 += monthDays[i];
        n1 += countLeapYears(*this);

        long int n2 = date.year * 365 + date.day;
        for (int i = 0; i < date.month - 1; i++)
            n2 += monthDays[i];
        n2 += countLeapYears(date);

        difference = n2 - n1;
        return difference;
    }

    // Destructor
    ~Date() {}
private:
    int day; // 1-31
    int month; // 1-12
    int year; // 2023 - present

    // Inline function to count leap years
    static inline int countLeapYears(Date d) {
        int years = d.year;
        if (d.month <= 2)
            years--;
        return years / 4 - years / 100 + years / 400;
    }
};

// Vehicle class
class Vehicle {
public:
    // Default Constructor
    Vehicle() : vehicleNumberPlate("XX XX XX XXXX"), vehicleType("XXXXX"), vehicleRent(0.0), vehicleStatus(false) {}
    // Parameterized Constructor
    Vehicle(string vehicleNumberPlate, string vehicleType, double vehicleRent, bool vehicleStatus) {
        this->vehicleNumberPlate = vehicleNumberPlate;
        this->vehicleType = vehicleType; 
        this->vehicleRent = vehicleRent;
        this->vehicleStatus = vehicleStatus; 
    }
    // Static variable to keep track
    static int count;
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

// Copy constructor for a scooter
class Scooter {
    Vehicle* v = new Vehicle(vehicleNumberPlate, vehicleType, vehicleRent, vehicleStatus); // dynamic memory allocation
private:
    Vehicle* vehicle = v; // copy constructor
    string vehicleNumberPlate = "KA 20 SC 1234"; // unique
    string vehicleType = "Scooter"; 
    double vehicleRent = 410; // per day
    bool vehicleStatus = true; // true if available
};

// Copy constructor for a bike
class Bike {
    Vehicle* v = new Vehicle(vehicleNumberPlate, vehicleType, vehicleRent, vehicleStatus); // dynamic memory allocation
private:
    Vehicle* vehicle = v; // copy constructor
    string vehicleNumberPlate = "KA 20 BK 4774"; // unique
    string vehicleType = "Bike";
    double vehicleRent = 530; // per day
    bool vehicleStatus = false; // false if not available
};

// Customer class
class Customer {
public:
    // Default Constructor
    Customer() : customerId(0), name("----"), phone("----------"), address("-----"), age(0) {}
    // Parameterized Constructor
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
    int customerId; // unique
    string name; // name
    string phone; // phone number
    string address; // address
    int age; // age
};

class Order {
public:
    // Default Constructor
    Order() {}

    // Mutators
    void setVehicle(Vehicle vehicle) {
        this->vehicle = vehicle;
    }
    void setCustomer(Customer customer) {
        this->customer = customer;
    }
    void setStartDate(Date startDate) {
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
    void setDateOfPayment(Date dateOfPayment) {
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
    Date getStartDate() {
        return this->startDate;
    }
    int getDuration(Date& startDate, Date& endDate) {
        this->duration = startDate - endDate;
        return this->duration;
    }
    double getTotalRent() {
        return this->totalRent;
    }
    string getModeOfPayment() {
        return this->modeOfPayment;
    }
    Date getDateOfPayment() {
        return this->dateOfPayment;
    }
    int getDiscount() {
        return this->discount;
    }

    friend class Date; // to access getDifference
    friend class Vehicle; // to access vehicleStatus
    friend class Customer; // to access customerId
    
    // Destructor
    ~Order() {}
private:
    Vehicle vehicle;
    Customer customer;
    Date startDate; // dd/mm/yyyy
    Date endDate; // dd/mm/yyyy
    int duration; // in days
    double totalRent;
    string modeOfPayment;
    Date dateOfPayment; // dd/mm/yyyy
    int discount;
    int finePerHour = 50;
};

class Authentication {
public:
    Authentication() {}
    bool authenticate(const string& username,const string& password); 
private:
    string admin_username = "admin";
    string admin_password = "admin";
};

// In-line function to authenticate admin
bool Authentication::authenticate(const string& username,const string& password) {
    if(username == this->admin_username && password == this->admin_password) {
        cout << "Authentication successful!" << endl;
        return true;
    }
    else {
        cout << "Authentication failed!" << endl;
        return false;
    }
}

/*
double operator*(Vehicle& vehicle, Order& order) {
    return vehicle.getVehicleRent() * (double)order.getDuration();
}
*/


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
    cout << "4. View all orders" << endl;
    cout << "5. View all customers" << endl;
    cout << "6. View all vehicles" << endl;
    cout << "7. Exit" << endl;
    cout << "\n\n\n" << endl;

    // Admin menu choice
    cout << "Enter your choice: ";
    int choice; cin >> choice;
    cout << endl;

    // Admin menu choice handler
    switch(choice) {
        case 1: {
            // Register a new customer
            cout << "--------------------------------" << endl;
            cout << "    Register a new customer     " << endl;
            cout << "--------------------------------" << endl;
            cout << "Enter customer id: ";
            int customerId; cin >> customerId;
            cout << endl;
            cout << "Enter name: ";
            string name; cin >> name;
            cout << endl;
            cout << "Enter phone: ";
            string phone; cin >> phone;
            cout << endl;
            cout << "Enter address: ";
            string address; cin >> address;
            cout << endl;
            cout << "Enter age: ";
            int age; cin >> age;
            cout << endl;
            Customer customer(customerId, name, phone, address, age);
            cout << "Customer registered successfully!" << endl;
            cout << "\n\n\n" << endl;
            break;
        }
        case 2: {
            // Register a new vehicle
            cout << "--------------------------------" << endl;
            cout << "     Register a new vehicle     " << endl;
            cout << "--------------------------------" << endl;
            cout << "Enter vehicle number plate: ";
            string vehicleNumberPlate; cin >> vehicleNumberPlate;
            cout << endl;
            cout << "Enter vehicle type: ";
            string vehicleType; cin >> vehicleType;
            cout << endl;
            cout << "Enter vehicle rent: ";
            double vehicleRent; cin >> vehicleRent;
            cout << endl;
            cout << "Enter vehicle status (1 for available, 0 for not available): ";
            bool vehicleStatus; cin >> vehicleStatus;
            cout << endl;
            Vehicle vehicle(vehicleNumberPlate, vehicleType, vehicleRent, vehicleStatus);
            cout << "Vehicle registered successfully!" << endl;
            cout << "\n\n\n" << endl;
            break;
        }
        case 3: {
            // Create an order
            cout << "--------------------------------" << endl;
            cout << "        Create an order         " << endl;
            cout << "--------------------------------" << endl;
            cout << "Enter vehicle number plate: ";
            string vehicleNumberPlate; cin >> vehicleNumberPlate;
            cout << endl;
            cout << "Enter customer id: ";
            int customerId; cin >> customerId;
            cout << endl;
            cout << "Enter start date: ";
            string startDate;
            cin >> startDate;
            cout << endl;
            cout << "Enter duration: ";
            int duration; cin >> duration;
            cout << endl;
            cout << "Enter total rent: ";
            double totalRent; cin >> totalRent;
            cout << endl;
            cout << "Enter mode of payment: ";
            string modeOfPayment; cin >> modeOfPayment;
            cout << endl;
            cout << "Enter date of payment: ";
            string dateOfPayment; cin >> dateOfPayment;
            cout << endl;
            cout << "Enter discount: ";
            int discount; cin >> discount;
            cout << endl;
            Order order;
            cout << "Order created successfully!" << endl;
            cout << "\n\n\n" << endl;
            break;
        }
        case 4: {
            // View all orders
            cout << "--------------------------------" << endl;
            cout << "         View all orders        " << endl;
            cout << "--------------------------------" << endl;
            cout << "Order 1" << endl;
            cout << "Order 2" << endl;
            cout << "Order 3" << endl;
            cout << "Order 4" << endl;
            cout << "Order 5" << endl;
            cout << "\n\n\n" << endl;
            break;
        }
    }

    return 0;
}

