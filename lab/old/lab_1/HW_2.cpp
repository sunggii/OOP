#include <iostream>
#include <string.h>
using namespace std;
class Point {
	private:
	  double x;
	  double y;
	  string name1;
	  char name2[20];

	public:
	   void setX(double X){
		 this->x = X;
	   }
	   void setY(double Y){
		 this->y = Y;
	   }
	   void setName1(string S1){
		 this->name1 = S1;
	   }
	   void setName2(char* p){ //p คือ ชื่อ pointer
		  strcpy(name2 , p);
	   }

       void set(double X,double Y,string S1,char * p){
         this->x=X;
         this->y=Y;
         this->name1=S1;
         strcpy(name2 , p);
       }
	
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	string getName1(){
		return name1;
	}
    char* getName2(){
        return &name2[3];// คือบอกตำแหน่งเริ่มต้นของข้อความ &ชื่อตัวแปร[]
    }
	void show(void);
};
void Point::show(){
	cout<< "string name : "<< name1 << endl;
    cout<< "char name : "<< name2 <<endl;
	cout<< "x = "<< x << endl;
	cout<< "y = "<< y << endl;
}

int main(){
	Point myPoint;
	myPoint.setX(2.0);
	myPoint.setY(3.0);
	myPoint.setName1("mypoint");
	myPoint.setName2((char *)"Sunggii"); //น่าสนใจ

	cout<<"string name : "<<myPoint.getName1()<<endl;
    cout<<"char name : "<<myPoint.getName2()<<endl;
    cout<<"X = "<<myPoint.getX()<<endl;
    cout<<"Y = "<<myPoint.getY()<<endl;
	
    myPoint.set(5.0,6.0," Apin ",(char *)"taubaki");
    myPoint.show();
}
