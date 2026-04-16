#include "node.hpp"
#include <iostream>
using namespace std;

class BTree24 {
	node* root;

	public:
	BTree24() {
		root = nullptr;
	}

	void reset() {
		root = nullptr;
	}

	node* search(node* n, int num) {
		if (!n) return n;

		for (int i = 0; i < n->size; i++) {
			if (n->keys[i] == num) {
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

	bool insert(int num) {
    if (!root) {
        root = new node; // Removed 'node*' to avoid shadowing
        root->parent = nullptr;
        root->keys[0] = num;
        root->children = new node*[5]();
        root->size = 1;
        return true;
    }

    node* w = search(root, num);

    // check if num already existed
    for (int i = 0; i < w->size; i++) {
        if (w->keys[i] == num) return false;
    }

    // --- STEP 1: Standard Leaf Insertion ---
    int i = 0;
    while (i < w->size && num > w->keys[i]) {
        i++;
    }
    // Shift keys to the right
    for (int j = w->size; j > i; j--) {
        w->keys[j] = w->keys[j - 1];
    }
    w->keys[i] = num;
    w->size++;

    // --- STEP 2: The While Loop for Overflows ---
    while (w->size == 4) {
        node* par = w->parent;

        // Create the two new split nodes
        node* w1 = new node;
        w1->keys[0] = w->keys[0];
        w1->keys[1] = w->keys[1];
        w1->size = 2;
        w1->children = new node*[5]();

        node* w2 = new node;
        w2->keys[0] = w->keys[3];
        w2->size = 1;
        w2->children = new node*[5]();

        // CRITICAL: Move children from old 'w' to new 'w1' and 'w2'
        for (int j = 0; j <= 2; j++) {
            w1->children[j] = w->children[j];
            if (w1->children[j]) w1->children[j]->parent = w1;
        }
        for (int j = 3; j <= 4; j++) {
            w2->children[j - 3] = w->children[j];
            if (w2->children[j - 3]) w2->children[j - 3]->parent = w2;
        }

        int midKey = w->keys[2];

        if (!par) {
            // Case: Splitting the root
            par = new node;
            par->keys[0] = midKey;
            par->size = 1;
            par->children = new node*[5]();
            par->parent = nullptr;
            
            w1->parent = par;
            w2->parent = par;
            par->children[0] = w1;
            par->children[1] = w2;
            
            root = par; // Tree grows taller
        } else {
            // Case: Promoting to existing parent
            w1->parent = par;
            w2->parent = par;

            // Find where to insert midKey in parent
            int pos = 0;
            while (pos < par->size && midKey > par->keys[pos]) {
                pos++;
            }

            // Shift parent keys and children to make room
            for (int j = par->size; j > pos; j--) {
                par->keys[j] = par->keys[j - 1];
                par->children[j + 1] = par->children[j];
            }

            par->keys[pos] = midKey;
            par->children[pos] = w1;
            par->children[pos + 1] = w2;
            par->size++;
        }
				
				delete[] w->children;
        delete w; // Clean up the old 4-key node
        w = par;  // Move up to the parent to check if it now has 4 keys
    }

    return true;
	}

	// WARNING. Do not modify these methods.
    // Doing so will nullify your score for this activity.
	void print_node(string s, node* n) {
		cout << s << ": ";
		for (int i = 0; i < n->size; i++) {
			cout << n->keys[i] << " ";
		}
		cout << endl;
		for (int i = 0; i <= n->size; i++) {
			if (n->children[i]) {
				print_node("Child " + to_string(i+1) + " of " + s,n->children[i]);
			}
		}
	}
    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: NULL -- must be [" << par->keys[0] << ",...]" << endl;
            } else if (!par) {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: [" << curr->parent->keys[0] << ",...] -- must be NULL" << endl;
            } else {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: [" << curr->parent->keys[0] << ",...] -- must be [" << par->keys[0] << ",...]" << endl;
            }
            return false;
        }
        bool res = true;
        for (int i = 0; i < curr->size; i++) {
        	res &= check_parent(curr->children[i], curr);
		}
        return res;
    }

	void print() {
		print_node("Root", root);
		check_parent(root, NULL);
	}
};