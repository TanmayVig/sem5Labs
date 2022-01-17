#include<iostream>
#include<string>
#include<iomanip>
#define M 5
using namespace std;

class Books{
    private:
        string author;
        string title;
        float price;
        string publisher;
        int stock_position;
        void friend add_to_array(Books &,Books,int);
        void friend bill(Books arr[],int);
        void friend search_by_author(Books arr[],string);
        void friend search_by_title(Books arr[],string);
        void friend show_all_books(Books arr[]);
    public:
        Books(){}
        Books(string a, string t, float pr, string pub, int st){
            author = a;
            title=t;
            price=pr;
            publisher=pub;
            stock_position = st;
        }
        bool match(string,string);
        void details();
        float query(int);
        void update_price(float);
};

bool Books::match(string t, string auth){
    if(title==t && auth==author) return true;
    return false;
}

void Books::details(){
    cout<<"Title: "<<title<<endl<<"Author: "<<author<<endl;
    cout<<"Publisher: "<<publisher<<endl<<"Price: "<<price<<endl;
}

float Books::query(int q){
    if(q<=stock_position){
        stock_position-=q;
        return q*price;
    }
    return 0.0;
}

void Books::update_price( float p){
    price=p;
}

void add_to_array(Books &a,Books b,int q){
    a=b;
    a.stock_position = q;
}

void bill(Books arr[],int n){
    float total=0;
    for(int i=0;i<n;i++){
        total+=arr[i].price * arr[i].stock_position;
        cout<<"Item: "<<i+1<<endl;
        cout<<"Title: "<<arr[i].title<<endl;
        cout<<"Author: "<<arr[i].author<<endl;
        cout<<"Price: "<<arr[i].price<<endl;
        cout<<"Quantity: "<<arr[i].stock_position<<endl;
    }
    cout<<"----------------------------------\nTotal: "<<total<<endl;
}

void show_all_books(Books arr[]){
    cout<<"___________________________________________________________________________________\n";
    cout<<"|Title             |Author           |Publisher         |Price     |Stock Position|\n";
    cout<<"___________________________________________________________________________________\n";
    for(int i=0;i<M;i++){
        cout<<left<<"|"<<setw(18)<<arr[i].title<<"|"<<setw(17)<<arr[i].author<<"|"<<setw(18)<<arr[i].publisher<<"|"<<setw(10)<<arr[i].price<<"|"<<setw(14)<<arr[i].stock_position<<"|\n";
        cout<<"___________________________________________________________________________________\n";
    }
}

void search_by_author(Books arr[],string a){
    cout<<"_________________________________________________________________\n";
    cout<<"|Title             |Publisher         |Price     |Stock Position|\n";
    cout<<"_________________________________________________________________\n";
    for(int i=0;i<M;i++){
        if(arr[i].author==a){
            cout<<left<<"|"<<setw(18)<<arr[i].title<<"|"<<setw(18)<<arr[i].publisher<<"|"<<setw(10)<<arr[i].price<<"|"<<setw(14)<<arr[i].stock_position<<"|\n";
            cout<<"_________________________________________________________________\n";
        }
    }
}


void search_by_title(Books arr[],string a){
    cout<<"__________________________________________________________________\n";
    cout<<"|Author             |Publisher         |Price     |Stock Position|\n";
    cout<<"__________________________________________________________________\n";
    for(int i=0;i<M;i++){
        if(arr[i].title==a){
            cout<<left<<"|"<<setw(18)<<arr[i].title<<"|"<<setw(18)<<arr[i].publisher<<"|"<<setw(10)<<arr[i].price<<"|"<<setw(14)<<arr[i].stock_position<<"|\n";
            cout<<"__________________________________________________________________\n";
        }
    }
}

int main(){
    Books arr[M],bought[M];
    string author,title,publisher;
    float price;
    int stock,n=0;
    bool flag;
    cout<<"Eneter Details of books in stock.\n";
    for(int i=0;i<M;i++){
        cout<<"Details of book "<<i+1<<endl;
        cout<<"Enter Title\n";
        cin.clear();
        cin.sync();
        getline(cin,title);
        cout<<"Enter Author's name\n";
        getline(cin,author);
        cout<<"Enter Publisher\n";
        getline(cin,publisher);
        cout<<"Enter Price\n";
        cin>>price;
        cout<<"Enter Stock Position\n";
        cin>>stock;
        arr[i]=Books(author,title,price,publisher,stock);
    }
    while(1){
        int choice=0;
        cout<<"Enter 1 to buy Book\nEnter 2 to see all book details\nEnter 3 to update price of a book\nEnter 4 to search all books by an author\nEnter 5 to search books by Title\nEnter 0 to exit.\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the Title and Author of the book\n";
                cin.clear();
                cin.sync();
                getline(cin,title);
                getline(cin,author);
                for(int i=0;i<M;i++){
                    flag = arr[i].match(title,author);
                    if(flag){
                        int q,amt;
                        cout<<"Congratulations!! We have the required book in stock.\n";
                        arr[i].details();
                        cout<<"Enter the Number of Books you want? \t";
                        cin>>q;
                        amt=arr[i].query(q);
                        if(amt!=0){
                            add_to_array(bought[n],arr[i],q);
                            cout<<"Cost of books: "<<amt<<endl;
                            n++;
                        }else{
                            cout<<"Stock Unavailable.\n";
                            flag=false;
                        }
                        break;
                    }
                } 
                if(!flag) cout<<"We Do not have the book you require\n";
                break;
            case 2:
                show_all_books(arr);
                break;
            case 3: 
                cout<<"Enter the Title and Author of Book\n";
                cin.clear();
                cin.sync();
                getline(cin,title);
                getline(cin,author);
                flag=false;
                for(int i=0;i<M;i++){
                    if(arr[i].match(title,author)){
                        float price=0;
                        flag=true;
                        cout<<"Enter new price: ";
                        cin>>price;
                        arr[i].update_price(price);
                        break;
                    }
                }
                if(!flag){
                    cout<<"Book not found"<<endl;
                }
                break;
            case 4:
                cout<<"Enter Name of Author: ";
                cin.clear();
                cin.sync();
                getline(cin,author);
                search_by_author(arr,author);
                break;
            case 5:
                cout<<"Enter Title of Book: ";
                cin.clear();
                cin.sync();
                getline(cin,title);
                search_by_title(arr,title);
                break;
            default:
                cout<<"Enter valid input\n";
                break;
        }
        if(choice==0) break;
    }
    bill(bought,n);
    return 0;
}