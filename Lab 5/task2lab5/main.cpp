#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

string generateRandomString(int length) {
    string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}

double randomInRange(double min, double max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    // Generate a random double between 0 and 1
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;

    // Scale and shift the random value to the desired range
    return min + randomFraction * (max - min);
}

string generateRandomMonth() {
    int r = rand() % 12;

    switch(r)
    {
        case 0:
            return "January";
            break;

        case 1:
            return "February";
            break;

        case 2:
            return "March";
            break;

        case 3:
            return "April";
            break;

        case 4:
            return "May";
            break;

        case 5:
            return "June";
            break;

        case 6:
            return "July";
            break;

        case 7:
            return "August";
            break;

        case 8:
            return "September";
            break;

        case 9:
            return "October";
            break;

        case 10:
            return "November";
            break;

        case 11:
            return "December";
            break;

        default:
            break;
    }

    return "";
}

void generateInformationRandom(Employee e[])
{
    for(int i = 0; i < 100; i++)
    {
        e[i].setName(generateRandomString(randomInRange(4, 10)));
        e[i].setDOB(randomInRange(1, 31), generateRandomMonth(), randomInRange(1960, 2006));
        e[i].setSalary(randomInRange(10000.00, 100000.00));
    }
}

void showAllBasedOnAge(Employee e[])
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100 - i - 1; j++)
        {
            Employee temp = e[j].compareAge(e[j+1]);
            if(temp == e[j])
                swap(e[j], e[j + 1]);
        }
    }

    for(int i = 0; i < 100; i++)
    {
        e[i].getInfo();
        cout << "Age: " << e[i].getAge() << endl;
    }
}

int main()
{
    Employee e[100];

    generateInformationRandom(e);

    showAllBasedOnAge(e);

    return 0;
}
