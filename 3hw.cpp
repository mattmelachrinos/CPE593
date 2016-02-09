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

int * quicksort(int array1[], int R, int L){
	if R <= L;
		return;
	int i = L;
	int j = R;

	while i < j{






	}

	return array1[];
}

int main(){

	ifstream infile;
	infile.open("hw3.dat", ios::in);
	srand(time(NULL));
	if (infile.is_open()){
		int n;
		infile >> n;
		int array1[n];
		for (int i=0 ; i<n ; i++){
			infile >> array1[i];
		}

		infile.close();
		//array1 = quicksort(array1,0,n-1);
		for (int i = 0 ; i < n ; i++)
			cout << array1[i] << " " ;
		cout << endl;
	}
	else
		return 1;
}
