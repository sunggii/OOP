//ตัวอย่าง association
#include <iostream>
#include <cstring> //cstring เหมือน string.h
using namespace std;

class Student{
    char sName[20];

    public:
        Student(){
            setsName("Noname");
        }
        Student(char *n){
            setsName(n);
        }
        ~Student(){
            cout << sName << endl;
        }

        void setsName(char *n){
            strcpy(sName , n);
        }
        char* getsNmae(){
            return sName;
        }
};

class Course{
    char id[20];

    public:
        Course(){
            setCourse("COSxxxx");
        }
        Course(char *n){
            setCourse(n);
        }
        ~Course(){
            cout << id << endl;
        }

        void setCourse(char *n){
            strcpy(id, n);
        }
        char* getId(){
            return id;
        }
};

class Enrollment{
    Student *std;
    Course *cos;
    char term[10];

    public:
        Enrollment(Student *s, Course *c, char *t): std(s) , cos(c){
            //s->setsName(s);
            //cos->setCourse(c);
            setTerm(t);
            printEnrollment();

        }

        void setTerm(char *n){
            strcpy(term , n);
        }
        void printEnrollment(){
            cout<<"\nName : "<<std->getsNmae()<<endl;
            cout<<"Course : "<<cos->getId()<<endl;
            cout<<"Term : "<<term<<endl;
        }
};

main(){
    Student *s[2] = {new Student("Apin") ,
                     new Student("yeri")};

    Course *c[3] = {new Course("COS2101") ,
                    new Course("COS2102") ,
                    new Course("COS2103")};

    Enrollment e1(s[0] , c[0] , "1/57");
    Enrollment e2(s[0] , c[1] , "1/57");
    Enrollment e3(s[1] , c[0] , "1/57");
    Enrollment e4(s[1] , c[1] , "2/57");
    Enrollment e5(s[1] , c[2] , "2/57");


    cout<<"\n===== delete Course ===== "<<endl;
    for (int i = 0; i < 3; i++)
    {
        delete c[i];
    }

    cout<<"\n===== delete Student ===== "<<endl;
    for (int i = 0; i < 3; i++)
    {
        delete s[i];
    }
    
    return 0;
}