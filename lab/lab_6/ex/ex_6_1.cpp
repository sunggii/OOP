#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char fname[20];
    char lname[20];

    public:
        Person(){
            setName("firstname", "lantname");
        }
        Person(char *f, char *l){
            setName(f , l);
        }

        void setName(char *f, char *l){
            strcpy(fname , f);
            strcpy(lname , l);
        }
        void showName(){
            cout << fname << " " << lname <<endl;
        }

        char* getFname(){
            return fname;
        }
        char* getLname(){
            return lname;
        }
};

class Studen: public Person{
    char id[10];

    public:
        void setId(char *i){
            strcpy(id , i);
        }
        void showId(){
            cout << "Student ID : " << id << endl;
        }
};

main(){
    Person p("Apin" , "Wa");
    //p.showName();
    cout << p.getFname()<<" "<<p.getLname() <<endl;

    Studen s;
    s.showName();
    s.setName("Yeri" , "kim");
    s.setId("12345");
    s.showName();
    s.showId();
    return 0;
}