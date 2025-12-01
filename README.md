# AVL-Tree Project
AVL Tree Project for CSPB2270

Overview:
First, I've implemented an AVL Tree, which is a self-balancing BST that maintains height balance by rotating after insertion and/or deletion (LL, RR, LR, RL). (This is based on the structure described in the wikipedia article on AVL Trees: https://en.wikipedia.org/wiki/AVL_tree)

Second, I've implemented an unbalanced BST to demonstrate the advantages of AVL Trees. (This based on the BST we implemented in HW03.)

The goal of the main function is to demonstrate the difference in height and structure between a balanced AVL Tree and a standard BST when inserting sequential numbers.

Explanation:
AVL Tree: An AVL tree automatically rotates nodes during insertion and deletion to maintain balance. This ensures an O(log n) runtime for both.

Standard BST: Each node has at most two children. The left child is less than the parent; the right child is greater. Inserting numbers in ascending order creates an unbalanced tree (essentially a linked list).

I considered including a time comparison between the AVL tree and BST for searching and deleting. However, when I randomly inserted and deleted nodes, the standard BST would generally remain balanced and beat the AVL tree, which was, of course, constantly rotating and, thus, taking more time. BSTs generally perform fine when random inputs are somewhat equally distributed. The AVL Tree, however, outperforms the BST when numbers are insert sequentially as in the main function.

Files:
AVLTree.h and AVLTree.cpp
BST.h and BST.cpp
main.cpp (which exaggerates the difference between AVL Trees and standard BSTs)

Compile and Run:
g++ main.cpp AVLTree.cpp BST.cpp -o tree_demo
./tree_demo
