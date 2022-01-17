#include<iostream>
#include<math.h>
using namespace std;
float encmatrix[3][1], decmatrix[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];
void KeyMatrix() { 
   int i, j;
   char mes[3];
   cout<<"\nEnter plain text of length 3(use A through Z): ";
   cin>>mes;
   for(i = 0; i < 3; i++)
   msg[i][0] = mes[i] - 65;
   cout<<"Enter 3x3 matrix key:\n";
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++) {
      cin>>a[i][j];
      m[i][j] = a[i][j];
   }
}
void Encrypt() { //encrypts the message
   int i, j, k;
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
   encmatrix[i][j] = encmatrix[i][j] + a[i][k] * msg[k][j];
   cout<<"\nEncrypted text: ";
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(encmatrix[i][0], 26) + 65); //modulo 26 is taken for each element of the matrix obtained by multiplication
}
void inversematrix() { //find inverse of key matrix
   int i, j, k;
   float p, q;
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++) {
      if(i == j)
         b[i][j]=1;
      else
         b[i][j]=0;
   }
   for(k = 0; k < 3; k++) {
      for(i = 0; i < 3; i++) {
         p = m[i][k];
         q = m[k][k];
         for(j = 0; j < 3; j++) {
            if(i != k) {
               m[i][j] = m[i][j]*q - p*m[k][j];
               b[i][j] = b[i][j]*q - p*b[k][j];
            }
         }
      }
   }
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++)
   b[i][j] = b[i][j] / m[i][i];
   cout<<"\n\nInverse Matrix:\n";
   for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++)
      cout<<b[i][j]<<" ";
      cout<<"\n";
   }
}
void Decrypt() { //decrypt the message
   int i, j, k;
   inversematrix();
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
   decmatrix[i][j] = decmatrix[i][j] + b[i][k] * encmatrix[k][j];
   cout<<"\nDecrypted text: ";
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(decmatrix[i][0], 26) + 65); //modulo 26 is taken to get the original message
   cout<<"\n";
}
int main() {
   KeyMatrix();
   int n;
   Encrypt();
   cout<<"\nEnter 1 to Decrypt and 0 to exit.\t";
   cin>>n;
   if(n){
       Decrypt();
   }
   return 0;
}