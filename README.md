# CS2_Lab3

# Doubly Linked Lists
## Introduction
Given some of the students in the class have not seen Linked Lists we are going to do some more practice with them in this week's homework and lab.  Another variation on Linked Lists is a doubly linked list.  In a doubly linked list you have a pointer to not only the next node in the list but also to the previous node in the list.

## What to Implement
I am going to include my singly linked list code again, though you can start your own if you prefer.  You should implement, and test, a doubly linked list code that has an addItem, addItemAtEnd, showList, showReverseList (prints out the list in reverse order), and a deleteItem which finds the first occurrence of an item in a list and deletes that item.

Note that my picture shows a simple doubly linked list.  People like to use dummy first and last nodes (like we saw in the homework) with doubly linked lists.  You are welcome to do this if you like, but you do not have to do so.

#include <iostream>
using namespace std;

class LLData {
private:
    int data;
    LLData *next;
    LLData() {}
public:
    LLData(int d, LLData *nxt) {
        data = d;
        next = nxt;
    }
    int getData() { return data; }
    LLData* getNext() { return next; }
    void setData(int d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }
};
class LinkedList {
private:
    LLData* first;
public:
    LinkedList() { first = NULL; }
    LLData *getFirst() { return first; }
    void addItem(int d) {
        first = new LLData(d,first);
    }
    void showList() {
        LLData *curr = getFirst();
        while (curr != NULL) {
            cout << curr->getData() << " -> ";
            curr = curr->getNext();
        }
        cout << endl;
    }
    void addItemAtEnd(int d) {
        if (first == NULL) {
            first = new LLData(d,first);
        }
        else {
            LLData* curr = first;
            while (curr->getNext() != NULL) {
                curr = curr->getNext();
            }
            curr->setNext(new LLData(d,curr->getNext()));
        }
    }
};


## What To Turn In
Submit your code.  In addition, you should design testing to effectively test your code and show the output your code produces for your tests.



