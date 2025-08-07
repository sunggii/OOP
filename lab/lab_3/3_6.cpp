#include <iostream>
using namespace std;

class Rectangle
{
    static int count;
    int width;
    int height;

public:
    // แก้ให้เรียกผ่าน fuc set
    Rectangle()
    {
        set(0, 0);
        count++;
        cout << "count Obj = " << count << endl;
    }
    Rectangle(int w, int h)
    {
        set(w, h);
        count++;
        cout << "count Obj = " << count << endl;
    }
    ~Rectangle()
    {
        count--;
        cout << "count ~Obj = " << count << endl;
    }

    void set(int w, int h)
    {
        width = w;
        height = h;
    }
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }

    static int countObj()
    {
        return count;
    }

    void display (){
        cout << "Width: " <<width <<endl;
        cout << "Height: " <<height <<endl;
    }
    
    void show(int i, int j);
};
int Rectangle::count;

// เอาไว้ให้ getRec ใช้
void Rectangle::show(int i, int j)
{
    cout << "a[" << i << "][" << j << "] width  = " << width << endl;
    cout << "a[" << i << "][" << j << "] height = " << height << endl;
}

// class MyRect มีหน้าที่เก็บข้อมูลของ class Rectangle
class MyRect
{
    int row, col;
    Rectangle **a;

    // เพิ่ม fuc จองพื้นที่ ลบ
    void setAtt(int r, int c)
    { // ไม่ต้องมี para มารับ a เพราะเราไม่ได้รับค่าอะไรมาอยู่แล้ว a เป็นพ้อยเอาไว้จองที่แลเวเราก็เข้าถึงในนี้ได้อยู่แล้ว
        row = r;
        col = c;

        a = new Rectangle *[row]; // จองที่ row
        for (int i = 0; i < row; i++)
        {
            a[i] = new Rectangle[col]; // จองที่ col สังเกตว่าไม่มี * หน้า[] กรณีเป็นมิติสุดท้าย
        }
    }

    void deleteArray()
    {
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
    MyRect()
    {
        setAtt(0, 0);
    }
    MyRect(int r, int c)
    {
        setAtt(r, c);
    }
    ~MyRect()
    {
        deleteArray();
    }

    void setRect();
    Rectangle getRect(int i, int j);
    void showRect();
    void reset(int reRow, int reCol);

    // set แค่ตัวเดียว รับ index มาเลย ไม่ต้อง cin
    void setOne(int i, int j, int w, int h)
    {
        a[i][j].set(w, h);
    };

    void setWid(int i, int j, int w)
    {
        a[i][j].setWidth(w);
    };

    // set ตัวเดียว แต่รับ obj มาเลย
    void setOneObj(int i, int j, Rectangle &p)
    {
        a[i][j] = p; // p เป็นสมาชิก class Rectangle ที่มีข้อมูล wid height มาอยู่แล้ว
    }
};

void MyRect::setRect()
{
    cout << "========setRect=========" << endl;
    int w, h;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "input width  a[" << i << "][" << j << "] : ", cin >> w;
            cout << "input height a[" << i << "][" << j << "] : ", cin >> h;
            a[i][j].set(w, h); // set width height ให้ obj
            /*
            a[i][j].setWidth(w);
            a[i][j].setHeight(h);*/
            cout << endl;
        }
    }
}

Rectangle MyRect::getRect(int i, int j)
{
    return a[i][j]; // return ข้อมูลของ obj ตามตำแหน่งที่ main ส่งมา
}

void MyRect::showRect()
{
    cout << "==========show===========" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "a[" << i << "][" << j << "] width  = " << a[i][j].getWidth();
            cout << "\na[" << i << "][" << j << "] height = " << a[i][j].getHeight();
            cout << endl;
            cout << endl;
        }
    }
}

void MyRect::reset(int reRow, int reCol)
{
    cout << "========reset=========" << endl;
    deleteArray();        // คืนพื้นที่
    setAtt(reRow, reCol); // จองที่ข้อมูลใหม่
    setRect();            // เก็บข้อมูลใหม่
}

