#include<iostream>
using namespace std;
class Box{
	private:
		int width;
		int heigth;
		int length;
	
	public:
		void set(int w, int h, int l){
			width = w;
			heigth = h;
			length = l;
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
	
	int volume;
	int total;
	volume=myBox.getWidth()*myBox.getHeigth()*myBox.getLength();
	cout<<"myBox volume ="<<volume<<endl;
	
	total=yourBox.getWidth()*yourBox.getHeigth()*yourBox.getLength();
	cout<<"yourBox volume ="<<total<<endl;
}

