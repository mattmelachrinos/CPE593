/*
        Matthew Melachrinos

        I pledge my honor that I have abided by the Stevens Honor System

        I worked with Dillon Guarino on this assignment.
*/

#include <iostream>
#include <math.h>
using namespace std;



int main()
{
  //Get values of A and B
  long long  a,b;
  cout << "input a: " << endl;
  cin >> a;
  cout << "input b: " << endl;
  cin >> b;

  if (a >= b) {
    cout << "A >= B which is invalid" << endl;
    return 1;
  }
  if (b > 100000000000000) {
    cout << "B cannot be greater than 10^14" << endl;
    return 1;
  }

  bool a_evenness = false;
  if (a%2==0) a_evenness = true;

  long long ba_range = (b-a);
  bool sieve_list [ba_range];
  for ( long long i = 0; i<=(b-a);i++){
    sieve_list[i] = true;
  }

  //handle the even numbers
  if (a_evenness){
    for (long long  i = 0; i <= ba_range; i+=2){
      sieve_list[i] = false;
    }
    if (a == 2){
      sieve_list[0] = true;
    }
  }
  else{
    for ( long long  i = 1; i <= ba_range; i+=2){
      sieve_list[i] = false;
    }
  }

  //handle primes multiples that aren't even
  for ( long long i = 3; i <= sqrt(b); i+=2){
    for ( long long j = i*i; j <= b; j+=i){    //Originally i iterated by 2*i but I found that this caused bugs when I jump to a in the line below
                                                  //and skipping to a makes a much bigger difference for the large numbers.
      if (j < a) {        //if j is less than a, skip to a
        if (a % i==0){
          j = a;
        }
        else{
          j = a + (i-(a%i));
        }
      }
      if (i >= a){
        sieve_list[j-1] = false;
      }
      else{
         sieve_list[j-a] = false;
      }
    }

  }

  if (a==1){
    sieve_list[0] = false;
    sieve_list[1] = true;
  }

  //Count the primes
   long long  number_of_primes = 0;
  for ( long long i = 0; i <=ba_range; i ++){
    if (sieve_list[i])  number_of_primes++;
  }

  cout << "number of primes : " << number_of_primes << endl;

  // Print the Bool Array
  // Don't uncomment this for big ba_range's ..... duh

/*  for (long long int i = 0; i <=ba_range; i ++){
      cout << sieve_list[i];
  }
  cout << endl;
*/



  return 1;
}
