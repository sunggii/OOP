#include <iostream> //op = กรณีมี atb เป็น *
#include <cstring>
using namespace std;
class Pet{
    char *name;
    int sex; 

    public:
        Pet(){
            sex = 0; name = 0;
        }
        Pet(char *n, int s){
            name = new char[strlen(n) +1]; //+1 ไว้เผื่อที่ให้ /0
            strcpy(name , n);
            sex = s;
        }
        ~Pet(){
            delete[] name;
        }

        Pet& operator= (const Pet& p){
            if (this == &p) return *this;
            sex = p.sex;
            delete[] name; //ลบของเก่าก่อน
            if (p.name != 0)
            {
                name = new char[strlen(p.name) +1];
                strcpy(name , p.name);
            }
            return *this;
        }

        void show(){
            cout <<"Name: " <<name <<endl;
            cout <<"Sex: " <<(sex? "Female" : "Male") <<endl;
        }
};

class Color{
    int x;

    public:
        Color(){
            x = 0;
        }
        Color(int i){
            x = i;
        }
        char *getColor(){
            switch (x)
            {
                case 1: return "black";
                case 2: return "brown";
                case 3: return "white";
                default: return "other";
            }
        }

        void show(){
            cout << "Color: " <<getColor() <<endl;
        }
};

class Dog: public Pet{
    char *breed;
    Color c;

    public:
        Dog(){
            breed = 0;
        }
        Dog(char *n,int s,char *b, Color j):Pet(n,s){
            c = j;
            breed = new char[strlen(b) +1];
            strcpy(breed , b);
        }
        ~Dog(){
            delete[] breed;
        }

        Dog& operator= (const Dog& d){
            if (this == &d) return *this;
            Pet::operator=(d);
            c = d.c;
            delete[] breed;
            if (d.breed != 0)
            {
                breed = new char[strlen(d.breed) +1];
                strcpy(breed , d.breed);
            }
            return *this;
        }

        void show(){
            Pet::show();
            cout << "Breed: " << breed << endl;
            c.show();
        }
};

main(){
    Dog d1("Peter", 0 , "Thai BangKeaw" , 3) , d2;
    //d2 = d1;
    d2.operator=(d1);
    d2.show();
}