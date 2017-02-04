//====================================================
// studen: Fady Safar
//====================================================
/*HW1d Sum reciprocals

do this as float and as double

    sum1= 1/1 + 1/2 + ... + 1/100


    sum2= 1/100 + 1/99 + .... + 1/1

print out sum1
print out sum2
print out sum1 - sum2

You should see that the two sums are not quite equal, which leads to the question, which is more correct?
*/
//===========================================================

#include <iostream>
using namespace std;

float fSum_1=0;
double dSum_1=0;
float fSum_2=0;
double dSum_2=0;
float fTotal=0;
double dTotal=0;


int main () {
    cout << " As float calculations" << '\n';
    for ( float i=1;i<=100;i++) {
        fSum_1 += (1/i);
        dSum_1 += (1/i);

    }
    cout << " Sum 1 = " << fSum_1 << '\n';
    for (float i=100;i>=1;i--) {
        fSum_2 = fSum_2 +(1/i);
        dSum_2 = dSum_2 + (1/i);
    }
    cout << " Sum 2 = " << fSum_2 << '\n';

    fTotal= fSum_1 -fSum_2;
    dTotal= dSum_1 -dSum_2;
    cout << "Sum1 -Sum2 = " << fTotal <<'\n';

    cout << " As Double calculations" << '\n';
    cout << " Sum 1 = " << dSum_1 << '\n';
    cout << " Sum 2 = " << dSum_2 << '\n';
    cout << "Sum1 -Sum2 = " << dTotal <<'\n';


}
