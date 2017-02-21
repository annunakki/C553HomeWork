//=========================================================================
//================Fady Safar==============================
//=================================================================
/*
 * Edit the code hw3a.cc in session03 and make main work.  You are not allowed to rewrite main,
 * you have to make your class work with main as it is. In other words, make the const variables
 * work by appropriately defining your methods const.
 *
 */
//============================================================================
#include <iostream>
using namespace std;


class Vec3d {
private:
    const int x;
    const int y;
    const int z;


public:

    Vec3d (int axis1, int axis2, int axis3) : x(axis1), y(axis2), z(axis3){}

    Vec3d (int axis1)  : x(axis1), y(0), z(0) {}

    friend Vec3d  operator +(Vec3d a, Vec3d b){
        return Vec3d (a.x+b.x, a.y+b.y, a.z+b.z); }

Vec3d add(const Vec3d add_elem) const {

    return Vec3d (x+add_elem.x, y+add_elem.y, z+add_elem.z);
}

Vec3d dot(const Vec3d dot_elem) const {
    return Vec3d (x*dot_elem.x, y*dot_elem.y, z*dot_elem.z);
}

friend Vec3d operator* (const Vec3d sclr,int num ){
    return Vec3d (num*sclr.x, num*sclr.y, num*sclr.z);
}

friend Vec3d operator *(int numm, const Vec3d sclrr){
     return Vec3d (numm*sclrr.x, numm*sclrr.y, numm*sclrr.z);
}


    friend ostream& operator << (ostream& st, Vec3d op) {
        st << "(" << op.x << "," << op.y << "," << op.z << ")";
        return st;
    }



   };



int main() {
    const Vec3d a(1.0, 2, 2.5); //(1.0, 2.0, 2.5) (x,y,z)
    cout << a << '\n';

    Vec3d b(5.0);         //(5.0, 0.0, 0.0)
    cout << b << '\n';


    Vec3d c = a + b;
    cout << c << '\n';

    Vec3d c2 = a.add(b);   // call a method
    cout << c2 << '\n';

 //   double d = a.dot(b); //  dot product = a.x*b.x + a.y*b.y + a.z*b.z
 //   cout << d << '\n';

    Vec3d e = a * 2;   //scalar multiplication
    cout << e << '\n';

    Vec3d f = 2 * a;   //scalar multiplication
    cout << f << '\n';
}
