//==========================================
/* Student name: Fady Safar
============================================
 HW1a 3n+1 conjecture
 read in a number from keyboard (suppose n = 5)

    if it's odd, multiply by 3 and add 1.
    if it's even divide by 2.

    Repeat until the number converges to 1
    5	16	8	4	2	1
============================================
*/

#include <iostream>
using namespace std;

int main()
{
    int iNum;
    int iRem=0;
    int iAns=0;
    int iRun=0;

    cout << "Please Enter a Number --> " << '\t';
    cin >> iNum;

    iAns=iNum;

    for (iRun=1;iAns=1;i++) {

        iRem=iAns % 2;

        if (iRem == 0) {
            iAns=iAns /2;
            cout << "Run " << iRun << " and the Result = " << iAns << '\n';
        }

        else  {
            iAns= (iAns*3)+1;
            cout << "Run " << iRun << " and the Result = " << iAns << '\n';
        }
    }

 }
