#include <iostream>
using namespace std;

class Rectangle{
    static int count;
    int width;
    int height;
    public:
    //แก้ให้เรียกผ่าน fuc set
        Rectangle(){ 
            set(0,0);
            count++;
            cout<<"count Obj = "<<count<<endl;
        }
        ~Rectangle(){
            count--;
            cout<<"count ~Obj = "<<count<<endl;
        }

        void set(int w , int h){
            width = w;
            height = h;
        }
        void setWidth(int w){
            width = w;
        }
        void setHeight(int h){
            height = h;
        }

         int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }
        
        static int countObj(){
            return count;
        }
        void show(int i , int j);
};
int Rectangle::count;

//เอาไว้ให้ getRec ใช้
void Rectangle::show(int i , int j){
    cout<<"a["<<i<<"]["<<j<<"] width  = "<<width<<endl;
    cout<<"a["<<i<<"]["<<j<<"] height = "<<height<<endl;
}

class MyRect{
    int row, col;
    Rectangle **a;

    void setAtt(int r , int c , Rectangle **x){
            row = r;
            col = c;
            a = x;

            a = new Rectangle *[row];  //จองที่ row
            for (int i = 0; i < row; i++)
            {
                a[i] = new Rectangle [col]; //จองที่ col สังเกตว่าไม่มี * หน้า[] กรณีเป็นมิติสุดท้าย
            }

        }
    
        void deleteArray(Rectangle **d){
            if (a != 0)
            {
                for (int i = 0; i < row; i++)
                    {
                    delete[] a[i];
                }
                delete[] a;
            }
        }

    public:
        //MyRect():row(0) , col(0) , a(0){}
        MyRect(){
            setAtt(0,0,0);
        }
        MyRect(int r , int c){//ทไมไม่ต้องมี para มารับ a ก็ทำงานได้
           setAtt(r,c,a);
           
        }
        ~MyRect(){
           deleteArray(a);
        }
        
        //เพิ่ม fuc จองพื้นที่ ลบ
        void setRect();
        void deleteArray();
        Rectangle getRect(int i, int j);
        void showRect();
        void reset(int reRow, int reCol);

        //set แค่ตัวเดียว รับ index มาเลย ไม่ต้อง cin
        void setOne(int i , int j, int w, int h){
            a[i][j].set(w,h);
        };

        void setWid(int i , int j, int w){
            a[i][j].setWidth(w);
        };
        
};


void MyRect::setRect(){
    cout<<"========setRect========="<<endl;
    int w, h;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"input width  a["<<i<<"]["<<j<<"] : ",cin>>w;
            cout<<"input height a["<<i<<"]["<<j<<"] : ",cin>>h;
            a[i][j].set(w,h); //set width height ให้ obj
            cout<<endl;
        }
    }
}

Rectangle MyRect::getRect(int i, int j){
    cout<<"========getRect========="<<endl;
    return a[i][j]; //return ข้อมูลของ obj ตามตำแหน่งที่ main ส่งมา 
}

void MyRect::showRect(){
    cout<<"==========show==========="<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"] width  = "<< a[i][j].getWidth();
            cout<<"\na["<<i<<"]["<<j<<"] height = "<< a[i][j].getHeight();cout<<endl;
            cout<<endl;
        }
    }
}

void MyRect::reset(int reRow, int reCol){
    cout<<"========reset========="<<endl;
    //คืนพื้นที่
    if (a != 0)
            {
                for (int i = 0; i < row; i++)
                    {
                    delete[] a[i];
                }
                delete[] a;
            }
    //จองที่ข้อมูลใหม่
            row = reRow; col = reCol;
            a = new Rectangle *[row];  //จองที่ row
            for (int i = 0; i < row; i++)
            {
                a[i] = new Rectangle [col]; //จองที่ col สังเกตว่าไม่มี * หน้า[] กรณีเป็นมิติสุดท้าย
            }
    //เก็บข้อมูลใหม่
    int w, h;
     for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"input width  a["<<i<<"]["<<j<<"] : ",cin>>w;
            cout<<"input height a["<<i<<"]["<<j<<"] : ",cin>>h;
            a[i][j].set(w,h);
            cout<<endl;
        }
    }
}

main(){
    int row , col;
    cout<<"======= Array size======"<<endl;
    cout<<"input row : ", cin>>row;
    cout<<"input col : ",cin>>col;
    cout<<"======================="<<endl;

    MyRect rec(row,col); //จองที่ ar
    rec.setRect();
    rec.showRect();

    int r , c;
    Rectangle getResult; //สร้างตัวแปรชนิดเดียวกับ a มารับค่าที่ a ชี้
    cout<<"\ninput index for getRect"<<endl;
    cout<<"input row : ",cin>>r;
    cout<<"input col : ",cin>>c;
    getResult =  rec.getRect(r,c); 
    getResult.show(r,c); //ใช้ fun show ของ class Rectangle

    
    cout<<"======= Reset Array size======"<<endl;
    int reRow, reCol;
    cout<<"input row : ", cin>>reRow;
    cout<<"input col : ",cin>>reCol;
    rec.reset(reRow,reCol);
    
    cout<<"input index for getRect"<<endl;
    cout<<"input row : ",cin>>r;
    cout<<"input col : ",cin>>c;
    Rectangle getResult2 =  rec.getRect(r,c);  //หรือจะประกาศในบรรทัดเดียวกับแบบนี้ก็ได้
    getResult2.show(r,c); 

    //set ตัวเดียว
    int rOne , cOne;
    cout<<"======= Array size======"<<endl;
    cout<<"input row : ", cin>>rOne;
    cout<<"input col : ",cin>>cOne;
    cout<<"======================="<<endl;
    MyRect oneRec(rOne,cOne);

    int a , b;
    cout<<"\ninput index row : ",cin>>a;
    cout<<"input index rol : ",cin>>b;

    /*for ( int i = 0; i < a; i++)
    {
        
    
            oneRec.setOne(a,b);
            oneRec.showOne(a,b);
        
        
    }*/

   int w , h;
   cout<<"input width : ",cin>>w;
   cout<<"input height : ",cin>>h;


    oneRec.setOne(a,b,w,h);
    //Rectangle getResult2 =  rec.getRect(r,c);
    Rectangle resultOne = oneRec.getRect(a,b);
    oneRec.showRect();


    int rWidth , cWidth;
    cout<<"======= Array size======"<<endl;
    cout<<"input row : ", cin>>rWidth;
    cout<<"input col : ",cin>>cWidth;
    cout<<"======================="<<endl;
    MyRect recWidth(rWidth,cWidth);
    int x , y;
    cout<<"\ninput index row : ",cin>>x;
    cout<<"input index rol : ",cin>>y;
    int wid;
    cout<<"input width : ",cin>>wid;
    recWidth.setWid(x,y,wid);
    Rectangle resultOneWid = recWidth.getRect(a,b);
    recWidth.showRect();

    return 0;
}
