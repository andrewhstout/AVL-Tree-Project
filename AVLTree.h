#ifndef AVLTREE_H__
#define AVLTREE_H__

struct avl_node {
    int key;
    avl_node* left;
    avl_node* right;
    int height;
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    
    void insert(int key);
    void remove(int key);
    bool contains(int key);

    avl_node* get_root(); //getter

private:
    avl_node* root;

    avl_node* insert_recursive(avl_node* node, int key);
    avl_node* remove_recursive(avl_node* node, int key);

    avl_node* leftRotate(avl_node* X);
    avl_node* rightRotate(avl_node* X);
    avl_node* leftRightRotate(avl_node* X);
    avl_node* rightLeftRotate(avl_node* X);

    void delete_subtree(avl_node* node);

    int getHeight(avl_node* node);
    int getBalance(avl_node* node);
    avl_node* minValueNode(avl_node* node);
};

#endif // AVLTREE_H__