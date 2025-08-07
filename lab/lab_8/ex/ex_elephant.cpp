#include <iostream> //subscipt op แบบไม่ใช้กับ array
using namespace std;

class Elephsnt{
    int x, y, z;

    public:
        Elephsnt(int i, int j, int k){
            x = i;
            y = j;
            z = k;
        }

        int operator[](int);//op  overloding
};
//เขียนนอก class ได้เหมือน func ทั่ว
int Elephsnt:: operator[](int i){
    switch (i)
    {
    case 1: return x;
    case 2: return y;
    case 3: return z;
    default: return 0;

    }
}

main(){
    Elephsnt e(3,4,5);
    cout << e[1] << e[2] << e[3] << e[4] <<endl;
}