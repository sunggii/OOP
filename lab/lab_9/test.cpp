#include <iostream>
#include <cstring>
using namespace std;

//-------วันเดือนปีเกิด-------
class Date
{
    int day;
    int month;
    int year;
    char *nameDay; // sunday , monday

public:
    Date()
    {
        nameDay = 0;
        setDate(0, 0, 0); // ถ้าเป็น int 0000 มันจะได้ 0 ตัวเดียว
    }
    Date(int d, int m, int y, char *n)
    {
        nameDay = new char[strlen(n) + 1];
        strcpy(nameDay, n);

        setDate(d, m, y);
    }
    Date(int d, int m)
    {
        setDay(d);
        setMonth(m);
        setYear(0);
        nameDay = 0;
    }
    Date(int d)
    {
        setDay(d);
        setMonth(0);
        setYear(0);
        nameDay = 0;
    }
    ~Date()
    {
        //cout << "dalete " << day << "/" << month << "/" << year << endl;
        delete[] nameDay;
    }
    // coppy con------------
    Date(const Date &d)
    {
        //cout << "\nDate::coppy constructer" << endl;
        setDate(d.day,d.month,d.year);

        if (d.nameDay != 0)
        {
            nameDay = new char[strlen(d.nameDay) + 1];
            strcpy(nameDay, d.nameDay);
        }
        else{
            cout << "nameDay = 0" <<endl;
            nameDay = 0;
        }
    }
    //---------------------

    // set
    void setDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
    void setNameDay(char *n){
        if (nameDay != 0)
        {
            delete[] nameDay;
        }
        nameDay = new char[strlen(n) +1];
        strcpy(nameDay , n);
        
    }

    // get
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
    char *getNameDay(){
        return nameDay;
    }

    // show
    void showDate()
    {
        if (nameDay != 0)
        {
           cout << " " << nameDay << " " << day << "/" << month << "/" << year << endl;
        } else {
            cout << "none " << day << "/" << month << "/" << year << endl;
        }
        
    }

    // lab 9------------
    // operator =
    Date& operator=(const Date &d)
    {
        if (this == &d){
            cout <<"\nsame obj";
            return *this; // เช็คว่าเป็นตัวเดียวกันแล้วยัง
        }
        setDate(d.day,d.month,d.year);

        if (d.nameDay != 0)
        {
            setNameDay(d.nameDay);
        }
        else{
            cout << "\nnameDay = 0";
            nameDay = 0;
        }
        return *this;
    }

    // ostream , istream
    friend ostream &operator<<(ostream &os, const Date &d);
    friend istream &operator>>(istream &is, Date &r);
    //-----------------
};

//-------------------
// ostream
ostream &operator<<(ostream &os, const Date &d)
{
    if (d.nameDay != 0)
    {
        os <<" " << d.nameDay << " " << d.day << "/" << d.month << "/" << d.year << endl;
    } else {
        os << " " << d.day << "/" << d.month << "/" << d.year << endl;
    }
    
    return os;
}

// istream
istream &operator>>(istream &is, Date &d)
{
    char nd[10]; //Wednesday +\0 ตัวที่ยาวที่สุด
    cout << "Enter name day: ", is >> nd; d.setNameDay(nd);
    cout << "Enter day: ", is >> d.day;
    cout << "Enter mont: ", is >> d.month;
    cout << "Enter year: ", is >> d.year;
    return is;
}
//-------------------

//-------ที่อยู่---------
class Address
{
    char *road;
    char *subDistrict;
    char *district;
    char *province;
    int zipCode;

public:
    Address()
    {
        road = subDistrict = district = province = 0;
        setZipCode(0);
    }
    Address(char *r, char *s, char *d, char *p, int z)
    {
        road = new char[strlen(r) +1];
        strcpy(road, r);

        subDistrict = new char[strlen(s) +1];
        strcpy(subDistrict, s);

        district = new char[strlen(d) +1];
        strcpy(district , d);

        province = new char[strlen(p) +1];
        strcpy(province , p);

        setZipCode(z);
        //setAddress(r, s, d, p, z);
    }
    ~Address()
    {
        //cout << "delete Address " << endl;
        delete[] road;
        delete[] subDistrict;
        delete[] district;
        delete[] province;
    }
    // coppy con------------
    Address(const Address &a)
    {
        //cout << "\nAddress::coppy constructer" << endl;
        setZipCode(a.zipCode);

        if (a.road != 0)
        {
            road = new char[strlen(a.road) + 1];
            strcpy(road, a.road);
        }
        else{
            cout << "road = 0 ";
            road = 0;
        }

        if (a.subDistrict != 0)
        {
            subDistrict = new char[strlen(a.subDistrict) +1];
            strcpy(subDistrict, a.subDistrict);
        }
        else{
            cout << "subDistrict= 0 ";
            subDistrict = 0;
        }

        if (a.district != 0)
        {
            district = new char[strlen(a.district) +1];
            strcpy(district , a.district);
        }
        else{
            cout << "district = 0 ";
            district = 0;
        }

        if (a.province != 0)
        {
            province = new char[strlen(a.province) +1];
            strcpy(province , a.province);
        }
        else{
            cout << "province = 0 ";
            province = 0;
        } 
    }
    //---------------------

    // set
    void setAddress(char *r, char *s, char *d, char *p, int z)
    {
        setRoad(r);
        setSubDistrict(s);
        setDistrict(d);
        setProvince(p);
        setZipCode(z);
    }
    void setRoad(char *r)
    {
        if (road != 0)
        {
            delete[] road;
        }
        road = new char[strlen(r) + 1];
        strcpy(road, r);
    }
    void setSubDistrict(char *s)
    {
        if (subDistrict != 0)
        {
            delete[] subDistrict;
        }
        subDistrict = new char[strlen(s) + 1];
        strcpy(subDistrict, s);
    }
    void setDistrict(char *d)
    {
        if (district != 0)
        {
            delete[] district;
        }
        district =  new char[strlen(d) + 1];
        strcpy(district, d);
    }
    void setProvince(char *p)
    {
        if (province != 0)
        {
            delete[] province;
        }
        province = new char[strlen(p) + 1];
        strcpy(province, p);
    }
    void setZipCode(int z)
    {
        zipCode = z;
    }

