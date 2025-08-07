#include <iostream>
using namespace std;

class Fabric
{
private:
    int color; //1.ขาว 2.เขียว 3.น้ำตาล 4.เทา
public:
    virtual void show()=0;
    Fabric(int c) {
        if (c>0 && c<5)
        {
            color = c;
        } else {
            color = 1;
        }
    }
    virtual ~Fabric() {}
    //get
    int getColor(){
        return color;
    }
    virtual string getDtail(){
        switch (color)
        {
        case 1: return "white";
        case 2: return "green";
        case 3: return "brown";
        case 4: return "gray";
        }
    }
};

class Cotton:public Fabric
{
private:
    int type; //ความหนา 1.มาก 2.กลาง 3.บาง
public:
    Cotton(int t, int c):Fabric(c) {
        if (t>0 && t<4)
        {
            type = t;
        }else {
            type = 1;
        }
    }
    ~Cotton() {}
    //get
    int getType(){
        return type;
    }
    string getDtail(){
        switch (type)
        {
        case 1: return "namak";
        case 2: return "naglang";
        case 3: return "bang";
        }
    }
    //show
    void show(){
        cout << "color = " << Fabric::getColor()<<" "<<Fabric::getDtail() <<endl;
        cout << "type = " << type << " "<<getDtail()<<endl;
    }
};

class Linen:public Fabric
{
private:
    int grade; //คุณภาพ 1.ดีมาก 2.ดี 3.พอใช้
public:
    Linen(int g, int c):Fabric(c) {
        if (g>0 && g<4)
        {
            grade = g;
        } else {
            grade = 1;
        }
    }
    ~Linen() {}
    //get
    int getGrade(){
        return grade;
    }
    string getDtail(){
        switch (grade)
        {
        case 1: return "demak";
        case 2: return "de";
        case 3: return "poshai";
        }
    }
    //show
    void show(){
        cout << "color = " << Fabric::getColor()<<" "<<Fabric::getDtail() <<endl;
        cout << "grade = " << grade << " "<<getDtail()<<endl;
    }
};

class Polyester:public Fabric
{
private:
    int type; //เนื้อผ้า 1.ไมโคร 2.ไม่ใช่ไมโคร
public:
    Polyester(int t, int c):Fabric(c) {
        if (t>0 && t<3)
        {
            type = t;
        } else {
            type = 1;
        }
    }
    ~Polyester() {}

    //get
    int getType(){
        return type;
    }
    string getDtail(){
        switch (type)
        {
        case 1: return "micro";
        case 2: return "not micro";
        }
    }
    //show
    void show(){
        cout << "color = " << Fabric::getColor()<<" "<<Fabric::getDtail() <<endl;
        cout << "type = " << type << " "<<getDtail()<<endl;
    }
};


class ClothItem
{
private:
    double price;
    Fabric **fabric;
    int num;
public:
    virtual void show()=0;
    ClothItem() {
        setPrice(100);
        fabric = 0;
        num = 0;
    }
    ClothItem(double p, int n){
        setPrice(p);
        setNum(n);
        fabric = 0;
    }
    virtual ~ClothItem() {
        cout << "~ClothItem " <<endl;
        showClothItem();
        delete[] fabric;
    }
    //set
    void setPrice(double p){
        if (p >= 0)
        {
            price = p;
        } else {
            price = 100;
        }   
    }
    void setNum(int n){
        if (n<0)
        {
            num = 1;
        }
        
        num  = n;
        delete[] fabric;
        fabric = new Fabric*[num];
    }
    void setFabric(int i, Fabric* f){
        fabric[i]  = f;
    }
    //get
    double getPrice(){
        return price;
    }
    int getnum(){
        return num;
    }
    Fabric *getFabric(int i){
        return fabric[i];
    }

    void showClothItem(){
        cout << "price = " <<price <<endl;
        cout << "num = " <<num <<endl;
        for (int i = 0; i < num; i++)
        {
            cout << "fabric[" << i <<"]:" <<endl;
            cout << fabric[i]->getDtail() <<endl;;
        }
    }
    Fabric* operator[](int i){
       return getFabric(i);
    }
};

class Bag :public ClothItem //abs class void show() = 0;
{
private:
    int type; //1.สำหรับผญ. 2.สำหรับผช. 3.ทั้งคู่
    static int count;
public:
    Bag():ClothItem() {
        count++;
        setType(3);
    }
    Bag(int t, double p ,int n):ClothItem(p,n) {
        count++;
        setType(t);
    }
    ~Bag() {
        count--;
        cout <<"\n~Bag" <<endl;
        cout << "type = " << type <<endl;
        cout << "count = " << count <<endl;
    }
    //set
    void setType(int t){
        if (t>0 && t<4)
        {
            type = t;
        } else {
            type = 1;
        }
    }
    //get
    int getType(){
        return type;
    }
    static int getCount(){
        return count;
    }
    
};
int Bag::count;

