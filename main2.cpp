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
    // Copy constructor
    Date(const Date& date) {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
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

        difference = n1 - n2;
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

Date inputDate(string dateformat) {
    int day, month, year;
    day = stoi(dateformat.substr(0, dateformat.find('-')));
    month = stoi(dateformat.substr(dateformat.find('-') + 1, dateformat.find_last_of('-') - dateformat.find('-') - 1));
    year = stoi(dateformat.substr(dateformat.find_last_of('-') + 1));
    Date date(day, month, year);
    return date;
}


// Vehicle class
class Vehicle {
public:
    // Default Constructor
    Vehicle() : vehicleNumberPlate("XX XX XX XXXX"), vehicleType("XXXXX"), vehicleRent(0.0), vehicleStatus(false) {}
    // Parameterized Constructor
    Vehicle(string vehicleNumberPlate, string vehicleName, double vehicleRent, bool vehicleStatus) {
        this->vehicleNumberPlate = vehicleNumberPlate;
        this->vehicleName = vehicleName;
        this->vehicleRent = vehicleRent;
        this->vehicleStatus = vehicleStatus;
    }
    // Static variable to keep track
    static int count;
    // Mutators
    virtual void setVehicleNumberPlate(string vehicleNumberPlate) {
        vehicleNumberPlate = vehicleNumberPlate; 
    }
    virtual void setVehicleType(string vehicleType) {
        vehicleType = vehicleType;
    }
    virtual void setVehicleRent(double vehicleRent) {
        vehicleRent = vehicleRent;
    }
    virtual void setVehicleStatus(bool vehicleStatus) {
        vehicleStatus = vehicleStatus;
    }
    virtual void setVehicleName(string vehicleName) {
        vehicleName = vehicleName;
    }

    // Accessors
    virtual string getVehicleNumberPlate() {
        return vehicleNumberPlate;
    }
    virtual string getVehicleType() {
        return this->vehicleType;
    }
    virtual double getVehicleRent() {
        return this->vehicleRent;
    }
    virtual bool getVehicleStatus() {
        return this->vehicleStatus;
    }
    virtual string getVehicleName() {
        return this->vehicleName;
    }

    // Destructor
    ~Vehicle() {}
protected:
    string vehicleNumberPlate; // unique
    string vehicleName; // name of the vehicle
    string vehicleType; // car, bike, etc.
    double vehicleRent; // per day
    bool vehicleStatus; // true if available, false if not
};

// Scooter class inheriting from Vehicle class
class Scooter : public Vehicle {
public:
    // Default Constructor
    Scooter() {
        setVehicleType("Scooter");
    }
    // Parameterized Constructor
    Scooter(string vehicleNumberPlate, string vehicleName, double vehicleRent, bool vehicleStatus) {
        setVehicleNumberPlate(vehicleNumberPlate);
        setVehicleName(vehicleName);
        setVehicleRent(vehicleRent);
        setVehicleStatus(vehicleStatus);
        setVehicleType("Scooter");
    }
    // Virtual functions for runtime polymorphism
    virtual void setVehicleType(string type) {
        vehicleType = type;
    }
    virtual void setVehicleNumberPlate(string numberPlate) {
        vehicleNumberPlate = numberPlate;
    }
    virtual void setVehicleName(string name) {
        vehicleName = name;
    }
    virtual void setVehicleRent(double rent) {
        vehicleRent = rent;
    }
    virtual void setVehicleStatus(bool status) {
        vehicleStatus = status;
    }
    // Accessors virtual functions
    virtual string getVehicleType() {
        return vehicleType;
    }
    virtual string getVehicleNumberPlate() {
        return vehicleNumberPlate;
    }
    virtual string getVehicleName() {
        return vehicleName;
    }
    virtual double getVehicleRent() {
        return vehicleRent;
    }
    virtual bool getVehicleStatus() {
        return vehicleStatus;
    }
};

// Bike class inheriting from Vehicle class
class Bike : public Vehicle {
public:
    // Default Constructor
    Bike() {
        setVehicleType("Bike");
    }
    // Parameterized Constructor
    Bike(string vehicleNumberPlate, string vehicleName, double vehicleRent, bool vehicleStatus) {
        setVehicleNumberPlate(vehicleNumberPlate);
        setVehicleName(vehicleName);
        setVehicleRent(vehicleRent);
        setVehicleStatus(vehicleStatus);
        setVehicleType("Bike");
    }
    // Virtual functions for runtime polymorphism
    virtual void setVehicleType(string type) {
        vehicleType = type;
    }
    virtual void setVehicleNumberPlate(string numberPlate) {
        vehicleNumberPlate = numberPlate;
    }
    virtual void setVehicleName(string name) {
        vehicleName = name;
    }
    virtual void setVehicleRent(double rent) {
        vehicleRent = rent;
    }
    virtual void setVehicleStatus(bool status) {
        vehicleStatus = status;
    }
    // Accessors virtual functions
    virtual string getVehicleType() {
        return vehicleType;
    }
    virtual string getVehicleNumberPlate() {
        return vehicleNumberPlate;
    }
    virtual string getVehicleName() {
        return vehicleName;
    }
    virtual double getVehicleRent() {
        return vehicleRent;
    }
    virtual bool getVehicleStatus() {
        return vehicleStatus;
    }
};

// An array for all the vehicles available
int vehicles_size = 5;
Vehicle* vehicles = new Vehicle[50] {
    Scooter("MH 12 AB 1234", "Scooter", 100.0, true),
    Scooter("MH 12 AB 1235", "Scooter", 100.0, true),
    Bike("MH 12 AB 1236", "Bike", 200.0, true),
    Bike("MH 12 AB 1237", "Bike", 200.0, true),
    Vehicle("MH 12 AB 1238", "Car", 300.0, true)
};

Vehicle checkAvailability(string type) {
    for(int i = 0; i < vehicles_size; i++) {
        if(vehicles[i].getVehicleType() == type && vehicles[i].getVehicleStatus() == true) {
            return vehicles[i];
        }
    }
    cout << "No available vehicles for rentals" << endl;
    exit(0);
}


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
protected:
    int customerId; // unique
    string name; // name
    string phone; // phone number
    string address; // address
    int age; // age
};

