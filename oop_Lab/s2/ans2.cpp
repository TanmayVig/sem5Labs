#include <iostream>
#include <string>
using namespace std;
class Employee{
private:
string name;
string id;
int salary;
public:
Employee(string n, string i, int s){
id=i;
name=n;
salary = s;
}
virtual ~Employee(){
cout<<"Deleting Employee\n";
}
void getEmployee(){
cout<<"Employee id: "<<id<<"\nEmployee Name: "<<name<<"\nEmployee salary: "<<salary<<endl;
}
};
class Scientist: protected Employee{
private:
int num_publications;
int num_awards;
string *publications;
string *awards;
public:
Scientist(int num_pub, string *pub, string *aw,int n_a, string name, string id, int salary):Employee(name,id,salary){
num_publications = num_pub;
num_awards = n_a;
publications = new string[num_publications];
for(int i=0;i<num_publications;i++){
publications[i] =pub[i];
}
awards = new string[n_a];
for(int i=0;i<n_a;i++){
awards[i] =aw[i];
}
}
~Scientist(){
cout<<"\nDeleting Scientist\n";
delete[] publications;
delete[] awards;
}
void getScientist(){
cout<<"\nScientist Details:\n";
getEmployee();
cout<<"\nTotal publications: "<<num_publications<<endl; 
cout<<"Publications:\n";
for(int i=0;i<num_publications;i++){
cout<<" "<<publications[i]<<endl;
}
cout<<"\nTotal Awards: "<<num_awards<<endl;
cout<<"Awards:\n";
for(int i=0;i<num_awards;i++){
cout<<" "<<awards[i]<<endl;
}cout<<"\n";
}
};
class Manager : protected Employee{
private:
string title;
int yrs_of_exp;
int teams;
public:
Manager(string t, int yrs, int tm,string name, string id, int salary):Employee(name,id,salary){
title=t;
yrs_of_exp=yrs;
teams = tm;
}
~Manager(){
cout<<"\nDeleting Manager\n";
}
void getManager(){
cout<<"\nManager Details: \n";
getEmployee();
cout<<"Title as Manager: "<<title<<endl;
cout<<"Years of Experience: "<<yrs_of_exp<<endl;
cout<<"Teams Managed: "<<teams<<endl; 
}
};
class Laborer : protected Employee{
private:
int overtime;
int wage_over;
int leaves;
public:
Laborer(int o, int w_o, int l,string name, string id, int salary) :Employee(name,id,salary){
overtime = o;
wage_over = w_o;
leaves = l;
}
~Laborer(){
cout<<"\nDeleting Laborer\n";
}
void getLaborer(){
cout<<"\nLabourer Details: \n"<<endl;
getEmployee();
cout<<"Overtime: "<<overtime<<endl;
cout<<"Wage in overtime: "<<wage_over<<endl;
cout<<"Total leaves: "<<leaves<<endl;
}
};
int main(){
string a1[]={"alpha", "beta"}, p1[]={"one","two"},a2[]={"gamma", "delta"},p2[]={"three","four"};
Scientist s1(2, p1,a1,2,"Paras","100",100);
Scientist s2(2, p2,a2,2,"Naman","103",10010);
s1.getScientist();
s2.getScientist();
Manager m1("General Manager",6, 10, "Tanmay Vig", "101", 10000000);
Manager m2("Assistant Manager",3, 6, "Manuj Monga", "104", 1000000);
m1.getManager();
m2.getManager();
Laborer l1(8,500,1,"Rishabh","102",10000);
Laborer l2(10,10,2,"Almas","105",-1000);
l1.getLaborer();
l2.getLaborer();
return 0;
}
