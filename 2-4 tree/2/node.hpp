#pragma once
struct node {
	node* parent;
	int keys[4];
	node** children;
	int size = 0;
};
/*

*/





/*
bool remove(int key) {
    if (!root) return false;

    // --- STEP 1: SEARCH FOR KEY ---
    node* curr = root;
    int idx = -1;

    while (curr) {
        idx = 0;
        while (idx < curr->size && key > curr->keys[idx]) idx++;

        if (idx < curr->size && curr->keys[idx] == key) break;
        curr = curr->children[idx];
    }

    if (!curr) return false; // not found

    // --- STEP 2: IF INTERNAL NODE → SWAP WITH SUCCESSOR ---
    if (!curr->isLeaf()) {
        node* w = curr->children[idx + 1];

        // go to leftmost node
        while (!w->isLeaf()) {
            w = w->children[0];
        }

        // swap with first key of w
        curr->keys[idx] = w->keys[0];
        curr = w;
        idx = 0;
    }

    // --- STEP 3: REMOVE FROM LEAF ---
    for (int i = idx; i < curr->size - 1; i++) {
        curr->keys[i] = curr->keys[i + 1];
    }
    curr->size--;

    // --- STEP 4: FIX UNDERFLOW ---
    while (curr != root && curr->size == 0) {
        node* parent = curr->parent;

        int pos = 0;
        while (parent->children[pos] != curr) pos++;

        node* leftSib = (pos > 0) ? parent->children[pos - 1] : nullptr;
        node* rightSib = (pos < parent->size) ? parent->children[pos + 1] : nullptr;

        // --- CASE 1: TRANSFER ---
        if (rightSib && rightSib->size > 1) {
            // borrow from right sibling
            curr->keys[0] = parent->keys[pos];
            curr->size = 1;

            parent->keys[pos] = rightSib->keys[0];

            for (int i = 0; i < rightSib->size - 1; i++) {
                rightSib->keys[i] = rightSib->keys[i + 1];
            }
            rightSib->size--;

            return true;
        }
        else if (leftSib && leftSib->size > 1) {
            // borrow from left sibling
            for (int i = curr->size; i > 0; i--) {
                curr->keys[i] = curr->keys[i - 1];
            }

            curr->keys[0] = parent->keys[pos - 1];
            curr->size = 1;

            parent->keys[pos - 1] = leftSib->keys[leftSib->size - 1];
            leftSib->size--;

            return true;
        }

        // --- CASE 2: FUSION ---
        if (rightSib) {
            // merge with right sibling
            curr->keys[0] = parent->keys[pos];
            curr->size = 1;

            for (int i = 0; i < rightSib->size; i++) {
                curr->keys[curr->size++] = rightSib->keys[i];
            }

            // shift parent keys
            for (int i = pos; i < parent->size - 1; i++) {
                parent->keys[i] = parent->keys[i + 1];
            }

            // shift children
            for (int i = pos + 1; i < parent->size; i++) {
                parent->children[i] = parent->children[i + 1];
            }

            parent->size--;
            delete rightSib;
        }
        else if (leftSib) {
            // merge with left sibling
            leftSib->keys[leftSib->size++] = parent->keys[pos - 1];

            for (int i = 0; i < curr->size; i++) {
                leftSib->keys[leftSib->size++] = curr->keys[i];
            }

            for (int i = pos - 1; i < parent->size - 1; i++) {
                parent->keys[i] = parent->keys[i + 1];
            }

            for (int i = pos; i < parent->size; i++) {
                parent->children[i] = parent->children[i + 1];
            }

            parent->size--;
            delete curr;
            curr = leftSib;
        }

        curr = parent;
    }

    // --- ROOT FIX ---
    if (root->size == 0) {
        node* oldRoot = root;
        root = root->children[0];
        if (root) root->parent = nullptr;
        delete oldRoot;
    }

    return true;
}

*/