class HandBag:public Bag
{
private:
    int strap;//1.มีสาย 2.ไม่มีสาย
public:
    HandBag():Bag() {
        setPrice(199);
        setType(1);//1.สำหรับผญ.
        
        setStrap(1);
    }
    HandBag(int s,int t, double p ,int n):Bag(t,p,n) {
        setStrap(s);
    }
    ~HandBag() {
        cout <<"\nHandBag" <<endl;
        show();
    }

    //set
    void setStrap(int s){
        if (s>0 && s<3)
        {
            strap  = s;
        } else {
            strap = 1;
        }
    }
    //get
    int getStrap(){
        return strap;
    }
    //show
    void show(){
        cout<< "strap = " <<strap <<endl;
        
    }
};

class Backpack:public Bag
{
private:
    int frame; //1.มีแผ่นรอง 2.ไม่มีแผ่นรอง
    ClothItem **keep;
    int num;
public:
    Backpack():Bag() {
        Bag::setType(2);
        Bag::setPrice(299);

        setFrame(2);
        keep = 0;
        num = 0;
    }
    Backpack(int f, int nk,int t, double p ,int n):Bag(t,p,n) {
        setFrame(f);
        setNum(nk);
        keep = 0; //ถ้ารันไม่ได้ ตรงนี้อาจจะไม่ต้องกำหนดค่าให้ keep = 0;
    }
    Backpack(Backpack& b){ //copy con
        keep = 0;
        num = 0;

        setFrame(b.getFrame());
        setNum(b.getNum());
        for (int i = 0; i < num; i++)
        {
            setKeep(i , b.getKeep(i));
        }
        
    }
    ~Backpack() {
        cout << "\nBackpack " <<endl;
        show();
        /*cout<< "frame = " <<frame <<endl;
        cout<< "num = " <<num <<endl;
        //แสดงค่าที่อยูใน keep
        for (int i = 0; i < ClothItem::getnum(); i++)
        {
            cout << "keep[" << i <<"]:" <<endl;
            cout << keep[i]->getFabric(i)->getDtail()<< endl;
        }*/
        delete[] keep;
    }
    //set
    void setFrame(int f){
        if (f>0 && f<3)
        {
            frame = f;
        } else {
            frame = 1;
        }
    }
    //overlode--------
    void setFrame(int f,int nk){
        if (f>0 && f<3)
        {
            frame = f;
        } else {
            frame = 1;
        }
        setNum(nk);
    }
    void setFrame(int f,int nk,int t, double p){
        if (f>0 && f<3)
        {
            frame = f;
        } else {
            frame = 1;
        }
        setNum(nk);
        Bag::setType(t);
        Bag::setPrice(p);
    }
    void setFrame(int f,int nk,int t, double p ,int n){
        if (f>0 && f<3)
        {
            frame = f;
        } else {
            frame = 1;
        }
        setNum(nk);
        Bag::setType(t);
        Bag::setPrice(p);
        Bag::setNum(n);
    }
    
    //----------------
    void setNum(int n){
        if (n<0)
        {
            num = 1;
        }
        
        num  = n;
        delete[] keep;
        keep = new ClothItem*[num];
    }
    void setKeep(int i, ClothItem* c){
        keep[i]  = c;
    }
    //get
    int getFrame(){
        return frame;
    }
    int getNum(){
        return num;
    }
    ClothItem *getKeep(int i){
        return keep[i];
    }
    //show
    void show(){
        cout<< "frame = " <<frame <<endl;
        cout<< "num = " <<num <<endl;
        for (int i = 0; i < num; i++)
       {
            cout << "keep[" << i <<"]:" <<endl;
            for (int j = 0; j < num; j++)
            {
                cout << keep[i]->getFabric(j)->getDtail()<< endl;
            }
       }
    }
    void showBackpack(){
        //----base-----
        Bag::showClothItem();
        cout << "type = " << Bag::getType() <<endl;
        cout << "count = " << Bag::getCount() <<endl;
        //-----------
        cout<< "frame = " <<frame <<endl;
        cout<< "num = " <<num <<endl;
       for (int i = 0; i < num; i++)
       {
            cout << "keep[" << i <<"]:" <<endl;
            for (int j = 0; j < num; j++)
            {
                cout << keep[i]->getFabric(j)->getDtail()<< endl;
            }
       }
       
       
    }

    ClothItem* operator[](int i){
        return getKeep(i);
    }

    bool operator==(Backpack& b){
        /*if ()
        {
            //
        }*/
        
    }
};

class Hat:public ClothItem
{
private:
    int uv; //1.กัน 2.ไม่กัน
    int type; //1.หมวกเบสบลอ 2.บักเก็ต 3.ปีกกว้าง
public:
    Hat():ClothItem() {
        ClothItem::setPrice(80);

        setType(2);
        setUv(2);
    }
    Hat(int t, int u, double p, int n):ClothItem(p,n) {
        setType(t);
        setUv(u);
    }
    ~Hat() {
        cout << "\nHat" <<endl;
        show();
    }

