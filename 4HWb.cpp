/*
I pledge my honor that I have abided by the
Stevens Honor System.
                                --Matthew Melachrinos
Worked closely with Dillon Guarino
*/

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

template<typename T>
class LinkedList {
private:
    class Node {
    public:
        T val;
        Node* next;
        Node* prev;
        Node(const T& v, Node* next, Node* prev)
            : val(v), next(next), prev(prev) {}
    };
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    void addFront(const T arr[], int n) {
        if(head == nullptr) {
            head = new Node(arr[0], nullptr, nullptr);
            Node* temp = head;
            for(int i = 1; i<n; i++, temp=temp->next)
                temp->next = new Node(arr[i], nullptr, temp);
        }
        else {
            Node* temp = head;
            for(int i = n-1; i >=0; i--, temp=temp->prev)
                temp->prev = new Node(arr[i], temp, nullptr);
            head = temp;
        }
    }

    void addBack(const T arr[], int n) {
        Node *temp = head;

        if(head!=nullptr)
            for(; temp->next != nullptr; temp = temp->next);

        for(int i = 0; i<n; i++, temp=temp->next)
            temp->next = new Node(arr[i], nullptr, temp);
    }

    void removeFront(int n) {
        if (head == nullptr)
            return;

        for(int i=0; i<n; i++) {
            Node* temp = head;
            temp->next->prev = nullptr;
            head = temp->next;
            delete [] temp;
        }
    }

    void removeBack(int n) {
        if(head == nullptr)
            return;
        Node *temp = head;
        for(; temp->next != nullptr; temp = temp->next);
        for(int i = 0; i < n; i++) {
            Node *del = temp;
            del->prev->next = nullptr;
            temp = del->prev;
            delete [] del;
        }

    }

    void output() {
        for(Node* temp = head; temp != nullptr; temp=temp->next)
            cout << temp->val << " ";
        cout << endl;
    }
};



int main(){
    ifstream infile;
    infile.open("HW4b.txt");
    int n;
    string command, line;
    int arrSize;

    LinkedList<int> myList;

    if (infile.is_open()) {
        while(std::getline(infile,line))
        {
            istringstream iss(line);
            istringstream checkNum(line);
            iss >> command;
            checkNum >> command;
            cout << "COMMAND: " << command << endl;
            if(command == "OUTPUT")
               myList.output();
            else {
                arrSize = 0;
                while (checkNum >> n)
                    arrSize++;
                if(arrSize > 1) {
                    int arr[arrSize] ;
                    for(int i = 0; i < arrSize; i++) {
                        iss >> n;
                        arr[i] = n;
                    }
                    if(command == "ADD_FRONT")
                        myList.addFront(arr, arrSize);
                    else if(command == "ADD_BACK")
                        myList.addBack(arr, arrSize);
                }
                if(command == "REMOVE_FRONT")
                    myList.removeFront(n);
                else if(command == "REMOVE_BACK")
                    myList.removeBack(n);
            }
        }
    }

    else
        cout << "Error opening file\n";

    return 0;
}
