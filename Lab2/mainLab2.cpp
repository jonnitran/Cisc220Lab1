/*
 * mainLab2.cpp
 *
 *  Created on: Mar 1, 2019
 *      Author: Jonni Tran
 */



#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



//Creates 10 to 25 numbers of an array with a range of lowest -10 and highest of 10
int *array_gen(int &length, int &high, int &low);

//Prints array
void print_array(int *array, int legth);

//Makes a filter to the array determined b window size
int hanning_window(int *array, int window_size);

//Takes filter and applies it to array
int *filter_array(int *array, int length, int window_size);

//Prints out the graph from array
void print_graph(int *array, int length, int high, int low);

//Making a 2D array
int **array_2D(int &x, int &y);

int main(){
	srand(time(NULL));
	int high;
	int low;
	int length;
	int hanning_size = 3;
	int x;
	int y;

	//Case 1
	int *pointer_1 = array_gen(length, high, low);

	cout << "Randomly generated array" << endl;
	print_array(pointer_1, length);

	cout << "Graph of array" << endl;
	print_graph(pointer_1, length, high, low);

	cout << endl << endl << endl;

	int *filtered_array_1 = filter_array(pointer_1, length, hanning_size);

	cout << "Filtered array" << endl;
	print_array(filtered_array_1, length);

	cout << "Graph of the filtered array, hanning size " << hanning_size << endl;
	print_graph(filtered_array_1, length, high, low);

	cout << "Printing 2D matrix" << endl;
	int **arr2D_1 = array_2D(x,y);
	for (int i = 0; i < x; i++){
		print_array(arr2D_1[i],y);
	}

	//Case 2
	int *pointer_2 = array_gen(length, high, low);

	cout << "Randomly generated array" << endl;
	print_array(pointer_2, length);

	cout << "Graph of array" << endl;
	print_graph(pointer_2, length, high, low);

	cout << endl << endl << endl;

	int *filtered_array_2 = filter_array(pointer_2, length, hanning_size);

	cout << "Filtered array" << endl;
	print_array(filtered_array_2, length);

	cout << "Graph of the filtered array, hanning size " << hanning_size << endl;
	print_graph(filtered_array_2, length, high, low);

	cout << "Printing 2D matrix" << endl;
	int **arr2D_2 = array_2D(x,y);
	for (int i = 0; i < x; i++){
		print_array(arr2D_2[i],y);		}

	//Case 3
	int *pointer_3 = array_gen(length, high, low);

	cout << "Randomly generated array" << endl;
	print_array(pointer_3, length);

	cout << "Graph of array" << endl;
	print_graph(pointer_3, length, high, low);

	cout << endl << endl << endl;

	int *filtered_array_3 = filter_array(pointer_3, length, hanning_size);

	cout << "Filtered array" << endl;
	print_array(filtered_array_3, length);

	cout << "Graph of the filtered array, hanning size " << hanning_size << endl;
	print_graph(filtered_array_3, length, high, low);

	cout << "Printing 2D matrix" << endl;
	int **arr2D_3 = array_2D(x,y);
	for (int i = 0; i < x; i++){
		print_array(arr2D_3[i],y);
	}


	return 0;
}



//Below are functions 18 - 21
int *array_gen(int &length, int &high, int &low){
	length = (rand() % 15) + 10; //Length of array from 10 - 25
	high = (rand() % 10); //Highest values of array from 0 - 10
	low = (rand() % 10) - 10; //Lowest values of array from -10 - 0
	int *arr = new int[length];

	for (int i = 0; i < length; i++){
			arr[i] = rand() % (high - low) + low;
	}

	return arr;

}

void print_array(int *array, int length){
	for(int i = 0; i < length; i++){

		if(array[i] < 0){
			cout << array[i] << ", "; //Done to align the negative numbers with the rest of them
		}
		else{
			cout << " " << array[i] << ", ";
		}

	}
	cout << endl;
}
int hanning_window(int *array, int window_size){
	int overall_weight = 0;
	int weight = 1;
	int sum = 0;
	//Array[0] is the middle of the array. The left of it is negative and right is positive to make it easier to discern.
	for(int i = 0 - (window_size / 2); i <= (window_size / 2); i++){
		//Weight of the middle is the largest and the edges are the smallest
		overall_weight += weight;
		sum += (array[i] * weight);
		if(i < 0)
			weight++;
		else
			weight--;
	}
	int avg = sum /= overall_weight;

	return avg;
}

int *filter_array(int *array, int length, int window_size){
	int *filter_arr = new int[length];
	//Determines number of 0's to put into the filter
	int border = window_size / 2;
	int i = 0;

	for(i = 0; i < border; i++){
		filter_arr[i] = 0;
	}

	for(; i < length; i++){
			filter_arr[i] = 0;
	}

	//Filtering
	for(; i < length - border; i++){
		filter_arr[i] = hanning_window(&array[i], window_size);
	}

	return filter_arr;
}

void print_graph(int *array, int length, int high, int low){
	for(; low <= high; low++){
		 //To align the graph like in the example
		if(low < 0){
			cout << low << ": ";
		}
		else{
			cout << " " << low << ": ";
		}

		for(int i = 0; i < length; i++){
			if(array[i] == low){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}

int **array_2D(int &x, int &y){
	x = (rand() % 5) + 5; //5 - 10
	y = (rand() % 4)  + 4; //4 - 8

	//Creating 2D array and making it full of 0's
	int **arr_x = NULL;
	arr_x = new int *[x];


	for (int i = 0; i < x; i++){
		arr_x[i] = new int [y];
		for (int j = 0; j < y; j++){
			arr_x[i][j] = 0;

		}
	}
	//Putting the the 1's in the coords from the random numbers
	for (int k = 0; k < 5; k++){
			int rand_x = (rand() % x);
			int rand_y = (rand() % y);

			if (arr_x[rand_x][rand_y] == 0){
				arr_x[rand_x][rand_y] = 1;
			}
			else if (arr_x[rand_x][rand_y] == 1){
				k--;
			}
		}
	return arr_x;
}

