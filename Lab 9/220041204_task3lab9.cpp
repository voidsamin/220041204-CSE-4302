#include <iostream>
#include <string>

using namespace std;

class Vehicle{
    protected:
        string licensePlate;
        string manufacturer;
        double carriageSizeLim;

    public:
        Vehicle() : licensePlate(NULL), manufacturer(NULL), carriageSizeLim(0.0) {}
        Vehicle(string _plate, string _manufacturer, double carr) : licensePlate(_plate), manufacturer(_manufacturer), carriageSizeLim(carr) {}
        void setLicensePlate(const string& plate) {
            licensePlate = plate;
        }
        void setManufacturer(const string& __manufacturer) {
            manufacturer = __manufacturer;
        }
        void setCarriageSizeLimit(const double& limit) {
            if(limit > 50.00)
                carriageSizeLim = limit;
        }
        string getLicensePlate() const {
            return licensePlate;
        }
        string getManufacturer() const {
            return manufacturer;
        }
        double getCarriageSizeLimit() const {
            return carriageSizeLim;
        }
        virtual void performMaintenance() = 0;
        ~Vehicle() {}
};

class GasolineVehicle : public Vehicle {
    protected:
        double fuelTankCapacity;
        string fuelType;

    public:
        GasolineVehicle() : Vehicle() {
            fuelTankCapacity = 0.0;
            fuelType = "";
        }

        GasolineVehicle(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type) : Vehicle(_plate, _manufacturer, carr) {
            fuelTankCapacity = fuel_cap;
            fuelType = fuel_type;
        }

        void setFuelTankCapacity(const double& fuel_cap) {
            fuelTankCapacity = fuel_cap;
        }

        void setFuelType(const string& fuel_type) {
            fuelType = fuel_type;
        }

        double getFuelTankCapacity() const {
            return fuelTankCapacity;
        }

        string getFuelType() const {
            return fuelType;
        }

        double calculateFuelConsumption(const double& distance) {
            return distance * 0.512;
        }

        void performMaintenance() {
            cout << "Gasoline Vehicle under maintenance." << endl;
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

        void setBatteryCapacity(const double& batt_cap) {
            batteryCapacity = batt_cap;
        }

        void setChargingTime(const double& charge_time) {
            chargeTime = charge_time;
        }

        double getBatteryCapacity() const {
            return batteryCapacity;
        }

        double getChargingTime() const {
            return chargeTime;
        }

        double  electricityConsumption(const double& distance) {
            return distance * 0.346;
        }

        void performMaintenance() {
            cout << "Electric Vehicle under maintenance." << endl;
        }
};

class Motorcycle : public GasolineVehicle {
    public:
        Motorcycle() : GasolineVehicle() { }
        Motorcycle(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type) : GasolineVehicle(_plate, _manufacturer, carr, fuel_cap, fuel_type) { }
        void performMaintenance() {
            cout << "Motorcycle - maintenance" << endl;
        }
        double calculateFuelConsumption(const double& distance) {
            return distance * 1.4;
        }
        ~Motorcycle() {}
};

class Car : public GasolineVehicle {
    protected:
        int passengerCapacity;

    public:
        Car() : GasolineVehicle() {
            passengerCapacity = 0;
        }
        Car(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type, int ppl) : GasolineVehicle(_plate, _manufacturer, carr, fuel_cap, fuel_type) {
            if(ppl > 0)
                passengerCapacity = ppl;
            else
                passengerCapacity = 0;
        }
        void setPassengeCapacity(const unsigned int& ppl) {
            passengerCapacity = ppl;
        }
        int getPassengerCapacity() const {
            return passengerCapacity;
        }
        double calculateFuelConsumption(const double& distance) {
            return distance * 6.0;
        }
        void performMaintenance() {
            cout << "Car - maintenance" << endl;
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

        void setCargoCapacity(const double& cargo_cap) {
            if(cargo_cap > 300)
                cargoCapacity = cargo_cap;
        }

        double getCargoCapacity() const {
            return cargoCapacity;
        }

        double calculateFuelConsumption(const double& distance) {
            return distance * 30.0;
        }

        void performMaintenance() {
            cout << "Truck - maintenance" << endl;
        }

        ~Truck() { }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
    protected:
        double energyRegenerationEfficiency;

    public:
        HybridVehicle() : GasolineVehicle(), ElectricVehicle() {
            energyRegenerationEfficiency = 0.0;
        }
        HybridVehicle(string _plate, string _manufacturer, double carr, double fuel_cap, string fuel_type, double batt_cap, double charge_time, double regen) : GasolineVehicle(_plate, _manufacturer, carr, fuel_cap, fuel_type), ElectricVehicle(_plate, _manufacturer, carr, batt_cap, charge_time) {
            if(regen > 0)
                energyRegenerationEfficiency = regen;
            else
                energyRegenerationEfficiency = 0.0;
        }
        void performMaintenance() {
            cout << "Hybrid Vehicle - maintenance" << endl;
        }
        double calculateFuelConsumption(const double& distance) {
            double consumption = .0894 * distance;
            consumption -= (consumption * .346);
            consumption += (distance * 1.4);

            return consumption;
        }
        ~HybridVehicle() { }
};

int main()
{
    Vehicle *v;

    GasolineVehicle g("DHA 23-1223", "TOYOTA", 1500.00, 100, "Octane");
    v = &g;
    v->performMaintenance();

    ElectricVehicle e("DHA 23-1223", "TOYOTA", 1500.00, 100, 50);
    v = &e;
    v->performMaintenance();

    Motorcycle m("DHA 23-1223", "HONDA", 300, 20, "Octane");
    v = &m;
    v->performMaintenance();
    cout << m.calculateFuelConsumption(45.63) << " liters" << endl;

    Car c("DHA 23-1223", "TOYOTA", 1500.00, 100, "Octane", 5);
    v = &c;
    v->performMaintenance();
    cout << c.calculateFuelConsumption(45.63) << " liters" << endl;

    Truck t("DHA 43-1223", "TATA", 500, 200, "Diesel", 3000);
    v = &t;
    v->performMaintenance();
    cout << t.calculateFuelConsumption(45.63) << " liters" << endl;

    HybridVehicle h("DHA 23-1223", "TOYOTA", 1500.00, 100, "Octane", 100, 50, 1.3);
    //v = &h;
    h.performMaintenance();
    cout << h.calculateFuelConsumption(45.63) << " liters" << endl;

    return 0;
}
