#include <iostream>
#include <cmath>
using namespace std;
 
class Distance
{
    private:
        int feet;
        int inch;
        Distance friend add(Distance,Distance);
    public:
        void set  ();
        void disp ();
};
  
void Distance:: set()
{
    cout << "Enter Value of feets : "; cin >> feet;
    cout << "Enter value of inches : "; cin >> inch;
     
    
}
 
void Distance:: disp()
{
    cout << endl << "\tFeets : " << feet;
    cout << endl << "\tInches: " << inch;
}
 
Distance add(Distance d1,Distance d2){
    Distance temp;
    int totdist = d2.inch+ d1.inch;
    temp.feet = totdist/12+ d2.feet + d1.feet;
    temp.inch = totdist%12;
    return temp;
}

 
int main()
{
    Distance d1;
    Distance d2;
    Distance d3;
    Distance d4;
 
    cout << "Enter Distance1 : " << endl;
    d1.set();
     
    cout << "Enter Distance2 : " << endl;
    d2.set();
 
    d3 = add(d1,d2);
 
    cout << endl << "Distance1 : " ;
    d1.disp();
 
    cout << endl << "Distance2 : " ;
    d2.disp();
 
    cout << endl << "Distance3 : " ;
    d3.disp();
 
    cout << endl;         
    return 0;
}