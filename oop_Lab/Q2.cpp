#include <iostream>
using namespace std;

int N;
class Matrix {

	int arr[100][100];

public:
	void operator>>(Matrix);
	void operator<<(Matrix);
	void operator+(Matrix );
	void operator-(Matrix );
	void operator*(Matrix );
	void operator~();
};
void Matrix::operator>>(Matrix temp)
{
    cout<<"Enter the elements of Matrix:\n";

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cin>>arr[i][j];
		}
	}
}
void Matrix::operator<<(Matrix temp)
{
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
void Matrix::operator+(Matrix ob)
{
	Matrix mat,temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			mat.arr[i][j] = arr[i][j]
						+ ob.arr[i][j];
		}
	}
	cout<<"Sum of matrix is::\n";
	mat<<temp;
}
void Matrix::operator-(Matrix ob)
{
		Matrix mat,temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			mat.arr[i][j] = arr[i][j]
						- ob.arr[i][j];
		}
	}
	cout<<"Subtraction of matrix is::\n";
	mat<<temp;
}
void Matrix::operator*(Matrix ob)
{
	Matrix mat,temp;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			mat.arr[i][j] = 0;

			for (int k = 0; k < N; k++) {
				mat.arr[i][j] += arr[i][k]
							* (ob.arr[k][j]);
			}
		}
	}
    cout<<"Multiplication of matrix is::\n";
	mat<<temp;
}
void Matrix::operator~()
{
		Matrix mat,temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			mat.arr[j][i] = arr[i][j];
		}
	}
	cout<<"Transpose of matrix is::\n";
	mat<<temp;
}
int main()
{
    Matrix temp;
    cout<<"Enter the size of matrix: ";
    cin>>N;
    Matrix mat1;
    cout<<"Matrix 1:\n";
    mat1>>temp;
    int f;
    do{
        cout<<"Enter:";
        cout<<"\tTo Add:1\n\tTo Subtract:2\n\tTo Multiplication:3\n\tTo find Transpose of matrix:4\n\tExit:5\n";
    
        cin>>f;
        if(f==1)
        {
           Matrix mat2; 
           cout<<"Matrix 2:\n";
           mat2>>temp;
           mat1 + mat2;
        }
        else if(f==2)
        {
            Matrix mat2; 
           cout<<"Matrix 2:\n";
           mat2>>temp;
           mat1 - mat2;
        }
        else if(f==3)
        {
            Matrix mat2; 
           cout<<"Matrix 2:\n";
           mat2>>temp;
           mat1 * mat2;
        }
        else if(f==4)
        {
           ~mat1;
        }
        else
        break;
    }while(f<=4);
	return 0;
}