class Order {
public:
    // Default Constructor
    Order() {
        this->vehicle = Vehicle();
        this->customer = Customer();
        this->startDate = Date();
        this->endDate = Date();
        this->duration = 0;
        this->modeOfPayment = "Cash";
        this->dateOfPayment = Date();
    }
    // Parameterized Constructor
    Order(Vehicle v, Customer c, Date sd, Date ed, string mod, Date dop) {
        this->vehicle = v;
        this->customer = c;
        this->startDate = sd;
        this->endDate = ed;
        this->duration = getDuration(sd, ed);
        this->modeOfPayment = mod;
        this->dateOfPayment = dop;
    }

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
    void setTotalRent(double totalRent) {
        this->totalRent = totalRent;
    }
    void setModeOfPayment(string modeOfPayment) {
        this->modeOfPayment = modeOfPayment;
    }
    void setDateOfPayment(Date dateOfPayment) {
        this->dateOfPayment = dateOfPayment;
    }

    // Accessors
    Vehicle getVehicle() {
        return this->vehicle;
    }
    Customer getCustomer() {
        return this->customer;
    }
    Date& getStartDate() {
        return this->startDate;
    }
    int getDuration(Date& startDate, Date& endDate) {
        this->duration = endDate - startDate;
        return this->duration;
    }
    Date& getEndDate() {
        return this->endDate;
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

    // Friend classes
    friend class Date; // to access getDifference
    friend class Vehicle; // to access vehicleStatus
    friend class Customer; // to access customerId
    
    // Destructor
    ~Order() {}
protected:
    Vehicle vehicle;
    Customer customer;
    Date startDate; // dd/mm/yyyy
    Date endDate; // dd/mm/yyyy
    int duration; // in days
    double totalRent;
    string modeOfPayment;
    Date dateOfPayment; // dd/mm/yyyy
};

// Bill class
class Bill : public Bike, public Scooter {
public:
    // Default Constructor
    Bill() {}
    // Parameterized Constructor
    Bill(Order& order) {
        this->setOrder(order);
        double totalRent = order.getDuration(order.getStartDate(), order.getEndDate()) * order.getVehicle().getVehicleRent();
        this->setTotalRent(totalRent);
    }
    // Mutators
    void setOrder(Order& order) {
        this->order = order;
    }
    void setTotalRent(double totalRent) {
        this->totalRent = totalRent;
    }
    // Accessors
    Order& getOrder() {
        return this->order;
    }
    double getTotalRent() {
        return this->totalRent;
    }
    void printOrder() {
        cout << "--------------------------------" << endl;
        cout << "             Bill               " << endl;
        cout << "--------------------------------" << endl;
        cout << "Vehicle Number Plate: " << this->order.getVehicle().getVehicleNumberPlate() << endl;
        cout << "Vehicle Name: " << this->order.getVehicle().getVehicleName() << endl;
        cout << "Vehicle Type: " << this->order.getVehicle().getVehicleType() << endl;
        cout << "Vehicle Rent: " << this->order.getVehicle().getVehicleRent() << endl;
        cout << "Vehicle Status: " << this->order.getVehicle().getVehicleStatus() << endl;
        cout << "Customer Id: " << this->order.getCustomer().getCustomerId() << endl;
        cout << "Customer Name: " << this->order.getCustomer().getName() << endl;
        cout << "Customer Phone: " << this->order.getCustomer().getPhone() << endl;
        cout << "Customer Address: " << this->order.getCustomer().getAddress() << endl;
        cout << "Customer Age: " << this->order.getCustomer().getAge() << endl;
        cout << "Start Date: " << this->order.getStartDate().getDay() << "-" << this->order.getStartDate().getMonth() << "-" << this->order.getStartDate().getYear() << endl;
        cout << "End Date: " << this->order.getEndDate().getDay() << "-" << this->order.getEndDate().getMonth() << "-" << this->order.getEndDate().getYear() << endl;
        cout << "Total Rent: " << this->totalRent << endl;
    }
    // Destructor
    ~Bill() {}
protected:
    Order order;
    double totalRent;
};


// An array to store customers and orders
int customers_size = 2;
Customer* customers = new Customer[50] {
    Customer(1, "Customer 1", "1234567890", "Address 1", 20),
    Customer(2, "Customer 2", "1234567891", "Address 2", 21)
};

int orders_size = 2;
Order* orders = new Order[50] {
    Order(vehicles[0], customers[0], Date(1, 4, 2023), Date(2, 7, 2023), "Cash", Date(2, 4, 2023)),
    Order(vehicles[1], customers[1], Date(1, 5, 2023), Date(2, 11, 2023), "Cash", Date(2, 5, 2023))
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

// Register a new customer
Customer registerCustomer() {
    cout << "--------------------------------" << endl;
    cout << "    Register a new customer     " << endl;
    cout << "--------------------------------" << endl;
    Customer customer;
    cout << "Enter customer id: ";
    int customerId; cin >> customerId;
    customer.setCustomerId(customerId);
    cout << endl;
    cout << "Enter name: ";
    string name; cin >> name;
    customer.setName(name);
    cout << endl;
    cout << "Enter phone: ";
    string phone; cin >> phone;
    customer.setPhone(phone);
    cout << endl;
    cout << "Enter address: ";
    string address; cin >> address;
    customer.setAddress(address);
    cout << endl;
    cout << "Enter age: ";
    int age; cin >> age;
    customer.setAge(age);
    cout << endl;

    customers[++customers_size] = customer;
    cout << "Customer registered successfully!" << endl;
    return customer;
}

// Register a new vehicle
void registerVehicle() {
    cout << "--------------------------------" << endl;
    cout << "    Register a new vehicle      " << endl;
    cout << "--------------------------------" << endl;
    cout << "Select your vehicle type:" << endl;
    cout << "(a) Bike" << endl;
    cout << "(b) Scooter" << endl;
    cout << "Enter the vehicle type (a/b): ";
    char ch; cin >> ch; cout << endl;
    cout << "Enter vehicle number plate: ";
    string vehicleNumberPlate; cin >> vehicleNumberPlate;
    cout << endl;
    cout << "Enter vehicle name: " << endl;
    string vehicleName; cin >> vehicleName;
    cout << endl;
    cout << "Enter vehicle rent: ";
    double vehicleRent; cin >> vehicleRent;
    cout << endl;
    cout << "Enter vehicle status (1 for available, 0 for not available): ";
    bool vehicleStatus; cin >> vehicleStatus;
    cout << endl;
    cout << "Enter the vehicle type:" << endl;
    cout << "(a) Bike" << endl;
    cout << "(b) Scooter" << endl;
    cout << "(a / b) ? " << endl;
    string vehicleType; cin >> vehicleType;
    if(vehicleType == "a") {
        Bike* b = new Bike();
        b->setVehicleNumberPlate(vehicleNumberPlate);
        b->setVehicleName(vehicleName);
        b->setVehicleRent(vehicleRent);
        b->setVehicleStatus(vehicleStatus);
        vehicles[++vehicles_size] = *b;
    } else if(vehicleType == "b") {
        Scooter* sc = new Scooter();
        sc->setVehicleNumberPlate(vehicleNumberPlate);
        sc->setVehicleName(vehicleName);
        sc->setVehicleRent(vehicleRent);
        sc->setVehicleStatus(vehicleStatus);
        vehicles[++vehicles_size] = *sc;
    } else {
        Vehicle* v = new Vehicle();
        v->setVehicleNumberPlate(vehicleNumberPlate);
        v->setVehicleName(vehicleName);
        v->setVehicleRent(vehicleRent);
        v->setVehicleStatus(vehicleStatus);
        vehicles[++vehicles_size] = *v;
    }
    cout << "Vehicle registered successfully!" << endl;
    cout << "\n\n\n" << endl;
}

// Create an order
void createOrder() {
    cout << "--------------------------------" << endl;
    cout << "        Create an order         " << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter vehicle type(Scooter/Bike): ";
    string vehicleType; cin >> vehicleType;
    Vehicle vehicle = checkAvailability(vehicleType);
    cout << endl;
    Customer c = registerCustomer();
    cout << endl;
    cout << "Enter start date (dd-mm-yyyy): ";
    string startDate; cin >> startDate;
    Date sd = inputDate(startDate);
    cout << endl;
    cout << "Enter end date (dd-mm-yyyy): ";
    string endDate; cin >> endDate;
    Date ed = inputDate(endDate);
    cout << endl;
    cout << "Enter mode of payment: ";
    string modeOfPayment; cin >> modeOfPayment;
    cout << endl;
    cout << "Enter date of payment: ";
    string dateOfPayment; cin >> dateOfPayment;
    Date dop = inputDate(dateOfPayment);
    cout << endl;
    Order order(vehicle, c, sd, ed, modeOfPayment, dop);
    orders[++orders_size] = order;
    cout << "Order created successfully!" << endl;
    // Generate bill
    Bill bill(order);
    bill.printOrder();
    cout << "\n\n\n" << endl;
}

// View all customers
void viewAllCustomers() {
    cout << "--------------------------------" << endl;
    cout << "        View all customers      " << endl;
    cout << "--------------------------------" << endl;
    // Access elemts of customers array
    for(int i = 0; i < customers_size; i++) {
        cout << "Customer " << i + 1 << endl;
        cout << "Customer Id: " << customers[i].getCustomerId() << endl;
        cout << "Customer Name: " << customers[i].getName() << endl;
        cout << "Customer Phone: " << customers[i].getPhone() << endl;
        cout << "Customer Address: " << customers[i].getAddress() << endl;
        cout << "Customer Age: " << customers[i].getAge() << endl;
        cout << "\n\n" << endl;
    }
    cout << "\n\n\n" << endl;
}

// View all vehicles
void viewAllVehicles() {
    cout << "--------------------------------" << endl;
    cout << "        View all vehicles       " << endl;
    cout << "--------------------------------" << endl;
    // Access elements of vehicles array
    for(int i = 0; i < vehicles_size; i++) {
        cout << "Vehicle " << i + 1 << endl;
        cout << "Vehicle Number Plate: " << vehicles[i].getVehicleNumberPlate() << endl;
        cout << "Vehicle Name: " << vehicles[i].getVehicleName() << endl;
        cout << "Vehicle Type: " << vehicles[i].getVehicleType() << endl;
        cout << "Vehicle Rent: " << vehicles[i].getVehicleRent() << endl;
        cout << "Vehicle Status: " << vehicles[i].getVehicleStatus() << endl;
        cout << "\n\n" << endl;
    }
    cout << "\n\n\n" << endl;
}

// View all orders
void viewAllOrders() {
    cout << "--------------------------------" << endl;
    cout << "        View all orders         " << endl;
    cout << "--------------------------------" << endl;
    // Access elemts of orders array
    for(int i = 0; i < orders_size; i++) {
        cout << "Order " << i + 1 << endl;
        cout << "Vehicle Number Plate: " << orders[i].getVehicle().getVehicleNumberPlate() << endl;
        cout << "Vehicle Name: " << orders[i].getVehicle().getVehicleName() << endl;
        cout << "Vehicle Type: " << orders[i].getVehicle().getVehicleType() << endl;
        cout << "Vehicle Rent: " << orders[i].getVehicle().getVehicleRent() << endl;
        cout << "Vehicle Status: " << orders[i].getVehicle().getVehicleStatus() << endl;
        cout << "Customer Id: " << orders[i].getCustomer().getCustomerId() << endl;
        cout << "Customer Name: " << orders[i].getCustomer().getName() << endl;
        cout << "Customer Phone: " << orders[i].getCustomer().getPhone() << endl;
        cout << "Customer Address: " << orders[i].getCustomer().getAddress() << endl;
        cout << "Customer Age: " << orders[i].getCustomer().getAge() << endl;
        cout << "Start Date: " << orders[i].getStartDate().getDay() << "-" << orders[i].getStartDate().getMonth() << "-" << orders[i].getStartDate().getYear() << endl;
        cout << "End Date: " << orders[i].getEndDate().getDay() << "-" << orders[i].getEndDate().getMonth() << "-" << orders[i].getEndDate().getYear() << endl;
        cout << "\n\n" << endl;
    }
    cout << "\n\n\n" << endl;
}

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
    while(choice != 7) {
        // try and except block to handle exceptions
        try {
            if(choice == 1) {
                registerCustomer();
            }
            else if(choice == 2) {
                registerVehicle();
            }
            else if(choice == 3) {
                createOrder();
            }
            else if(choice == 4) {
                viewAllOrders();
            }
            else if(choice == 5) {
                viewAllCustomers();
            }
            else if(choice == 6) {
                viewAllVehicles();
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
        catch(exception& e) {
            cout << "Exception occurred: " << e.what() << endl;
            exit(0);
        }
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    }
    return 0;
}

