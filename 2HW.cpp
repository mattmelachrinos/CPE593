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

int powerMod(long long x , long long n , long long m){
  long long prod = 1;
  while (n > 0){
    if (n % 2 != 0){
      prod = prod * x % m;
    }
    x = x*x % m;
    n = n/2;
  }
  return prod;
}

bool miller_rabin(int n){
  if (n < 2)
      return false;
  else if (n == 2)
      return true;
  else if (n%2 == 0)
      return false;

  long long k = 1;
  long long m = n-1;
  while (m%2 == 0){
    k++;
    m /= 2;
  }
  srand (time(NULL));
  long long nminus2 = n - 2;
  long long a;
  long long x;
  bool nextWitness;

  for (long j=1 ; j< 10 ; j++){
    a = rand() % (nminus2) + 2;
    x = powerMod(a,m,n);
    nextWitness = false;
    if (x == 1 || x == n - 1)
      continue;
    for (int q ; q < k ; q++){
      x = x*x % n;
      if (x == 1)
        return false;
      else if ( x == m-1){
        nextWitness = true;
        break;
      }

    }
    if (!nextWitness)
      return false;
  }

  return true;
}

int main(){

  ifstream infile;
  infile.open("hw2.dat", ios::in);
  if (infile.is_open()){
    int n;
    infile >> n;
    while ( !infile.eof() ){
      cout << n << " ";
      if(miller_rabin(n)){
        cout << "true" << endl;
      }
      else{
        cout << "false" << endl;
      }
      infile >> n;
    }



    infile.close();
  }
else
  return 1;
}
