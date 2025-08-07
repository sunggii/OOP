#include<iostream>
using namespace std;
class Box{
	private:
		int width;
		int heigth;
		int length;
	
	public:
		void set(int w, int h, int l){
			width=w;
			heigth=h;
			length=l;
		}
		
	int getWidth(){
		return width;
	}
	int getHeigth(){
		return heigth;
	}
	int getLength(){
		return length;
	}
	void show(void);
};

void Box::show(){
	cout<<"Width = "<<width<<endl;
	cout<<"Heigth = "<<heigth<<endl;
	cout<<"Length = "<<length<<endl;
	cout<<endl;
}

main(){
	Box myBox, yourBox;
	myBox.set(4,5,6);
	yourBox.set(8,6,10);
	myBox.show();
	yourBox.show();
	
	int volumeMybox;
	int volumeYourbox;
	volumeMybox=myBox.getWidth() * myBox.getHeigth() * myBox.getLength();
	cout<<"myBox volume ="<<volumeMybox<<endl;
	
	volumeYourbox=yourBox.getWidth() * yourBox.getHeigth() * yourBox.getLength();
	cout<<"yourBox volume ="<<volumeYourbox<<endl;
}

