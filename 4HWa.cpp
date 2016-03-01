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


int main(){

	ifstream infile;
	infile.open("HW4a.txt", ios::in);
	if (infile.is_open()){
    string instruction;
    while (!infile.eof()){
      instruction = infile.getline();
      /*
      if (instruction == "ADD_FRONT" || instruction == "ADD_BACK" || instruction == "REMOVE_FRONT" || instruction == "REMOVE_BACK"){

      }
      */
      cout << instruction << endl;
    }
		infile.close();
	}
	else
		return 1;
}