    // get
    char *getRoad()
    {
        return road;
    }
    char *getSubDistrict()
    {
        return subDistrict;
    }
    char *getDistrict()
    {
        return district;
    }
    char *getProvince()
    {
        return province;
    }
    int getZipCode()
    {
        return zipCode;
    }

    // show
    void showAddress();

    // lab 9------------
    // operator =
    Address &operator=(const Address &a)
    {
        if (this == &a){
            cout <<"same obj";
            return *this; // เช็คว่าเป็นตัวเดียวกันแล้วยัง
        }
        setZipCode(a.zipCode);

        if (a.road != 0)
        {
            setRoad(a.road);
        }
        else{
            cout << "\nroad = 0 ";
            road = 0;
        }

        if (a.subDistrict != 0)
        {
            setSubDistrict(a.subDistrict);
        }
        else{
            cout << "subDistrict= 0 ";
            subDistrict = 0;
        }

        if (a.district != 0)
        {
            setDistrict(a.district);
        }
        else{
            cout << "district = 0 ";
            district = 0;
        }

        if (a.province != 0)
        {
            setProvince(a.province);
        }
        else{
            cout << "province = 0 ";
            province = 0;
        }

        return *this;
    }

    // ostream , istream
    friend ostream &operator<<(ostream &os, const Address &a);
    friend istream &operator>>(istream &is, Address &a);
    //-----------------
};
void Address ::showAddress()
{
    if(road!= 0 && subDistrict != 0 && district != 0 && province != 0){
        cout << "\nRoad: " << road << endl;
        cout << "SubDistrict: " << subDistrict << endl;
        cout << "District: " << district << endl;
        cout << "Province: " << province << endl;
        cout << "zip code: " << zipCode << endl;
    } else {
        cout << "\nRoad: none" <<  endl;
        cout << "SubDistrict: none" << endl;
        cout << "District: none" << endl;
        cout << "Province: none" << endl;
        cout << "zip code: "<< zipCode << endl;
    }
}
//-------------------
// ostream
ostream &operator<<(ostream &os, const Address &a)
{
    if(a.road!= 0 && a.subDistrict != 0 && a.district != 0 && a.province != 0){
        os << "\nRoad: " << a.road << endl;
        os << "SubDistrict: " << a.subDistrict << endl;
        os << "District: " << a.district << endl;
        os << "Province: " << a.province << endl;
        os << "zip code: " << a.zipCode << endl;
    } else {
        os << "\nRoad: none" <<  endl;
        os << "SubDistrict: none" << endl;
        os << "District: none" << endl;
        os << "Province: none" << endl;
        os << "zip code: "<< a.zipCode << endl;
    }
    return os;
}

// istream
istream &operator>>(istream &is, Address &a)
{
    char r[30], s[30], d[30], p[30]; int z;
    cout << "Road: "; is>> r; 
    cout << "SubDistrict: "; is>>s; 
    cout << "District: "; is>>d;
    cout << "Province: "; is>>p;
    cout << "zip code: "; is>>z; 
    a.setAddress(r,s,d,p,z);
    return is;
}
//-------------------

class Person
{
    static int num;
    char *fname;
    char *lname;
    Date *bday;
    Address add;

public:
    Person()
    {
        num++;
        fname = lname = 0;
        //bday.setDate(0, 0, 0); bday.setNameDay("none");
        //bday = 0;
        bday = new Date();
        add.setAddress("none", "none", "none", "none", 0);
    }
    Person(char *f, char *l, Date &d, Address &a) 
    {
        num++;
        fname = new char[strlen(f) + 1]; //+1 ไว้เผื่อที่ให้ /0
        strcpy(fname , f);
        lname = new char[strlen(l) + 1]; //+1 ไว้เผื่อที่ให้ /0
        strcpy(lname, l);

        /*bday = new Date(); //new เพื่อส่ง Date ไปเกิด
        bday->setDate(d.getDay(), d.getMonth(), d.getYear());
        bday->setNameDay(d.getNameDay());*/
        bday = new Date(d); //copy ค่าที่รับจาก d มาใส่ bday

        add = Address(a); 
        //add = a; อันเก่าใช้ set อัรบนเรียก copycon อันนี้เรียก op=
        /*add.setAddress(a.getRoad(), a.getSubDistrict(), a.getDistrict(),
        a.getProvince() , a.getZipCode());*/
        
    }
    ~Person()
    {
        cout << "delete " << fname << " " << lname << endl;
        delete[] fname;
        delete[] lname;
        delete bday;
    }
    // lab_9-----------------
    // coppy con------------
    Person(const Person &p)
    {
        cout << "\nPerson:: coppy constructer" <<endl;
        add = p.add;

        /*if (p.bday != 0)
        {
            /*bday = new Date();
            bday = p.bday;*/
            /*bday = new Date();
            bday->setDate(p.bday->getDay(), p.bday->getMonth(), p.bday->getYear());
            bday->setNameDay(p.bday->getNameDay());
            bday = new Date(*p.bday); //จองที่สำหรับตัวที่ copy
            //*this->bday = *p.bday;

        } else {
            cout << "\nbday = new Date() ";
            bday = new Date(); //จะได้ defult Date
        }*/
        bday = new Date(*p.bday); //จองที่สำหรับตัวที่ copy

        if (p.fname != 0)
        {
            fname = new char[strlen(p.fname) + 1]; 
            strcpy(fname, p.fname);
        } else {
            cout << "fanme = 0 ";
            fname = 0;
        }

        if (p.lname != 0)
        {
            lname = new char[strlen(p.lname) + 1];
            strcpy(lname, p.lname);
        }else {
            cout <<"lname = 0 " <<endl;
            lname = 0;
        }
    }
    //---------------------

