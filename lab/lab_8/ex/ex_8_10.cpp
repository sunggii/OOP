#include <iostream> //function call op -> ()
using namespace std;

const int MAX = 100;

class MyMatrix{
    int a[MAX][MAX];

    public:
        MyMatrix();
        int& operator() (int ,int);
        int& operator() (int);
        int& operator() ();

};
// con ก็เขียนข้างนอกได้
MyMatrix::MyMatrix(){
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            a[i][j] = 0;
        }
        
    }
}

int& MyMatrix:: operator() (int x ,int y){
    if(x < 0 || x >= MAX || y < 0 || y >= MAX){
        cout << "The index nuber is out of bound" <<endl;
        exit(1);
    }

    return a[x][y];
}

int& MyMatrix:: operator() (int x){
    if(x < 0 || x >= MAX ){
        cout << "The index nuber is out of bound" <<endl;
        exit(1);
    }

    return a[x][x];
}

int& MyMatrix:: operator() (){
    return a[0][0];
}

main(){
    MyMatrix m;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //m(i,j) = i + j;
            m.operator()(i,j) = i + j; 
            cout << m(i,j) <<" ";
        }
        cout <<endl;
        
    }

    cout <<"\nm() = " <<m() <<endl;
    
    cout <<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "m(" <<i <<") = " << m(i) <<endl;
    }
    
    return 0;
}