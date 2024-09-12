#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    nrElems = 0;
    head = nullptr;
}


void Bag::add(TElem elem) {
    Node* newNode = new Node(elem);
    newNode->next = head; // newNode.next for value newNode->next for *pointers
    head = newNode;
    nrElems++;
}


bool Bag::remove(TElem elem) {
    //walk list with 2 *pointers
    Node* currentNode = head;
    Node* prevNode = nullptr;
    
    //runs and stops when it hits elem
    //now sitting on the correct positions, current is now the elem
    // !error xCode on this comparrison "&& currentNode->elem.first != elem" not working or is it my bad?
    while (currentNode != nullptr && currentNode->elem != elem) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    // If element not found, return false
     if (currentNode == nullptr) {
         return false; // Element is not in the list
     }
    
    //in case currentNode is the very first element and need to remove the head
    if (currentNode != nullptr && prevNode == nullptr) {
        head = head->next;
    } 
    //not sure what this does?
    else if (currentNode != nullptr) {
        prevNode->next = currentNode->next;
        currentNode->next = nullptr;
        }
    delete currentNode; // not sure this line is right?
    nrElems--;
	return true;
}


bool Bag::search(TElem elem) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->elem == elem) {
            return true;  // Element found
        }
        current = current->next;  // Traverse to the next node
    }
    return false;  // Element not found
}

int Bag::nrOccurrences(TElem elem) const {
    int counter = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->elem == elem) {
            counter += 1;
        }
        //forgot to move forward
        current = current->next;
    }
	return counter;
}


int Bag::size() const {
	return nrElems;
}


bool Bag::isEmpty() const {
	return nrElems == 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