    // operator =
    Person &operator=(const Person &p)
    {
        cout<<"op= in Person" <<endl;
        if (this == &p){
            cout<< "same Person";
            return *this;
        }
        //num = p.num; ตัวแปร static ค่ามันจะนับไปเรื่อยๆอยู่แล้วทุกๆ obj จะมีค่า num เป็นค่าล่าสุด
        //cout << "p.num = "<< p.num <<endl;
        //cout << "num = "<< num <<endl;
        add = p.add;
        
        /*if (p.bday!=0)
        {
            setBday(*p.bday); //การเข้าถึงค่าจริงของข้อมูล

        } else {
            bday = new Date();
        }*/
        setBday(*p.bday); //การเข้าถึงค่าจริงของข้อมูล
        if (p.fname != 0)
        {
            setFanme(p.fname);
        } else {
            fname = 0;
        }

        if (p.lname != 0)
        {
            setLname(p.lname);
        } else {
            lname = 0 ;
        }
        return *this;
    }

    // ostream
    void print(ostream &os)
    {
        os << "\n===== print Person =====" << endl;
        /*if (fname != 0 && lname != 0)
        {
            os << "Person no. " << count() << endl;
            os  << fname << " " << lname;
            bday->showDate();
            add.showAddress();
        } else {
            os  << "Person no. " << count() << endl;
            os  << "fanme: none lname: none" <<endl;
            //os << "none " << "none" << "/" << "none" << "/" << "none" << endl;
            bday->showDate();
            add.showAddress();
        }*/
        os << "\n===== print Person =====" << endl;
        os << "Person no. " << count() << endl;
        if (fname != 0 && lname != 0)
        {
            os  << fname << " " << lname;
        } else {
            os  << "fanme: none lname: none" <<endl;
        }
        bday->showDate();
        add.showAddress();
    }

    // istream
    void input(istream &is)
    {
        char fn[20], ln[20]; Date d;
        cout << "\n======= input ======= " << endl;
        cout << "Enter first name: ";is >> fn; setFanme(fn); 
        cout << "Enter last  name: ";is >> ln; setLname(ln);
        cout<<endl; is >> d; setBday(d);
        cout<<endl; is >> add;
        /*if (bday != 0)
        {
            cout<<endl; is >> d; setBday(d);
        } else {
            //cout << "can not input bday = 0 " <<endl;
            cout << "\nbday = 0 ";
            bday = new Date(); //จองที่ให้ bday เพื่อให้ input ได้
            cout<<endl; is >> d; setBday(d);
        }*/
        
    }
    //----------------------

    // set
    void setPerson(char *f, char *l, Date &d, Address &a)
    {
        setFanme(f);
        setLname(l);
        setBday(d);
        setAdd(a);
    }
    void setFanme(char *f)
    {
        if (fname != 0)
        {
            delete[] fname;
        }
        
        fname = new char[strlen(f) +1];
        strcpy(fname, f);
    }
    void setLname(char *l){
        if (lname != 0)
        {
            delete[] lname;
        }
        
        lname = new char[strlen(l) +1];
        strcpy(lname, l);
    }
    void setBday(Date &d)
    {
        if (bday != 0)
        {
            delete bday; // ลบ Date ตัวเก่าถ้ามีอยู่
        }
        bday = new Date(d); // สร้าง Date ตัวใหม่
    }
    void setAdd(Address &a)
    {
        add = a;
    }

    // show
    void showPerson(ostream& os)
    {
        //cout << "\n===== show Person =====" << endl;
        print(os);
        
    }

    // get
    char *getFname()
    {
        return fname;
    }
    char *getLname()
    {
        return lname;
    }
    Date *getBday()
    {
        return bday;
    }
    Address getAdd()
    {
        return add;
    }

    static int count()
    {
        return num;
    }
};
int Person ::num;

class Student: virtual public Person{
    char *id;
    char *fac;
    char *university;

    public:
        Student(){
            id = fac = university = 0;
        }
        Student(char *i,char *f, char *u){
            id = new char[strlen(i) + 1]; 
            strcpy(id, i);

            fac = new char[strlen(f) + 1];  
            strcpy(fac,f);

            university = new char[strlen(u) + 1]; 
            strcpy(university , u); 
        }
        //bese
        Student(char *fn, char *ln,Date& d, Address& a, char *i, char *f ,char *u ):Person(fn, ln, d, a){
            id = new char[strlen(i) + 1]; 
            strcpy(id, i);

            fac = new char[strlen(f) + 1];  
            strcpy(fac,f);

            university = new char[strlen(u) + 1]; 
            strcpy(university , u); 
        }
        ~Student(){
            cout << "bye Student" << endl;
            delete[] id;
            delete[] fac;
            delete[] university;
        }

    // lab_9-----------------
    // coppy con------------
    Student(const Student &s) //:Person(s)
    {
        Person::operator=(s);
        cout << "\nStudent:: coppy constructer";
        if (s.id != 0)
        {
            id = new char[strlen(s.id) + 1]; 
            strcpy(id, s.id);
        } else {
            cout << "\nid = 0 ";
            id = 0;
        }

        if (s.fac != 0)
        {
            fac = new char[strlen(s.fac) + 1];  
            strcpy(fac,s.fac);
        } else {
            cout << "fac = 0 ";
            fac = 0;
        }

        if (s.university != 0)
        {
            university = new char[strlen(s.university) + 1]; 
            strcpy(university , s.university);
        } else {
            cout << "university = 0 " <<endl;
            university = 0; 
        }
    }
    //---------------------

    // operator =
    Student &operator=(const Student &s)
    {
        cout<<"op= in Student" <<endl;
        if (this == &s){
            cout << "same Student" <<endl;
            return *this;
        }
        Person::operator=(s);

        if (s.id != 0)
        {
            setId(s.id);
        } else {
            id = 0;
        }

        if (s.fac != 0)
        {
            setFac(s.fac);
        } else { 
            fac = 0;
        }

        if (s.university != 0)
        {
            setUnoversity(s.university);
        } else {
            university = 0;
        }

        return *this;
    }

