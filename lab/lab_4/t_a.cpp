#include <iostream> //4.1 แบบ procedural 
using namespace std;

//(x1 * x2) + (y1 * y2)
float dot(float x1 , float x2, float y1, float y2){
    return (x1 * x2) + (y1 * y2);
};

//x = ((x1 + x2)/2)   y = ((y1 + y2)/2)
void midPoint(float x1 , float x2, float y1, float y2,float& mX, float& mY){
    mX = ((x1 + x2)/2); // = 3
    mY = ((y1 + y2)/2); // = 2.5
};

void input(float& x1 , float& y1, float& x2, float& y2){
    cout<<"input p1X :",cin>>x1; //2
    cout<<"input p1Y :",cin>>y1; //3

    cout<<"\ninput q2X :",cin>>x2; //4
    cout<<"input q2Y :",cin>>y2; //2
}

void point(float x1 , float y1, float x2, float y2){
    cout<<"\nP("<<x1<<")("<<y1<<")"<<endl;
    cout<<"Q("<<x2<<")("<<y2<<")"<<endl;
};

main(){
    //จุด P
    float p1X , p1Y;
    //จุด Q
    float q2X , q2Y;
    input(p1X , p1Y, q2X , q2Y);
    point(p1X , p1Y, q2X , q2Y);


    float scalar;
    scalar = dot(p1X, q2X, p1Y, q2Y); //(2 * 4) + (3 * 2) = 14
    cout<<"\nscalar product  = "<<scalar<<endl;

    float midX , midY;
    midX = midY  = 0;
    midPoint(p1X, q2X, p1Y, q2Y, midX , midY);
    cout<<"mid = ("<<midX<<","<<midY<<")"<<endl; //"(3 , 2.5)"
   
    return 0;
}