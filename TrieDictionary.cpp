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
  // read the dict file
  if(infile.is_open()){
    while(!infile.eof()){
      getline(infile,word);
      dictTrie.load(word);

    }
  }
  infile.close();
//Trie Dictionary is now built


  ifstream boggleFile;
  boggleFile.open("boggle.dat", ios::in);
  char letter;
  int size;

  if(boggleFile.is_open())
    boggleFile >> size;
  char boggleArray[size*size];

  for(int i = 0 ; i < size*size ; i++){
    boggleFile >> letter;
    boggleArray[i] = letter;
    cout << boggleArray[i] << endl;
  }




  return 0;
}
