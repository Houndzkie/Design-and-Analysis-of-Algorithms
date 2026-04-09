#include <bits/stdc++.h>
#include "splay.hpp"
using namespace std;

int main () {
  Splay* splay = new Splay();
  
  do {
    cout << "Enter operation: ";
    char input;
    cin >> input;
    int x;

    switch (input) {
      case 'i':
        cin >> x;
        splay->insert(splay->getRoot(), x);
        break;
      case 'r':
        cin >> x;
        splay->deleteNode(splay->getRoot(), x);
        break;
      case 'p':
        splay->print();
    }
  }
}