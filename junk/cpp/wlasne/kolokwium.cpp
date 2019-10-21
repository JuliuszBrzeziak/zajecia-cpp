#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath> 

using namespace std;

class GeometricObject
{
    public:

    virtual bool Draw()=0;

    void GetType()
    {
        cout << "unknow" << endl;
    }
};
GeometricObject::GeometricObject()


class Shape :public GeometricObject
{
    public:
    virtual int area()=0;
};


class Polygon :public Shape
{
    public:
    virtual void GetType(){
        cout << "Polygon" << endl;
    }
};

class pointXY
{
    public:
    int x,y;
//potrzebny konstrukot domyślny!!!
    pointXY(int a=0, int b = 0){
        x=a;
        y=b;
    }

    int GetX(){
        return x;
    }
    int GetY(){
        return y;
    }

    virtual void GetType(){
        cout << "Line" << endl;
    }


};


class Line :public GeometricObject{
    public:
    int p1x,p1y,p2x,p2y;
    Line(int a, int b, int c, int d);

    bool Draw(int r, int t){
        double obl;
        obl = ((t-p2y)*(p2x - p1x) - (p2y - p1y)*(r - p1x));
        return true;
    }





};


    Line::Line(int a, int b, int c, int d): GeometricObject(){
        p1x = a;
        p1y = b;
        p2x = c;
        p2y = d;
    }





int main(){
    cout << "hello" << endl;
    Line lin(2,2,2,2);
    return 0;
}