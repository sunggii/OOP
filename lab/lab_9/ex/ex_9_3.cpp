#include <iostream> //coppy constructer
#include <cstring>
using namespace std;
class Pet{
    char *name;
    int sex; 

    public:
        Pet(){
            sex = 0; name = "none";
        }
        Pet(char *n, int s){
            name = new char[strlen(n) +1]; //+1 ไว้เผื่อที่ให้ /0
            strcpy(name , n);
            sex = s;
        }
        ~Pet(){
            delete[] name;
        }

        //coppy con------------
        Pet(const Pet& p){
            cout <<"\nPet ::coppy constructer is called" <<endl;
            sex = p.sex;
            if (p.name != 0)
            {
                name = new char[strlen(p.name) +1]; //+1 ไว้เผื่อที่ให้ /0
                strcpy(name , p.name);
            }
            
        }
        //---------------------

        //obj ที่ return , obj ที่เป็น para จะมาเรียก coppy con
        Pet myPet(Pet p){
            p.show();
            return p;
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

        //coppy con------------
        /*Dog(const Dog& d){
            //cout <<"\nDog::coppy constructer is called" <<endl;
            Pet::operator=(d);
            
            c = d.c;
            if(d.breed != 0){
                breed = new char[strlen(d.breed) +1];
                strcpy(breed , d.breed);
            }
        }*/
       
        //เขียนได้ 2 แบบ
        Dog(const Dog& d):Pet(d), c(d.c){
            //cout <<"\nDog::coppy constructer is called" <<endl;
            if(d.breed != 0){
                breed = new char[strlen(d.breed) +1];
                strcpy(breed , d.breed);
            }
        }
        //---------------------

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
    Pet p;
    p.show();
    Pet p1("Pukpui" , 1);
    Pet p2 = p1;
    p2.show();
    p2.myPet(p1);
}