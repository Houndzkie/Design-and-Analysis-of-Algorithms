#include <bits/stdc++.h>
#include "avl.hpp"
using namespace std;

int main () {
  AVL* avl = new AVL();
  
  do {
    cout << "Enter operation: ";
    char input;
    cin >> input;
    int x;

    switch (input) {
      case 'i':
        cin >> x;
        avl->insert(avl->getRoot(), x);
        break;
      case 'r':
        cin >> x;
        avl->deleteNode(avl->getRoot(), x);
        break;
      case 'p':
        avl->print();
    }
  }
}