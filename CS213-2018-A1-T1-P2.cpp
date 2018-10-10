// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <valarray>


//#include <cassert>
int need;
using namespace std;
// A structure to store a matrix
struct matrix
{
  valarray<int> data;       //valarray that will simulate matrix
  int row, col;
};



// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2);
matrix operator-  (matrix mat1, matrix mat2);
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar



matrix operator+  (matrix mat1, matrix mat2){            // Add if same dimensions
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix (mat1.row, mat1.col, data4, mat4);
if(mat1.row==mat2.row&&mat1.col==mat2.col){
     for (int i = 0; i < mat1.row*mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]+mat2.data[i];
}

    return mat4;
}}

matrix operator-  (matrix mat1, matrix mat2){             // Sub if same dimensions
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix (mat1.row, mat1.col, data4, mat4);
if(mat1.row==mat2.row&&mat1.col==mat2.col){
     for (int i = 0; i < mat1.row*mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]-mat2.data[i];
}}
    return mat4;
}



matrix operator*  (matrix mat1, matrix mat3){
matrix mat4;
int data4[mat1.row*mat3.col];
createMatrix (mat1.row, mat3.col, data4, mat4);
if(mat1.col==mat3.row){
for (int i = 0; i < mat1.row; i++) {
        for (int j = 0; j < mat3.col; j++) {
            int sum = 0;
            for (int k = 0; k < mat1.col; k++)
                sum = sum + mat1.data[i * mat1.col + k] * mat3.data[k * mat3.col + j];
            mat4.data[i * mat4.col + j] = sum;
        }

    }}
    return mat4;
}

matrix operator+  (matrix mat1, int scalar){          // Add a scalar
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix (mat1.row,mat1.col, data4, mat4);
cout <<endl<<"enter scaler : ";
int x;
cin >>x;
for (int i = 0; i < mat1.row*mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]+x;
}
    return mat4;
}

matrix operator-  (matrix mat1, int scalar){             // Subtract a scalar
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix (mat1.row, mat1.col ,data4, mat4);
cout <<endl<<"enter scaler : ";
int x;
cin >>x;
for (int i = 0; i < mat1.row * mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]-x;
}
    return mat4;
}

matrix operator*  (matrix mat1, int scalar){               // Multiple by scalar
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix (mat1.row,mat1.col, data4, mat4);

cout <<endl<<"enter scaler : ";
int x;
cin >>x;
for (int i = 0; i < mat1.row*mat1.col; ++i)
    {
        mat4.data[i]=mat1.data[i]*x;
}
    return mat4;
}

ostream& operator<< (ostream &out,  matrix mat ) {
    for (int i = 0; i < mat.row; ++i)
    {
        for (int j = 0; j < mat.col; ++j)
        out << " " << mat.data[i * mat.col + j];
        out << endl;
    }
    return out;
}


int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {10,15,20,25,30,35,40,45};
  int data3 [] = {2,4,6,8,10,12,14,16};
  matrix mat1, mat2, mat3;
  createMatrix (4, 2, data1, mat1);
  createMatrix (4, 2, data2, mat2);
  createMatrix (2, 4, data3, mat3);
  cout << mat1 <<endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  loop: cout <<endl<<" Choose"<<endl<<endl;
  cout << ("1- mat1 + mat2") << endl ;
  cout << ("2- mat1 - mat2") << endl ;
  cout << ("3- mat1 * mat2") << endl ;
  cout << ("4- mat1 + scaler") << endl ;
  cout << ("5- mat1 - scaler") << endl ;
  cout << ("6- mat1 * scaler") << endl ;
  cout<<"7- end"<<endl;
  cin>>need;
    if (need==7){
        return 0;
    }
  if (need==1){

  cout << (mat1 + mat2) << endl << endl;
  goto loop;
  }


  if (need==2){

  cout << (mat1 - mat2) << endl << endl;
   goto loop;
   }

    if (need==3){

  cout << (mat1 * mat3) << endl << endl;
     goto loop;
}

    if (need==4){

  cout << (mat1+2) << endl << endl;
     goto loop;
}

    if (need==5){

  cout << (mat1-2) << endl << endl;
     goto loop;
}

    if (need==6){

  cout << (mat1*2) << endl << endl;
     goto loop;
}


/* The next code will not work until you write the functions


  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
 }

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data.resize (row * col);
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}
