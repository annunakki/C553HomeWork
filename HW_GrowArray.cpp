/*###############################################################################
 * ###################### GrowArray ###############################################
 * ###############################################################################
 * #############################Fady Safar######################################
 * #############################################################################
 *
 * Define a list class using the 5 methods we reviewed in class to make the following work:
 *
 *
 *
 * GrowArray f(GrowArray x) {
 * x.add(1);
  *return x;
*}
*
*int main() {
 * GrowArray a;
  *for (int i = 0; i < 10; i++)
   * a.add(i);
*  GrowArray b = a;
 * cout << b << '\n';
*  GrowArray c;
*  c = a;
*  cout << b << '\n';
*  c = f(b);
*  cout << b << '\n';
*/
//##############################################################################

#include <iostream>
using namespace std;


class GrowArray {
private:


    int size;
    int used;
    int* array;

public:
    GrowArray():size(1),used(0),array(new int[1]){}
    GrowArray(int assign): size(assign), used(0), array(new int[assign]){ }

void add (int x){
    if ( used >= size){
        int* temp= array;
        array=new int[size*2];

        for (int i=0; i<size; i++){
            array[i]= temp[i];
        }
        delete [] temp;
        size =size*2;

    }
     array[ used++]=x;
}

friend ostream& operator << (ostream& op, const GrowArray& a){
    for (int i=0; i<a.used; i++){
         op << a.array[i] << " ";
    }
    return op;
}

friend GrowArray f (GrowArray x) {
  x.add(1);
  return x;
}

GrowArray (const GrowArray& orig): size(orig.size),used(orig.used), array(new int [orig.size]){
    for (int i=0; i<used; i++){
        array[i]=orig.array[i];
    }

}

GrowArray& operator = (const GrowArray& b){
   if (this != &b){
    delete [] array;
    size=b.size;
    used=b.used;
    array =new int [size];
    for (int i=0;i < used; i++){
        array[i]=b.array[i];
    }
   }
   return *this;
}

~GrowArray (){
    delete [] array;
    }
};

int main() {
  GrowArray a;
  for (int i = 0; i < 10; i++)
    a.add(i);
  GrowArray b = a;
  cout << b << '\n';
  GrowArray c;
  c = a;
  cout << b << '\n';
  c = f(b);
  cout << b << '\n';

}



