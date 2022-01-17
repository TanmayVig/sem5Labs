#include<iostream>
using namespace std;

class String{
    private:
        char str[30];
        int friend strlen(String s);
    public:
        void input();
        void show();
        void operator==(String s);
        void operator=(String s);
        void operator+(String s);
        void operator<<(String s);
        void operator>>(String s);
        void operator~();
        int operator/(String s);
};

int strlen(String s){
    int len=0;
    while(*(s.str+len)!='\0'){
        len++;
    }
    return len;
}

void String::input(){
    cout<<"Enter String: ";
    cin.clear();
    cin.sync();
    cin.getline(str,30);
}

void String::show(){
    for(int i=0;str[i]!='\0';i++){
        cout<<str[i];
    }
}

void String::operator==(String s){
    int i=0;
    bool equal=true;
    while(*(str+i)!='\0' && *(s.str + i)!='\0' ){
        // cout<<*(str+i)<<" "<<*(s.str + i);
        if(*(str+i)!=*(s.str+i)){
            equal=false;
            break;
        }
        i++;
    }
    if(equal && *(str+i)=='\0' && *(s.str+i)=='\0') cout<<"Both String are equal\n";
    else cout<<"Strings are not equal\n";
}

void String::operator=(String s){
    int i=0,len= sizeof(s.str)/sizeof(char);
    for(int i=0;i<len;i++){
        *(str+i)= *(s.str+i);
        // str[i]=s.str[i];
    }
    *(str+len )='\0';
}

void String::operator+(String s){
    int len=0;
    while(this->str[len]!='\0') len++; 
    for(int i=0;s.str[i]!='\0';++i,++len){
        this->str[len] = s.str[i];
    }
    this->str[len] = '\0';
}

void String::operator<<(String s){
    cout<<"Sring:\t";
    s.show();
    cout<<"\n";
}

void String::operator>>(String s){
    cout<<"Reverse String:\t";
    for(int i=strlen(s);i>=0;i--){
        cout<<s.str[i];
    }
    cout<<"\n";
}

void String::operator~(){
    bool ans=true;
    int len = strlen(*this)-1;
    // cout<<len;
    for(int i=0;i<=len/2;i++){
        // cout<<str[i]<<" "<<str[len-i]<<endl;
        if(str[i]!=str[len-i]){
            ans=false;
            break;
        }
    }
    if(ans) cout<<"Yes It is palindrome\n";
    else cout<<"No it is not palindrome\n";
}

int String::operator/(String s)
{
   int flag=0,k,i,j,len=strlen(*this),len1=strlen(s)-1;
   for(i=0;i<len;i++)
    {
      if(str[i]==s.str[0])
       {
        if(str[i+len1]==s.str[len1])
          {
           for(j=i,k=0;j<i+len1+1,k<len1;j++,k++)
             {
              if(str[j]==s.str[k])
                flag=1;
              else
                {
                  flag=0;
                  break;
                }
              }
           }
        }
    }
   if(flag==0)
     return 0;  //not a substring

     return 1;  //it is a substring
}

int main(){
    while(true){
        int choice=8,br=0,c;
        String a,b;
        a.input();
        b.input();
        cout<<"Main Menu\n\t1. Equality\n\t2. String copy\n\t3. Concat\n\t4. Show\n\t5. Reverse\n\t6. Palindrome\n\t7. Sub String\n\t8. Exit\nPlease enter your choice\t";
        cin>>choice;
        switch (choice)
        {
        case 1:
            a==b;
            break;
        case 2:
            b=a;
            cout<<"The String is copied: ";
            b.show();
            cout<<endl;
            break;
        case 3:
            a+b;
            a.show();
            cout<<"\n";
            break;
        case 4:
            b<<a;
            break;
        case 5:
            b>>a;
            break;
        case 6:
            ~a;
            break;
        case 7:
            c=a/b;
            if(c){
                cout<<"YES\n";
            }else cout<<"NO\n";
            break;
        case 8:
            br=1;
            break;
        default:
            cout<<"Enter Valid option\n";
            break;
        }
        if(br) break;
    }
    return 0;
}