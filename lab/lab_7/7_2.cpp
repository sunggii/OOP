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
            setName("firstname", "lastname");
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

class Student: virtual public Person{
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
        Student(char *f, char *l,Date& d, Address& a, char *i, char *fac ,char *u ):Person(f, l, d, a){
            setStudent(i,f,u);
        }
        /*
        Student(char *f, char *l,Date& d, Address& a, char *i, char *fac ,char *u ){
            setPerson(f, l, d, a);
            setStudent(i,f,u);
        }*/
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

class Teachar: virtual public Person{
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
        Teachar(char *f, char *l,Date& d, Address& a,char *fac, char *u, char *c,double s):Person(f, l, d, a){
            setTeacher(fac,u,c,s);
        }
        /*
        Teachar(char *f, char *l,Date& d, Address& a,char *fac, char *u, char *c,double s){
            setPerson(f, l, d, a);
            setTeacher(f,u,c,s);
        }*/
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

//multi
class TeachingAssistant: public Student , public Teachar{
    char nickName[10];
    char aptitude[30]; //ความถนัด

    public:
        TeachingAssistant(){
            setTA("none" , "none");
        }
        TeachingAssistant(char * n , char *ap){
            setTA(n,ap);
        }
        //--------base single ทั้ง 2 แบบ---------
        TeachingAssistant(char *i, char *fac ,char *u 
                         ,char *f, char *uni, char *c,double s
                         ,char * n , char *ap):Student(i,fac,u) , Teachar(f,uni,c,s)
        {
            setTA(n,ap);
        }
        /*
        TeachingAssistant(char *i, char *fac ,char *u 
                         ,char *f, char *uni, char *c,double s
                         ,char * n , char *ap)
        {
            setStudent(i,fac,u);
            setTeacher(f,uni,c,s);
            setTA(n,ap);
        }*/

       /*
       ----------base multipel-------------
       กรณีต้องการ set ค่าเริ่มต้นให้ Person ด้วย
       กรณี multiple inheritance ต้องสั่งแบบนี้มันถึงจะขึ้นไปทำตามที่สั่ง ไม่งั้นมันจะไปเรียก default constructor เสมอ*/
        TeachingAssistant(char *fn, char *l,Date& d, Address& a
                         ,char *i, char *fac ,char *u 
                         ,char *f, char *uni, char *c,double s
                         ,char * n , char *ap):Student(i,fac,u) , Teachar(f,uni,c,s) , Person(fn,l,d,a)
        {
            setTA(n,ap);
        }
        
        /*
        //ตามความเข้าใจในตอนแรก TA จะ set ค่าให้ Person ไม่ได้
        //เราเลยเรียก con ที่เรียกไป Person อีกที
        //จะเห็นว่าวิธีนี้ก็สามารถเข้าถึง Person ได้ 
        //แต่ Person จะถูกเรียกแบบ l defut
        TeachingAssistant(char *fn, char *l,Date& d, Address& a
                         ,char *i, char *fac ,char *u 
                         ,char *f, char *uni, char *c,double s
                         ,char * n , char *ap):Student(fn,l,d,a, i,fac,u) , Teachar(fn,l,d,a, f,uni,c,s)
        {
            setTA(n,ap);
        }*/
        ~TeachingAssistant(){
            cout << "delete TA " << nickName << endl;
        }

        //set
        void setTA(char * n , char *ap){
            strcpy(nickName , n);
            strcpy(aptitude , ap);
        }
        void setNickName(char * n ){
            strcpy(nickName , n);
        }
        void setAptitude(char *ap){
            strcpy(aptitude , ap);
        }

        //get
        char* getNickName(){
            return nickName;
        }
        char* getAptitude(){
            return aptitude;
        }

