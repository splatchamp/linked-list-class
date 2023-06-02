#include <iostream>
#include "LinkedList.h"
using std::cout, std::endl;

int main() {
    LinkedList<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
//    int element = ll.at(4);
//    cout << element << endl;
    std::string output = ll.toString();
    cout << output;
}