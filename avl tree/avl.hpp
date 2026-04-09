#include <bits/stdc++.h>
#include "node.hpp"
using namespace std;

class AVL {
  node* root;

  public:
    AVL() {
      root = nullptr;
    }

    node* getRoot() {
      return root;
    }

    int height(node* n) {
      if (!n) return 0;
      return n->height;
    }

    node* rightRotate(node* x) {
      node* y = x->left;
      x->left = y->right;
      y->right = x;
      
      x->height = 1 + max(height(x->left), height(x->right));
      y->height = 1 + max(height(y->left), height(y->right));

      return y;
    }

    node* leftRotate(node* x) {
      node* y = x->right;
      x->right = y->left;
      y->left = x;

      x->height = 1 + max(height(x->left), height(x->right));
      y->height = 1 + max(height(y->left), height(y->right));

      return y;
    }

    int getBalance(node* n) {
      if (!n) return 0;
      return height(n->left) - height(n->right);
    }

    node* insert(node* n, int key) {
      if (!n) {
        node* ret = new node;
        ret->key = key;
        ret->left = nullptr;
        ret->right = nullptr;
        ret->height = 1;
        return ret;
      }

      if (key < n->key) {
        n->left = insert(n->left, key);
      } else if (key > n->key) {
        n->right = insert(n->right, key);
      } else {
        return n;
      }

      n->height = 1 + max(height(n->left), height(n->right));
      int balance = getBalance(n);

      if (balance > 1 && key < n->left->key) {
        return rightRotate(n);
      }
      if (balance < -1 && key > n->right->key) {
        return leftRotate(n);
      }
      if (balance > 1 && key > n->left->key) {
        n->left = leftRotate(n->left);
        return rightRotate(n); 
      }
      if (balance < -1 && key < n->right->key) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
      }

      return n;
    }

    node* deleteNode(node* n, int key) {
      if (!n) return n;

      if (key < n->key) {
        n->left = deleteNode(n->left, key);
      } else if (key > n->key) {
        n->right = deleteNode(n->right, key);
      } else {
        if (!n->left || !n->right) {
          node* temp = n->left ? n->left : n->right;
          delete n;

          if (temp) {
            return temp;
          } else {
            return nullptr;
          }
        } else {
          node* temp = n->right;
          while (temp->left) temp = temp->left;
          n->key = temp->key;
          n->right = deleteNode(n->right, temp->key);
        }
      }

      n->height = 1 + max(height(n->left), height(n->right));
      int balance = getBalance(n);

      if (balance > 1 && getBalance(n->left) >= 0) {
        return rightRotate(n);
      }
      if (balance > 1 && getBalance(n->left) < 0) {
        n->left = leftRotate(n->left);
        return rightRotate(n);
      }
      if (balance < -1 && getBalance(n->right) <= 0) {
        return leftRotate(n);
      }
      if (balance < -1 && getBalance(n->right) > 0) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
      }

      return n;
    }
};



// redo by memory

int height(node* n) {
  if (!n) return 0;
  return n->height;
}

int getBalance(node* n) {
  if (!n) return 0;
  return height(n->left) - height(n->right);
}

node* rightRotate(node* x) {
  node* y = x->left;
  x->left = y->right;
  y->right = x;

  x->height = 1 + max(height(x->left), height(x->right));
  y->height = 1 + max(height(y->left), height(y->right));

  return y;
}

node* leftRotate(node* x) {
  node* y = x->right;
  x->right = y->left;
  y->left = x;

  x->height = 1 + max(height(x->left), height(x->right));
  y->height = 1 + max(height(y->left), height(y->right));

  return y;
}

node* insert(node* n, int key) {
  if (!n) {
    node* ret = new node;
    ret->key = key;
    ret->left = nullptr;
    ret->right = nullptr;
    ret->height = 1;
    return ret;
  }

  if (key < n->key) {
    n->left = insert(n->left, key);
  } else if (key > n->key) {
    n->right = insert(n->right, key);
  } else {
    return n;
  }

  n->height = 1 + max(height(n->left), height(n->right));
  int balance = getBalance(n);

  if (balance > 1 && key < n->left->key) {
    return rightRotate(n);
  } else if (balance < -1 && key > n->right->key) {
    return leftRotate(n);
  } else if (balance > 1 && key > n->left->key) {
    n->left = leftRotate(n->left);
    return rightRotate(n);
  } else if (balance < -1 && key < n->right->key) {
    n->right = rightRotate(n->right);
    return leftRotate(n);
  }

  return n;
}

node* remove(node* n, int key) {
  if (!n) return n;

  if (key < n->key) {
    n->left = remove(n->left, key);
  } else if (key > n->key) {
    n->right = remove(n->right, key);
  } else {
    if (!n->left || !n->right) {
      node* temp = n->left ? n->left : n->right;
      delete n;

      if (temp) {
        return temp;
      } else {
        return nullptr;
      }
    } else {
      node* temp = n->right;
      while (temp->left) temp = temp->left;
      n->key = temp->key;
      n->right = remove(n->right, temp->key);
    }
  }

  n->height = 1 + max(height(n->left), height(n->right));
  int balance = getBalance(n);

  if (balance > 1 && getBalance(n->left) >= 0) {
    return rightRotate(n);
  } else if (balance > 1 && getBalance(n->left) < 0) {
    n->left = leftRotate(n->left);
    return rightRotate(n);
  } else if (balance < -1 && getBalance(n->right) <= 0) {
    return leftRotate(n);
  } else if (balance < -1 && getBalance(n->right) > 0) {
    n->right = rightRotate(n->right);
    return leftRotate(n);
  }

  return n;
}