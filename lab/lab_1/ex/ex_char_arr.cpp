#include <iostream>
#include <string.h>
using namespace std;

class A{
    string s1;
    char s2[20];
    public:
        void setS1(string n){
            s1 = n;
        }
        void setS2(char *n){
            strcpy(s2, n);
        }

        string getS1(){
            return s1;
        }
        char* getS2(){
            return s2;
        }
};

main(){
    A tence;
    tence.setS1("I am S1.");
    tence.setS2("I am S2.");
    cout<<tence.getS1()<<endl;
    cout<<tence.getS2()<<endl;
    return 0;
}