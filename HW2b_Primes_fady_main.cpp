//===================================================
//  Fady Safar
//====================================================
/*Write the following  function called isPrime that returns true
 *  if the number is prime, and false if it is not.
 * bool isPrime(unsigned long long p) { ... }
 * Your program should enter in a number and print prime or not prime.
*/
//======================================================

#include <iostream>
#include <cmath>

using namespace std;

float num;
unsigned long long p;
string ans;

bool isPrime(unsigned long long p){

    int n=sqrt(p)+1;
    for (int i=2;i<=n;++i){
        if ((double (p)/i) == floor(double(p)/i)){
            return false;
        }
    }
return true;
}


int main()
{
    A:

    cout <<"Please enter a number --> ";
    cin >> num;

    if (num != floor(num)){
        cout << "\n This is not an integer number. Please try again \n" <<endl;
        goto A;
    }

    if (num<2) { cout << "\n The entered number is : not Prime \n"<<endl;return 0;}
    else if (num == 2) {  cout << "\n The entered number is : Prime \n"<<endl;return 0;};

    p=num;

    if (isPrime(p)==true){
        ans="Prime";
    }
        else
        ans="not Prime";

    cout << "\n The entered number is : " << ans << endl <<endl;
}
