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

void quicksort(int array1[], int L, int R){
	if (R <= L)
		return;
	int i = L;
	int j = R;
	int pivot = array1[rand()%(R-L+1) + L];
//	int pivot = (array1[L]+array1[R])/2;
	while (i < j) {
			while (array1[i] < pivot)
					i++;
			while (array1[j] > pivot)
					j--;

		 if (i < j) {
					swap(array1[j], array1[i]);
		 }
			quicksort(array1, L, j);
			quicksort(array1, j+1, R);
	}

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
		quicksort(array1,0,n-1);
		for (int i = 0 ; i < n ; i++)
			cout << array1[i] << " " ;
		cout << endl;
	}
	else
		return 1;
}
