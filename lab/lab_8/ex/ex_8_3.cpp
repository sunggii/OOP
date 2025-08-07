#include <iostream>
using namespace std;
class Counter{
    int count;

    public:
        Counter(){
            count = 0;
        }
        Counter(int c){
            count = c;
        }

        int getCount(){
            return count;
        }

        //perfix
        Counter operator ++(){
            ++count;
            return *this;
        }
        //postfix แค่เพิ่ม int เข้าไปก็จะกลายเป็น postfix
        Counter operator++(int){
            Counter temp = getCount();
            cout << "temp count = " <<temp.count<<endl;
            count++;
            return temp;
        }

        //perfix
        friend Counter operator --(Counter& x){
            x.count--;
            return x;
        }
        //postfix แค่เพิ่ม int เข้าไปก็จะกลายเป็น postfix
        friend Counter operator--(Counter& x ,int){
            x.count--;
            return x;
        }
};

main(){
    Counter a,b,c,d,e;
    b = ++a;   //prefix
    cout << "a = " << a.getCount() <<endl;
    cout << "b = " << b.getCount() <<endl;
    cout<<endl;

    c = a++;  //postfix
    //a++;
    cout << "a = " << a.getCount() <<endl;
    //cout << "b = " << b.getCount() <<endl;
    cout << "c = " << c.getCount() <<endl;

   /*
    d = --c;
    //e = a--;
    e = operator--(a);
    cout << "\nc = " << c.getCount() <<endl;
    cout << "d = " << d.getCount() <<endl;
    cout << "e = " << e.getCount() <<endl;*/
    return 0;
}