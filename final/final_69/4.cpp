#include <iostream>
#include <string>
using namespace std;

class Material
{
private:
    double price;
public:
    Material(){
        setPrice(1);
    }
    Material(double p) {
        setPrice(p);
    }
    virtual~Material() {cout << "~Material"; showMaterial();}
    virtual void show() = 0;
    virtual string getType() = 0;

    //set
    void setPrice(double p){
        if (p >= 0)
        {
            price = p;
        } else {
            price = 1;
        }
        
    }
    //get
    double getPrice(){
        return price;
    }
    //show
    void showMaterial(){
        cout << "price = " <<price <<endl;
    }
};

class Gem :public Material
{
private:
    int type; //1เพชร 2.ทับทิม 3.ไพลิน 4.หยก 5.นิล
public:
    Gem():Material() {
        setType(1);
    }
    Gem(int t, double p):Material(p) {
        setType(t);
    }
    ~Gem() {cout << "~Gem"; show();}

    //set
    void setType(int t){
        if (t>0 && t<6)
        {
            type = t;
        } else {
            type = 1;
        }
        
    }
    //get
    string getType(){
        switch (type)
        {
        case 1: return "Gem: petch";
        case 2: return "Gem: tabtim";
        case 3: return "Gem: pilin";
        case 4: return "Gem: yok";
        case 5: return "Gem: nil";
        }
    }
    //show
    void showGem(){
        cout <<"type = " << getType() <<endl;
    }
    void show(){
        Material::showMaterial();
        showGem();
    }
};

class Glod :public Material
{
private:
    int type; //1.9k 2.10k 3.14k 4.18k 5.20k
public:
    Glod():Material() {
        setType(1);
    }
    Glod(int t, double p):Material(p) {
        setType(t);
    }
    ~Glod() {cout << "~Glod"; show();}

    //set
    void setType(int t){
        if (t>0 && t<6)
        {
            type = t;
        } else {
            type = 1;
        }
        
    }
    //get
    string getType(){
        switch (type)
        {
        case 1: return "Glod: 9k";
        case 2: return "Glod: 10k";
        case 3: return "Glod: 14k";
        case 4: return "Glod: 18k";
        case 5: return "Glod: 20k";
        }
    }
    //show
    void showGlod(){
        cout <<"type = " << getType() <<endl;
    }
    void show(){
        Material::showMaterial();
        showGlod();
    }
};
//------------------
ostream &operator<<(ostream &os , Material& m){
    m.show();
    return os;
}
//------------------

class Jewelry
{
private:
    double pay;  //ค่าแรง
    Material **m;
    int num;
    static int count;
public:
    Jewelry() {
        count++;
        setPay(1);
        m = 0;
        num = 0;
    }
    Jewelry(int p) {
        count++;
        setPay(p);
        m = 0;
        num = 0;
    }
    virtual~Jewelry() { 
        count--;
        cout << "~Jewelry"; showJewelry();
        delete[] m;
    }
    virtual void show() = 0;
    virtual string getType() = 0;

    //set
    void setPay(int p){
        if (p >= 0)
        {
            pay = p;
        } else {
            pay = 0;
        }
    }
    void setNum(int n){
        if (n == num)
        {
            return;
        }
        if (n < 0)
        {
            num = 1;
        }

        delete[] m;
        num = n;
        m = new Material *[num];
    }
    void setM(int i, Material* x){
        m[i] = x;
    }
    //get
    int getPay(){
        return pay;
    }
    int getNum(){
        return num;
    }
    Material *getM(int i){
        return m[i];
    }
    double getPrice(){ //หาราคารวม
        double total = 0;
        for (int i = 0; i < num; i++)
        {
           total +=  m[i]->getPrice();
        }
        return total + getPay();
    }
    static int getCount(){
        return count;
    }
    //show
    void showJewelry(){
        cout << "pay = " << pay <<endl;
        cout << "num = "  <<num <<endl;
        for (int i = 0; i < num; i++)
        {
            m[i]->show();
        }
        
    }

    string operator!(){
        return getType();
    }

};
int Jewelry::count;

