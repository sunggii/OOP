//ตัวอย่าง aggregation
#include <iostream>
#include <cstring>
using namespace std;

class Teacher{
    char tName[10];

    public:
        Teacher(){
            settName("Noname");
        }
        Teacher(char *n){
            settName(n);
        }
        ~Teacher(){
            cout << "delete" << tName << endl;
        }
        
        void settName(char *n){
            strcpy(tName , n);
        }
        char* gettName(){
            return tName;
        }
};

class Faculty{
    char fName[20];
    Teacher **listTeacher;

    public:
        Faculty(){
            setfName("None");
            listTeacher = 0;
        }
        Faculty(char *n, Teacher **t){
            setfName(n);
            listTeacher = t;
        }
        ~Faculty(){
            cout << "delet " << fName << endl;
        }

        void setfName(char *n){
            strcpy(fName , n);
        }
        char* getfName(){
            return fName;
        }
        char* getTeacher(int i){
            return listTeacher[i]->gettName();
        }
};

main (){
    Teacher *t[3] = { new Teacher("Pawalai") , 
                      new Teacher("Sathit") ,
                      new Teacher("Ratchanee") };

    Faculty *sci = new Faculty("Science" , t);

    cout<<"====== Teacher in Faculty ======"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << sci->getTeacher(i) << endl;
    }

    cout<<"===== delete Faculty ====="<<endl;
    delete sci;

    cout<<"===== delete Teacher ====="<<endl;
    for (int i = 0; i < 3; i++)
    {
        delete t[i];
    }
    
    return 0;
}