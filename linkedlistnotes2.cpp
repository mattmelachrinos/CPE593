#include <vector>   //growarray
#include <list>     //LinkedList (probably singly linked)
 using namespace std;

int main(){
  list<int> a;
  for (int i = 0 ; i < 10 ; i++){
    a.push_back(i);
    a.push_front(i);
  }
  for (list<int>::iterator i = a.begin() ; i != a.end() ; ++i)
    cout << *i << " ";
}
