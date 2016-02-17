/*

I pledge my honor that I have abided by the Stevens Honor System.

                                --Matthew Melachrinos

Worked closely with Dillon Guarino

*/


#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int quicksort(int a[], int key ){

}

int main(){

	ifstream infile;
	infile.open("HW3.txt", ios::in);
	srand(time(NULL));
	if (infile.is_open()){
    while (!.eof){
		  int n;
      int key;
		  infile >> n;
		  int a[n];
		  for (int i=0 ; i<n ; i++){
			   infile >> a[i];
		  }
      infile >> key;
    }
		infile.close();
	}
	else
		return 1;
}