    //set
    void setUv(int u){
        if (u>0 && u<3)
        {
            uv = u;
        } else {
            uv = 1;
        } 
    }
    void setType(int t){
        if (t>0 && t<4)
        {
            type = t;
        } else {
            type = 1;
        }
    }
    //get
    int getUv(){
        return uv;
    }
    int getType(){
        return type;
    }
    //show
    void show(){
        cout << "uv = " <<uv <<endl;
        cout << "type = " <<type <<endl;
    }
};
//------------------
ostream &operator<<(ostream& os, ClothItem& c){
    c.show();
    return os;
}
//------------------

int main(){
    //---------------
    cout << "---- Declare *fabric[9] ----- "<<endl;
    Cotton c0(1,1);
    Cotton c1(2,2);
    Cotton c2(3,3);

    Linen l3(1,1);
    Linen l4(2,2);
    Linen l5(3,3);

    Polyester p6(1,2);
    Polyester p7(2,4);
    Polyester p8(1,3);

    Fabric *fabric[9] = {&c0, &c1, &c2,
                         &l3, &l4, &l5,
                         &p6, &p7, &p8};

    for (int i = 0; i < 9; i++)
    {
        fabric[i]->show();
        cout << endl;
    }
    
    //---------------

    //---------------
    //cout << "----- Delcaer * ----- "<<endl;
    HandBag *handBag1 = new HandBag();
    handBag1->setStrap(2);
    handBag1->setType(3);

    handBag1->setPrice(400);
    handBag1->setNum(2);
    handBag1->setFabric(0, fabric[2]);
    handBag1->setFabric(1, fabric[6]);


    Hat *hat1 = new Hat();
    hat1->setUv(1);
    hat1->setType(1);

    hat1->setPrice(750);
    hat1->setNum(1);
    hat1->setFabric(0, fabric[3]);
    cout <<*hat1 <<endl;


    Hat *hat2 = new Hat();
    hat2->setUv(2);
    hat2->setType(3);

    hat2->setPrice(3000);
    hat2->setNum(1);
    hat2->setFabric(0, fabric[7]);


    Backpack *backpack1 = new Backpack();
    backpack1->setFrame(1);
    backpack1->setType(2);

    backpack1->setPrice(1500);
    backpack1->ClothItem::setNum(1);
    backpack1->setFabric(0, fabric[0]);

    //เก็บของ 2 อย่าง
    backpack1->setNum(2);
    backpack1->setKeep(0, handBag1);
    backpack1->setKeep(1, hat1);
    //---------------

    //---------------
    cout << "\n----- Delcaer *item[4] ----- "<<endl;
    ClothItem *item[4] = {handBag1, hat1, hat2 ,backpack1};
    for (int i = 0; i < 4; i++)
    {
        cout << "item[" << i << "]:" <<endl;
        cout << *item[i] <<endl;
    }
    
    //---------------

    //---------------
    cout << "\n----- Delcaer p1 ----- "<<endl;
    Polyester p1(1,1);
    hat1->setNum(2);
    hat1->setFabric(1, &p1);

    cout <<*hat1 <<endl;


    //---------------
    
    //---------------
    cout << "\n----- op[] ----- "<<endl;
    int white = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << "item[" << i << "]:" <<endl;
        cout << item[i]->getFabric(i)->getColor() <<endl;
        if (item[i]->getFabric(i)->getColor() == 1)
        {
            white++;
        }
        
    }
    cout << "white = " <<white <<endl;

    //---------------

    //---------------
    cout << "\n----- *backpack2----- "<<endl;
    Backpack *backpack2 = new Backpack(*backpack1);
    cout << "backpack2:" <<endl;
    backpack2->show();

    //---------------

    //---------------
    cout << "\n----- update *backpack2----- "<<endl;
    backpack2->ClothItem::setNum(3);
    backpack2->setFabric(0, fabric[1]);
    backpack2->setFabric(1, fabric[4]);
    backpack2->setFabric(2, fabric[8]);

    backpack2->setNum(2);
    backpack2->setKeep(0, backpack1);
    backpack2->setKeep(1, hat2);
    backpack2->setType(3);
    backpack2->setPrice(3500);
    cout << *backpack2 <<endl;
    //---------------

    //---------------
    backpack2->setFrame(2,2);
    backpack2->setFrame(1,1,1,2000);
    backpack2->setFrame(1,1,1,2000, 1);
    //---------------

    //---------------
    cout << "\n----- delete ---- "<<endl;
    delete handBag1;
    delete hat1;
    delete hat2;
    delete backpack1;
    delete backpack2;
    //---------------

    cout << "\n--- end ---" <<endl;
}