class Necklace :public Jewelry
{
private:
    int type; //1.มีจี้ 2.ไม่มีจี้
public:
    Necklace():Jewelry() {
        setType(1);
    }
    Necklace(int t, int p):Jewelry(p) {
        setType(t);
    }
    ~Necklace() {cout << "~Necklace "; show();}

    //set
    void setType(int t){
        if (t>0 && t<3)
        {
            type = t;
        } else {
            type = 1;
        }
    }
    //get
    string getType(){
        switch (type)
        {
        case 1: return "Necklace: have jee";
        case 2: return "Necklace: not have jee";
        }
    }
    //show
    void showNecklace(){
        cout << "type = " <<getType() <<endl;
    }
    void show(){
        Jewelry::showJewelry();
        showNecklace();
    }
};

class Earring :public Jewelry
{
private:
    int type; //1.แบบแป้น 2.แบบห่วง 3.แบบระย้า
public:
    Earring():Jewelry() {
        setType(1);
    }
    Earring(int t, int p):Jewelry(p) {
        setType(t);
    }
    ~Earring() {cout << "~Earring "; show();}

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
    string getType(){
        switch (type)
        {
        case 1: return "Earring: pan";
        case 2: return "Earring: hoop";
        case 3: return "Earring: rayaa";
        
        }
    }
    //show
    void showEarring(){
        cout << "type = " <<getType() <<endl;
    }
    void show(){
        Jewelry::showJewelry();
        showEarring();
    }
};

class Ring :public Jewelry
{
private:
    int type; //1.มีหัว 2.ไม่มีหัว
public:
    Ring():Jewelry() {
        setType(1);
    }
    Ring(int t ,int p):Jewelry(p) {
        setType(t);
    }
    ~Ring() {
        cout << "~Ring "; show();
    }

    //set
    void setType(int t){
        if (t>0 && t<3)
        {
            type = t;
        } else {
            type = 1;
        }
    }
    //get
    string getType(){
        switch (type)
        {
        case 1: return "Ring: have hua";
        case 2: return "Ring: not have hua";
        }
    }
    //show
    void showRing(){
        cout << "type = " <<getType() <<endl;
    }
    void show(){
        Jewelry::showJewelry();
        showRing();
    }
};
//---------------------
ostream &operator<<(ostream &os , Jewelry& j){
    j.show();
    return os;
}
//---------------------


class Box
{
private:
    Jewelry **jew;
    int num;
    int color; //1.ดำ 2.แดง 3.ขาว 4.ชมพู
public:
    Box() {
        jew = 0;
        num = 0;
        setColor(1);
    }
    Box(int c) {
        jew = 0;

        setColor(c);
    }
    Box(Box& b) {
        jew = 0;
        num = 0;
        setColor(b.getColor());
        setNum(b.getNum());
        for (int i = 0; i < num; i++)
        {
            setJew(i , b.getJew(i));
        }
        
    }
    ~Box() {
        cout << "~Box "; showBox();
        delete[] jew;
    }

    //set
    void setNum(int n){
        if (n == num)
        {
            return;
        }
        if (n < 0)
        {
            num = 1;
        }

        delete[] jew;
        num = n;
        jew = new Jewelry *[num];
    }
    void setJew(int i,Jewelry* j ){
        jew[i] = j;
    }
    void setColor(int c){
        if (c>0 && c<5)
        {
            color = c;
        } else {
            color = 1;
        }
    }
    //get
    int getColor(){
        return color;
    }
    int getNum(){
        return num;
    }
    Jewelry *getJew(int i){
        return jew[i]; 
    }
    double getPrice(){ //หาราคารวม
    //cout << "num = " << num  <<endl;
        double total = 0;
        for (int i = 0; i < num; i++)
        {
           total +=  jew[i]->getPrice();
        }
        return total;
    }
    //show
    void showBox(){
        cout << "color = " << color <<endl;
        cout << "num = " <<num <<endl;
        for (int i = 0; i < num; i++)
        {
            cout << "jew[" <<i << "]:" <<endl;
            jew[i]->showJewelry();
            cout <<endl;
        }
        
    }
    void showBox(int){
        cout << "color = " << color <<endl;
        cout << "num = " <<num <<endl;
        
    }

