#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -99999;

// Default constructor of the class DynamicStack. It uses 16 as the initial
// capacity of the array, and allocates the required memory space for the
// stack. The function appropriately initializes the fields of the created
// empty stack.
// setting initial capacity to 16
// size declared as zero and creating the stack with initial capacity
DynamicStack::DynamicStack() {

    init_capacity_ = 16;
    size_ = 0;
    items_ = new DynamicStack::StackItem[init_capacity_];

}

// Parametric constructor of the class DynamicStack. It allocates the required
// memory space for the stack of the given capacity. The function
// appropriately initializes the fields of the created empty stack.
// setting capacity, definining initial capacity, initial size is zero, and new stack with capacity
DynamicStack::DynamicStack(unsigned int capacity){

    capacity_ = capacity;
    init_capacity_ = capacity_;
    size_ = 0;
    items_ = new DynamicStack::StackItem[capacity_];

}

// Destructor of the class DynamicStack. It deallocates the memory space
// allocated for the stack.
// deleting stack since it was creating using the new operator
DynamicStack::~DynamicStack() {

    delete[] items_;

}

// Returns true if the stack is empty and false otherwise.
//empty means the size is 0, checking for this condition and returning true, if condition doesn't run, function returns false
bool DynamicStack::empty() const {

    if (size_ == 0)
    {
        return true;
    }
    return false;

}

// Returns the number of items in the stack.
//size is already defined, just simply have to return ir
int DynamicStack::size() const {

    return size_;
}

// Takes as an argument a StackItem value. If the stack is not full, the value
// is pushed onto the stack. Otherwise, the capacity of the stack is doubled,
// and the item is then pushed onto the resized stack.
//doubling capacity if the size has reached it so that the new valiue can be added
// the value is set to the array items at index size, size is then increased so the value is at the last index
void DynamicStack::push(StackItem value) {

    if ( size_ >= capacity_)
    {
        capacity_ = capacity_ * 2;
    }

    items_[size_] = value;
    size_++;

    return;

}

// Removes and returns the top item from the stack as long as the stack is
// not empty. If the number of items remaining in the stack after popping
// is less than or equal to one quarter of the capacity of the array, then
// the array is halved. However, if the new halved capacity is less than
// the initial capacity, then no resizing takes place. Finally, If the stack
// is empty before the pop, the EMPTY STACK constant is returned.
// if size is zero, call empty stack
//create reference to the top item before removing it, so it can be returned
DynamicStack::StackItem DynamicStack::pop() {

    if (size_ == 0)
    {
        return EMPTY_STACK;
    }

    DynamicStack::StackItem reference = items_[size_-1];
    size_--;
// comparison with 1/4 of the capacity, and half the capacity with the initial capacity, if both true, the capacity is halved
    if (size_ <= (capacity_ / 4) && (capacity_ / 2) >= init_capacity_ )
    {
        capacity_ = capacity_/2;
    }
// returning reference to popped value
    return reference;
}

// Returns the value at the top of the stack without removing it. If the
// stack is empty, it returns the EMPTY_STACK constant instead
//size-1 is the last index, returning this index in the items_ will give the value at the top without removing it

DynamicStack::StackItem DynamicStack::peek() const {

    if (size_ == 0)
    {
        return EMPTY_STACK;
    }

    return items_[size_-1];

}

// Prints the stack items sequentially and in order, from the top to the
// bottom of the stack.
// not graded
// creating i to iterate through indices of items_
//outputting the value at each index
void DynamicStack::print() const {

    for (int i = 0; i < size_-1; i++)
    {
        std::cout << items_[i] << "\t";
    }

}