        //show
        void showTA(){
            cout << "\nTeachingAssistant" <<endl;
            cout << "nick name: " << nickName <<endl;
            cout <<"aptitude: " << aptitude <<endl;
        }
};

main(){
    //multple
    //----------------7.2---------------
    //--------------
    /*TeachingAssistant ta1;
    ta1.showPerson();
    ta1.showStudent();
    ta1.showTeacher();
    ta1.showTA();
    //--------------

   //--------------
    TeachingAssistant ta2;
    Date dTa2;
    dTa2.setDate(8,8,2005);
    Address aTa2;
    aTa2.setAddress("38 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);

    ta2.setPerson("Nekoyama", "Sui" , dTa2 , aTa2);
    ta2.setStudent("660503","Sci","RU");
    ta2.setTeacher("Science","Ramkhamhaeng","2103",35000);
    ta2.setTA("neko","Coding");

    ta2.showPerson();
    ta2.showStudent();
    ta2.showTeacher();
    ta2.showTA();
    //--------------

    //---------------
    TeachingAssistant ta3;
    Date dTa3;
    dTa3.setDay(29);
    dTa3.setMonth(8);
    dTa3.setYear(2005);

    Address aTa3;
    aTa3.setRoad("60 Ramkhamhaeng ");
    aTa3.setSubDistrict("Hua Mak");
    aTa3.setDistrict("Bang Kapi");
    aTa3.setProvince("Bangkok");
    aTa3.setZipCode(10240);

    ta3.setName("Yerim" , "Kim");
    ta3.setBday(dTa3);
    ta3.setAdd(aTa3);

    ta3.setId("660504");
    ta3.Student:: setFac("sci");
    ta3.Student:: setUnoversity("RU");

    ta3.Teachar:: setFac("Science");
    ta3.Teachar::  setUnoversity("Ramkhamhaeng");
    ta3.setCourse("2102");
    ta3.setSalary(35000);

    ta3.setNickName("yeri");
    ta3.setAptitude("Coding");

    //ta3.showPerson();
    Date resultBd = ta3.getBday(); 
    Address resultAdd = ta3.getAdd();

    cout <<"\n===== get Person =====" <<endl;
    cout<<"Person no. "<<Person::count() <<endl;
    cout << ta3.getFname() << " "<<ta3.getLname()<<" ";
    cout << resultBd.getDay() << "/" <<resultBd.getMonth() <<"/" <<resultBd.getYear() <<endl;
    cout<<"Road: "<<resultAdd.getRoad()<<endl;
    cout<<"SubDistrict: "<<resultAdd.getSubDistrict()<<endl;
    cout<<"District: "<<resultAdd.getDistrict() <<endl;
    cout<<"Province: "<<resultAdd.getProvince() <<endl;
    cout<<"zip code: " << resultAdd.getZipCode()<<endl;

    //cout <<"\n===== get Student =====" <<endl;
   cout << "\nStudent" <<endl;
   cout << "university: " << ta3.Student:: getUniversity() <<endl;
   cout << "faculty: " << ta3.Student:: getFac() <<endl;
   cout << "Student ID : " << ta3.getID() << endl;

    //cout <<"\n===== get Teacher =====" <<endl;
   cout << "\nTreacher" <<endl;
   cout << "university: " << ta3.Teachar:: getUniversity() <<endl;
   cout <<"faculty: " << ta3.Teachar:: getFac() <<endl;
   cout << "Course: "<< ta3.getCourse() << "  Salary: "<< ta3.getSalary() <<endl;

   //cout <<"\n===== get TA =====" <<endl;
    cout << "\nTeachingAssistant" <<endl;
    cout << "nick name: " << ta3.getNickName() <<endl;
    cout <<"aptitude: " << ta3.getAptitude() <<endl;*/

    //base-----------
    //---------------
    Date dTa4(13,8,2005);
    Address aTa4("26 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    TeachingAssistant ta4("660505","sci","RU",
                          "Science","Ramkhamhaeng","2101",35500,
                          "brookie" , "coding");

    ta4.showPerson();
    ta4.showStudent();
    ta4.showTeacher();
    ta4.showTA();
    //---------------

    //---------------
    Date dTa5(13,8,2005);
    Address aTa5("68 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    TeachingAssistant ta5("660505","sci","RU",
                          "Science","Ramkhamhaeng","2101",35500,
                          "mali" , "coding");

    ta5.setPerson("Apinya" , "Wa", dTa5, aTa5);

    ta5.showPerson();
    ta5.showStudent();
    ta5.showTeacher();
    ta5.showTA();
    //---------------

    //---------------
    Date dTa6(10,8,2005);
    Address aTa6("42 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    TeachingAssistant ta6("Stubaki","Fuyumi" , dTa6 , aTa6 ,
                          "660505","sci","RU",
                          "Science","Ramkhamhaeng","2101",35500,
                          "kiki" , "coding");

    ta6.showPerson();
    ta6.showStudent();
    ta6.showTeacher();
    ta6.showTA();
    //---------------
    //---------------

    //single--------
    //base
   /*Date dS1;
   dS1.setDate(9,9,2009);
   Address aS1("35 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   Student s1("miki","Urasawa",dS1,aS1,"660502","sci","Ramkhamhaeng");
   s1.showPerson();
   s1.showStudent();

   Date dT1(2,2,2005);
   Address aT1("32 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
   Teachar t1("naoki","Urasawa",dT1,aT1,"sci","Ramkhamhaeng","2103",36000);
   t1.showPerson();
   t1.showTeacher();*/
    //--------------
   cout<<"\n===== destructor ====="<<endl;
 
    return 0;
}