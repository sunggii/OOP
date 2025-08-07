#include <iostream>
#include <cstring>
using namespace std;

//-------วันเดือนปีเกิด-------
class Date{
    int day;
    int month;
    int year;

    public:
        Date(){
            setDate(0,0,0); //ถ้าเป็น int 0000 มันจะได้ 0 ตัวเดียว
        }
        Date(int d, int m, int y){
            setDate(d,m,y);
        }
        Date(int d, int m){
            setDay(d);
            setMonth(m);
            setYear(0);
        }
        Date(int d){
            setDay(d);
            setMonth(0);
            setYear(0);
        }
        ~Date(){
            cout << "dalete " << day <<"/" << month << "/" <<year << endl;
        }

    //set
        void setDate(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        void setDay(int d){
            day = d;
        }
        void setMonth(int m){
            month = m;
        }
        void setYear(int y){
            year = y;
        }

    //get
        int getDay(){
            return day;
        }
        int getMonth(){
            return month;
        }
        int getYear(){
            return year;
        }

    //show
        void showDate(){
            cout <<"\n===== show Date =====" <<endl;
            cout << day <<"/" << month << "/" <<year << endl;
        }
};

//-------ที่อยู่---------
class Address{ 
    char road[30];
    char subDistrict[30];
    char district[30];
    char province[30];
    int zipCode;
    //char addName[10];

    public:
        Address(){
            setAddress("none","none" ,"none" ,"none" ,0);
        }
        Address(char *r, char *s, char *d, char *p , int z){
            setAddress(r,s,d,p,z);
        }
        ~Address(){
            cout << "delete Address " <<endl;
        }

        //set
        void setAddress(char *r, char *s, char *d, char *p , int z){
            strcpy(road , r);
            strcpy(subDistrict , s);
            strcpy(district , d);
            strcpy(province , p);
            zipCode = z;
        }
         void setRoad(char *r){
            strcpy(road , r);
        }
        void setSubDistrict(char *s){
            strcpy(subDistrict , s);
        }
        void setDistrict(char *d){
            strcpy(district , d);
        }
        void setProvince(char *p){
            strcpy(province , p);
        }
        void setZipCode(int z){
            zipCode = z;
        }
        
        //get
         char *getRoad(){
            return road;
        }
        char *getSubDistrict(){
            return subDistrict;
        }
        char *getDistrict(){
            return district;
        }
        char *getProvince(){
            return province;
        }
        int getZipCode(){
            return zipCode;
        }

        //show
        void showAddress();
};
void Address :: showAddress(){
    cout<<"\n======== show Address ========"<<endl;
            cout<<"Road: "<<road <<endl;
            cout<<"SubDistrict: "<<subDistrict <<endl;
            cout<<"District: "<<district <<endl;
            cout<<"Province: "<<province <<endl;
            cout<<"zip code: " << zipCode<<endl;
}

class Person{
    static int num;
    char fname[20];
    char lname[20];
    Date bday;
    Address add;

    public:
        Person(){
            num++;
            setName("firstname", "lantname");
            bday.setDate(0,0,0);
            add.setAddress("none", "none" , "none" ,"none" , 0);
        }
        Person(char *f, char *l,Date& d, Address& a){
            //setName(f , l);
            num++;
            setPerson(f,l,d,a);
        }
        ~Person(){
            cout<<"delete "<<fname<<" "<<lname<<endl;
        }

        //set
        void setPerson(char *f, char *l,Date& d, Address& a){
            strcpy(fname , f);
            strcpy(lname , l);
            bday = d;
            add = a;
            
        }
        void setName(char *f, char *l){
            strcpy(fname , f);
            strcpy(lname , l);
        }
        void setBday(Date& d){
            bday = d;
        }
        void setAdd(Address& a){
            add = a;
        }

        //show
        void showPerson(){
            cout <<"\n===== show Person =====" <<endl;
            cout<<"Person no. "<<count() <<endl;
            cout << fname << " " << lname;
            cout << "  " << bday.getDay() <<"/" << bday.getMonth()<< "/" <<bday.getYear() << endl;
            cout<<"Road: "<<add.getRoad()<<endl;
            cout<<"SubDistrict: "<<add.getSubDistrict()<<endl;
            cout<<"District: "<<add.getDistrict() <<endl;
            cout<<"Province: "<<add.getProvince() <<endl;
            cout<<"zip code: " << add.getZipCode()<<endl;
        }
        void showName(){
            cout << fname << " " << lname <<endl;
        }

        //get
        char* getFname(){
            return fname;
        }
        char* getLname(){
            return lname;
        }
        Date getBday(){
            return bday;
        }
        Address getAdd(){
            return add;
        }

        static int count(){
            return num;
        }
        
};
int Person :: num;

class Student: public Person{
    char id[10];
    char fac[20];
    char university[20];

