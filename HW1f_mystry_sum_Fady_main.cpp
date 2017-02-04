//===============================================================
// name: Fady Safar
/* Compute the sum 1/12 + 1/2 + 1/32 + .... 1/n2

Use float to compute your answer.  Note that this will result in a maximum accuracy of 7 digits.

Figure out how many iterations you will need before the contribution of 1/n2 is too small and no longer matters.

Then, instead of printing this sum (which will be unrecognizable, some strange number around 1.64) print out the following expression:

sqrt(6*s)

where s is the sum.

In order to use the sqrt function you will have to #include <cmath>



You may recognize the number you get from this.  But it will not be very accurate.

Now, try to make n bigger.  And compute the answer backwards as well.  The output of your program should be:

cout << sqrt(6 * s1) << '\n';

cout << sqrt(6 * s2) << '\n';

where s1 and s2 are the sums computed forward and backward.

This is all you have to submit, but you should try to figure out which of these two numbers is more accurate.

It should be fairly obvious which answer is better as n increases.
*/
//=======================================================================

#include <iostream>
#include <cmath>

using namespace std;

int iNum=0;
float fSum_fwd=0;
float fSum_bwd=0;
float i=0;

int main() {

    cout << "Please enter a number -->\t";
    cin >> iNum;

    for (float i=1 ; i<=iNum ; i++) {
        fSum_fwd += 1/(i*i);

    }


    for (float i=iNum ; i>0 ; i--) {
        fSum_bwd += 1/(i*i);

    }



   cout << "The forward sum = " << sqrt(6*fSum_fwd) << endl;
   cout << "The backward sum = " << sqrt(6*fSum_bwd) << endl;

   return 0;

}
