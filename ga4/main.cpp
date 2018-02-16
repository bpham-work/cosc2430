#include <iostream>
#include "doublylinkedlist.h"
#include "linkedlist.h"
using namespace std;

int main() {
    DoublyLinkedList<int> list;
    //list.append(0);
    //list.append(1);
    //list.append(2);
    //list.append(3);
    //list.append(4);
    //list.print();
    //cout << list.popFromLeft(4) << endl;
    //list.print();
    cout << list.popFromRight(0) << endl;
    list.print();
    return 0;
}
