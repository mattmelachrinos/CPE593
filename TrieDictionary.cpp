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
    string word;
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
    temp->word = word;

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

  Node * getRoot(){
    return root;
  }

  void findAllWords(char **array, Node *pointer, int x, int y){
    while(0 < x  && x < 4){
      while(0 < y && y < 4){
        if (pointer->isWord)
          cout << pointer->word << " is a word." << endl;
        if (pointer != nullptr)
          findAllWords(array, pointer, x, y);
      }
    }
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

//Building boggle array below
  ifstream boggleFile;
  boggleFile.open("boggle.dat", ios::in);
  char letter;
  int size;

  if(boggleFile.is_open())
    boggleFile >> size;
  char **boggleArray;
  boggleArray = new char *[size];
  for(int i = 0; i <size; i++)
      boggleArray[i] = new char[size];


  for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
      boggleFile >> letter;
      boggleArray[i][j]= letter;
      cout << boggleArray[i][j] << endl;
    }
  }
//boggle file built

  for(int x = 0 ; x < size ; x++){
    for(int y = 0 ; y < size ; y++)
      dictTrie.findAllWords(boggleArray , dictTrie.getRoot(), x, y);
  }



  return 0;
}
