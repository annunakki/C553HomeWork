//========================================================
//==================================================
//==========================================================
/*
 * Read in a series of two numbers.  The first is an angle theta (in degrees, with North = 0 going clockwise so East = 90
 * and West = 270.  The second number is the distance.

Starting at location x=0, y = 0 compute the location of a robot if it follows the instructions.
Stop when either theta or distance is negative.  For example:

90.0 5.0           output should be:    Location: x = 5.0, y = 0.0

180.0 3.0         output should be:    Location: x = 5.0, y = -3.0

45.0 2.0           output should be:    Location: x = 6.4142, y = -1.5858

-1 -1                 program terminates.
*/
//==========================================================

#include<iostream>
#include<cmath>

using namespace  std;

class Location {

private:

 static double x;
 static double y;
double theta=0;
double dist=0;

 public:

Location (double in1, double in2) : theta(in1), dist(in2)  {

     x +=  dist * cos ((90-theta) * M_PI /180);
     y +=  dist * sin ((90-theta)* M_PI / 180);

}

    friend ostream& operator << (ostream& out, Location op) {
        out << "Location: x= " << op.x <<", y = "<<op.y<<endl;
        return out;
    }


};

double Location::x=0;
double Location::y=0;


int main(){

    double in_arry[2]={0};

    do {

    cout << " Please enter the coordinates in form 'Theta Distance' --> ";

    for (int i=0;i<2;i++){
        cin >> in_arry[i];

    }

    double& A= in_arry[0];
    double& B= in_arry[1];

    if ((A <0) || (B<0)){
        return 0;
    }

    Location pos (A,B);

     cout << pos<<endl;

}while (true);


    }