    public:
        Student(){
            setStudent("none","none","none");
        }
        Student(char *i,char *f, char *u){
            setStudent(i,f,u);
        }
        //bese
        /*Student(char *f, char *l,Date& d, Address& a, char *i, char *fac ,char *u ):Person(f, l, d, a){
            setStudent(i,f,u);
        }*/
        Student(char *f, char *l,Date& d, Address& a, char *i, char *fac ,char *u ){
            setPerson(f, l, d, a);
            setStudent(i,f,u);
        }
        ~Student(){
            cout << "bye Student" << endl;
        }

        //set
        void setStudent(char *i,char *f, char *u){
            strcpy(id , i);
            strcpy(fac , f);
            strcpy(university , u);
        }
        void setId(char *i){
            strcpy(id , i);
        }
        void setFac(char *f){
            strcpy(fac , f);
        }
        void setUnoversity(char *u){
            strcpy(university , u);
        }

        //get
        char *getID(){
            return id;
        }
        char *getFac(){
            return fac;
        }
        char *getUniversity(){
            return university;
        }

        //show
        void showStudent(){
            //cout <<"===== show Student =====" <<endl;
            cout << "\nStudent" << endl;
            cout << "university: " << university << endl;
            cout << "faculty: " << fac << endl;
            cout << "Student ID : " << id << endl;
        }
        void showId(){
            cout << "Student ID : " << id << endl;
        }
};

class Teachar: public Person{
    char fac[20];
    char university[20];
    char course[10];
    double salary;

    public:
        Teachar(){
            setTeacher("none","none","none",0.0);
        }
        Teachar(char *f, char *u, char *c,double s){
            setTeacher(f,u,c,s);
        }
        //base
        /*
        Teachar(char *f, char *l,Date& d, Address& a,char *fac, char *u, char *c,double s):Person(f, l, d, a){
            setTeacher(fac,u,c,s);
        }*/
        Teachar(char *f, char *l,Date& d, Address& a,char *fac, char *u, char *c,double s){
            setPerson(f, l, d, a);
            setTeacher(f,u,c,s);
        }
        ~Teachar(){
            cout << "bey Teacher" <<endl;
        }

        //set
        void setTeacher(char *f, char *u, char *c,double s){
            strcpy(fac , f);
            strcpy(university , u);
            strcpy(course , c);
            salary = s;
        }
        void setFac(char *a){
            strcpy(fac , a);
        }
        void setUnoversity(char *b){
            strcpy(university , b);
        }
        void setCourse(char *c){
            strcpy(course , c);
        }
        void setSalary(double s){
            salary = s;
        }

        //get
        char *getFac(){
            return fac;
        }
        char *getUniversity(){
            return university;
        }
        char *getCourse(){
            return course;
        }
        double getSalary(){
            return salary;
        }

