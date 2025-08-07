#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    char s[20];

    public:
        MyString(){
            strcpy(s , " ");
        }
        MyString(char *x){
            strcpy(s , x);
        }

        bool operator < (MyString m){
            return (strlen(s) < strlen(m.s))? true: false;
        }
        bool operator == (MyString m){
            return (strcmp(s , m.s) == 0) ? true : false;
        }

        void show(){
            cout << s <<endl;
        }
};


main(){
    MyString x("INT2103") , y("COS2102");
    x.show();
    y.show();

    //ternary
    (x == y? cout << "equal": cout <<"not equal");//เขียนย่อ
    (x.operator<(y)? cout << "\nx < y": cout << "\nx >= y"); //เขียนเต็ม
}