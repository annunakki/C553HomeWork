//=================================================
//=================Fady Safar========================
//================================================
/*Complete the bitmap code we specified in class.  Since we wrote main, you have a specification of the
 * kind of operations that have to work.  Later, we will augment this class to actually write your bitmap
 * to disk as a .png file.



For now, see the code, but:

This code is C++11, using uint32_t and #include <cstdint> so to compile using g++ you will need the option:

g++ -std=c++11 bitmap.cc



Every element is an integer comprised of rgba, the a is alpha (transparency).  This assignment does not require
 that you deal with these colors.  If you are given the color whose value is 1, simply store the number 1 in every
 element for that draw.

000000000000000000000000000000000
000000000000000000000000000000000
000000000000000000000000000000000
000000001100000000011000000000000
000000001100000000011000000000000
000000000000010000000000000000000
000000000000010000000000000000000
000000000000010000000000000000000
000000000000000000000000000000000
000000010000000000010000000000000
000000001111111111100000000000000
000000000000000000000000000000000
000000000000000000000000000000000
000000000000000000000000000000000
000000000000000000000000000000000


*/
//============================================================
#include <iostream>
#include <cstdio>
#include<cmath>
#include<iomanip>

using namespace std;

class Bitmap {

private:
   enum { ROWS = 30, COLS = 40 };
    int a[ROWS][COLS];

public:
    Bitmap () {
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    a[i][j] = 0;
        }

    Bitmap (int n) {
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    a[i][j] = n;
        }

    void horizLine (int w, int x, int y , int z){
        for (int i=x;i<=y;i++){
            a[w][i]=z;
        }
    }

    void vertLine  (int w, int x, int y , int z){
        for (int i=x;i<=y;i++){
            a[i][w]=z;
        }
    }

    void rect  (int x, int y, int w , int h, int p){
        for (int i=x;i<=h;i++){
            for (int j=y;j<=w;j++){
                a[i][j]=p;
            }
        }
    }

 // the idea of the function below for Bresenham method is taken but not copied from a code online
    void line (int x0, int y0, int x1 , int y1, int p) {
       int dx=fabs(x1-x0);
       int dy=fabs(y1-y0);
       int err=2*dy-dx;
       int ds=2*dy;
       int dt=2*(dy-dx);

       a[x0][y0]=p;

      while (x0<x1){
          x0++;
          if (err<0)
              err +=ds;
          else{
              y0++;
              err +=dt;
          }
          a[x0][y0]=p;

            a[x0][y0]=p;

            }
        }
//--------------------------------------------


        friend ostream& operator << (ostream& s, Bitmap& op){

            for (int i=0;i<ROWS;i++){
                for (int j=0;j<COLS;j++){
                     s << setw(1)<<op.a[i][j];
                }
                s <<endl;
            }
            return s;
        }


};



int main (){

        Bitmap b1;
        Bitmap b2(3);
        // no sizes yet...	Bitmap b3(100,200);
        // each method has a last parameter (color) which is an integer (32-bit)
        b2.horizLine(5, 1, 27, 99); // row=5, col 1 to 27, set every pixel to 99
        b2.vertLine(19, 5, 20, 45); // col 19, row 5 to 20, set every pixel to 45
        b2.rect(9, 9, 5, 8, 205); // x=9, y = 9, w=5, h=8, set every pixel to 205
        b2.line(28, 7, 8, 25, 92); // diagonal line using Bresenham, set every pixel to 92 << (x0,y0,x1,y1,c)
        cout << b2;




}
