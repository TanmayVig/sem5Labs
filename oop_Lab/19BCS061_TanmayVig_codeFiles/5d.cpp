#include<iostream>

using namespace std;

class Time{
    private:
        int hrs,min;
        Time friend sum(Time&,Time&);
    public:
        void setTime(int h,int m){
            hrs=h%24;min=m;
        }
        void showTime(){
            cout<<hrs<<"hrs: "<<min<<"min "<<endl;
        }
};

Time sum(Time &t1, Time &t2){
    Time t;
    t.hrs = (t1.hrs + t2.hrs + (t1.min + t2.min)/60)%24;
    t.min = (t1.min + t2.min)%60;
    return t;
}

int main(){
    Time t1,t2,t3;
    int hrs,min;
    cout<<"Enter time 1\nEnter hrs:\t";
    cin>>hrs;
    cout<<"Enter min:\t";
    cin>>min;
    t1.setTime(hrs,min);

    cout<<"Enter time 2\nEnter hrs:\t";
    cin>>hrs;
    cout<<"Enter min:\t";
    cin>>min;
    t2.setTime(hrs,min);

    t3 = sum(t1,t2);

    cout<<"Displaying times:\n";
    cout<<"Time 1 = \t";
    t1.showTime();

    cout<<"Time 2 = \t";
    t2.showTime();

    cout<<"Time 3 = \t";
    t3.showTime();
    return 0;
}
