//===========================================================
//  Fady Safar
//=======================================================
/*
 * Complete the program given out in class to convert numbers to strings.
 * In order to do this you will have to pull digits off the number.  Remember that for an integer n:

n % 10

would be the last digit.  To turn that digit into a character you will need:

char x = n % 10 + '0';

This will result in '0', '1', '2', etc.  Your job is to build a string equivalent to your number and print it out.

*/
//===============================================================

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

char toChr;
float Numchk;
int iNum;
int i=10;
float fNum=0;
int digt=0;
int num;

int main() {

    A:

    cout << "\n Please enter an integer number --> ";
    cin >> Numchk;

    if (Numchk != floor (Numchk)) {
        cout << "\n This is not an integer number. Please try again \n \n \n";
        goto A;
    }

system("cls");

cout << "\n Please enter an integer number --> "<<Numchk;


    iNum=Numchk;
    num=iNum;


    do {    // <-- count the digits of the given number
        fNum = float(iNum/i);
        if ( iNum%i != iNum ) {
                digt+=1;
                 i *=10;
    }


    } while (iNum%i != iNum);

    cout <<"\n \n The given number has " << digt+1 << " digits \n" << endl;

    //print out the number to string into form '1','2',....

    cout << " The equivalent string = ";


    for ( int i= pow(10,digt);i>=1;i /=10) {

        fNum = float(iNum /i);
        fNum =floor (fNum);
        iNum=iNum%i;
        toChr=fNum+'0';

        cout <<"'"<<toChr<<"',";
    }


    toChr= num+'0';

    cout << '\n' <<"\n The equivalent string for the entered number =  " << toChr << endl;

    cout << '\n' <<endl<<'\n' <<endl;


 }
