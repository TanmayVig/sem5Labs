#include<iostream>

using namespace std;

class Complex{
    private:
        float real;
        float imag;
        Complex friend sum(Complex,Complex);
    public:
        void set(float r,float i){
            real = r; imag = i;
        }
        void display(){
            cout<<real<<" + "<<imag<<"i\n";
        }
};

Complex sum(Complex x,Complex y){
    Complex c;
    c.real = x.real+y.real; c.imag = x.imag+y.imag;
    return c;
}

int main(){
    Complex a,b,c;
    float r,i;
    cout<<"Enter value of complex number 1.\nreal part:\t";
    cin>>r;
    cout<<"imaginary part:\t"; cin>>i;
    a.set(r,i);

    cout<<"Enter value of complex number 2.\nreal part:\t";
    cin>>r;
    cout<<"imaginary part:\t"; cin>>i;
    b.set(r,i);

    c = sum(a,b);
    cout<<"Displaying values of complex numbers:\n";
    cout<<"number 1:\n";
    a.display();
    cout<<"number 2:\n";
    b.display();
    cout<<"number 3:\n";
    c.display();
    return 0;
}
