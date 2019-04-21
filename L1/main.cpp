/*
 * Lab2.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: Allysa Mae Tuano
 *      Partner: Jonni Tran
 *      Lab TA: Lauren Olson
 *      Lab 1
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
# include <iostream>
# include <stdlib.h>
# include <time.h>
#include <array>


void divider(); // really just to organize the lab
void func1();
void func2(int x);
int func3();
void func4(int *x);
void func5(int &alias);
void func6(int *x, int *y);
void func7(char *a, char *b, char &c, char d);
bool func8a(int *x, int *y);
void func8b();
void func8(int x, int &y);
void func9(int x);
void func10(int x, int y);
int *func11();
void func12(int arr[],int arrint);
int *func13(int *x, int *y, int *z);
int *func14(int *x, int *y, int *z);
void func15(int arr[], int size);
void func16(double arr[], int size);
void func17(int arr[], int &size);


int main() {
	srand(time(NULL));
	int a = 6;
	func1();
	cout << "a = "<<a << endl; // "x + 1"
	cout << "&a = " << &a << endl; // x address
	func2(a); //call by value
	//print value of 6 then 10, different address
	int b = func3();
	divider();
	cout << "b = " << b << endl; // "5"
	cout << "&b = " << &b << endl; // address
	func4(&b);// prints out address of b through a pointer x, and the address of the pointer
	int c = 2;
	cout << "c = " << c << endl; //"2"
	cout << "&c = " << &c << endl; // address of c
	func5(c); // prints out generated value, then adds it to c.
	// input address should match the address of c

	a = 10;
	b = 20;
	func6(&a , &b);
	cout << "a = " << a << endl; // a = 32
	cout << "b = " << b << endl; // b = 42
	divider();

	char char1 = 'w';
	char char2 = 'a';
	char char3 = 't';
	char char4 = 'e';
	char char5 = 'r';

	cout << char1 << char2 << char3 << char4 << char5 << endl; // "water"
	func7(&char1, &char2, char3, char4);
	cout << char1 << char2 << char3 << char3 << char4 << char4 << endl; // "coffee"
	divider();
	cout << "***function 8:" << endl;
	a = 10;
	b = 20;
	c = 30;
	cout << func8a(&a,&b) << endl; // should return and print 0
	cout << func8a(&c,&a) << endl; // return: 1, now a = 30, c = 10
	cout << func8a(&b,&c) << endl; // return: 1, now b = 10, c = 20

	divider();
	func8b();
	func8b();
	func8b();
	divider();

	a = 10;// 3 test cases
	b = 8;
	c = 4;
	func8(5, a);
	func8(3, b); //prints out randomly generated ints in an array
	func8(7, c); // 3rd  parameter has the smallest value
	divider();

	func9(10);
	func9(5);
	func9(7);
	divider();

	func10(5, 10);
	func10(9, 25);
	func10(7, 50);
	divider();

	int *x = func11();
	cout << "variable = "<< *x << endl; // prints out a different value from in the function
	cout << "address = "<< x << endl; // prints out the same address of the variable in the function
	// it works in that theres no errors, but there was a warning.
	divider();

	int arr12ba[25]; // three test cases
	int arr12bb[25];
	int arr12bc[25];
	for (int i = 0; i < 25; i++){
			arr12ba[i] = rand() % 10;
			arr12bb[i] = rand() % 10;
			arr12bc[i] = rand() % 10; // prints each value of the array
		}
	cout << "***function 12 and 12b:" << endl;
	func12(arr12ba,sizeof(arr12ba)/sizeof(arr12ba[0]));
	cout << "***function 12 and 12b:" << endl;
	func12(arr12bb,sizeof(arr12bb)/sizeof(arr12bb[0]));
	cout << "***function 12 and 12b:" << endl;
	func12(arr12bc,sizeof(arr12bc)/sizeof(arr12bc[0]));
	divider();

	int lengtha = 50 - (rand() % 25); // three test cases
	int lengthb = 50 - (rand() % 25);
	int lengthc = 50 - (rand() % 25);
	int higha = 5 + (rand() % 5);
	int highb = 5 + (rand() % 5);
	int highc = 5 + (rand() % 5);
	int lowa = -5 - (rand() % 5);
	int lowb = -5 - (rand() % 5);
	int lowc = -5 - (rand() % 5);

	int *arr13a = func13(&lengtha, &higha, &lowa);
	cout << "***function 13:" << endl;
	func12(arr13a,lengtha); // prints an actual array
	int *arr13b = func13(&lengthb, &highb, &lowb);
	cout << "***function 13:" << endl;
	func12(arr13b,lengthb); // prints an actual array
	int *arr13c = func13(&lengthc, &highc, &lowc);
	cout << "***function 13:" << endl;
	func12(arr13c,lengthc); // prints an actual array
	divider();

	int *arr14a= func14(&lengtha, &higha, &lowa);
	cout << "***function 14:" << endl;
	func12(arr14a,lengtha); // just prints garbage
	int *arr14b = func14(&lengthb, &highb, &lowb);
	cout << "***function 14:" << endl;
	func12(arr14b,lengthb); // just prints garbage
	int *arr14c = func14(&lengthc, &highc, &lowc);
	cout << "***function 14:" << endl;
	func12(arr14c,lengthc); // just prints garbage
	divider(); // this doesn't work because it's relying on a variable that is local to the function



	int *arr15a = func13(&lengtha, &higha, &lowa);
	func15(arr15a, lengtha); // just reusing old arrays
	int *arr15b = func13(&lengthb, &highb, &lowb);
	func15(arr15b, lengthb); // just reusing old arrays
	int *arr15c = func13(&lengthc, &highc, &lowc);
	func15(arr15c, lengthc); // just reusing old arrays
	divider();


	double arr16a[10]; // making a double array for function 16
	double arr16b[10]; // three test cases
	double arr16c[10];
	for (int i = 0; i < 10; i++){
			arr16a[i] = (double)rand()/10;
			arr16b[i] = (double)rand()/10;
			arr16c[i] = (double)rand()/10;
	}
	func16(arr16a, 10); // prints out 10 different addresses per array
	func16(arr16b, 10);
	func16(arr16c, 10);
	divider();



	int size = 25;
	int arr17a[size];// three test cases
	int arr17b[size];
	int arr17c[size];
	for (int i = 0; i < size; i++){
			arr17a[i] = rand() % 10;// generates each value of the array
			arr17b[i] = rand() % 10;
			arr17c[i] = rand() % 10;
		} // recycling function 12.b to make an array for function 17

	func17(arr17a, size);
	func17(arr17b, size);
	func17(arr17c, size);



}
void divider() {
	cout << "*****************************" << endl;
}
void func1(){
	cout << "***function 1:" << endl;
	int x = 1;
	cout << "int x = " << x << endl;
	cout << "int &x = " << &x << endl;
	divider();

}

void func2(int x){
	//call by value
	cout << "***function 2:" << endl;
	x += 4;
	cout << "int x = " << x << endl;
	cout << "int &x = " << &x << endl;
	divider();
}

int func3(){
	cout << "***function 3:" << endl;
	int x = 5;
	cout << "int x = " << x << endl;
	cout << "int &x = " << &x << endl;
	return x;
}

void func4(int *x){
	//takes in an integer address
	//returns nothing
	//cubes the value at the address
	//prints the value, address in the parameter, address of the parameter
	//call by pointer
	cout << "***function 4:" << endl;
	*x = *x^3;
	cout << "int x = " << x << endl;
	cout << "int &x = " << &x << endl;
	divider();
}

void func5(int &alias){
	//takes in input parameter as an alias for an integer
	//returns nothing
	//create a variable, set it to a random number between 1-10, add it to the input parameter
	//print the random number, new value, address of input parameter.
	//call by reference
	cout << "***function 5:" << endl;
	//srand(time(NULL));
	int value = rand() %10;
	alias += value;
	cout << "random number = " << value << endl;
	cout << "new value = " << alias << endl;
	cout << "input address = " << &alias << endl;
	divider();
}

void func6(int *x, int *y){
	//takes in 2 pointer addresses
	//returns nothing
	//create an int address variable, set that to the first parameter, change to 32
	//change the address  in the variable so it holds the second parameter, change to 42
	cout << "***function 6:" << endl;
	int *a6 = x;
	*a6 = 32;
	int *b6 = y;
	*b6 = 42;
}

void func7(char *a, char *b, char &c, char d){
	//uses call by value, pointer, and reference to modify characters
	cout << "***function 7:" << endl;
	*a = 'c';
	*b = 'o';
	c = 'f';
	d = 'p';

}

bool func8a(int *x, int *y){
	//swaps if x > y
	//returns boolean true if switched
	int temp;
	if (*x > *y){
		temp = *x; /* save the value at address x */
		*x = *y; /* put y into x */
		*y = temp; /* put x into y */
		return true;
	}
	return false;

}

