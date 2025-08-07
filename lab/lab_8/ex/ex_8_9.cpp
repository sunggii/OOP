#include <iostream> //subscipt op แบบใช้กับ array
using namespace std;

const int MAX = 3;

class MyArray{
    int array[MAX];

    public:
        MyArray();
        int &operator[] (int n){
            if(n < 0 || n >= MAX){
                cout << "The index nuber is out of bound" <<endl;
                exit(1);
            }

            return array[n];
        }
};
// con ก็เขียนข้างนอกได้
MyArray::MyArray(){
    for (int i = 0; i < MAX; i++)
    {
        array[i] = 0;
    }
    
}

main(){
    MyArray a,b;
    int i; //ตัวอ้าง index

    for (int i = 0; i < MAX; i++)
    {
        a[i] = i*2;
        cout << "a[" <<i<< "] = " <<a[i] <<endl;
    }
    cout <<endl;

    for (int i = 0; i < 4; i++)
    {
        b[i] = a[i] *3;
        cout << "b[" <<i<< "] = " <<b[i] <<endl;
    }
    cout << "subscript operator" <<endl;
    
    return 0;
}