    Jewelry *operator[](int i){
        getJew(i);
    }
    operator double(){
        getPrice();
    }


};

int main(){
    //----------------
    cout << "\n----- Declaer *a[8] -----" <<endl;
    Gem petch(1,30000);
    Gem tabtim(2,25000);
    Gem pilin(3,15000);
    Gem yok(4,1000);
    Gem nil(5,400);
    Glod g1(4,20000);
    Glod g2(3,10000);
    Glod g3(2,5000);
    Material *a[8] = {&petch, &tabtim, &pilin, &yok, &nil, &g1, &g2, &g3};

    for (int i = 0; i < 8; i++)
    {
        cout << *a[i] <<endl;
    }
    
    //----------------

    //----------------
    cout <<"\n----- delcaer *w[3]-----" <<endl;
    Necklace n1(1,2500);
    n1.setNum(2);
    n1.setM(0, a[5]);
    n1.setM(1, a[0]);

    Earring e1(2,1500);
    e1.setNum(2);
    e1.setM(0, a[5]);
    e1.setM(1, a[2]);

    Ring r1(1, 900);
    r1.setNum(2);
    r1.setM(0, a[6]);
    r1.setM(1, a[3]);

    Jewelry *w[3] = {&n1, &e1, &r1};

    for (int i = 0; i < 3; i++)
    {
        w[i]->show();
        cout << endl;
    }
    //----------------

    //----------------
    cout <<"\n----- delcaer Box[2] -----" <<endl;
    Box b[2];
    b[0].setColor(4);
    b[0].setNum(2);
    b[0].setJew(0, w[0]);
    b[0].setJew(1, w[1]);

    b[1].setColor(1);
    b[1].setNum(1);
    b[1].setJew(0, w[2]);
    
    for (int i = 0; i < 2; i++)
    {
        cout << "b[" << i << "]:" <<endl;
        b[i].showBox();
        cout << endl;
    }
    //----------------

    //----------------
    cout <<"----- get Type -----" <<endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "b[" << i << "]:" <<endl;
        for (int j = 0; j < b[i].getNum(); j++)
        {
            cout << b[i].getJew(j)->getType() <<endl;
        }
        
    }
    //----------------

    //----------------
    /*cout <<"----- get Type[] -----" <<endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "b[" << i << "]:" <<endl;
        for (int j = 0; j < b[i].getNum(); j++)
        {
            cout << b[i][j] <<endl;
        }
        
    }*/
    //----------------

    //----------------
    cout <<"\n----- total price in Box -----" <<endl;
    cout <<"b[0]:   " << b[0].getPrice() <<endl;
    cout <<"b[1]:   " << b[1].getPrice() <<endl;
    cout << "total: "<< b[0].getPrice() + b[1].getPrice();
    //----------------

    //----------------
    cout <<"\n----- total price in Box -----" <<endl;
    double totalM = 0;
    double totalP = 0;
    double net = 0;
    for (int i = 0; i < 2; i++)
    {
        cout << "b[" << i << "]:" <<endl;
        for (int j = 0; j < b[i].getNum(); j++)
        {
            totalP +=  b[i].getJew(j)->getPay();
            cout << "total pay = " << b[i].getJew(j)->getPay() <<endl;
            for (int k = 0; k < b[i].getJew(j)->getNum(); k++)
            {
                totalM += b[i].getJew(j)->getM(k)->getPrice();
                cout << "total price = " << b[i].getJew(j)->getM(k)->getPrice() <<endl;
            }
            
        }
        net += totalM + totalP;
        cout <<"net = " << totalM + totalP <<endl;
    }
    cout << "price in b[0] + b[1] = " <<net <<endl;
    
    //----------------

    //----------------
    cout <<"\n----- delete -----" <<endl;
    cout <<"d[2]:";delete b;
    //----------------

    cout <<"\n----- end -----" <<endl;
}