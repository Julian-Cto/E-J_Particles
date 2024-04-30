#include "Matrices.h"
using namespace Matrices;

Matrix::Matrix(int _rows, int _cols)
{
    
}
    ///Add each corresponding element.
    ///usage:  c = a + b;
Matrix operator+(const Matrix& a, const Matrix& b) 
{
    Matrix test(0, 0);
    return test;
}

///Matrix multiply.  See description.
///usage:  c = a * b;
Matrix operator*(const Matrix& a, const Matrix& b) 
{
    Matrix test(0, 0);
    return test;
}

///Matrix comparison.  See description.
///usage:  a == b
bool operator==(const Matrix& a, const Matrix& b)
{
    return true;
}

///Matrix comparison.  See description.
///usage:  a != b
bool operator!=(const Matrix& a, const Matrix& b)
{
    return true;
}

///Output matrix.
///Separate columns by ' ' and rows by '\n'
ostream& operator<<(ostream& os, const Matrix& a)
{
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
{

}
///Call the parent constructor to create a 2x2 matrix
           ///Then assign each element as follows:
           /*
           scale   0
           0       scale
           */
           ///scale represents the size multiplier
ScalingMatrix::ScalingMatrix(double scale)
{

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
{

}