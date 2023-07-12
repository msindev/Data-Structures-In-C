# Binary Search Tree (BST)

This directory contains the implementation of a Binary Search Tree (BST) in C. The BST allows efficient storage and retrieval of data in a sorted manner.

## Files

- `bst-definition.c`: This file contains the implementation of various functions related to the BST, including `getnode()`, `insert()`, `inorder()`, `preorder()`, `postorder()`, `delete()`, and `minvaluenode()`.
- `bst-main.c`: This file provides a user interface to interact with the BST. It allows users to insert elements into the tree, delete elements from the tree, and perform tree traversals.
- `bst.h`: This header file contains the structure definition for the `bstree` node and function prototypes for the BST operations.

## Compilation

To compile the program, you can use the following commands:

```bash
gcc -c bst-definition.c -o bst-definition.o
gcc -c bst-main.c -o bst-main.o
gcc bst-definition.o bst-main.o -o program
```

## Usage

After compiling the program, you can run it using the following command:

```bash
./program
```
Once the program starts, you will be presented with a menu to perform different operations on the BST:

1. Insert Element in Tree: This option allows you to insert a new element into the BST.
2. Delete Element from Tree: This option allows you to delete an element from the BST.
3. Tree Traversals: This option displays the pre-order, in-order, and post-order traversals of the BST.
4. EXIT: This option exits the program.

## Note

Ensure that all the necessary files (bst-definition.c, bst-main.c, bst.h) are present in the same directory before compiling and running the program.

Feel free to explore and modify the code to suit your requirements. Enjoy working with Binary Search Trees!
