#include <iostream>
#include <string.h>
using namespace std;

class A{
    string s1;
    char s2[20];
    public:
    void setS1(string s){
        s1 = s;
    }
    void setS2(char *s){
        strcpy(s2, s); //strcpy = coppy string
    }
    string getS1(){
        return s1;
    }
    char* getS2(){
        return s2;
    }
};

int main(){
    A a; //=ชื่อ class ตามด้วยชื่อตัวแปรที่รับ ส่งค่า 
    a.setS1("I am S1.");
    a.setS2("I am S2.");
    cout<<a.getS1()<<endl;
    cout<<a.getS2()<<endl;
}