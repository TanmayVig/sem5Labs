#include<iostream>
#include<string>

using namespace std;

class Computer{
    protected:
        string processors;
        string companyName;
        int num_cores;
    public:
        Computer(string cN,string p, int cores){ // constructor
            companyName = cN;
            processors = p;
            num_cores = cores;
        }

        virtual void get_detail(){ // virtual function to get details
            cout<<"\nCompany Name: "+ companyName<<"\nProcessor: "+processors<<"\nNumber of Cores: "+num_cores<<endl;
        }
};

class PersonalComputer: public Computer{
    protected:
        string type;
    public:
        PersonalComputer(string t,string cN,string p, int cores) : Computer(cN,p,cores){ // constructor
            type=t;
        }
        void get_detail(){ // function with same name as in derived class to get details
            cout<<"\nCompany Name: "+ companyName<<"\nProcessor: "+processors<<"\nNumber of Cores: "+num_cores<<"\nType of Computer: "+type<<endl;
        }
    
};

int main(){
    
    Computer * c = new Computer("DELL","Intel i5",4); // initialize the computer class
    c->get_detail(); // calling from Computer class

    c = new PersonalComputer("Tablet","Lenovo","Qualcom SnapDragon 855", 8);

    c->get_detail(); // calling from PersonalComputer class
    return 0;
}