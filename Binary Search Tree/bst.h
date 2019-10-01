#ifndef bst_h
#define bst_h

#include <stdio.h>
#include <stdlib.h>
struct bstree
{
  int data;
  struct bstree *left, *right;
};

struct bstree *getnode();
struct bstree *insert(struct bstree *, struct bstree *);
void inorder(struct bstree *);
void preorder(struct bstree *);
void postorder(struct bstree *);
struct bstree *delete(struct bstree *, int);
struct bstree *minvaluenode(struct bstree *);

#endif
