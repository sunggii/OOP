#include <iostream>//static fuc, static vari
using namespace std;

class myObj{
    static int num; //static
    int width;
    int height;
    float price;

    public:
        myObj(){
            num++; //ตัวแปร static เอาไว้นับจำนวน obj
            set(0,0,0.0);
        }
        myObj(int w,int h,float p){
            num++;
            set(w,h,p);
        }

        ~myObj(){
            num--;
            cout<<num<<endl;
        }

        void set(int w,int h,float p){
            width = w;
            height = h;
            price = p;
        }

        //static fuc ไม่ใช่สมาชิกของ class 
        //ปรธโยช์คือ count จะรู้จำนวน obj ถึงจะยังไม่มี obj
        //count จะรู้ว่าจำนวน obj = 0
        static int count(){
            return num;
        }
};

//ทุกครั้งที่มีตัวแปร sattic ต้องประกาศไว้นอก class แบบนี้ด้วย
int myObj :: num;

main(){
    cout<<myObj::count()<<endl;
    myObj book;
    cout<<myObj::count()<<endl;
    {
        myObj pen(1,2,30.5),table(22,45,400.0);
        cout<<myObj::count()<<endl;
    }
    myObj pencil(22,45,400.00);
    cout<<myObj::count()<<endl;
    return 0;
}
