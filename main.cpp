#include <iostream>
#include "Stack.h"
using namespace std;


int main() {
    linkedList lists;

    lists.insertAtBeginning(20);
    lists.insertAtBeginning(10);
    lists.insertAtEnd(30);
    lists.insertAtEnd(40);
    lists.insertAtEnd(50);

    lists.display();

    return 0;
}