    // ostream
    void printStudent(ostream& os){
        Person::print(os);

        if (id != 0 && fac != 0 && university != 0)
            {
                os << "\nStudent" << endl;
                os << "university: " << university << endl;
                os << "faculty: " << fac << endl;
                os << "Student ID : " << id << endl;
            } else {
                os << "\nStudent" << endl;
                os << "university: none" << endl;
                os << "faculty: none" << endl;
                os << "Student ID : none" << endl;
            }
    }

    // istream
    void inputStudent(istream& is){
        Person::input(is);
        //------------------------
        char stuUni[30], stuF[30], stuID[8];
        cout << "\nuniversity: "; is>> stuUni; setUnoversity(stuUni);
        cout << "faculty: "; is>> stuF; setFac(stuF);
        cout << "Student ID : "; is>> stuID; setId(stuID);
    }

    //----------------------

        //set
        void setStudent(char *i,char *f, char *u){
            setId(i);
            setFac(f);
            setUnoversity(u);
        }
        void setId(char *i){
            if(id != 0){
                delete[] id;
            }

            id = new char[strlen(i) +1];
            strcpy(id , i);
        }
        void setFac(char *f){
            if (fac != 0)
            {
                delete[] fac;
            }

            fac = new char[strlen(f) +1];
            strcpy(fac , f);
        }
        void setUnoversity(char *u){
            if (university != 0)
            {
                delete[] university;
            }

            university = new char[strlen(u) +1];
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
        void showStudent(ostream& os){
            //cout <<"===== show Student =====" <<endl;
            printStudent(os);
        }
};

class Teachar: virtual public Person{
    char *fac;
    char *university;
    char *course;
    double salary;

    public:
        Teachar(){
            fac = university = course = 0;
            setSalary(0);
        }
        Teachar(char *f, char *u, char *c,double s){
            fac = new char[strlen(f) +1];
            strcpy(fac, f);

            university = new char[strlen(u) +1];
            strcpy(university , u);

            course = new char[strlen(c) +1];
            strcpy(course , c);

            setSalary(s);
        }
        //base
        Teachar(char *fn, char *ln,Date& d, Address& a,char *f, char *u, char *c,double s):Person(fn, ln, d, a){
            fac = new char[strlen(f) +1];
            strcpy(fac, f);

            university = new char[strlen(u) +1];
            strcpy(university , u);

            course = new char[strlen(c) +1];
            strcpy(course , c);
            
            setSalary(s);
        }
        ~Teachar(){
            cout << "bye Teacher" <<endl;
            delete[] fac;
            delete[] university;
            delete[] course;
        }
    // lab_9-----------------
    // coppy con------------
    Teachar(const Teachar &t) 
    {
        Person::operator=(t);
        cout << "\nTeacher:: coppy constructer";
        setSalary(t.salary);

        if (t.fac != 0)
        {
            fac = new char[strlen(t.fac) + 1]; 
            strcpy(fac, t.fac);
        } else {
            cout << "\nfac = 0 ";
            fac = 0;
        }

        if (t.university != 0)
        {
            university = new char[strlen(t.university) + 1]; 
            strcpy(university, t.university);
        } else {
            cout << "university = 0 ";
            university = 0;
        }

        if (t.course != 0)
        {
            course = new char[strlen(t.course) + 1]; 
            strcpy(course, t.course);
        } else {
            cout << "coures = 0 " <<endl;
            course = 0;
        }
    }
    //---------------------

    // operator =
    Teachar &operator=(const Teachar &t)
    {
        cout<<"op= in Teacher" <<endl;
        if (this == &t){
            cout << "same Teacher" <<endl;
            return *this;
        } 
        Person::operator=(t); 
        setSalary(t.salary);

        if (t.fac != 0)
        {
            setFac(t.fac);
        } else {
            fac = 0;
        }

        if (t.university != 0)
        {
            setUnoversity(t.university);
        } else {
            university = 0;
        }

        if (t.course != 0)
        {
            setCourse(t.course);
        } else {
            course = 0;
        }

        return *this;
    }
    /*
    // operator =
    Student &operator=(const Student &s)
    {
        cout<<"op= in Student" <<endl;
        if (this == &s){
            cout << "same Student" <<endl;
            return *this;
        }
        Person::operator=(s);

        if (s.id != 0)
        {
            setId(s.id);
        } else {
            id = 0;
        }

        if (s.fac != 0)
        {
            setFac(s.fac);
        } else { 
            fac = 0;
        }

        if (s.university != 0)
        {
            setUnoversity(s.university);
        } else {
            university = 0;
        }

        return *this;
    }*/

    // ostream
    void printTeacher(ostream& os){
        print(os);
        //Person::print(os);
        if (fac != 0 && university != 0 && course != 0)
        {
            os << "\nTreacher" <<endl;
            os << "university: " << university <<endl;
            os << "faculty: " << fac <<endl;
            os << "Course: "<< course << "  Salary: "<< salary <<endl;
        } else {
            os << "\nTreacher" <<endl;
            os << "university: none"<<endl;
            os << "faculty: none" <<endl;
            os << "Course: none" << "  Salary: "<< salary <<endl;
        }
    }

    // istream
    void inputTeacher(istream& is){
        input(is);
        //------------------------
        char Tuni[30] , Tfac[30] , Tcoures[30];
        cout << "\nuniversity: "; is>> Tuni; setUnoversity(Tuni);
        cout << "faculty: "; is>> Tfac;    setFac(Tfac);
        cout << "Course: "; is>> Tcoures;  setCourse(Tcoures);
        cout << "Salary: "; is>>salary;
    }

    //----------------------
    //set
    void setTeacher(char *f, char *u, char *c,double s){
        setFac(f);
        setUnoversity(u);
        setCourse(c);
        setSalary(s);
    }
    void setFac(char *a){
        if (fac != 0)
        {
            delete[] fac;
        }
            
        fac = new char[strlen(a) + 1];
        strcpy(fac , a);
    }
    void setUnoversity(char *b){
        if (university != 0)
        {
            delete[] university;
        }
            
        university = new char[strlen(b) + 1];
        strcpy(university , b);
    }
    void setCourse(char *c){
        if (course != 0)
        {
            delete[] course;
        }
            
        course = new char[strlen(c) + 1];
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
        void showTeacher(ostream& o){
            //cout <<"\n===== show Teacher =====" <<endl;
            printTeacher(o);
            
        }
};

//multi
class TeachingAssistant: public Student , public Teachar{
    char *nickName;
    char *aptitude; //ความถนัด

