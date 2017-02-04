//====================================================
// studen: Fady Safar
//====================================================
/*Convergence of n-gons

    1. Start with a circle r= 1
    2. Circumscribe an equilateral triangle, (n=3) around the circle
    3. Circumscribe a circle around the triangle, and print out the radius.
    4. Circumscribe a square (n=4) around the circle
    5. Circumscribe a circle around the square...
    6. Circumscribe a pentagon (n=5) around the circle.

    keep going until n=1,000,000 (106)

    print out the radius for n=1, n=10, 100, 1000, 10000, 100000, 106
*/
//===========================================================

#include <iostream>
#include <math.h>

using namespace std;

double iRadius=1;
const float PI=3.14159;
double i=1;
double iTheta=0;

double Calc_radius ( long n){
    if (n<3) {
       return 1;
}
    iTheta =(2*PI)/n;
    iRadius = iRadius / cos (iTheta/2);
    return iRadius;
}

int main() {

    for ( long n=1;n<=1000000;n++){
       Calc_radius(n);
        if (n == i){
        cout << "Circle raduis at n=" << n <<" = "<<iRadius <<endl;
        i=i*10;
        }
    }
}
