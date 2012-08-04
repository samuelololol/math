#include <iostream>
#include <fstream>

using namespace std;

template<class T,int D>
class Node
{
    public:
        Node():p_(NULL){p_ = new T[D];}

        ~Node(){delete[] p_;}

        void set(const T (&a)[D]){
            cout << D << " Dimension: ";
            for(int i; i<D; i++){
                p_[i] = a[i];
                cout << p_[i] <<", ";
            }
            cout << endl;
        }
    private:
        T* p_;
};

int main(int argc, char const* argv[])
{
    // example for 3 Dimension, 6 Dimension
    Node<double,3> n3;
    Node<double,6> n6;
    double b[]={5,6,7};
    double c[]={5,6,7,8,9,10};
    n3.set(b);
    n6.set(c);
    cout << "-----" << endl;

    // read isis data(4 Dimension)
    ifstream in("iris.data");
    Node<double,4> n4;
    double array4[4];
    while( in>>array4[0] 
        && in>>array4[1]
        && in>>array4[2]
        && in>>array4[3])
    {n4.set(array4);}

    return 0;
}
