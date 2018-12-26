#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;
const int q = 10;
void multiplication (int matrix1[q][q], int matrix2[q][q], int n, int v, int w) {
	cout << "Final matrix: "<<endl<<endl;
	int matrix3[q][q] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < w; j++) {
				for (int k = 0; k < v; k++) {
					matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
				}
				cout.width(4);
				cout << matrix3[i][j] << "  ";
				
			}
			cout << endl<<endl;
		}
}
void addiction(int matrix1[q][q], int matrix2[q][q], int n, int v) {
	cout << "Final matrix: " << endl << endl;
	int matrix3[q][q] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v; j++) {
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
			cout.width(4);
			cout << matrix3[i][j] << "  ";
		}
		cout << endl<<endl;
	}
}
	
void subtraction (int matrix1[q][q], int matrix2[q][q], int n, int v) {
	cout << "Final matrix: " << endl<<endl;
	int matrix3[q][q];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v; j++) {
			matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
			cout.width(4);
			cout << matrix3[i][j] << "  ";
		}
		cout << endl<<endl;
	}
}
	

int main(){
 int matrix1[q][q] = {0};
 int matrix2[q][q] = {0};
 int matrix3[q][q] = {0};

 int n, v,m,w;
cout << "Number of lines first matrix:";
cin >> n;
cout << "Number of columns first matrix:";
cin >> v;

cout << "Enter first matrix: ";
for (int i = 0; i < n; i++) {
	for (int j = 0; j < v; j++) {
		cin >> matrix1[i][j];
		matrix3[i][j] = matrix1[i][j];
	}
}
cout << "First matrix: " <<endl<<endl;
for (int i = 0; i < n; i++) {
	for (int j = 0; j < v; j++) {
		cout.width(4);
		cout << matrix1[i][j];
		cout << "  ";
	}
	cout << endl<<endl;

}
cout << "Number of lines second matrix:";
cin >> m;
cout << "Number of columns second matrix:";
cin >> w;
cout << "Enter second matrix: ";
for (int i = 0; i < n; i++) {
	for (int j = 0; j < v; j++) {
		cin >> matrix2[i][j];
	}
}
cout << "Second matrix: " << endl << endl;
for (int i = 0; i < n; i++) {
	for (int j = 0; j < v; j++) {
		cout.width(4);
		cout << matrix2[i][j];
		cout << "  ";
	}
	cout << endl << endl;
}

cout << endl << "Choice:" << endl << "1, if you want to add matrices" << endl;
cout << "2, if you want to subtract from one matrix another" << endl;
cout << "3, if you want to multiply two matrices" << endl;
cout << endl;

char choice;
do {
	
	choice = _getch();
	switch (choice) {
		
	case'1': if ((n == m) && (v == w)) {
		addiction(matrix1, matrix2, n, v);
	}
			 else cout << "It is impossible to add these matrices because they have a different number of lines and/or columns.";
		break;
	case'2': if ((n == m) && (v == w)) {
		subtraction(matrix1, matrix2, n, v);
	}
			 else cout << "It is impossible to subtract these matrices because they have a different number of lines and/or columns.";
		break;

	case'3': if (v == m) {
		multiplication(matrix1, matrix2, n, v, w);
	}
			 else cout << "It is impossible to multiply these matrices <<endl<<because the number of columns of the first matrix is not equal to the number of lines of the second matrix";
		break;
	}
} while (choice != 27);
return 0;
}

