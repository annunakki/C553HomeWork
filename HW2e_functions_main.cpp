//=======================================================================
//======================Fady Safar======================================
//======================================================================
/* Implement the following 4 functions:

For parts 1-4 of this assignment, make sure you can support up to n=30.

1. fact(n) computes n factorial using a loop.

2. fact2(n) computes n factorial using recursion

3. fibo(n) computes the nth fibonacci number using a loop where the sequence is 1, 1, 2, 3, 5, 8, 13, ...
and n=1 is the first number in the sequence.  Thus fibo(6)=8

4. fibo2(n) using recursion.

5. choose(n,r) = n!/(r!(n-r)!)  You should be able to support choose(52,6), the number of ways to play the NY lottery.

Use the following main:

int main() {
  cout << fact(5) << ' ' << fact2(5) << '\n';
  cout << fact(15) << ' ' << fact2(15) << '\n';
  cout << fibo(5) << ' ' << fibo2(5) << '\n';
  cout << fibo(13) << ' ' << fibo2(13) << '\n';
  cout << choose(52,6) << '\n';
}
*/
//=========================================================================

#include <iostream>
using namespace std;



long int fact(int n) {
long int fact_1=1;
    for ( int i=1;i<=n;i++){
        fact_1 *=i;
    }
    return fact_1;

}
//==============================
long int fact2(int n) {
    if (n <=1){
        return 1;
    }
    return n*fact(n-1);
}


//==============================
int fibo(int n) {
     int fibo_buffer=0;
     int fibo_next=1;
     int fibo_3=0;

    for (int i=0; i<n;i++) {
        fibo_3=fibo_next+fibo_buffer;
        fibo_next =fibo_buffer;
        fibo_buffer=fibo_3;

    }
    return fibo_3;
}
//==============================

int fibo2(int n){

    if (n==1 || n==2) {return 1; cout <<1;}
    else {
        return (fibo2(n-1)+fibo2(n-2));
        cout<<fibo2(n-1)+fibo2(n-2);
    }
}

//================================

double choose(unsigned int n, unsigned int r){

    double nn=1;
    double nr=1;
    int rr=1;
    double res=0;


    for (unsigned int i=1;i<=r;i++){
        rr *=i;

    }

    for (unsigned int i=1;i<=n;i++){
        nn *=i;
    }

    for (unsigned int i=1;i <=(n-r);i++){
        nr *=i;
    }

    res = nn / (rr*nr);

return res;
#if 0
    for (int i=2;i<=n;i++){
        carry=0; a=0;

        for (int i=0;i<ar_size;i++){
            a=reslt[i]*w+carry;
            reslt[i]=a%10;
            carry=a/10;
        }
        while (carry != 0){
            reslt[ar_size]=carry%10;
            carry=carry%10;
            ar_size++;
        }
    }

    for(int i=ar_size-1;i>-1;i--){
        cout << reslt[i];
    }
    return n/(rr*());
#endif

}
//==============================

int main() {
#if 0
    cout << "Please anter an integer number --> ";
    cin >> n;
#endif


    cout << fact(5) << ' ' << fact2(5) << '\n';
    cout << fact(15) << ' ' << fact2(15) << '\n';
    cout << fibo(5) << ' ' << fibo2(5) << '\n';
    cout << fibo(13) << ' ' << fibo2(13) << '\n';
    cout << choose(52,6) << '\n';




}
