#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pm_bst.h"


/* to find minimum value in tree */
bstNode* FindMin(bstNode *node)
{
  if(node == NULL)
    {
      return NULL;
    }
  else if(node -> left)
    {
      return FindMin(node -> left);
    }
  else
    return node;
}

/* to find maximum value in tree */
bstNode* FindMax(bstNode *node)
{
  if(node == NULL)
    {
      return NULL;
    }
  else if(node -> right)
    {
      FindMax(node -> right);
    }
  else
    return node;
}
