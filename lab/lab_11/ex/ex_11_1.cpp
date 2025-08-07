#include <iostream>
using namespace std;

template <class T>
T squqre(T x){
    return (x*x);
}

main(){
    cout << squqre(2) <<endl;
    cout << squqre(2.5) <<endl;
}