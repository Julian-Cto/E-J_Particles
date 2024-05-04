#include "Matrices.h"

namespace Matrices
{
    Matrix::Matrix(int _rows, int _cols) {
        cols = _cols;
        rows = _rows;
        a.resize(rows, vector<double>(cols));

    }
    ///Add each corresponding element.
    ///usage:  c = a + b;
    Matrix operator+(const Matrix& a, const Matrix& b) {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            throw runtime_error("Error: dimensions must agree");

        Matrix c(a.getRows(), a.getCols());
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                c(i, j) = a(i, j) + b(i, j);
            }
        }
        return c;
    }

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b) {
        if (a.getCols() != b.getRows())
            throw runtime_error("Error: dimensions must agree");
        Matrix c(a.getRows(), b.getCols());

        for (int i = 0; i < c.getRows(); i++) {
            for (int j = 0; j < c.getCols(); j++) {
                c(i, j) = 0;
                for (int k = 0; k < a.getCols(); k++) {
                    c(i, j) += (a(i, k) * b(k, j));
                }
            }
        }

        return c;
    }


    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b) {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
            return false;
        }
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                if (!(abs(a(i, j) - b(i, j)) < 0.001)) {
                    return false;
                }
            }
        }
        return true;
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b) {
        return !(a == b);
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a) {
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                os << setw(10) << a(i, j) << ' ';
            }
            os << endl;
        }
        return os;
    }

    /******************************************************************************************/
    //sub classes

    ///Call the parent constructor to create a 2x2 matrix
                ///Then assign each element as follows:
                /*
                cos(theta)  -sin(theta)
                sin(theta)   cos(theta)
                */
                ///theta represents the angle of rotation in radians, counter-clockwise
    RotationMatrix::RotationMatrix(double theta)
        : Matrix(2, 2)
    {
        a = { {cos(theta), -sin(theta)},{sin(theta), cos(theta)} };
    }
    ///Call the parent constructor to create a 2x2 matrix
               ///Then assign each element as follows:
               /*
               scale   0
               0       scale
               */
               ///scale represents the size multiplier
    ScalingMatrix::ScalingMatrix(double scale)
        : Matrix(2, 2)
    {
        a = { {scale, 0},{0, scale} };
    }
    ///Call the parent constructor to create a 2xn matrix
                ///Then assign each element as follows:
                /*
                xShift  xShift  xShift  ...
                yShift  yShift  yShift  ...
                */
                ///paramaters are xShift, yShift, and nCols
                ///nCols represents the number of columns in the matrix
                ///where each column contains one (x,y) coordinate pair
    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
        : Matrix(2, nCols)
    {
        for (int col = 0; col < nCols; col++) 
        {
            a[0][col] = xShift; // xShift for first row
            a[1][col] = yShift; // yShift for second row
        }
    }
}
