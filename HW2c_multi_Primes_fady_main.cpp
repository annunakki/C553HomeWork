//==========================================
//    Fady Safar
//===========================================
/*Using the function you wrote in the previous program, write another
 *  function that returns the count of how many primes are in the range [a,b] inclusive.

int countPrimes(unsigned long long a, unsigned long long b) { ...}

The main program should read in two numbers, and print out the result from this function.

For example, if I type:
1 10

there are 2,3,5,7 = 4 primes between 1 and 10 so the output should be:

4

The range is inclusive, so if I type

11 17

the output should be:

3
*/
//=====================================================

#include <iostream>
#include <cmath>
using namespace std;

int multiPrimes [2];
//int prm=0;


int countPrimes(unsigned long long a, unsigned long long b){


    a=multiPrimes[1];
    b=multiPrimes[2];
    int prm=0;
    int flg=0;

    if (a <3) {a=3; prm=1;}

    for (unsigned long long i=a;i<=b;i++){


        unsigned long long n=sqrt(i);
        for (unsigned long long j=2;j<=n;j++) {

            if (i%j == 0) {
                flg=1;
                break;
            }
        }
    //    if (i==1){ flg=1; }
    //    if (i==2){ flg=0;}
        if (flg ==0) { prm++;} else flg=0;

        }
    return prm;

}


int main(){
    //int prm=0;
    cout << "Please enter two positive integer numbers seperated by space --> ";
    for (int i=1;i<3;i++) {
    cin >> multiPrimes [i];
    }

  //  countPrimes(multiPrimes[1],multiPrimes[2]);

    cout << "\nTotal number of primes between the two entered numbers = " << countPrimes(multiPrimes[1],multiPrimes[2])<<endl;
    cout <<endl;


}
