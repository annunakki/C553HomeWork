//======================================================================
//====================Fady Safar=========================================
//=====================================================================
/*Using the NOAA windchill table in the provided URL, generate a duplicate table.

This is a test of your ability to use nested loops, implement the equation in C++.
 Don't forget to use the math function pow(x,y) in the library to compute the power.

http://www.nws.noaa.gov/om/winter/windchill.shtml (Links to an external site.)

There is no input to this program.
*/
//========================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int Temp[18]={0};
int Wind[12]={0};
int table[12][18]={0};
int val=45;


void init_arrays(){
    cout << "       ";
    for(int i=1;i<=18;i++){
        val -=5;
        Temp[i]=val;
       cout << setw(4) << Temp[i];
    }
    cout <<endl;
    for(int i=1;i<=20;i++){
       cout << "====";
    }
    val=0;
    for (int i=1;i<=12;i++){
        val +=5;

        Wind[i]=val;
    }
}


int main() {

    init_arrays();

    for (int i=1;i<=12;i++){
       cout<< setw(4) << Wind[i] << " | ";
        for (int j=1;j<=18;j++){
            table[i][j]=35.74+(0.6215*Temp[j])-(35.75*(pow(Wind[i],0.16)))+(0.4275*Temp[j]*pow(Wind[i],0.16));
               cout << setw(4) << table[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
