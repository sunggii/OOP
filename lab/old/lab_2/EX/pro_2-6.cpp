#include <iostream>
#include <string.h>
using namespace std; 
class MyName{
    char name[10];
    public:
     MyName(){
        strcpy(name,"noname");
        cout<<"Hi: "<<name<<endl;
     }
     MyName(char *n){
        strcpy(name, n);
        cout<<"Hi: "<<name<<endl;
     }
     ~MyName(){
        cout<<"bye bye: "<<name<<endl;
     }
};
main(){
    MyName n1;
    MyName n2("Apinya");
    {
        MyName n3("Tsubaki");
    }
    MyName n4("Kii");
}