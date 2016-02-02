
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


bool miller_rabin(int data){
  bool isPrime;
  isPrime = true;
  return isPrime;
}

int main(){

  ifstream infile;
  infile.open("hw2.dat", ios::in);
  int data;
  while (!infile.eof()){
    infile >> data;
    cout << data << " ";
    if(miller_rabin(data)){
      cout << "true" << endl;
    }
    else{
      cout << "false" << endl;
    }
  }



  infile.close();
  return 1;
}
