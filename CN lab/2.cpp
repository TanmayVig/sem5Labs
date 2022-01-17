#include<iostream>
#include <string>

using namespace std;

// function to encrypt the plain text
void Encrypt(string key, string &s){

    for(int i=0;i<s.length();i++){ // iterating over plain text
        // checking if character is an alphabet
        if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))) continue;

        int first_char = islower(s[i]) ? 'a' : 'A',
            //converting range from ascii to 0-25
            rel_s = s[i]- first_char, 
            rel_key = key[i]- first_char;

            //encrypting text
            rel_s+=rel_key; 
            rel_s%=26;

            //changing range back to ascii and storing
            s[i]=rel_s + first_char;
    }
}

// function to decrypt the plain text
void Decrypt(string key,string &s){ 

    for(int i=0;i<key.length();i++){// iterating over plane text
        // checking if character is an alphabet
        if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))) continue;

        int first_char = islower(s[i]) ? 'a' : 'A',
            // decrypting text
            rel_s = s[i]- key[i]; 
            if(rel_s<0){
                rel_s+=26;
            }

            //changing range back to ascii and storing
            s[i]=rel_s + first_char;
    }
}

int main(){
    string input, key;
    int choose;
    cout<<"Enter the plain test:\t";
    getline(cin, input); // taking plain text input
    cout<<"Enter Key of length "<<input.size()<<":\t";
    getline(cin,key); // taking key input
    cout<<"To Encrypt enter 1.\nTo Decrypt enter 2.\n";
    cin>>choose; // taking command to encrypt or decrypt
    if(choose==1){
        Encrypt(key,input);
        cout<<"Encrypted: "<<input<<endl;
    }
    else{
        Decrypt(key,input);
        cout<<"Decrypted: "<<input<<endl;
    }
    return 0;
}