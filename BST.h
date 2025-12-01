#ifndef BST_H__
#define BST_H__

struct bst_node {
    int data;
    bst_node* left;
    bst_node* right;
};

class BST {
public:
    BST();
    ~BST();

    void insert(int data);
    void remove(int data);

    bst_node* get_root();

private:
    bst_node* root;

    bst_node* insert_recursive(bst_node* node, int data);
    bst_node* remove_recursive(bst_node* node, int data);
    bst_node* minValueNode(bst_node* node);
    void delete_subtree(bst_node* node);
};

#endif // BST_H__