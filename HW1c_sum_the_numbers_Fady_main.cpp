//====================================================
// studen: Fady Safar
//====================================================
/*sum the numbers from 1 to 100.

Display the answer using the Gauss formula n(n+1)/2
Display the answer using a loop.  Verify that both answers are the same.

*/
//=====================================================

#include <iostream>
using namespace std;

int i=0;
int iSum=0;
int iAns=0;
int iGauss=0;
bool bEquel;

int main () {
    for (i=1;i<=100;i++) {
        iSum +=i;
            }
    cout << "Total Loop Sum = " << iSum << '\n';
    iGauss=(100 * (100+1)) /2;
    cout << "Gauss sum = " << iGauss <<'\n' << '\n';

    bEquel= iSum == iGauss;

    cout << "Are both answers equal? : " << bEquel << '\n';

}
