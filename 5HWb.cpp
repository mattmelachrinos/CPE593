#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Hashmap {
private:
	string** table;
	int size;
	int used;
	int limit;
	int hist[11];

	int hash(const string& s) const {
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
			sum = sum * 26 + s[i];
		return sum;
	}
public:
	Hashmap(int initialSize) {
		int i;
		for (i = 1; i < initialSize; i *= 2)
			;
		limit = i / 2;
		size = limit*2;
		table = new string*[size];
		for (int i = 0; i < size; i++)
			table[i] = nullptr;
		used = 0;
		for (int i = 0; i < 11; i++)
			hist[i] = 0;
	}
	~Hashmap() {
		for (int i = 0; i < size; i++)
			delete table[i];
		delete [] table;
	}
	Hashmap(const Hashmap& orig)  {
		table = new string*[orig.size];
		size = orig.size;
		used = orig.used;
		limit = orig.limit;
		for (int i = 0; i < 11; i++)
			hist[i] = orig.hist[i];
		for (int i = 0; i < orig.size; i++)
			if (orig.table[i] == nullptr)
				table[i] = nullptr;
			else
				table[i] = new string(*orig.table[i]);
	}
	Hashmap& operator=(const Hashmap& orig) {
		if (this != &orig) {
			this->~Hashmap();
#if 0
			for (int i = 0; i < size; i++)
				delete table[i];
			delete [] table;
#endif
			table = new string*[orig.size];
			size = orig.size;
			used = orig.used;
			limit = orig.limit;
			for (int i = 0; i < 11; i++)
				hist[i] = orig.hist[i];
			for (int i = 0; i < orig.size; i++)
				if (orig.table[i] == nullptr)
					table[i] = nullptr;
				else
					table[i] = new string(*orig.table[i]);
		}
		return *this;
	}

	void add(const string& s) {
		int bin = hash(s);
		int count = 0;
		while (table[bin] != nullptr) {
			bin = (bin+1) % size;
			count ++;
		}
		hist[count]++;
		table[bin] = new string(s);
	}
	void printHist(){
		cout << "insert    ||    Count" << endl;
		for (i = 0 ; i<hist.size() ; i++)
			cout << i << "             " << hist[i] << endl;
	}
};

int main() {
	Hashmap m(100000);
	ifstream infile;
	infile.open("dict.txt", ios::in);
	string word;
	if(infile.is_open()){
		int i = 0;
		while(!infile.eof()){
			getline(infile,word);
			m.add(word);
			if(i%10000 == 0){
				cout << i << endl;
			}
			i++;
		}
	}
	infile.close();

	m.printHist();

return 0;
}
