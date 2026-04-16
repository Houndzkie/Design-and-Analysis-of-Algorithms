#include "node.hpp"

node* search(node* n, int num) {
  if (!n) return n;

  for (int i = 0; i < n->size; i++) {
    if (num == n->keys[i]) {
      return n;
    }
    if (num < n->keys[i]) {
      if (n->children[i]) {
        return search(n->children[i], num);
      }
    }
  }

  if (n->children[n->size]) {
    return search(n->children[n->size], num);
  }

  return n;
}

node* root = nullptr;

bool insert(int num) {
  if (!root) {
    root = new node;
    root->parent = nullptr;
    root->keys[0] = num;
    root->children = new node*[5];
    root->size = 1;
    return true;
  }

  node* w = search(root, num);

  for (int i = 0; i < w->size; i++) {
    if (w->keys[i] == num) {
      return false;
    }
  }

  int i = 0;

  while (i < w->size && num > w->keys[i]) i++;

  for (int j = w->size; j > i; j--) {
    w->keys[j] = w->keys[j - 1];
  }

  w->keys[i] = num;
  w->size++;

  while (w->size == 4) {
    node* par = w->parent;
    int mid = w->keys[2];

    node* w1 = new node;
    w1->keys[0] = w->keys[0];
    w1->keys[1] = w->keys[1];
    w1->children = new node*[5];
    w1->size = 2;

    node* w2 = new node;
    w2->keys[0] = w->keys[3];
    w2->children = new node*[5];
    w2->size = 1;

    for (int i = 0; i <= 2; i++) {
      w1->children[i] = w->children[i];
      if (w1->children[i]) w1->children[i]->parent = w1;
    }

    for (int i = 3; i <= 4; i++) {
      w2->children[i - 3] = w->children[i];
      if (w2->children[i - 3]) w2->children[i - 3]->parent = w2;
    }

    if (!par) {
      par = new node;
      par->parent = nullptr;
      par->keys[0] = mid;
      par->children = new node*[5];
      par->children[0] = w1;
      par->children[1] = w2;
      w1->parent = par;
      w2->parent = par;
      par->size = 1;
      root = par;
    } else {
      w1->parent = par;
      w1->parent = par;

      int i = 0;

      while (i < par->size && mid > par->keys[i]) i++;

      for (int j = par->size; j > i; j--) {
        par->keys[j] = par->keys[j - 1];
        par->children[j + 1] = par->children[j];
      }

      par->keys[i] = mid;
      par->children[i] = w1;
      par->children[i + 1] = w2;
      par->size++;
    }

    delete w;
    w = par;
  }

  return true;
}