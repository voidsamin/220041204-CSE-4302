#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Coordinate{
    private:
        float abscissa;
        float ordinate;

    public:
        Coordinate() : abscissa(0.0), ordinate(0.0) { }
        Coordinate(float x, float y) : abscissa(x), ordinate(y) { }
        ~Coordinate() { }

        float getAbscissa() const
        {
            return abscissa;
        }

        float getOrdinate() const
        {
            return ordinate;
        }

        void display() const
        {
            cout << "Abscissa: " << abscissa << ", Ordinate: " << ordinate << endl;
        }

        void setAbscissa(const float& x)
        {
            abscissa = x;
        }

        void setOrdinate(const float& y)
        {
            ordinate = y;
        }

        float operator - (const Coordinate& c) const
        {
            float dist = pow(c.abscissa - abscissa, 2) + pow(c.ordinate - ordinate, 2);
            dist = sqrt(dist);
            return dist;
        }

        float getDist() const
        {
            float dist = pow(abscissa, 2) + pow(ordinate, 2);
            dist = sqrt(dist);

            return dist;
        }

        void move_x(const float& val)
        {
            abscissa += val;
        }

        void move_y(const float& val)
        {
            ordinate += val;
        }

        void move(const float& x_val, const float& y_val)
        {
            abscissa += x_val;
            ordinate += y_val;
        }

        bool operator < (const Coordinate& c) const
        {
            return getDist() < c.getDist();
        }

        bool operator > (const Coordinate& c) const
        {
            return getDist() > c.getDist();
        }

        bool operator <= (const Coordinate& c) const
        {
            return getDist() <= c.getDist();
        }

        bool operator >= (const Coordinate& c) const
        {
            return getDist() >= c.getDist();
        }

        bool operator == (const Coordinate& c) const
        {
            return getDist() == c.getDist();
        }

        bool operator != (const Coordinate& c) const
        {
            return getDist() != c.getDist();
        }
};

void randomAssignment(Coordinate c[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int x = rand() % 100;
        int y = rand() % 100;
        c[i].setAbscissa((float)x);
        c[i].setOrdinate((float)y);
    }
}

void sort(Coordinate c[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(c[j] > c[j + 1])
            {
                Coordinate temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}

int main()
{
    Coordinate coord[10];
    randomAssignment(coord, 10);
    sort(coord, 10);

    cout << "Highest: " << coord[9].getDist() << endl;
    cout << "Lowest: " << coord[0].getDist() << endl;

    coord[5].display();
    cout << coord[5].getDist() << endl;

    return 0;
}
