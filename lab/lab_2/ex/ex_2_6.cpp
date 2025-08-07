#include <iostream>
#include <string.h>
using namespace std;

class myName{
    char name[10];
    public:
        myName(){
            strcpy(name,"noname");
            cout<<"Hi:P"<<name<<endl;
        }
        myName(char *n){
            strcpy(name, n);
            cout<<"Hi:P "<<name<<endl;
        }
        //destructor
       ~myName(){
        cout<<"bye bye ;( "<<name<<endl;
       }
};

main(){
    myName n1;
    myName n2("yeri");
    cout<<endl;
    {
        myName n3("rei");
    }
    cout<<endl;
    myName n3("rebecca");
    return 0;
}