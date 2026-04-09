#include <bits/stdc++.h>
#include "node.hpp"
using namespace std;

class Splay {
  node* root;

  public:
    Splay() {
      root = nullptr;
    }

    node* getRoot() {
      return root;
    }

    node* rightRotate(node* x) {
      node* y = x->left;
      x->left = y->right;
      y->right = x;
      return y;
    }

    node* leftRotate(node* x) {
      node* y = x->right;
      x->right = y->left;
      y->left = x;
      return y;
    }

    node* splay(node* n, int key) {
      if (!n || n->key == key) return n;

      if (key < n->key) {
          if (n->left == nullptr)
              return n;
          if (key < n->left->key) {
              n->left->left = splay(n->left->left, key);
              n = rightRotate(n);
          }
          else if (key > n->left->key) {
              n->left->right = splay(n->left->right, key);
              if (n->left->right)
                  n->left = leftRotate(n->left);
          }
          return (n->left == nullptr) ? n : rightRotate(n);
      } else {
          if (n->right == nullptr)
              return n;
          if (key < n->right->key) {
              n->right->left = splay(n->right->left, key);
              if (n->right->left)
                  n->right = rightRotate(n->right);
          }
          else if (key > n->right->key) {
              n->right->right = splay(n->right->right, key);
              n = leftRotate(n);
          }
          return (n->right == nullptr) ? n : leftRotate(n);
      }
    }

    node* insert(node* n, int key) {
      node* ret = new node;
      ret->key = key;
      ret->left = nullptr;
      ret->right = nullptr;

      if (!n) return ret;

      n = splay(n, key);

      if (key < n->key) {
        ret->right = n;
        ret->left = n->left;
        n->left = nullptr;
      } else if (key > n->key) {
        ret->left = n;
        ret->right = n->right;
        n->right = nullptr;
      } else {
        delete ret;
        return n;
      }

      return ret;
    }

    node* deleteNode(node* n, int key) {
      if (!n) return n;

      n = splay(n, key);

      if (key != n->key) return n;

      node* temp = n;

      if (!n->right) {
        n = n->left;
      } else {
        node* l = n->left;
        node* r = n->right;
        node* minRight = n->right;
        while (minRight->left) minRight = minRight->left;
        r = splay(r, minRight->key);
        r->left = l;
        n = r;
      }

      delete temp;
      return n;
    }
};


// redo by memory

node* rightRotate(node* x) {
  node* y = x->left;
  x->left = y->right;
  y->right = x;
  return y;
}

node* leftRotate(node* x) {
  node* y = x->right;
  x->right = y->left;
  y->left = x;
  return y;
}

node* splay(node* n, int key) {
  if (!n || key == n->key) return n;

  if (key < n->key) {
    if (!n->left) return n;
    if (key < n->left->key) {
      n->left->left = splay(n->left->left, key);
      n = rightRotate(n);
    } else if (key > n->left->key) {
      n->left->right = splay(n->left->right, key);
      if (n->left->right) n->left = leftRotate(n->left);
    }
    return n->left ? rightRotate(n) : n;
  } else if (key > n->key) {
    if (!n->right) return n;
    if (key > n->right->key) {
      n->right->right = splay(n->right->right, key);
      n = leftRotate(n);
    } else if (key < n->right->key) {
      n->right->left = splay(n->right->left, key);
      if (n->right->left) n->right = rightRotate(n->right);
    }
    return n->right ? leftRotate(n) : n;
  }
}

node* insert(node* n, int key) {
  node* ret = new node;
  ret->key = key;
  ret->left = nullptr;
  ret->right = nullptr;
  
  if (!n) return ret;

  n = splay(n, key);

  if (key < n->key) {
    ret->right = n;
    ret->left = n->left;
    n->left = nullptr;
  } else if (key > n->key) {
    ret->left = n;
    ret->right = n->right;
    n->right = nullptr;
  } else {
    delete ret;
    return n;
  }

  return ret;
}

node* remove(node* n, int key) {
  if (!n) return n;

  n = splay(n, key);

  if (key != n->key) return n;

  node* temp = n;

  if (!n->right) {
    n = n->left;
  } else {
    node* l = n->left;
    node* r = n->right;
    node* minRight = n->right;
    while (minRight->left) minRight = minRight->left;
    r = splay(r, minRight->key);
    r->left = l;
    n = r;
  }

  delete temp;
  return n;
}