    public:
        TeachingAssistant(){
            nickName = aptitude = 0;
    
        }
        TeachingAssistant(char * n , char *ap){
            nickName = new char[strlen(n) +1];
            strcpy(nickName , n);

            aptitude = new char[strlen(ap) +1];
            strcpy(aptitude  ,ap);
        }
        //-------- base multipel --------
        TeachingAssistant(char *i, char *fac ,char *u 
                         ,char *f, char *uni, char *c,double s
                         ,char * n , char *ap):Student(i,fac,u) , Teachar(f,uni,c,s)
        {
            nickName = new char[strlen(n) +1];
            strcpy(nickName , n);

            aptitude = new char[strlen(ap) +1];
            strcpy(aptitude  ,ap);
        }
       
       //-------- base multipel --------
        TeachingAssistant(char *fn, char *l,Date& d, Address& a
                         ,char *i, char *fac ,char *u 
                         ,char *f, char *uni, char *c,double s
                         ,char * n , char *ap):Student(i,fac,u) , Teachar(f,uni,c,s) , Person(fn,l,d,a)
        {
            nickName = new char[strlen(n) +1];
            strcpy(nickName , n);

            aptitude = new char[strlen(ap) +1];
            strcpy(aptitude  ,ap);
        }
        
        ~TeachingAssistant(){
            cout << "delete TA " << endl;
            delete[] nickName;
            delete[] aptitude;
        }
        //lab 9-------------
        //coppy con---------
        TeachingAssistant(TeachingAssistant& ta) //:Student(ta), Teachar(ta) , Person(ta)
        { 
            TeachingAssistant::operator=(ta); 

            cout << "\nTA:: coppy constructer";
            if (ta.nickName != 0)
            {
                nickName = new char[strlen(ta.nickName) +1];
                strcpy(nickName, ta.nickName);
            } else {
                cout << "\n nickName = 0 ";
                nickName = 0;
            }

            if (ta.aptitude != 0)
            {
                aptitude  = new char[strlen(ta.aptitude) +1];
                strcpy(aptitude , ta.aptitude );
            } else {
                cout << "aptitude = 0 "<<endl;
                aptitude = 0;
            }
            
        }
        //------------------

        //operator =
        TeachingAssistant& operator=(TeachingAssistant& ta){
            cout<<"\nop= in TA" <<endl;
            if(this == &ta){
                cout << "same TA" <<endl;
                return *this;
            }
            Student::operator=(ta);
            //Teachar::operator=(ta);
            if (ta.Teachar::getFac()!=0 && ta.Teachar::getUniversity() != 0 && ta.getCourse())
            {
                Teachar::setTeacher(ta.Teachar::getFac(),ta.Teachar::getUniversity() , 
                                ta.getCourse() , ta.getSalary());
            } else {
                Teachar::setFac("none"); Teachar::setUnoversity("none"); Teachar::setCourse("none");
                setSalary(ta.getSalary());
            }
            
            if (ta.nickName != 0)
            {
                setNickName(ta.nickName);
            } else {
                nickName = 0;
            }

            if (ta.aptitude != 0)
            {
                setAptitude(ta.aptitude);
            } else {
                aptitude = 0;
            }

            return *this;
        }
        //ostream
        void printTA(ostream& os){
            Teachar::printTeacher(os);
            //Student::printStudent(os);
            if ((Student::getID()) != 0 && (Student::getFac()) != 0 && (Student::getUniversity()) != 0)
            {
                os << "\nStudent" << endl;
                os << "university: " << Student::getUniversity() << endl;
                os << "faculty: " << Student::getFac() << endl;
                os << "Student ID : " << Student::getID() << endl;
            } else {
                os << "\nStudent" << endl;
                os << "university: none" << endl;
                os << "faculty: none" << endl;
                os << "Student ID : none" << endl;
            }

            if (nickName != 0 && aptitude != 0)
            {
                os << "\nTeachingAssistant" <<endl;
                os << "nick name: " << nickName <<endl;
                os <<"aptitude: " << aptitude <<endl;
            } else {
                os << "\nTeachingAssistant" <<endl;
                os << "nick name: none" <<endl;
                os <<"aptitude: none" <<endl;
            }
        }
        //istream
        void inputTA(istream& is){
            inputTeacher(is);
            //------------------------
            char stuUni[30], stuF[30], stuID[8];
            cout << "\nuniversity: "; is>> stuUni; Student::setUnoversity(stuUni);
            cout << "faculty: "; is>> stuF;        Student::setFac(stuF);
            cout << "Student ID : "; is>> stuID;   Student::setId(stuID);
            //------------------------
            char n[20] , ap[20];
            cout << "\nTeachingAssistant" <<endl;
            cout << "nick name: "; is>> n;
            cout <<"aptitude: "; is>>  ap;
            setTA(n,ap);
        }
        //------------------

