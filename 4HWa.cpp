/*
I pledge my honor that I have abided by the
Stevens Honor System.
                                --Matthew Melachrinos
Worked closely with Dillon Guarino
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;


class GrowArray {
  private:
  	int* p;
  	int size;
  	int used;
  	// this should double the size of your list
  	void grow() {
      size *= 2;
      int* temp = new int[size];
      copy(p, p+size, temp);
      p = temp;
      temp = nullptr;
      delete [] temp;
  	}

  public:
  	GrowArray() : p(new int[1]), size(1), used(0) {
  	}
  	GrowArray(int capacity) : p(new int[capacity]), size(capacity), used(0) {
  	}
  	~GrowArray() {delete [] p;}

  //  void addstart(int v []){
  //    used++;
  //  }
    void addEnd(int v [] , int n){
      used += n;
      if (used > size)
        grow();
      for (int i = 0 ; i < n ; i++)
        p[i+n-1] = v[i];
    }
    void addStart(int v [] , int n){
      int* temp = new int[used];
      copy(p,p+used,temp);
      used += n;
      if (used > size)
        grow();
      for (int i = 0 ; i < n ; i++)
        p[i] = v[i];
      copy(temp, temp+used-n, p+n);
      delete temp;
    }
    void removeFront(int v[]){
      int a = v[0];
      int* temp = new int[used];
      copy(p+a, p+used,temp);
      copy(temp,temp+used-a, p);
      size -= a;
      delete temp;
    }
    void removeBack(int n[]){
      used -= n[0];
    }
    void printArray(){
      for (int i = 0 ; i < used ; i++)
        cout << p[i] << ' ';
      cout << endl;
    }
  	int getCapacity() const {
      return size;
  	}
  	int getUsed() const {
  		return used;
  	}
  	int get(int i) const { //O(1)
  		if (i < 0 || i >= used)
  			throw "Die!";
  		return p[i];
  	}
    void set(int i, int v) { // O(1)
  		if (i < 0 || i >= used)
  			throw "Die!";
  		p[i] = v;
  	}

};

int main(){
  GrowArray a;

	ifstream infile;
	infile.open("HW4a.txt", ios::in);
  string instruction, line;

	if (infile.is_open()){

    while (getline(infile,line)){

      istringstream iss(line);
      istringstream checkNum(line);
      iss >> instruction;
      checkNum >> instruction;
      int n = 0;
      while (checkNum >> n)
        n++;
      int values [n];
      for (int i = 0 ; i < n ; i++){
        iss >> values[i];
      }

      if (instruction == "ADD_FRONT"){
        a.addStart(values,n);
      }
      else if (instruction == "ADD_BACK"){
        a.addEnd(values,n);
      }
      else if (instruction == "REMOVE_FRONT"){
        a.removeFront(values);
      }
      else if (instruction == "REMOVE_BACK"){
        a.removeBack(values);
      }
      else if (instruction == "OUTPUT"){
        a.printArray();
      }


      cout << instruction << endl;
    }
		infile.close();
	}
	else
		return 1;
}
