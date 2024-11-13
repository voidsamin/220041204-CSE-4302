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

        double calculateFuelConsumption(const double& distance, const double& mileage) {
            return distance * mileage;
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

int main()
{
    Vehicle *v;

    GasolineVehicle g("DHA 23-1223", "TOYOTA", 1500.00, 100, "Octane");
    v = &g;
    v->performMaintenance();

    ElectricVehicle e("DHA 23-1223", "TOYOTA", 1500.00, 100, 50);
    v = &e;
    v->performMaintenance();

    return 0;
}