main()
{
    /*Rectangle A(2,2);
    A.display();*/
    //----------------------------

    int row, col;
    cout << "======= Array size======" << endl;
    cout << "input row : ", cin >> row; // 2
    cout << "input col : ", cin >> col; // 2
    cout << "=======================" << endl;

    MyRect rec(row, col); // จองที่ array
    // MyRect rec(2,2); //จองที่ array
    rec.setRect();
    rec.showRect();

    int r, c;
    Rectangle getResult; // สร้างตัวแปรชนิดเดียวกับ a มารับค่าที่ a ชี้
    cout << "\ninput index for getRect" << endl;
    cout << "input row : ", cin >> r;
    cout << "input col : ", cin >> c;
    getResult = rec.getRect(r, c);
    getResult.show(r, c); // ใช้ fun show ของ class Rectangle

    cout << "======= Reset Array size======" << endl;
    int reRow, reCol;
    cout << "input row : ", cin >> reRow;
    cout << "input col : ", cin >> reCol;
    rec.reset(reRow, reCol);

    cout << "input index for getRect" << endl;
    cout << "input row : ", cin >> r;
    cout << "input col : ", cin >> c;
    Rectangle getResult2 = rec.getRect(r, c); // หรือจะประกาศในบรรทัดเดียวกับแบบนี้ก็ได้
    getResult2.show(r, c);

    // set ตัวเดียว
    /*int rOne , cOne;
    cout<<"=======Array size======"<<endl;
    cout<<"input row : ", cin>>rOne;
    cout<<"input col : ",cin>>cOne;
    cout<<"======================="<<endl;
    MyRect oneRec(rOne,cOne);

    char choice; //อยากให้ถามด้วยว่าป้อนครบยัง
    do
    {
        int a , b;
        cout<<"\ninput index row : ",cin>>a;
        cout<<"input index rol : ",cin>>b;

        int w , h;
        cout<<"input width : ",cin>>w;
        cout<<"input height : ",cin>>h;
        oneRec.setOne(a,b,w,h);
        Rectangle resultOne = oneRec.getRect(a,b);
        oneRec.showRect();


        cout<<"Is it complete yet (y/n) : ",cin>>choice;
    } while (choice == 'n' || choice == 'N');


    //กรณี set ตาม index แต่มีแค่ width
    int rWidth , cWidth;
    cout<<"======= Array size======"<<endl;
    cout<<"input row : ", cin>>rWidth;
    cout<<"input col : ",cin>>cWidth;
    cout<<"======================="<<endl;
    MyRect recWidth(rWidth,cWidth);
    do
    {
        int x , y;
        cout<<"\ninput index row : ",cin>>x;
        cout<<"input index rol : ",cin>>y;

        int wid;
        cout<<"input width : ",cin>>wid;
        recWidth.setWid(x,y,wid);
        Rectangle resultOneWid = recWidth.getRect(x,y);
        recWidth.showRect();

        cout<<"Is it complete yet (y/n) : ",cin>>choice;
    } while (choice == 'n' || choice == 'N');*/

    /*char choice; //อยากให้ถามด้วยว่าป้อนครบยัง
    //set ตัวเดียว แต่รับ obj มาเลย
    int rO , cO;
    cout<<"======= Array size======"<<endl;
    cout<<"input row : ", cin>>rO;
    cout<<"input col : ",cin>>cO;
    cout<<"======================="<<endl;
    MyRect recOneObj(rO,cO);

    do
    {
        int x , y;
        cout<<"\ninput index row : ",cin>>x;
        cout<<"input index rol : ",cin>>y;

        int w,h;
        cout<<"input width : ",cin>>w;
        cout<<"input height : ",cin>>h;
        Rectangle p(w,h); //ส่ง p ที่เป็น obj ไปเลย
        recOneObj.setOneObj(x,y,p);
        Rectangle resultOneObj = recOneObj.getRect(x,y);
        recOneObj.showRect();

        cout<<"Is it complete yet (y/n) : ",cin>>choice;
    } while (choice == 'n' || choice == 'N');*/

    cout << "\n===== destructor =====" << endl;
    return 0;
}
