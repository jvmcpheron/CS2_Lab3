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
