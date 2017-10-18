#ifndef bst_included
#define bst_included


/* a binary search tree node */
typedef struct bstNode
{
  
  char *name;
  struct bstNode *left;
  struct bstNode *right;
  
}bstNode;

/* to find minimum value in tree */
bstNode* FindMin(bstNode *node);

/* to find maximum value in tree */
bstNode* FindMax(bstNode *node);

/* to insert new name into bst */
bstNode* InsertName(bstNode *node, char *name);

/* to delete given name from bst */
bstNode* DeleteName(bstNode *node, char *name);

/* to find given name in bst */
bstNode* FindName(bstNode *node, char *name);

/* to print tree in order */
void PrintInOrder(bstNode *node);

/* to print tree in preorder */
void PrintPreorder(bstNode *node);

/* to print tree in postorder */
void PrintPostorder(bstNode *node);




#endif
