//ตัวอย่าง composition
#include <iostream>
#include <cstring>
using namespace std;

class Department{
    char dname[20];

    public:
        Department(){
            setDname("None");
        }
        Department(char *n){
            setDname(n);
        }
        ~Department(){
            cout << "delete" << dname << endl;
        }

        void setDname(char *n){
            strcpy(dname , n);
        }
        char* getDname(){
            return dname;
        }
};

class Faculty{
    char fname[20];
    int num;
    Department *listDepartment;

    public:
        Faculty(){
            setFname("None");
            num = 0;
            listDepartment = 0;
        }
        Faculty(char *n, int x ,char d[3][20]){
            setFname(n);
            num = x;

            listDepartment = new Department[num];
            for (int i = 0; i < num; i++)
            {
                listDepartment[i].setDname(d[i]);
            }
            
        }
        ~Faculty(){
            delete[] listDepartment;
            cout << "delete "<< fname << endl;
        }

        void setFname(char *n){
            strcpy(fname , n);
        }
        char* getFname(){
            return fname;
        }
        char* getDepartment(int i){
            return listDepartment[i].getDname();
        }
};

main(){
    char d[3][20];

    strcpy(d[0], "Computer Science");
    strcpy(d[1], "Mathematics");
    strcpy(d[2], "Chemistry");

    Faculty *sci = new Faculty("Science" , 3 , d);

    cout<<"==== Department in Faculty ===="<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << sci->getDepartment(i) << endl;
    }

    cout<<"\n==== delete Faculty ===="<<endl;
    delete sci;

    return 0;
}