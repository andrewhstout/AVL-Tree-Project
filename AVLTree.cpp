#include "AVLTree.h"
#include <iostream>
#include <algorithm>

using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    delete_subtree(root);
}

void AVLTree::insert(int key) {
    root = insert_recursive(root, key);
}

void AVLTree::remove(int key) {
    root = remove_recursive(root, key);
}

bool AVLTree::contains(int key) {
    avl_node* node = root;
    while (node) {
        if (key == node->key) {
            return true;
        }
        if (key < node->key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return false;
}

avl_node* AVLTree::get_root() {
    return root;
}

// This is an attempt to recreate the code described in the AVL Tree wikipedia article
//https://en.wikipedia.org/wiki/AVL_tree

// LL Rotation (Right Rotation)
avl_node* AVLTree::rightRotate(avl_node* X) {
    avl_node* Z = X->left;
    avl_node* T3 = Z->right; // Inner child

    //Rotate
    Z->right = X;
    X->left = T3;

    // Update heights
    X->height = 1 + max(getHeight(X->left), getHeight(X->right));
    Z->height = 1 + max(getHeight(Z->left), getHeight(Z->right));

    return Z; // new root
}

// RR Rotation (Left Rotation)
avl_node* AVLTree::leftRotate(avl_node* X) {
    avl_node* Z = X->right;
    avl_node* T23 = Z->left;

    Z->left = X;
    X->right = T23;

    X->height = 1 + max(getHeight(X->left), getHeight(X->right));
    Z->height = 1 + max(getHeight(Z->left), getHeight(Z->right));

    return Z;
}

// LR Rotation (Left-Right)
avl_node* AVLTree::leftRightRotate(avl_node* X) {
    X->left = leftRotate(X->left);
    return rightRotate(X);
}

// RL Rotation (Right-Left)
avl_node* AVLTree::rightLeftRotate(avl_node* X) {
    X->right = rightRotate(X->right);
    return leftRotate(X);
}
// Recursive insertion
avl_node* AVLTree::insert_recursive(avl_node* node, int key) {
    if (!node) {
        avl_node* newNode = new avl_node;
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key) {
        node->left = insert_recursive(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert_recursive(node->right, key);
    }
    else {
        return node; // duplicate
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Rotation cases
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node); //LL
    }
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node); //RR
    }
    if (balance > 1 && key > node->left->key) {
        return leftRightRotate(node); //LR
    }
    if (balance < -1 && key < node->right->key) {
        return rightLeftRotate(node); //RL
    }

    return node;
}

// Recursive deletion
avl_node* AVLTree::remove_recursive(avl_node* node, int key) {
    if (!node) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = remove_recursive(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove_recursive(node->right, key);
    }
    else {
        if (!node->left || !node->right) { 
            avl_node* temp = node->left ? node->left : node->right;
            if (!temp) { // Node with no child
                delete node;
                return nullptr;
            }
            else { // Node with one child
                *node = *temp;
                delete temp;
            }
        }
        // Node with two children
        else {
            avl_node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove_recursive(node->right, temp->key);
        }
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Compute balance factor
    int balance = getBalance(node);

    // Rotation cases
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node); //LL
    }
    if (balance > 1 && getBalance(node->left) < 0) {
        return leftRightRotate(node); //LR
    }
    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node); //RR
    }
    if (balance < -1 && getBalance(node->right) > 0) {
        return rightLeftRotate(node); //RL
    }

    return node;
}

void AVLTree::delete_subtree(avl_node* node) {
    if (!node) {
        return;
    }
    else {
        delete_subtree(node->left);
        delete_subtree(node->right);
        delete node;
    }
}

// AVL helpers
int AVLTree::getHeight(avl_node* node) {
    if (node != nullptr) {
        return node->height;
    }
    else {
        return 0;
    }
}

int AVLTree::getBalance(avl_node* node) {
    return getHeight(node->left) - getHeight(node->right);
}

avl_node* AVLTree::minValueNode(avl_node* node) {
    avl_node* current = node;
    while (current->left) {
        current = current->left;
    }
    return current;
}