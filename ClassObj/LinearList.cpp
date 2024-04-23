#include "LinearList.h"

// -------------------------------------------------------------------------
// base linear list
// ------------------------------------------------------------------------- 
LinearList::LinearList(int num){
    size = (num > 10) ? num: 10;
    buffer = new int[size];
}

LinearList::~LinearList(){
    delete []buffer;
}

bool LinearList::insert(int x, int i) {}

bool LinearList::remove(int &x, int i) {}

int LinearList::element(int i) const {}

int LinearList::search(int x) const {}

int LinearList::length() const {}

// -------------------------------------------------------------------------
// queue
// ------------------------------------------------------------------------- 
bool Queue::enQueue(int x){
    return insert(x, length());
}

bool Queue::deQueue(int &x){
    return remove(x, 1);
}

// -------------------------------------------------------------------------
// stack
// ------------------------------------------------------------------------- 
bool Stack::push(int x){
    return insert(x, 1);
}

bool Stack::pop(int &x){
    return remove(x, 1);
}
