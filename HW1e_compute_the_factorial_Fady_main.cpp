//====================================================
// studen: Fady Safar
//====================================================
/*HW1e Read in number and compute n factorial

Read in n from keyboard.

    Compute n!  (n factorial)

    example n=3   3! = 3 * 2 * 1 = 6


    try for n=10 3628800
    n=20 ???
    n=30
*/
//===========================================================

#include <iostream>
using namespace std;

int iNum;
int iFact=1;
int i=0;


main () {

    cout << "Please enter a number -->" <<'\t' ;
    cin >> iNum;

    for (i=1;i<=iNum;i++) {
        iFact=iFact*i;

    }
    cout << "The factorial of (" << iNum << ") =" << iFact << '\n';


}
