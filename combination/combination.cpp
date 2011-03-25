#include <iostream>
#include <ostream>
using namespace std;

// num! jchen
class jchen {
public:
    jchen (int num)
        :base_(num),
        out_(1) { }
    friend int operator/(const jchen& j1, const jchen& j2){
        int ret = 1;
        for (int i = j2.base_ + 1; i < j1.base_ + 1; i++) {
            ret *= i;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, jchen& j) {
        os << j.out();
        return os;
    }
    int base(){return base_;}

private:
    int base_;
    int out_;
    int out(){
        for (int i = 2; i < base_+1; i++) {
            out_  *= i;
        }
        return out_;
    }
};

//c(nd, nd)
class comb {
public:
    comb (int nu, int nd)
        :u_(jchen(nu)),
        d_(jchen(nd)),
        out_(1) {}
    friend ostream& operator<<(ostream& os, comb& c) {
        os << c.out();
        return os;
    }
private:
    jchen u_;
    jchen d_;
    int out_;
    int out(){
        return u_/d_;
    }
};

int main(int argc, const char *argv[])
{
    //jchen a = jchen(3);
    //jchen b = jchen(6);
    //cout << a << endl;
    //cout << b << endl;
    //cout << b/a << endl;
    comb a = comb(5,2);
    cout << a << endl;
    return 0;
}
