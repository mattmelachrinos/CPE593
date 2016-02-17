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

int search(int a[], int key ){

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
    while (!.eof){
		  infile >> n;
		  int a[n];
		  for (int i=0 ; i<n ; i++){
			   infile >> a[i];
		  }
      infile >> key;
      result = search(a,key);
      if (result == -1)

      delete a[];
    }
		infile.close();
	}
	else
		return 1;
}
