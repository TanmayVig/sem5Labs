#include<iostream>
#include<string>

using namespace std;

// function to decrypt cipher
string decrypt(string code, unsigned int key){
    for(int c=0;c<code.size();c++){ // itereting every element in cypher
        // ignore characters other then alphabets
        if(!((code[c]>='a' && code[c]<='z') || (code[c]>='A' && code[c]<='Z'))) continue;

        int firstChar= islower(code[c]) ? 'a' : 'A', //checking if the char in capital or not
            relativeVal=code[c]-firstChar, // shifting the values of character between 0-25
            newVal=relativeVal-key; // shifting values accotding to key
        if(newVal<0){ // changing values if they are negative
            newVal+=26;
        }
        code[c]=firstChar + newVal; // changing realative values to original values and storing them
    }
    return code;
}

// function to encrypt the cipher
string encrypt(string code, unsigned int key){
    for(int c=0;c<code.size();c++){ // iterating every element in cypher
        //ignore characters other then alphabets
        if(!((code[c]>='a' && code[c]<='z') || (code[c]>='A' && code[c]<='Z'))) continue;

        int firstChar=islower(code[c]) ? 'a':'A', //checking if the char in capital or not
            relativeVal=code[c]-firstChar,// shifting the values of character between 0-25
            newVal=(relativeVal+key)%26;// shifting values according to key and mentaining them in range 0-25
        
        code[c] = firstChar + newVal;// changing realative values to original values and storing them
    }
    return code;
}

int main(){
    unsigned int key;
    string code,descision;
    
    // taking input for code
    cout<<"Enter the code.\t";
    getline(cin,code);

    //taking input for key
    cout<<"Enter the key:\t";
    cin>>key;

    // giving user choice to Decrypt or Encrypt
    cout<<"Enter \"D\" to decrypt and \"E\" to encrypt\n";
    cin>>descision;

    key%=26; // k must be in range 0-25

    if(descision=="D"){ // decrypting code
        cout<<decrypt(code,key)<<endl;
    }else{ // encrypting code
        cout<<encrypt(code,key)<<endl;
    }
    return 0;
}