#include <iostream>

using namespace std;

class Matrix3D {
    private:
        double data[3][3];
        int inc;
        int count;

    public:
        Matrix3D() {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                    data[i][j] = 0.0;
            }

            inc = 1;
            count = 0;
        }

        Matrix3D(double values[3][3]) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                    data[i][j] = values[i][j];
            }
            inc = 1;
            count = 0;
        }

        Matrix3D(double values[3][3], int _increment) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                    data[i][j] = values[i][j];
            }

            if(_increment < 0) {
                cerr << "Invalid increment value." << endl;
                inc = 1;
                count = 0;
            }
            else {
                inc = _increment;
                count = 1;
            }
        }

        ~Matrix3D() {}

        double det() const {
            return ( data[0][0] * (data[1][1] * data[2][2]) - (data[1][2] * data[2][1]) )
                 - ( data[0][1] * (data[1][0] * data[2][2]) - (data[1][2] * data[2][0]) )
                 + ( data[0][2] * (data[1][0] * data[2][1]) - (data[1][1] * data[2][0]) );
        }

        Matrix3D inverse() {
            double determinant = det();

            if(determinant == 0) {
                cerr << "Determinant is zero, singular matrix. No inverse matrix." << endl;
                return Matrix3D(data, inc);
            }

            double invdata[3][3];
            invdata[0][0] = ( data[1][1] * data[2][2] ) - ( data[1][2] * data[2][1] ) / determinant;
            invdata[0][1] = ( data[0][2] * data[2][1] ) - ( data[0][1] * data[2][2] ) / determinant;
            invdata[0][2] = ( data[0][1] * data[1][2] ) - ( data[0][2] * data[1][1] ) / determinant;
            invdata[1][0] = ( data[1][2] * data[2][0] ) - ( data[1][0] * data[2][2] ) / determinant;
            invdata[1][1] = ( data[0][0] * data[2][2] ) - ( data[0][2] * data[2][0] ) / determinant;
            invdata[1][2] = ( data[0][2] * data[1][0] ) - ( data[0][0] * data[1][2] ) / determinant;
            invdata[2][0] = ( data[1][0] * data[2][1] ) - ( data[1][1] * data[2][0] ) / determinant;
            invdata[2][1] = ( data[0][1] * data[2][0] ) - ( data[0][0] * data[2][1] ) / determinant;
            invdata[2][2] = ( data[0][0] * data[1][1] ) - ( data[0][1] * data[1][0] ) / determinant;

            return Matrix3D(invdata, inc);
        }

        /*double getMatrix() {
            return data;
        }*/  //Facing problems with the getter function.

        void setIncrement(int val) {
            if(count || val < 0) {
                cerr << "Can not set increment step." << endl;
                return;
            }

            inc = val;
        }

        void increment() {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                    data[i][j] += inc;
            }
            count++;
        }

        void display() {
            cout << "Matrix: " << endl;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                    cout << data[i][j] << " ";
                cout << endl;
            }
        }

        Matrix3D operator + (const Matrix3D& mat) {
            Matrix3D temp;

            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                    temp.data[i][j] = data[i][j] + mat.data[i][j];
            }

            return temp;
        }

        Matrix3D operator - (const Matrix3D& mat) {
            Matrix3D temp;

            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                    temp.data[i][j] = data[i][j] - mat.data[i][j];
            }

            return temp;
        }

        Matrix3D operator * (const Matrix3D& mat) {
            Matrix3D temp;

            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    for(int k = 0; k < 3; k++)
                        temp.data[i][j] += data[i][k] * mat.data[k][j];
                }
            }

            return temp;
        }

        bool operator > (const Matrix3D& mat) {
            return det() > mat.det();
        }

        bool operator < (const Matrix3D& mat) {
            return det() < mat.det();
        }

        bool operator >= (const Matrix3D& mat) {
            return det() >= mat.det();
        }

        bool operator <= (const Matrix3D& mat) {
            return det() <= mat.det();
        }

        bool operator == (const Matrix3D& mat) {
            return det() == mat.det();
        }

        bool operator != (const Matrix3D& mat) {
            return det() != mat.det();
        }
};

int main() {
    double val[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double dat[3][3] = {{5, 1, 4}, {6, 2, 2}, {7, 9, 15}};

    Matrix3D mat1(val), mat2(dat);

    cout << "Determinant: " << mat1.det() << endl;
    cout << "Determinant: " << mat2.det() << endl;

    mat1.display();
    mat2.display();

    mat1.setIncrement(-5);
    mat1.setIncrement(4);
    mat1.increment();
    mat1.display();

    Matrix3D mat3 = mat1.inverse();
    mat3.display();

    mat3 = mat1 + mat2;
    mat3.display();

    mat3 = mat1 - mat2;
    mat3.display();

    mat3 = mat1 * mat2;
    mat3.display();

    return 0;
}
