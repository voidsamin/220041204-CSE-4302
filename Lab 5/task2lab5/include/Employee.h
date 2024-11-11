#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Employee
{
    private:
        string name;
        int birth_day;
        string birth_month;
        int birth_year;
        string DOB;
        double salary;

        const static int current_day;
        const static string current_month;
        const static int current_year;

        int monthsToNumber(const string& month);
        int calcAge();
        bool isAgeValid();
        void setDefaultDOB();

    public:
        Employee();
        ~Employee();

        void setName(const string& __name);
        void setDOB(const int& day, const string& month, const int& year);
        void setSalary(const double& sal);
        void setInfo(const string& __name, const int& day, const string& month, const int& year, const double& sal);

        string getName() const;
        string getDOB() const;
        double getSalary() const;
        void getInfo() const;

        int getAge();
        //Another getAge function using system time

        Employee& compareAge(const Employee& e);
        bool operator == (const Employee& e);
};

#endif // EMPLOYEE_H
