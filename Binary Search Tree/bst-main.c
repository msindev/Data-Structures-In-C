#include "bst.h"

int main()
{
  struct bstree *root = NULL, *newnode;
  int choice, num;
  while (1)
  {
    printf("1. Insert Element in Tree\n 2. Delete Element from Tree\n 3. Tree Traversals\n 4. EXIT\n");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
        newnode = getnode();
        printf("Enter number to enter: ");
        scanf("%d", &num);
        newnode -> data = num;
        root = insert(root, newnode);
        break;
      case 2:
        printf("Enter number to delete: ");
        scanf("%d", &num);
        root = delete(root, num);
        break;
      case 3:
        printf("\n PreOrder Traversal: ");
        preorder(root);
        printf("\n InOrder Traversal: ");
        inorder(root);
        printf("\n PostOrder Traversal: ");
        postorder(root);
        break;
      case 4:
        exit(0);
      default:
        printf("Wrong Choice\n");
    }
  }
  return 0;
}
