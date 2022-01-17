#include<iostream>
#include<string>

using namespace std;

class Employee{
    protected:
        string name;
        float salary;
        int id;
    public:
        Employee(){ }
        Employee(string n, float s,int i){
            name=n;salary=s;id=i;
        }
        virtual void getDetail(){
            cout<<"\nEmployee Name: "<<name<<"\nSalary: "<<salary<<"\n\n";
        }
        virtual float getSalary(){
            return salary;
        }
};

class Teacher : public Employee{
    protected:
        string highest_Qualification;
        string* subs;
        int sub_count;
    public:
        Teacher(string h_Q,string s[], int s_c,string n, float sal, int id): Employee(n,sal,id){
            highest_Qualification = h_Q;
            sub_count = s_c;
            subs = new string[s_c];
            for(int i=0;i<s_c;i++){
                subs[i] = s[i];
            }
        }
        virtual ~Teacher(){
            delete[] subs;
        }
        virtual void getDetail(){
            cout<<"\nEmployee Name: "<<name<<"\nSalary: "<<salary<<"/nHighest Qualification: "<<highest_Qualification;
            cout<<"Subjects Teached:-";
            for(int i=0;i<sub_count;i++){
                cout<<i+1<<". "<<subs[i]<<endl;
            }
            cout<<"\n\n";
        }
};

class HOD : public Teacher{
    protected:
        int years;
        string dept;
    public:
        HOD(int yrs, string dpt,string h_Q,string s[], int s_c,string n, float sal,int id): Teacher(h_Q, s,s_c, n,sal,id){
            years = yrs;
            dept = dpt;
        }

        void getDetail(){
            cout<<"\nEmployee Name: "<<name<<"\nSalary: "<<salary<<"/nHighest Qualification: "<<highest_Qualification;
            cout<<"Subjects Teached:-";
            for(int i=0;i<sub_count;i++){
                cout<<i+1<<". "<<subs[i]<<endl;
            }
            cout<<"Years of Experience: "<<years<<"\n"<<"Department Handled: "<<dept<<"\n\n";
        }
};

class Proctor : public Teacher{
    protected:
        int tenure;
    public:
        Proctor(int ten,string h_Q,string s[], int s_c,string n, float sal,int id): Teacher(h_Q, s,s_c, n,sal,id){
            tenure = ten;
        }
        void getDetail(){
            cout<<"\nEmployee Name: "<<name<<"\nSalary: "<<salary<<"/nHighest Qualification: "<<highest_Qualification;
            cout<<"Subjects Teached:-";
            for(int i=0;i<sub_count;i++){
                cout<<i+1<<". "<<subs[i]<<endl;
            }
            cout<<"Tenure: "<<tenure<<"\n\n";
        }
};

class Warden : public Teacher{
    protected:
        int hostels_managed;
    public:
        Warden(int h_m,int ten,string h_Q,string s[], int s_c,string n, float sal,int id) : Teacher(h_Q, s,s_c, n,sal,id){
            hostels_managed = h_m;
        }
        void getDetail(){
            cout<<"\nEmployee Name: "<<name<<"\nSalary: "<<salary<<"/nHighest Qualification: "<<highest_Qualification;
            cout<<"Subjects Teached:-";
            for(int i=0;i<sub_count;i++){
                cout<<i+1<<". "<<subs[i]<<endl;
            }
            cout<<"Hostel Managed: "<<hostels_managed<<"\n\n";
        }
};


int main(){
    Employee *arr[4];
    string sub1[] = {"CEN-102","CEN-301"};
    string sub2[] = {"CEN-201", " CEN-404"};
    string sub3[] = {"ME-301","ME-302"};
    string sub4[] = {"EE-101","EE-201"};

    arr[0] = new  Teacher("M.Tech",sub1,2,"Paras",10000,1);
    arr[1] = new HOD(5,"Computer Engg", "PHD",sub2,2,"Almas",20000,2);

    arr[2] = new Proctor(10,"PHd",sub3,2,"Rishabh",50000,3);

    arr[3] = new Warden(3,9, "M.Tech", sub4,2,"Bhargav",20000,4);

    cout<<"Printing details of all Employees:\n";
    for(int i=0;i<4;i++){
        arr[i]->getDetail();
    }

    return 0;
}