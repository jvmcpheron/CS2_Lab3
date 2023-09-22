#include <iostream>
using namespace std;

class LLData {
private:
    int data;
    LLData* next;

    // Add a pointer to the previous node
    LLData* prev; 
public:
    LLData(int d, LLData* nxt, LLData* prv) {
        data = d;
        next = nxt;
        prev = prv;
    }
    int getData() { return data; }
    LLData* getNext() { return next; }

    // Getter for previous node
    LLData* getPrev() { return prev; } 

    void setData(int d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }

    // Setter for previous node
    void setPrev(LLData* prv) { prev = prv; } 
};

class LinkedList {
private:
    LLData* first;
public:
    LinkedList() { first = NULL; }
    LLData* getFirst() { return first; }

    
    // Add an item to the beginning of the list
    void addItem(int d) {
        if (first == NULL) {

            first = new LLData(d, NULL,  NULL);

        }
        else {

            LLData* newNode = new LLData(d, first, NULL);

            first->setPrev(newNode);
            first = newNode;
        }
    }

    // Add an item to the end of the list
    void addItemAtEnd(int d) {
        if (first == NULL) {
            first = new LLData(d, NULL, NULL);
        }
        else {
            LLData* curr = first;
            while (curr->getNext() != NULL) {
                curr = curr->getNext();
            }
            LLData* newNode = new LLData(d, NULL, curr);
            curr->setNext(newNode);
        }
    }

    // Display the list from the first to the last element
    void showList() {
        LLData* curr = getFirst();
        while (curr != NULL) {
            cout << curr->getData() << " -> ";
            curr = curr->getNext();
        }
        cout << endl;
    }

    // Display the list in reverse order
    void showReverseList() {
        LLData* curr = getFirst();
        while (curr->getNext() != NULL) {
            curr = curr->getNext();
        }
        while (curr != NULL) {
            cout << curr->getData() << " -> ";
            curr = curr->getPrev();
        }
        cout << endl;
    }

    // Delete the first occurrence of an item in the list
    void deleteItem(int d) {
        LLData* curr = getFirst();
        while (curr != NULL) {
            if (curr->getData() == d) {
                LLData* prevNode = curr->getPrev();
                LLData* nextNode = curr->getNext();
                if (prevNode != NULL) {
                    prevNode->setNext(nextNode);
                }
                else {
                    first = nextNode;
                }
                if (nextNode != NULL) {
                    nextNode->setPrev(prevNode);
                }
                delete curr; 
                break; 
            }
            curr = curr->getNext();
        }
    }
};

int main() {
    LinkedList myList;

    // Test addItem and showList
    myList.addItem(1);
    myList.addItem(2);
    myList.addItem(3);

    cout << "Original List: ";
    myList.showList(); 

    // Test addItemAtEnd and showList
    myList.addItemAtEnd(4);
    myList.addItemAtEnd(5);

    cout << "List after adding items to end: ";
    myList.showList(); 
    
    // Test showReverseList
    cout << "Reverse List: ";
    myList.showReverseList(); 

    // Test deleteItem
    myList.deleteItem(1); 
    myList.deleteItem(3); 

    cout << "List after deleting items: ";
    myList.showList(); 

    return 0;
}

