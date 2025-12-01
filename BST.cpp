#include "BST.h"

// This BST structure is based on HW03

BST::BST() {
  root = nullptr;
}

BST::~BST() {
    delete_subtree(root);
}

void BST::delete_subtree(bst_node* node) {
  if (!node) {
    return;
  }
  delete_subtree(node->left);
  delete_subtree(node->right);
  delete node;
}

// Insert helper
bst_node* BST::insert_recursive(bst_node* node, int data) {
    if (!node) {
        bst_node* ret = new bst_node;
        ret->data = data;
        ret->left = nullptr;
        ret->right = nullptr;
        return ret;
    }

    if (data < node->data) {
        node->left = insert_recursive(node->left, data);
    }
    else {
        node->right = insert_recursive(node->right, data);
    }
    return node;
}

void BST::insert(int data) {
    root = insert_recursive(root, data);
}

// Remove helper
bst_node* BST::minValueNode(bst_node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Another remove helper
bst_node* BST::remove_recursive(bst_node* node, int data) {
    if (!node) {
        return nullptr;
    }
    if (data < node->data) {
        node->left = remove_recursive(node->left, data);
    }
    else if (data > node->data) {
        node->right = remove_recursive(node->right, data);
    }
    else {
        if (!node->left) {
            bst_node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            bst_node* temp = node->left;
            delete node;
            return temp;
        }
        bst_node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = remove_recursive(node->right, temp->data);
    }
    return node;
}

void BST::remove(int data) {
    root = remove_recursive(root, data);
}

// The getter
bst_node* BST::get_root() {
    return root;
}