        //show
        void showTeacher(){
            //cout <<"\n===== show Teacher =====" <<endl;
            cout << "\nTreacher" <<endl;
            cout << "university: " << university <<endl;
            cout <<"faculty: " << fac <<endl;
            cout << "Course: "<< course << "  Salary: "<< salary <<endl;
        }
};

main(){
    //inherlit Student---------------
   /*Person p1;
   p1.showPerson();

   Student s1;
   Date dS1;
   dS1.setDay(9);
   dS1.setMonth(1);
   dS1.setYear(2005);

   Address aS1;
   aS1.setRoad("68 Ramkhamhaeng ");
   aS1.setSubDistrict("Hua Mak");
   aS1.setDistrict("Bang Kapi");
   aS1.setProvince("Bangkok");
   aS1.setZipCode(10240);

   s1.setName("Apin","Wa");
   s1.setBday(dS1);
   s1.setAdd(aS1);
   s1.setId("660500");
   s1.setFac("sci");
   s1.setUnoversity("Ramkhamhaeng");

   s1.showPerson();
   s1.showStudent();

   Student s2;
   s2.setStudent("660501","sci","Ramkhamhaeng");
   Date dS2;
   dS2.setDate(5,5,2005);
   Address aS2;
   aS2.setAddress("282 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   s2.setPerson("Rie","Ko",dS2,aS2);
   s2.showPerson();
   //cout <<"\n===== get Student =====" <<endl;
   cout << "\nStudent" <<endl;
   cout << "university: " << s2.getUniversity() <<endl;
   cout << "faculty: " << s2.getFac() <<endl;
   cout << "Student ID : " << s2.getID() << endl;*/

   //base
   Date dS3;
   dS3.setDate(9,9,2009);
   Address aS3("35 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   Student s3("miki","Urasawa",dS3,aS3,"660502","sci","Ramkhamhaeng");
   s3.showPerson();
   s3.showStudent();

   //-----------------

   //inherlit Teacher----------------
    /*Date dP2(6,2,2005);
    Address aP2("282 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Person p2("yeri","Kim",dP2,aP2);
    //p2.showPerson();
    Date resultBd = p2.getBday(); 
    Address resultAdd = p2.getAdd();

    cout <<"\n===== get Person =====" <<endl;
    cout<<"Person no. "<<Person::count() <<endl;
    cout << p2.getFname() << " "<<p2.getLname()<<" ";
    cout << resultBd.getDay() << "/" <<resultBd.getMonth() <<"/" <<resultBd.getYear() <<endl;
    cout<<"Road: "<<resultAdd.getRoad()<<endl;
    cout<<"SubDistrict: "<<resultAdd.getSubDistrict()<<endl;
    cout<<"District: "<<resultAdd.getDistrict() <<endl;
    cout<<"Province: "<<resultAdd.getProvince() <<endl;
    cout<<"zip code: " << resultAdd.getZipCode()<<endl;

    
    Teachar t1;
    Date dT1;
    dT1.setDay(1);
    dT1.setMonth(2);
    dT1.setYear(2005);

    Address aT1;
   aT1.setRoad("68 Ramkhamhaeng ");
   aT1.setSubDistrict("Hua Mak");
   aT1.setDistrict("Bang Kapi");
   aT1.setProvince("Bangkok");
   aT1.setZipCode(12040);

   t1.setName("joy","Full");
   t1.setBday(dT1);
   t1.setAdd(aT1);
   t1.setFac("sci");
   t1.setUnoversity("Ramkhamhaeng");
   t1.setCourse("2102");
   t1.setSalary(35000);

   t1.showPerson();
   t1.showTeacher();


   Teachar t2;
   t2.setTeacher("sci","Ramkhamhaeng","2103",35000);
   Date dT2;
   dT2.setDate(5,5,2005);
   Address aT2;
   aT2.setAddress("282 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   t2.setPerson("Rie","Ko",dT2,aT2);
   t2.showPerson();
   //cout <<"\n===== get Teacher =====" <<endl;
   cout << "\nTreacher" <<endl;
   cout << "university: " << t2.getUniversity() <<endl;
   cout <<"faculty: " << t2.getFac() <<endl;
   cout << "Course: "<< t2.getCourse() << "  Salary: "<< t2.getSalary() <<endl;*/

    //base
   Date dT3(2,2,2005);
   Address aT3("32 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   Teachar t3("naoki","Urasawa",dT3,aT3,"sci","Ramkhamhaeng","2103",36000);
   t3.showPerson();
   t3.showTeacher();
   //-------------------

   //Date-----------
   /*cout <<"\n:: Teast Date ::";
   Date d1;
   d1.showDate();

   Date d2(6,2,2005);
   cout <<"\n===== get Date =====" <<endl;
   cout << d2.getDay() << "/" <<d2.getMonth() << "/" <<d2.getYear() <<endl;

   Date d3;
   d3.setDate(4,12,1994);
   d3.showDate();

   Date d4;
   d4.setDay(1);
   d4.setMonth(1);
   d4.setYear(2005);
   cout <<"\n===== get Date =====" <<endl;
   cout << d4.getDay() << "/" <<d4.getMonth() << "/" <<d4.getYear() <<endl;

   Date d5(12,1);
   d5.showDate();

   Date d6(15);
   cout <<"\n===== get Date =====" <<endl;
   cout << d6.getDay() << "/" <<d6.getMonth() << "/" <<d6.getYear() <<endl;*/
   //--------------

   //Address-----------
   /*cout <<"\n:: Teast Address ::";
   Address a1;
   a1.showAddress();

   Address a2("282 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   cout <<"\n===== get Address =====" <<endl;
   cout << "Road: " << a2.getRoad() <<endl;
   cout << "SubDistrict: " << a2.getSubDistrict() <<endl;
   cout << "District: " << a2.getDistrict()<<endl;
   cout << "Province: " << a2.getProvince() <<endl;
   cout << "zip code:" << a2.getZipCode() <<endl;

   Address a3;
   a3.setAddress("66 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   a3.showAddress();

   Address a4;
   a4.setRoad("68 Ramkhamhaeng");
   a4.setSubDistrict("Hua Mak");
   a4.setDistrict("Bang Kapi");
   a4.setProvince("Bangkok");
   a4.setZipCode(10240);

   cout <<"\n===== get Address =====" <<endl;
   cout << "Road: " << a4.getRoad() <<endl;
   cout << "SubDistrict: " << a4.getSubDistrict() <<endl;
   cout << "District: " << a4.getDistrict()<<endl;
   cout << "Province: " << a4.getProvince() <<endl;
   cout << "zip code:" << a4.getZipCode() <<endl;*/
   //------------------

   cout<<"\n===== destructor ====="<<endl;
 
    return 0;
}