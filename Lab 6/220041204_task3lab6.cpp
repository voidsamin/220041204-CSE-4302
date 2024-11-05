#include <iostream>

using namespace std;

class Fahrenheit;
class Kelvin;

class Celsius {
    private:
        double temp;

    public:
        Celsius() : temp(0.0) {}
        Celsius(const double& celsius) {
            temp = 0.0;
            if(celsius < -273.15)
                cerr << "Invalid temperature, assign again" << endl;
            else
                temp = celsius;
        }
        ~Celsius() {}
        void assign(const double& celsius) {
            if(celsius < -273.15) {
                cerr << "Invalid temperature" << endl;
                return;
            }
            temp = celsius;
        }
        double getCelsius() const {
            return temp;
        }
        void display() const {
            cout << "The temperature is " << temp << " Celsius." << endl;
        }
        operator Fahrenheit() const;
        operator Kelvin() const;
};

class Fahrenheit {
    private:
        double temp;

    public:
        Fahrenheit() : temp(0.0) {}
        Fahrenheit(const double& fahrenheit) {
            temp = 0.0;
            if(fahrenheit < -459.67)
                cerr << "Invalid temperature, assign again" << endl;
            else
                temp = fahrenheit;
        }
        ~Fahrenheit() {}
        void assign(const double& fahrenheit) {
            if(fahrenheit < -459.67) {
                cerr << "Invalid temperature" << endl;
                return;
            }
            temp = fahrenheit;
        }
        double getFahrenheit() const {
            return temp;
        }
        void display() const {
            cout << "The temperature is " << temp << " Fahrenheit." << endl;
        }
        operator Celsius() const;
        operator Kelvin() const;
};

class Kelvin {
    private:
        double temp;

    public:
        Kelvin() : temp(0.0) {}
        Kelvin(const double& kelvin) {
            temp = 0.0;
            if(kelvin < 0.0)
                cerr << "Invalid temperature, assign again" << endl;
            else
                temp = kelvin;
        }
        ~Kelvin() {}
        void assign(const double& kelvin) {
            if(kelvin < 0.0) {
                cerr << "Invalid temperature" << endl;
                return;
            }
            temp = kelvin;
        }
        double getKelvin() const {
            return temp;
        }
        void display() const {
            cout << "The temperature is " << temp << " Kelvin." << endl;
        }
        operator Celsius() const;
        operator Fahrenheit() const;
};

Celsius::operator Fahrenheit() const {
    double t = getCelsius();
    return Fahrenheit( (9.0 * t / 5.0) + 32.0 );
}
Celsius::operator Kelvin() const {
    double t = getCelsius();
    return Kelvin ( t + 273.15 );
}

Fahrenheit::operator Celsius() const {
    double t = getFahrenheit();
    return Celsius( (t - 32.0) * 5.0 / 9.0 );
}
Fahrenheit::operator Kelvin() const {
    double t = getFahrenheit();
    return Kelvin( ( (t - 32.0) * 5.0 / 9.0 ) + 273.15 );
}

Kelvin::operator Celsius() const {
    double t = getKelvin();
    return Celsius( t - 273.15 );
}
Kelvin::operator Fahrenheit() const {
    double t = getKelvin();
    return Fahrenheit( ( ( t - 273.15 ) * 9.0 / 5.0 ) + 32.0 );
}

int main() {
    Fahrenheit f(104.5);
    f.display();
    f.assign(-500.0);
    f.assign(78.34);
    f.display();
    Celsius c = f;
    c.display();
    return 0;
}
