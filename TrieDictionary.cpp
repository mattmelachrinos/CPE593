#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Trie {
private:
  class Node {
  public:
    Node* next[26];
    bool isWord;
  };

  Node* root;
public:


  Trie(){
    root = new Node();
  }

 	void load(string word) {
    Node* temp = root;
    for(int i = 0 ; i < word.length() ; i++){
      word[i] = toupper(word[i]);
      int locationInAlphabet = word[i] - 65;
      if(temp->next[locationInAlphabet]){
        temp = temp->next[locationInAlphabet];
      }
      else{
        temp->next[locationInAlphabet] = new Node();
        temp = temp->next[locationInAlphabet];
      }
    }
    temp->isWord = true;

  }

  bool isWord(string word){
    Node* temp;
    temp = root;
    for(int i = 0 ; i < word.length() ; i++){
      word[i] = toupper(word[i]);
      int locationInAlphabet = word[i] - 65;
      if(temp->next[locationInAlphabet]){
        temp = temp->next[locationInAlphabet];
      }
      else{
        return false;
      }
    }
    return temp->isWord;
  }
};

int main() {
  Trie dictTrie;
  ifstream infile;
  infile.open("dict.txt", ios::in);
  string word;
  if(infile.is_open()){
    int i = 0;
    while(!infile.eof()){
      getline(infile,word);
      dictTrie.load(word);
      if(i%10000 == 0){
        cout << i << endl;
      }
      i++;
    }
  }
  infile.close();
  return 0;
}
