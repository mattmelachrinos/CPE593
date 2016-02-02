
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;


bool miller_rabin(int data){
  bool isPrime;
  int k = 1;
  float m;
  while (1){
    m = (data-1)/(pow(2,k));
    if (m != (int)m){
      k--;
      m = (data-1)/(pow(2,k));
      break;
    }

    k++;
  }
  srand (time(NULL));
  int dataminus2 = data - 2;
  int a;
  a = rand() % (dataminus2) + 2;
  //int x = pow(a,m) % data;
  cout << a << ' ';

  return isPrime;
}

int main(){

  ifstream infile;
  infile.open("hw2.dat", ios::in);
  int data;
  infile >> data;
  for (; !infile.eof() ; infile >> data){
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
