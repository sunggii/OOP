#include <iostream>
using namespace std;

class Meat
{
private:
    int type; // 1.หมู 2.ไก่ 3.ปลา 4.กุ้ง 5.หมึก 6.หอย
public:
    Meat() {
        type = 1;
    }
    Meat(int t) {
        setType(t);
    }
    ~Meat() {
        cout << "\n~Meat" <<endl;
        cout << "type = " <<type<<endl;
    }

    //set
    void setType(int t){
        if (t>0 && t<7)
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
};

class Vegetable
{
private:
    string name;

public:
    Vegetable() {
        name = " ";
    }
    Vegetable(string n) {
        name = n;
    }
    ~Vegetable() {
        cout << "\n~Vegetable" <<endl;
        cout << "nmee = " <<name <<endl;
    }

    //get
    string getName(){
        return name;
    }
};

class Food
{
private:
    double price;
    Meat *meat;
    int meatNum;
    Vegetable *veg;
    int vegNum;
    static int count;

public:
    Food() {
        count++;
        price = 99;
        meat = 0;
        veg = 0;
        meatNum = vegNum = 0;
    }
    Food(double p) {
        count++;
        setPrice(p);
        meat = 0;
        veg = 0;
        meatNum = vegNum = 0;
    }
    ~Food() {
        cout <<"\n~Food" <<endl;
        count--;
        cout << "count = " << count <<endl;
        cout << "price = " << price <<endl;
        cout << "meatNum = " << meatNum  <<endl;
        for (int i = 0; i < meatNum ; i++)
        {
           cout << meat[i].getType();
        }
        cout << "vegNum = " << vegNum <<endl;
        for (int i = 0; i < vegNum; i++)
        {
           cout << veg[i].getName();
        }
        delete[] meat;
        delete[] veg;
    }

    //set
    void setPrice(double p){
        if (p>= 0)
        {
            price = p;
        } else {
            price = 1;
        }
    }
    void setMeatNum(int m){
        if (m>= 0)
        {
            meatNum = m;
        } else {
            meatNum = 1;
        }
        
        delete[] meat;
        meat = new Meat[meatNum];
    }
    void setMeat(int i, Meat& m){
        meat[i] = m;
    }
    void setVegNum(int s){
        if (s>= 0)
        {
            vegNum = s;
        } else {
            vegNum = 1;
        }
        
        delete[] veg;
        veg = new Vegetable[vegNum];
    }
    void setVeg(int i, Vegetable& v){
        veg[i] = v;
    }

    //get
    double getPrice(){
        return price;
    }
    int getMeatNum(){
        return meatNum;
    }
    Meat getMeat(int i){
        return meat[i];
    }
    int getVegNum(){
        return vegNum;
    }
    Vegetable getVeg(int i){
        return veg[i];
    }
    static int getCount(){
        return count;
    }
};
int Food::count;

class Soup : public Food
{
private:
    int type;      // 1.ต้มยำ 2.แกงส้ม 3.ต้มโคลง 4.โป๊ะแตก
    int spicyLevel; // 1ไม่เผ็ด 2.น่อย 3.กลาง 4.มาก
public:
    Soup() {
        type = spicyLevel = 1;
    }
    Soup(int t, int s, double p):Food(p) {
        setType(t);
        setSpicyLevel(s);
    }
    ~Soup() {
        cout <<"\n~Soup" <<endl;
        show();
    }

    //set
    void setType(int t){
        if (t>0 && t<5)
        {
            type = t;
        } else {
            type = 1;
        }
    }
    void setSpicyLevel(int s){
        if (s>0 && s<5)
        {
            spicyLevel = s ;
        } else {
            spicyLevel = 1;
        }
        
    }
    //get
    int getType(){
        return type;
    }
    //show
    void show(){
        cout << "price = " << getPrice() <<endl;
        cout << "meatNum = " << getMeatNum() <<endl;
        if(getMeatNum() != 0 ){
            for (int i = 0; i < getMeatNum(); i++)
            {
                cout << getMeat(i).getType();
            }
        }
        cout << "vegNum = " << getVegNum() <<endl;
        if (getVegNum() != 0)
        {
            for (int i = 0; i < getMeatNum(); i++)
            {
            cout << getVeg(i).getName();
            }
        }
        
        cout << "type = " <<type <<endl;
        cout << "spicyLevel = " << spicyLevel <<endl;
    }
};

class Kaopad : public Food
{
private:
    int type; // 1.จานเล็ก 2.จานใหญ่
public:
    Kaopad() {
        type = 1;
    }
    Kaopad(int t, double p):Food(p){
        setType(t);
    }
    ~Kaopad() {
        cout << "\n~Kaopad "<<endl;
        cout << "price = " << getPrice() <<endl;
        cout << "meatNum = " << getMeatNum() <<endl;
        showMeat();
        cout << "vegNum = " << getVegNum() <<endl;
        for (int i = 0; i < getMeatNum(); i++)
        {
           cout << getVeg(i).getName();
        }
        cout << "type = " <<type <<endl;
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
    int getType(){
        return type;
    }

    bool isMoreExpensiveThan(Kaopad& k){
        if (getPrice() > k.getPrice() )
        {
            return true;
        } else {
            return false;
        }
    }

    void showMeat(){
        for (int i = 0; i < getMeatNum(); i++)
        {
           cout << getMeat(i).getType();
        }
    }
};

int main(){
    //-------------
    cout << "\n----- Declare s[2] ------" <<endl;
    Meat m1(4);
    Meat m2(5);
    Meat m3(6);
    Meat m4(3);

    Vegetable v1("malago");
    Vegetable v2("tuafacyao");


    Soup s1(1,4,250); 
    s1.setMeatNum(3);
    s1.setMeat(0,m1);
    s1.setMeat(1,m2);
    s1.setMeat(2,m3);

    Soup s2(2,3,100);
    s2.setMeatNum(1);
    s2.setMeat(0, m4);
    s2.setVegNum(2);
    s2.setVeg(0, v1);
    s2.setVeg(1, v2);

    Soup s[2] = {s1 , s2};

    for (int i = 0; i < 2; i++)
    {
        cout << "s[" << i << "]:" <<endl;
        s[i].show();
    }
    //-------------

    //-------------
    cout << "\n----- Declare k ------" <<endl;
    Meat m5(1);

    Vegetable v3("carrot");
    Vegetable v4("tonhom");

    Kaopad k(2,120);
    k.setMeatNum(1);
    k.setMeat(0 , m5);
    k.setVegNum(2);
    k.setVeg(0 , v3);
    k.setVeg(1 , v4);
    //-------------

    //-------------
    
    
    //-------------
    cout <<"\n----- end -----" <<endl;
}
