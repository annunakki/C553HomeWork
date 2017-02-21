//========================================================
//===================Fady Safar===================
//========================================================
/*
 * As discussed in class (and with the file posted on github) write a program that processes the arrays as specified,
 * including passing arrays, returning the average, and passing multiple parameters by reference.

 What needs to be done is open a file named "2f.dat"

After this file is opened, read in n to get the size for the array, and then read n elements into the array.
 Once this is done print the average of the array.

An an example of how the file should be formatted if n were to be equal to 3:

3

65

83

95

*/
//==============================================================

#include <iostream>
#include <fstream>

using namespace std;

int n=1;
int avg=0;



int get_array_avg(){

    ifstream f("2f.dat");

    if ( ! f.is_open() ) {
         cout <<" Either file is not found or Failed to open" << endl;
         return 0;
      }
      else {
         cout <<"File is opened " << endl;
      }

    f>>n;
    f.close();

    int array[n];

    for (int i=0;i<n;i++){
        f >>array[i];
        avg =+ array[i];
    }
    return avg;
}

int  main () {

    get_array_avg();


    cout << n<<endl;
    cout <<endl;

    cout << avg/n <<endl;
    cout << endl;
}