void func8b(){
	//srand(time(NULL));
	for (int i = 0; i < 20; i++){
		cout << "***function 8b:" << endl;
		int x = rand() %25; // this now generates actually random values with constantly changing seeds
		int y = rand() %25;
		if (func8a(&x,&y)){
			cout << "swap" << endl;
		}
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
}

void func8(int x, int &y){ //x is length, y is pass by reference
	//locate the smallest number in the randomly generated array and put it in the 3 parameter
	//srand(time(NULL));
	y = -1;
	int arr[x];
	arr[0] = rand() % 50;
	int small = arr[0];
	for (int i = 1; i < x; i++){
			arr[i] = rand() % 50;
			if (small > arr[i]){
				small = arr[i];
			}
		}
	arr[2] = small;
	for (int i = 0; i < x; i++){
			cout << arr[i] << ' '; // prints each value of the array
		}
	cout << endl;
}


void func9(int x){
	cout << "***function 9:" << endl;
	//srand(time(NULL));
	int arr[x];
	for (int i = 0; i < x; i++){
			arr[i] = rand() % 50;
			cout << arr[i] << ' '; // prints each value of the array
		}
	cout << endl;
	for (int i = 0; i < x/2; i++){
			int temp = arr[i];
			arr[i] = arr[x-i-1];
			arr[x-i-1] = temp;
		}
	for (int i = 0; i < x; i++){
				cout << arr[i] << ' ';
	}
	cout << endl;

}

void func10(int x, int y){
	// takes in an int for the length of an array
	// takes in an int for the range of numbers
	// generates random numbers, prints out numbers from small to large
	cout << "***function 10:" << endl;
	//srand(time(NULL));
		int arr[x];
		int *small = &y;
		for (int i = 0; i < x; i++){
			arr[i] = rand() % y;
		}

		for (int j = 0; j < x; j++){
			for (int k = 0; k < x; k++){
				if (*small > arr[k]){
					small = &arr[k];
				}
			}
			cout << *small << ' ';
			*small +=y+1;
		}


		cout << endl;
}

int *func11(){
	// creates a new function on stack
	// prints out the value and address, returns address
	// make sure int *x = func11(); for the main
	cout << "***function 11:" << endl;
	int stack = 3;
	cout << "variable = "<<stack << endl;
	cout << "address = "<< &stack << endl;
	return &stack;
}

void func12(int arr[],int arrint){
	// takes in an int array and returns nothing
	// prints out array
	// used for other functions
	for (int i = 0; i < arrint; i++){
			cout << arr[i] << ' '; // prints each value of the array
		}
	cout << endl;
}


int *func13(int *x, int *y, int *z){
	// takes in 3 int pointers
	// x = length
	// y = high number
	// z = low number
	int *arr = new int[*x];
	for (int i = 0; i < *x; i += 2){
		arr[i] = *z + rand() % (*y-*z);// range between - to + numbers
	}
	return arr;
}

int *func14(int *x, int *y, int *z){
	// takes in 3 int pointers
	// x = between 25 - 50
	// y = high number
	// z = low number
	int arr[*x];
	for (int i = 0; i < *x; i += 2){
		arr[i] = *z + rand() % (*y-*z);// range between - to + numbers
	}
	return arr;
}

void func15(int arr[], int size){
	cout << "***function 15:" << endl;
	for (int i = 0; i < size; i++){
				cout << &arr[i] << ' '; // prints each address of the array
			}
		cout << endl;
}

void func16(double arr[], int size){
	cout << "***function 16:" << endl;
	for (int i = 0; i < size; i++){
				cout << &arr[i] << ' '; // prints each address of the array
			}
		cout << endl;
}

void func17(int arr[], int &size){
	cout << "***function 17:" << endl;
	int arrsize = size;
	//int arr2 = new int[arrsize];
	for (int i = 1; i < size; i++){ // determine the size before declaring the new array
		if (arr[i] == arr[i-1]){
			arrsize -= 1;
		}
	}
	int *arr2 = new int[arrsize]; //Initializing a new array on the heap
	arr2[0] = arr[0]; // setting the first values equal
	int j = 1; // a counter for arr2

	for (int i = 1; i < size; i++){
		if (arr[i] == arr [i-1]){
		}
		else {
			arr2[j] = arr[i];
			j += 1;
		}
	}

	for (int i = 1; i < arrsize; i++){
			cout << arr2[i] << ' ' ;
		}
	cout << endl;
}
