/*

I pledge my honor that I have abided by the
Stevens Honor System.

                                --Matthew Melachrinos

Worked closely with Dillon Guarino

*/


#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

int binarySearch(int a[], int key , int size){
	int start = 0;
	int end = size-1;
	int guess = 1;
	int number = 0;
	if (key > a[end] || key < a[start])
		return number;

	while (a[guess] != key){
		number++;
		guess = (start + end)/2;
		if (a[guess] > key){
			end = guess;
			guess = (start + end)/2;
		}
		else if (a[guess] < key){
			start = guess;
			guess = (start + end)/2;
		}
		if (guess <= start || guess >= end){
			number = -number;
			break;
		}
	}

	return number;
}

int main(){

	ifstream infile;
	infile.open("HW3.txt", ios::in);
	if (infile.is_open()){
    int sizeOfArray;
    int key;
    int result;
    string first_word;
    infile >> first_word;
		infile >> first_word;
    while (!infile.eof()){
		  infile >> sizeOfArray;
		  int a[sizeOfArray];
		  for (int i=0 ; i<sizeOfArray ; i++){
		  	infile >> a[i];
		  }
      infile >> key;
      result = binarySearch(a,key,sizeOfArray);
      if (result <= 0 )
				cout << "Not Found : " << abs(result) << endl;
			else if (result > 0 )
				cout << "Found : " << result << endl;
    }
		infile.close();
	}
	else
		return 1;
}
