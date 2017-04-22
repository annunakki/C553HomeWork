//#########################################################################
//##################### Fady Safar ###########################################
//#########################################################################
// Please finish and submit the matrix class done in class before break.
//Make sure to implement constructor, destructor, copy constructor, operator =, and move constructor.
//###########################################################################

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Matrix {
private:
    double* m;
    double* sum;
    int rows,cols,val,size;

    class SizeErr {
    private:
        int line;
        const string file;
    public:

        SizeErr (int line, const char file[]):line(line),file(file) {}

        friend ostream& operator << (ostream& op, const SizeErr& e){
            return op << " error detected in file " << e.file << " at line : " << e.line;
        }};

public:
    // write constructor, destructor, copy constructor, operator =
    Matrix (int rows, int cols, int val=0) : rows(rows) ,cols(cols) ,val(val) { // constructor
        size=rows*cols;
        m=new double [size];
        for (int i=0; i<size;i++){
            m[i]=val;
            }
        }

    ~Matrix () {delete [] m;} //destructor

    Matrix(Matrix&& orig) {
        m = orig.m;
        rows = orig.rows;
        cols = orig.cols;
        orig.m = nullptr;
    }

    friend  ostream& operator << (ostream& op, const  Matrix& a){ // print out
       for( int i=0;i<a.size;i+=a.cols){
           for (int j=i;j<i+a.cols;j++){
               op << a.m[j]<< " ";
           }
           op << endl;
       }
  return op;
  }

    friend Matrix operator +(const Matrix& a, const Matrix& b) { // overloaded add operator
          // test if the two matrices are equal in size!!!
        try {  if (a.rows != b.rows || a.cols !=b.cols)
                throw SizeErr (__LINE__ , __FILE__);}
        catch (const SizeErr& e) { cout << e << '\n' ;}

        Matrix sum (a.rows,a.cols);

   for(int i=0;i<a.size;i++){
       for (int j=0;j<a.cols;j++){
           sum.m[i]=a.m[i]+b.m[i];
       }}
                return sum;
}



  double operator()  (int a, int b) const  {
     return m[a*cols+b];
      }

double& operator () (int a, int b){
    return m[a*cols+b] =5.5;
}

Matrix (const Matrix& orig): m (new double [orig.size]),rows(orig.rows),cols(orig.cols),size(orig.size){
    for (int i=0;i<size;i++){
        m[i]=orig.m[i];
    }
}

Matrix& operator = (const Matrix& old){
    if ( this != &old){
    delete [] m;
        m= new double [old.size];
    for (int i=0; i<old.size;i++){
        m[i]=old.m[i];
    }
    }
    return *this;
}


};

int main() {
    Matrix m1(3, 4); // zeros
    Matrix m2(2, 3, 1.5); // fill with 1.5
  cout << m1 << '\n';
    /*
    0   0   0   0
    0   0   0   0
    0   0   0   0
    */
    cout << m1(0, 1) << '\n';
    m1(0,1) = 5.5;

    Matrix m3 = m1 + m1;
    Matrix m4 = m3;  //copy constructor
    cout << m4 << '\n';
    m4(1,2) = 11.2;
    m3 = m4; // operator =
}
