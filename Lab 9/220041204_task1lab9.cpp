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

int main()
{
    Vehicle *v;

    return 0;
}