        //set
        void setTA(char * n , char *ap){
            setNickName(n); setAptitude(ap);
        }
        void setNickName(char * n ){
            if (nickName != 0)
            {
                delete[] nickName;
            }
            
            nickName = new char[strlen(n) +1];
            strcpy(nickName , n);
        }
        void setAptitude(char *ap){
            if (aptitude != 0)
            {
                delete[] aptitude;
            }
            
            aptitude = new char[strlen(ap) +1];
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
        void showTA(ostream& a){
            printTA(a);
        }
};

// ostream , instream
//-----------------------
// Person
ostream &operator<<(ostream &os, Person &p)
{
    p.print(os);
    return os;
}
istream &operator>>(istream &is, Person &p)
{
    p.input(is);
    return is;
}

// Student
ostream &operator<<(ostream &os, Student &s)
{
    s.printStudent(os);
    return os;
}
istream &operator>>(istream &is, Student&s)
{
    s.inputStudent(is);
    return is;
}

// Teacher
ostream &operator<<(ostream &os, Teachar &t)
{
    t.printTeacher(os);
    return os;
}
istream &operator>>(istream &is, Teachar &t)
{
    t.inputTeacher(is);
    return is;
}

// TA
ostream &operator<<(ostream &os, TeachingAssistant &ta)
{
    ta.printTA(os);
    return os;
}
istream &operator>>(istream &is, TeachingAssistant &ta)
{
    ta.inputTA(is);
    return is;
}
//-----------------------

main(){
    //TA-------------
    cout <<"\n:: Teast TA ::" <<endl;
    TeachingAssistant ta1;
    cout << "ta1: "; ta1.showTA(cout);

    TeachingAssistant ta2("bea","Coding");
    cout << "\nta2: "; ta2.showTA(cout);

    TeachingAssistant ta3("660503","Sci","RU",
                          "Science","Ramkhamhaeng","2103",35000, 
                          "pookie","C++");
    cout << "\nta3: "; ta3.showTA(cout);

    Date dTa4(9,12,2005 ,"wednesday");
    Address aTa4("38 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    TeachingAssistant ta4("Nekoyama", "Sui" , dTa4 , aTa4,
                          "660504","Sci","RU", 
                          "Science","Ramkhamhaeng","2102",35000, 
                          "neko","OOP");
    cout << "\nta4: "; ta4.showTA(cout);

    Date dTa5; dTa5.setDate(9,1,2005); dTa5.setNameDay("sunday");
    Address aTa5; aTa5.setAddress("68 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    TeachingAssistant ta5; 
    ta5.setPerson("Stubaki", "Fuyumi", dTa5, aTa5); 
    ta5.setStudent("660505","Sci","RU"); 
    ta5.setTeacher("Science","Ramkhamhaeng","2102",35000); 
    ta5.setTA("kiki" , "coding");

    cout << "\nta5: ";
    Date *resultDta5 = ta5.getBday();
    Address resultAta5 = ta5.getAdd();
    cout << "\n===== get TeachingAssistant =====" <<endl;
    cout << "Person no. " << Person::count() << endl;
    cout << ta5.getFname() << " " << ta5.getLname();
    cout << "  " << resultDta5->getNameDay() << " " << resultDta5->getDay() << "/" << resultDta5->getMonth() << "/" << resultDta5->getYear() << endl;
    cout << "Road: " << resultAta5 .getRoad() << endl;
    cout << "SubDistrict: " << resultAta5 .getSubDistrict() << endl;
    cout << "District: " << resultAta5 .getDistrict() << endl;
    cout << "Province: " << resultAta5 .getProvince() << endl;
    cout << "zip code: " << resultAta5 .getZipCode() << endl;

    cout << "\nTreacher" <<endl;
    cout << "university: " << ta5.Teachar:: getUniversity() <<endl;
    cout << "faculty: " << ta5.Teachar:: getFac() <<endl;
    cout << "Course: "<< ta5.getCourse() << "  Salary: "<< ta5.getSalary() <<endl;

    cout << "\nStudent" << endl;
    cout << "university: " << ta5.Student:: getUniversity() << endl;
    cout << "faculty: " << ta5.Student::getFac() << endl;
    cout << "Student ID : " << ta5.Student::getID() << endl;

    cout << "\nTeachingAssistant" <<endl;
    cout << "nick name: " << ta5.getNickName() <<endl;
    cout <<"aptitude: " << ta5.getAptitude()<<endl;

    //test coppy con
    cout << "\n---- Test coppy construct ----" <<endl;
    TeachingAssistant ta6 = ta1;
    cout << "\nta6 coppy ta1: "; ta6.showTA(cout);

    TeachingAssistant ta7 = ta4;
    cout << "\nta7 coppy ta4: "; ta7.showTA(cout);

    //teat op=
    cout << "\n---- Test operator = ----" <<endl;
    ta7 = ta7;
    cout << "\nta7 = ta7 "; ta7.showTA(cout);

    ta7 = ta5;
    cout << "\nta7 = ta5 "; ta7.showTA(cout);

    ta7 = ta3;
    cout << "\nta7 = ta3 "; ta7.showTA(cout);

    ta7 = ta2;
    cout << "\nta7 = ta2 "; ta7.showTA(cout);

    ta7 = ta1;
    cout << "\nta7 = ta1 "; ta7.showTA(cout);

    //test os
   cout << "\n---- Test ostream ----" <<endl;
   cout<<"ta1: "<<ta1;
   cout<<"\nta2: "<<ta2;
   cout<<"\nta3: "<<ta3;
   cout<<"\nta4: "<<ta4;
   cout<<"\nta5: "<<ta5;
   cout<<"\nta6: "<<ta6;
   cout<<"\nta7: "<<ta7;

   //test is
   cout << "\n---- Test istream ----" <<endl;
   cin>>ta6; cout<<"\nta6: "<<ta6;
   cin>>ta4; cout<<"\nta4: "<<ta4;
    //---------------

    //Teacher--------
    /*cout <<"\n:: Teast Teacher ::" <<endl;
    Teachar t1;
    cout << "t1: "; t1.showTeacher(cout);

    Teachar t2("sci","Ramkhamhaeng","2103",36000);
    cout << "\nt2: "; t2.showTeacher(cout);

    Date dT3; dT3.setDate(3,12,2005); dT3.setNameDay("monday");
    Address aT3; aT3.setAddress("35 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Teachar t3("neko" , "yama" , dT3 , aT3, "sci","Ramkhamhaeng","COS2103",36000);
    cout << "\nt3: "; t3.showTeacher(cout);

    Date dT4(9,1,2005,"sunday");
    Address aT4("37 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Teachar t4;
    t4.setPerson("naoki" , "ursawa", dT4, aT4);
    t4.setTeacher("sci","Ramkhamhaeng","COS2102",36000);

    cout << "\nt4: ";
    Date *resultDt4 = t4.getBday();
    Address resultAt4 = t4.getAdd();
    cout << "\n===== get Teacher =====" <<endl;
    cout << "Person no. " << Person::count() << endl;
    cout << t4.getFname() << " " << t4.getLname();
    cout << "  " << resultDt4->getNameDay() << " " << resultDt4->getDay() << "/" << resultDt4->getMonth() << "/" << resultDt4->getYear() << endl;
    cout << "Road: " << resultAt4 .getRoad() << endl;
    cout << "SubDistrict: " << resultAt4 .getSubDistrict() << endl;
    cout << "District: " << resultAt4 .getDistrict() << endl;
    cout << "Province: " << resultAt4 .getProvince() << endl;
    cout << "zip code: " << resultAt4 .getZipCode() << endl;

    cout << "\nTreacher" <<endl;
    cout << "university: " << t4.getUniversity() <<endl;
    cout << "faculty: " << t4.getFac() <<endl;
    cout << "Course: "<< t4.getCourse() << "  Salary: "<< t4.getSalary() <<endl;

    //test coppy con
    cout << "\n---- Test coppy construct ----" <<endl;
    Teachar t5 = t1;
    cout << "\nt5 coppy t1: "; t5.showTeacher(cout);

    Teachar t6 = t4;
    cout << "\nt6 coppy t4: "; t6.showTeacher(cout);

    //teat op=
    cout << "\n---- Test operator = ----" <<endl;
    t6 = t6;
    cout << "\nt6 = t6 "; t6.showTeacher(cout);

    t6 = t2;
    cout << "\nt6 = t2 "; t6.showTeacher(cout);

    t6 = t3;
    cout << "\nt6 = t3 "; t6.showTeacher(cout);

    t6 = t1;
    cout << "\nt6 = t1 "; t6.showTeacher(cout);

    //test os
   cout << "\n---- Test ostream ----" <<endl;
   cout<<"t1: "<<t1;
   cout<<"\nt2: "<<t2;
   cout<<"\nt3: "<<t3;
   cout<<"\nt4: "<<t4;
   cout<<"\nt5: "<<t5;
   cout<<"\nt6: "<<t6;

   //test is
   cout << "\n---- Test istream ----" <<endl;
   cin>>t5; cout<<"\nt5: "<<t5;
   cin>>t3; cout<<"\nt3: "<<t3;*/
    //---------------

    //Student--------
    /*cout <<"\n:: Teast Student ::" <<endl;
    Student s1;
    cout << "s1: "; s1.showStudent(cout);

    Student s2("660502","sci","Ramkhamhaeng");
    cout << "\ns2: "; s2.showStudent(cout);

    Date dS3(8,9,2005,"sunday");
    Address aS3("42 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Student s3("miki", "susuki", dS3, aS3,"660503","sci","Ramkhamhaeng");
    cout << "\ns3: ";  s3.showStudent(cout);

    Date dS4(9,1,2005,"wednesday");
    Address aS4("31 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Student s4;
    s4.setFanme("apinya"); s4.setLname("wa"); s4.setBday(dS4); s4.setAdd(aS4);
    s4.setId("6605004"); s4.setFac("sci"); s4.setUnoversity("Ramkhamhaeng");

    cout << "\ns4: ";
    Date *resultDs4 = s4.getBday();
    Address resultAs4 = s4.getAdd();
    cout << "\n===== get Student =====" <<endl;
    cout << "Person no. " << Person::count() << endl;
    cout << s4.getFname() << " " << s4.getLname();
    cout << "  " << resultDs4->getNameDay() << " " << resultDs4->getDay() << "/" << resultDs4->getMonth() << "/" << resultDs4->getYear() << endl;
    cout << "Road: " << resultAs4 .getRoad() << endl;
    cout << "SubDistrict: " << resultAs4 .getSubDistrict() << endl;
    cout << "District: " << resultAs4 .getDistrict() << endl;
    cout << "Province: " << resultAs4 .getProvince() << endl;
    cout << "zip code: " << resultAs4 .getZipCode() << endl;

    cout << "\nStudent" << endl;
    cout << "university: " << s4.getUniversity() << endl;
    cout << "faculty: " << s4.getFac() << endl;
    cout << "Student ID : " << s4.getID() << endl;

    //test coppy con
    cout << "\n---- Test coppy construct ----" <<endl;
    Student s5 = s1;
    cout << "\ns5 coppy s1: ";  s5.showStudent(cout);

    Student s6 = s4;
    cout << "\ns6 coppy s4: ";  s6.showStudent(cout);

    //teat op=
    cout << "\n---- Test operator = ----" <<endl;
    s6 = s6;
    cout << "\ns6 = s6 "; s6.showStudent(cout);

    s6 = s2;
    cout << "\ns6 = s2 "; s6.showStudent(cout);

    s6 = s3;
    cout << "\ns6 = s3 "; s6.showStudent(cout);

    s6 = s1;
    cout << "\ns6 = s1 "; s6.showStudent(cout);

    //test os
   cout << "\n---- Test ostream ----" <<endl;
   cout<<"s1: "<<s1;
   cout<<"\ns2: "<<s2;
   cout<<"\ns3: "<<s3;
   cout<<"\ns4: "<<s4;
   cout<<"\ns5: "<<s5;
   cout<<"\ns6: "<<s6;

   //test is
   cout << "\n---- Test istream ----" <<endl;
   cin>>s5; cout<<"\ns5: "<<s5;
   cin>>s4; cout<<"\ns4: "<<s4;*/
    //---------------

    //Person---------
    /*cout <<"\n:: Teast Person ::" <<endl;
    Person p1;
    cout << "p1: "; p1.showPerson(cout);

    Date dP2(15,9,2005,"wednesday");
    Address aP2("42 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    Person p2("sakamoto","sui",dP2, aP2);
    cout << "\np2: "; p2.showPerson(cout);

    Date dP3;
    dP3.setDay(8); dP3.setMonth(9); dP3.setYear(2005); dP3.setNameDay("sunday");
    Address aP3;
    aP3.setAddress("42 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);

    Person p3;
    p3.setFanme("mei"); p3.setLname("ji");
    p3.setBday(dP3);
    p3.setAdd(aP3);
    //cout << "\np3: "; p3.showPerson(cout);

    Date *resulDp2 = p3.getBday();
    Address resulAp2 = p3.getAdd();
    cout << "\np3: ";
    cout << "\n===== get Person =====" <<endl;
    cout << "Person no. " << Person::count() << endl;
    cout << p3.getFname() << " " << p3.getLname();
    cout << "  " << resulDp2->getNameDay()<< " " << resulDp2->getDay() << "/" << resulDp2->getMonth() << "/" << resulDp2->getYear() << endl;
    cout << "\nRoad: " << resulAp2 .getRoad() << endl;
    cout << "SubDistrict: " << resulAp2 .getSubDistrict() << endl;
    cout << "District: " << resulAp2 .getDistrict() << endl;
    cout << "Province: " << resulAp2 .getProvince() << endl;
    cout << "zip code: " << resulAp2 .getZipCode() << endl;

    //test coppy con
    cout << "\n---- Test coppy construct ----" <<endl;
    Person p4 = p1;
    cout << "\np4 coppy p1: "; p4.showPerson(cout);

    Person p5 = p2;
    cout << "\np5 coppy p2: "; p5.showPerson(cout);

    //teat op=
    cout << "\n---- Test operator = ----" <<endl;
    p4 = p4;
    cout << "\np4 = p4 "; p4.showPerson(cout);

    p4 = p3;
    cout << "\np4 = p3 "; p4.showPerson(cout);

    p4.operator=(p1);
    cout << "\np4 = p1 "; p4.showPerson(cout);

    //test os
   cout << "\n---- Test ostream ----" <<endl;
   cout<<"p1: "<<p1;
   cout<<"\np2: "<<p2;
   cout<<"\np3: "<<p3;
   cout<<"\np4: "<<p4;
   cout<<"\np5: "<<p5;

   //test is
   cout << "\n---- Test istream ----" <<endl;
   cin>>p4; cout<<"\np4: "<<p4;
   cin>>p5; cout<<"\np5: "<<p5;*/
    //---------------

    //Address--------
    /*cout <<"\n:: Teast Address ::" <<endl;
    Address a1;
    cout << "a1: "; a1.showAddress();

    Address a2("42 Ramkhamhaeng ","Hua Mak","Bang Kapi","Bangkok",10240);
    cout << "\na2: "; a2.showAddress();

    Address a3;
    a3.setRoad("31 Ramkhamhaeng ");
    a3.setSubDistrict("Hua Mak");
    a3.setDistrict("Bang Kapi");
    a3.setProvince("Bangkok");
    a3.setZipCode(10240);
    cout << "\na3: ";
    cout << "\n===== get Address =====" <<endl;
    cout << "Road: " << a3.getRoad() << endl;
    cout << "SubDistrict: " << a3.getSubDistrict() << endl;
    cout << "District: " << a3.getDistrict() << endl;
    cout << "Province: " << a3.getProvince() << endl;
    cout << "zip code: " << a3.getZipCode() << endl;

    //test coppy con
    cout << "\n---- Test coppy construct ----" <<endl;
    Address a4 = a1;
    cout << "\na4 coppy a1: "; a4.showAddress();

    Address a5 = a2;
    cout << "\na5 coppy a2: "; a5.showAddress();

    //teat op=
    cout << "\n---- Test operator = ----" <<endl;
    a5 = a5;
    cout << "\na5 = a5 "; a5.showAddress();

    a5 = a1;
    cout << "\na5 = a1 "; a5.showAddress();

    a1.operator=(a3);
    cout << "\na1 = a3 "; a1.showAddress();

    //test os
   cout << "\n---- Test ostream ----" <<endl;
   cout<<"a1: "<<a1;
   cout<<"\na2: "<<a2;
   cout<<"\na3: "<<a3;
   cout<<"\na4: "<<a4;
   cout<<"\na5: "<<a5;

   //test is
   cout << "\n---- Test istream ----" <<endl;
   cin>>a5; 
   cout<<"\na5: "<<a5;*/
    //---------------

    //Date-----------
   /*cout <<"\n:: Teast Date ::" <<endl;
   Date d1;
   cout << "d1: "; d1.showDate();

   Date d2(6,2,2005,"sunday");
   cout << "\nd2: "; d2.showDate();

   Date d3(7,9);
   cout << "\nd3: "; d3.showDate();

   Date d4(7);
   cout << "\nd4: "; d4.showDate();

   Date d5;
   d5.setDate(15,8,2005);
   d5.setNameDay("friday");
   cout << "\nd5: " <<endl;
   cout <<"===== get Date =====" <<endl;
   cout << d5.getNameDay() << " " << d5.getDay() << "/" 
        <<d5.getMonth() << "/" <<d5.getYear() <<endl;

   //test coppy con
   cout << "\n---- Test coppy construct ----" <<endl;
   Date d6 = d1;
   cout << "\nd6 coppy d1 "; d6.showDate();

   Date d7 = d2;
   cout << "\nd7 coppy d2 "; d7.showDate();

   //test op=
   cout << "\n---- Test operator = ----" <<endl;
   d4 = d5; 
   cout << "d4 = d5 "; d4.showDate();

   d4.operator=(d3);
   cout << "\nd4 = d3 "; d4.showDate();

   d4 = d4;
   cout << "\nd4 = d4 "; d4.showDate();

   //test os
   cout << "\n---- Test ostream ----" <<endl;
   cout<<"d1: "<<d1;
   cout<<"d2: "<<d2;
   cout<<"d3: "<<d3;
   cout<<"d4: "<<d4;
   cout<<"d5: "<<d5;
   cout<<"d6: "<<d6;
   cout<<"d7: "<<d7;

   //test is
   cout << "\n---- Test istream ----" <<endl;
   cin>>d1; 
   cout<<"\nd1: "<<d1;*/
   //--------------

   cout << "\n===== destructor =====" << endl;
}