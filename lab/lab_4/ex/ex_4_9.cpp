#include <iostream>
using namespace std;
int y;

int& g(){
    static int x;
    x++;
    return x;
}

int& h(){
    y++;
    return y;
}

main(){
    cout<<"x before g() = "<<g()<<endl;
    g() = 5;
    cout<<"x after g() = "<<g()<<endl;

    cout<<"\ny before h() = "<<h()<<endl;
    h() = 8;
    cout<<"y after y() = "<<h()<<endl;

    
    return 0;
}