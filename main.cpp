#include <iostream>
#include "AVLTree.h"
#include "BST.h"

using namespace std;

// Prints BST sideways (root to the left)
void print_bst(bst_node* node, int indent = 0) {
    if (!node) {
        return;
    }
    print_bst(node->right, indent + 4);
    if (indent) {
        cout << string(indent, ' ');
    }
    cout << node->data << "\n";
    print_bst(node->left, indent + 4);
}

// Prints AVL Tree sideways (root to the left)
void print_avl(avl_node* node, int indent = 0) {
    if (!node) {
        return;
    }
    print_avl(node->right, indent + 4);
    if (indent) {
        cout << string(indent, ' ');
    }
    cout << node->key << "\n";
    print_avl(node->left, indent + 4);
}

// Recursive height helper
int bst_height(bst_node* node) {
    if (!node) {
        return 0;
    }
    return 1 + max(bst_height(node->left), bst_height(node->right));
}

int avl_height(avl_node* node) {
    if (!node) {
        return 0;
    }
    return 1 + max(avl_height(node->left), avl_height(node->right));
}

int main() {
    BST bst;
    AVLTree avl;

    // Insert numbers from 1 to 15
    for (int i = 1; i <= 15; ++i) {
        bst.insert(i);
        avl.insert(i);
    }

    cout << "Standard BST - height: " << bst_height(bst.get_root()) << "\n";
    print_bst(bst.get_root());

    cout << "\nAVL Tree - height: " << avl_height(avl.get_root()) << "\n";
    print_avl(avl.get_root());

    return 0;
}