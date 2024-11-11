#include "Employee.h"

Employee::Employee()
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

int Employee::monthsToNumber(const string& month)
{
    if(birth_month == "January")
        return 1;
    else if(birth_month == "February")
        return 2;
    else if(birth_month == "March")
        return 3;
    else if(birth_month == "April")
        return 4;
    else if(birth_month == "May")
        return 5;
    else if(birth_month == "June")
        return 6;
    else if(birth_month == "July")
        return 7;
    else if(birth_month == "August")
        return 8;
    else if(birth_month == "September")
        return 9;
    else if(birth_month == "October")
        return 10;
    else if(birth_month == "November")
        return 11;
    else
        return 12;
}

int Employee::calcAge()
{
    int age = current_year - birth_year;

    if(monthsToNumber(current_month) < monthsToNumber(birth_month) || (monthsToNumber(current_month) == monthsToNumber(birth_month) && current_day < birth_day) )
        age--;

    return age;
}

bool Employee::isAgeValid()
{
    int age = calcAge();

    return age >= 18;
}

void Employee::setDefaultDOB()
{
    birth_day = 1;
    birth_month = "January";
    birth_year = 2002;
    DOB = "1 January 2002";
}

void Employee::setName(const string& __name)
{
    if(__name.size() <= 2)
        name = "John Doe";
    else
        name = __name;
}

void Employee::setDOB(const int& day, const string& month, const int& year)
{
    if(month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December")
        birth_month = month;
    else
    {
        setDefaultDOB();
        return;
    }

    birth_year = year;

    if(month == "September" || month == "April" || month == "June" || month == "November")
    {
        if(day >= 1 && day <= 30)
            birth_day = day;
        else
        {
            setDefaultDOB();
            return;
        }
    }
    else if(month == "January" ||  month == "March" || month == "May" || month == "July" || month == "August" || month == "October" || month == "December")
    {
        if(day >= 1 && day <= 31)
            birth_day = day;
        else
        {
            setDefaultDOB();
            return;
        }
    }
    else
    {
        if(year % 4 == 0 && year % 400 != 0)
        {
            if(day >= 1 && day <= 29)
                birth_day = day;
            else
            {
                setDefaultDOB();
                return;
            }
        }
        else
        {
            if(day >= 1 && day <= 28)
                birth_day = day;
            else
            {
                setDefaultDOB();
                return;
            }
        }
    }

    if(isAgeValid())
        DOB = to_string(birth_day) + " " + birth_month + " " + to_string(birth_year);
    else
        setDefaultDOB();
}

void Employee::setSalary(const double& sal)
{
    if(sal > 10000 && sal < 100000)
        salary = sal;
    else
        salary = 10000;
}

void Employee::setInfo(const string& __name, const int& day, const string& month, const int& year, const double& sal)
{
    setName(__name);
    setDOB(day, month, year);
    setSalary(sal);
}

string Employee::getName() const
{
    return name;
}

string Employee::getDOB() const
{
    return DOB;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::getInfo() const
{
    cout << "Name: " << getName() << endl;
    cout << "Date Of Birth: " << getDOB() << endl;
    cout << "Salary: " << getSalary() << endl;
}

int Employee::getAge()
{
    int age = calcAge();
    return age;
}

Employee& Employee::compareAge(const Employee& e)
{
    bool flag = false;

    if(birth_year < e.birth_year)
        flag = true;
    else if(birth_year == e.birth_year)
    {
        if(monthsToNumber(birth_month) < monthsToNumber(e.birth_month))
            flag = true;
        else if(monthsToNumber(birth_month) == monthsToNumber(e.birth_month))
        {
            if(birth_day < e.birth_day)
                flag = true;
        }
    }

    if(flag == true)
        return *this;
    else
        return const_cast<Employee&>(e);
}

bool Employee::operator == (const Employee& e)
{
    if(name == e.name && DOB == e.DOB && salary == e.salary)
        return true;

    return false;
}

const int Employee::current_day = 2;
const string Employee::current_month = "October";
const int Employee::current_year = 2024;
