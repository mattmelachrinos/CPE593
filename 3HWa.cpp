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

int search(int a[], int key , int size){
	int start = 0;
	int end = size-1;
	int guess;
	int number = 0;
	cout << " " << endl;
	if (key < a[end] && key > a[start]){
		while (a[guess] != key){
			number++;
			guess = (start + end)/2;
			if (a[guess] > key){
				end = guess;
				guess = (start + end)/2;
			}
			else if ( a[guess] < key){
				start = guess;
				guess = (start + end)/2;
			}


			if (guess <= start || guess >= end){
				number = -number;
				break;
			}
		}
	}
	return number;
}

int main(){

	ifstream infile;
	infile.open("HW3.txt", ios::in);
	if (infile.is_open()){
    int n;
    int key;
    int result;
    string first_word;
    infile >> first_word;
		infile >> first_word;
    while (!infile.eof()){
		  infile >> n;
		  int a[n];
		  for (int i=0 ; i<n ; i++){
		  	infile >> a[i];
		  }
      infile >> key;
      result = search(a,key,n);
      if (result < 0 )
				cout << "Not Found : " << abs(result) << endl;
			else if (result > 0 )
				cout << "Found : " << result << endl;
			else
				cout << "ERROR" << endl;
    }
		infile.close();
	}
	else
		return 1;
}
