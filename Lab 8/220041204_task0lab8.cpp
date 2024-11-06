#include <iostream>
#include <string>

using namespace std;

class MaintenanceCheck {
    protected:
        string VehicleType;
        string checkType;

    public:
        MaintenanceCheck() {}
        MaintenanceCheck(string ride, string check_type) : VehicleType(ride), checkType(check_type) {}
        void set(string ride, string check_type) {
            VehicleType = ride;
            checkType = check_type;
        }
        ~MaintenanceCheck() {}
};

class Vehicle{
    protected:
        string licensePlate;
        string manufacturer;
        double carriageSizeLim;
        MaintenanceCheck maintenance;

    public:
        Vehicle() : licensePlate(NULL), manufacturer(NULL), carriageSizeLim(0.0) {}
        Vehicle(string _plate, string _manufacturer, double carr) : licensePlate(_plate), manufacturer(_manufacturer), carriageSizeLim(carr) {}
        void setMaintenance(string ride, string check_type) {
            maintenance.set(ride, check_type);
        }
        ~Vehicle() {}
};

class GasolineVehicle : public Vehicle {
    protected:
        double fuelCapacity;
        string fuelType;

    public:
        GasolineVehicle() : Vehicle() {
            fuelCapacity = 0.0;
            fuelType = "";
        }

        GasolineVehicle(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type) : Vehicle(_plate, _manufacturer, carr) {
            fuelCapacity = fuel_cap;
            fuelType = fuel_type;
        }

        ~GasolineVehicle() {}
};

class ElectricVehicle : public Vehicle {
    protected:
        double batteryCapacity;
        double chargeTime;

    public:
        ElectricVehicle() : Vehicle() {
            batteryCapacity = 0.0;
            chargeTime = 0.0;
        }

        ElectricVehicle(string _plate, string _manufacturer, double carr, double batt_cap, double charge_time) : Vehicle(_plate, _manufacturer, carr) {
            batteryCapacity = batt_cap;
            chargeTime = charge_time;
        }
};

class Motorcycle : public GasolineVehicle {
    public:
        Motorcycle() : GasolineVehicle() { }
        Motorcycle(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type) : GasolineVehicle(_plate, _manufacturer, carr, fuel_cap, fuel_type) { }
        ~Motorcycle() {}
};

class Car : public GasolineVehicle {
    protected:
        int passengerLimit;

    public:
        Car() : GasolineVehicle() {
            passengerLimit = 0;
        }
        Car(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type, int ppl) : GasolineVehicle(_plate, _manufacturer, carr, fuel_cap, fuel_type) {
            if(ppl > 0)
                passengerLimit = ppl;
            else
                passengerLimit = 0;
        }

        ~Car() { }
};

class Truck : public GasolineVehicle {
    protected:
        double cargoCapacity;

    public:
        Truck() : GasolineVehicle() {
            cargoCapacity = 0.0;
        }

        Truck(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type, double cargo_cap) : GasolineVehicle(_plate, _manufacturer, carr, fuel_cap, fuel_type) {
            if(cargo_cap > 0.0)
                cargoCapacity = cargo_cap;
            else
                cargoCapacity = 0.0;
        }
        ~Truck() { }
};

class Hybrid : public GasolineVehicle, public ElectricVehicle {
    protected:
        double regenBrakeEff;

    public:
        Hybrid() : GasolineVehicle(), ElectricVehicle() {
            regenBrakeEff = 0.0;
        }
        Hybrid(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type, double batt_cap, double charge_time, double regen) : GasolineVehicle(_plate, _manufacturer, carr, fuel_cap, fuel_type), ElectricVehicle(_plate, _manufacturer, carr, batt_cap, charge_time) {
            if(regen > 0)
                regenBrakeEff = regen;
            else
                regenBrakeEff = 0.0;
        }
        ~Hybrid() { }
};

class Employee {
    protected:
        string name;
        int ID;

    public:
        Employee() : name(NULL), ID(0) {}
        Employee(string n, int id) : name(n), ID(id) {}
        ~Employee() {}
        string getName() const {
            return name;
        }
        int getID() const {
            return ID;
        }
};

class Manager : public Employee {
    public:
        Manager() : Employee() {}
        Manager(string n, int id) : Employee(n, id) {}
        ~Manager() {}
};

class Driver : public Employee {
    public:
        Driver() : Employee() {}
        Driver(string n, int id) : Employee(n, id) {}
        ~Driver() {}
};

class Branch {
    protected:
        string branchName;
        string branchCode;
        Motorcycle m[10];
        Car c[10];
        Truck t[10];
        ElectricVehicle e[10];
        Hybrid h[10];
        Manager man[10];
        Driver driv[30];

    public:
        Branch() {}
        ~Branch() {}

        void assignBranchName(string name) {
            branchName = name;
        }
        void assignBranchCode(string code) {
            branchCode = code;
        }

        void displayManagers() {
            for(int i = 0; i < 10; i++) {
                cout << "Mr. " << man[i].getName() << " ID: " << man[i].getID() << endl;
            }
        }

        void displayDrivers() {
            for(int i = 0; i < 30; i++) {
                cout << driv[i].getName() << " ID: " << driv[i].getID() << endl;
            }
        }
};

int main() {
    return 0;
}
