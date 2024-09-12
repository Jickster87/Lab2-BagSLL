#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    currentElem = bag.head;
}

void BagIterator::first() {
    currentElem = bag.head;
}

void BagIterator::next() {
    if (!valid()) {
        throw exception();
    }
    currentElem = currentElem->next;
}


bool BagIterator::valid() const {
    return currentElem != nullptr;
}



TElem BagIterator::getCurrent() const
{
    if (!valid()) {
        throw exception();
    }
    return currentElem->elem;
}
