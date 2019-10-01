#include "bst.h"

struct bstree *getnode()
{
  struct bstree *newnode;
  newnode = (struct bstree *)malloc(sizeof(struct bstree));
  newnode -> left = NULL;
  newnode -> right = NULL;
  return newnode;
}

struct bstree *insert(struct bstree *root, struct bstree *newnode)
{
  if(root == NULL)
    return newnode;
  if(newnode -> data < root -> data)
    root -> left = insert(root -> left, newnode);
  else if(newnode -> data > root -> data)
    root -> right = insert(root -> right, newnode);
  return root;
}

void inorder(struct bstree *root)
{
  if(root != NULL)
  {
    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);
  }
}

void preorder(struct bstree *root)
{
  if(root != NULL)
  {
    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
  }
}

void postorder(struct bstree *root)
{
  if(root != NULL)
  {
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> data);
  }
}

struct bstree *delete(struct bstree * root, int key)
{
  if(root == NULL)
    return root;
  if(key < root -> data)
    root -> left = delete(root -> left, key);
  else if(key > root -> data)
    root -> right = delete(root -> right, key);
  else
  {
    if(root -> left == NULL)
    {
      struct bstree *temp = root -> right;
      free(root);
      return temp;
    }
    else if(root -> right == NULL)
    {
      struct bstree *temp = root -> left;
      free(root);
      return temp;
    }
    struct bstree *temp = minvaluenode(root -> right);
    root -> data = temp -> data;
    root -> right = delete(root -> right, temp -> data);
  }
  return root;
}

struct bstree *minvaluenode(struct bstree *node)
{
  struct bstree *cur = node;
  while(cur -> left != NULL)
    cur = cur -> left;
  return cur;
}
