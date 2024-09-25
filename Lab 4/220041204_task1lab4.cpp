#include <iostream>
#include <cmath>

using namespace std;

#define PI acos(-1)

class Calculator{
private:
    float previousAngle;
    float currentAngle;
    float currentStatus;

    void setCurrentStatus(float paramAngle)
    {
        currentStatus = paramAngle;
    }
    float getCurrentStatus()
    {
        return currentStatus;
    }

    float calculateSine(float paramAngle)
    {
        return sin(paramAngle);
    }

    float calculateCosine(float paramAngle)
    {
        return cos(paramAngle);
    }

    float calculateTangent(float paramAngle)
    {
        if(paramAngle == 90.0 || paramAngle == 270.0 || paramAngle == 450.0 || paramAngle == 630.0 || paramAngle == 810.0 || paramAngle == -90.0 || paramAngle == -270.0 || paramAngle == -450.0 || paramAngle == -630.0)
        {
            cout << "Warning, tangent of current angle is undefined." << endl;
            return tan(previousAngle);
        }
        else
        {
            return tan(paramAngle);
        }
    }

public:
    Calculator(): previousAngle(0.0), currentAngle(0.0)
    {
        cout << "0 argument constructor called" << endl;
    }

    Calculator(float angle): previousAngle(0.0), currentAngle(angle)
    {
        cout << "1 argument constructor called" << endl;
        setCurrentStatus(angle);
    }

    float calculateSine()
    {
        setCurrentStatus(sin(currentAngle));
        return sin(currentAngle);
    }

    float calculateCosine()
    {
        setCurrentStatus(cos(currentAngle));
        return cos(currentAngle);
    }

    float calculateTangent()
    {
        if(currentAngle == 90.0 || currentAngle == 270.0 || currentAngle == 450.0 || currentAngle == 630.0 || currentAngle == 810.0 || currentAngle == -90.0 || currentAngle == -270.0 || currentAngle == -450.0 || currentAngle == -630.0)
        {
            cout << "Warning, tangent of current angle is undefined." << endl;
            currentAngle = previousAngle;
            setCurrentStatus(tan(currentAngle));
            return tan(currentAngle);
        }
        else
        {
            setCurrentStatus(tan(currentAngle));
            previousAngle = currentAngle;
            return tan(currentAngle);
        }
    }

    float calculateArcSine()
    {
        cout << currentAngle * PI / 180 << endl;
        setCurrentStatus(asin(currentAngle * PI / 180));
        return asin(currentAngle * PI / 180);
    }

    float calculateArcCosine()
    {
        cout << currentAngle * PI / 180 <<endl;
        setCurrentStatus(acos(currentAngle * PI / 180));
        return acos(currentAngle * PI / 180);
    }

    float calculateArcTangent()
    {
        cout << currentAngle * PI / 180 <<endl;
        setCurrentStatus(atan(currentAngle * PI / 180));
        return atan(currentAngle * PI / 180);
    }

    void calculateForAngle(float paramAngle)
    {
        cout << "Sine of " << paramAngle << " is: " << calculateSine(paramAngle) << endl;
        cout << "Cosine of " << paramAngle << " is: " << calculateCosine(paramAngle) << endl;
        cout << "Tangent of " << paramAngle << " is: " << calculateTangent(paramAngle) << endl;
    }

    void clear()
    {
        currentStatus = 0.0;
    }

    void display()
    {
        cout << "Calculator display: " << getCurrentStatus() << endl;
    }

    ~Calculator()
    {
        cout << "Destructor of the Calculator object is called" << endl;
    }
};

int main()
{
    Calculator c1(30.0), c2(270.0), c3;

    cout << "Sin:" << c2.calculateSine() << endl;
    cout << "Cos:" << c2.calculateCosine() << endl;
    cout << "Tan:" << c2.calculateTangent() << endl;

    cout << "ArcSin:" << c1.calculateArcSine() << endl;
    cout << "ArcCos:" << c1.calculateArcCosine() << endl;
    cout << "ArcTan:" << c1.calculateArcTangent() << endl;

    c3.calculateForAngle(60.0);
    c1.display();
    c2.display();
    c1.clear();
    c2.clear();
    c1.display();
    c2.display();

    return 0;
}
