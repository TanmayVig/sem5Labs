#include<iostream>

using namespace std;

class Rectangle{
    private:
        float length;
        float width;
    public:
        void setLength(float);
        void setWidth(float);
        float perimeter();
        float area();
        void show();
        int sameArea(Rectangle);
};

void Rectangle::setLength(float l){
    length=l;
    cout<<"Length of rectangle is set to "<<l<<endl;
}

void Rectangle::setWidth(float w){
    width=w;
    cout<<"Width of rectangle is set to"<<w<<endl;
}

float Rectangle::perimeter(){
    return 2*(length+width);
}

float Rectangle::area(){
    return length*width;
}

void Rectangle::show(){
    cout<<"Length of Rectangle: "<<length<<"\nWidth of Rectangle: "<<width<<endl;
}

int Rectangle::sameArea(Rectangle r){
    return area()==r.area() ? 1 : 0;
}

int main(){
    Rectangle r1,r2;
    cout<<"Setting dimentions of Rectangle 1.\n";
    r1.setLength(5); r1.setWidth(2.5);
    cout<<endl;

    cout<<"Setting dimentions of Rectangle 2.\n";
    r2.setLength(5); r2.setWidth(18.9);
    cout<<endl;

    cout<<"Showing details of Rectangles\n\n";
    cout<<"Rectangle 1:\n";
    r1.show();
    cout<<"Area: "<<r1.area()<<endl;
    cout<<"Perimeter: "<<r1.perimeter()<<endl;
    cout<<endl;
    cout<<"Rectangle 2:\n";
    r2.show();
    cout<<"Area: "<<r1.area()<<endl;
    cout<<"Perimeter: "<<r1.perimeter()<<endl;
    cout<<endl;

    if(r1.sameArea(r2)) cout<<"Both Rectangles have the same area.\n\n";
    else cout<<"Both Rectangles have different area.\n\n";

    cout<<"Changing dimentions of Rectangle 1.\n";
    r1.setLength(15);
    r1.setWidth(6.3);
    cout<<endl;

    cout<<"Showing details of Rectangles\n\n";
    cout<<"Rectangle 1:\n";
    r1.show();
    cout<<"Area: "<<r1.area()<<endl;
    cout<<"Perimeter: "<<r1.perimeter()<<endl;
    cout<<endl;
    cout<<"Rectangle 2:\n";
    r2.show();
    cout<<"Area: "<<r1.area()<<endl;
    cout<<"Perimeter: "<<r1.perimeter()<<endl;
    cout<<endl;

    if(r1.sameArea(r2)) cout<<"Both Rectangles have the same area.\n\n";
    else cout<<"Both Rectangles have different area.\n\n";

    return 0;
}