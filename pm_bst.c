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

/* to insert new name into bst */
bstNode* InsertName(bstNode *node, char *name)
{
  if(node == NULL)
    {
      bstNode *tmp;
      tmp = (bstNode *)malloc(sizeof(bstNode));
      tmp -> name = strdup(name);
      tmp -> left = tmp -> right = NULL;
      return tmp;
    }
  else if(strcmp(node -> name, name) > 0)
    {
      node -> right = InsertName(node -> right, name);
    }
  else if(strcmp(node -> name, name) < 0)
    {
      node -> left = InsertName(node -> left, name);
    }
  return node;
}

/* to delete name from bst */
bstNode* DeleteName(bstNode *node, char *name)
{
  bstNode *tmp;
  if(node == NULL)
    {
      printf("Name not found in System. Please try again.\n");
    }
  else if(strcmp(node -> name, name) < 0)
    {
      node -> left = DeleteName(node -> left, name);
    }
  else if(strcmp(node -> name, name) > 0)
    {
      node -> right = DeleteName(node -> right, name);
    }
  else
    {
      if(node -> right && node -> left)
	{
	  tmp = FindMin(node -> right);
	  node -> name = tmp -> name;
	  node -> right = DeleteName(node -> right, tmp -> name);
	}
      else
	{
	  tmp = node;
	  if(node -> left == NULL)
	    node = node -> right;
	  else if(node -> right == NULL)
	    node = node -> left;
	  free(tmp);
	}
    }
  return node;
}

/* to find a name in the bst */
bstNode* FindName(bstNode *node, char *name)
{
  if(node == NULL)
    {
      return NULL;
    }
  else if(name < node -> name)
    {
      return FindName(node -> left, name);
    }
  else
    {
      return node;
    }
}

/* to print tree in order */
void PrintInorder(bstNode *node)
{
  if(node == NULL)
    {
      return;
    }
  PrintInorder(node -> left);
  printf("%s", node -> name);
  PrintInorder(node -> right);
}

FILE *fi;                                  /* pointer for write file */
/* to print tree in preorder */
void PrintPreorder(bstNode *node)
{
  if(node == NULL)
    {
      return;
    }
  fprintf(fi,"%s", node -> name);         /* to print tree into employees.txt file Preorder form */
  printf("%s", node -> name);
  PrintPreorder(node -> left);
  PrintPreorder(node -> right);
}

/* to print tree in postorder */
void PrintPostorder(bstNode *node)
{
  if(node == NULL)
    {
      return;
    }
  PrintPostorder(node -> left);
  PrintPostorder(node -> right);
  printf("%s", node -> name);
}

/* menu that prints options for user */
void menu()
{
  printf("Enter '1' to add a name.\n");
  printf("Enter '2' to delete a name.\n");
  printf("Enter '3' to view all names in the system.\n");
  printf("Enter '0' to quit.\n");
}

/* main method for use of bst, user input and read/write to file */
int main()
{
  bstNode* root = NULL;                  /* created empty tree */
  int option;                            /* option for menu loop */
  char nm[200];                          /* nm string variable for name input from file */
  char in[200];                          /* in string variable for name input from user */
  FILE *f;                               /* pointer for read file */
  f = fopen("employees.txt","r");        /* opening file employees.txt to read and write */
  if(f == NULL)
    {
      printf("Couldn't open file. :(\n");
      exit(1);
    }
  while(fgets(nm, 200, f) != NULL)
    {
      //printf("%s", nm);
      root = InsertName(root, nm);
    }
  fclose(f);

  printf("Welcome to Personnel Management System!\n");
  menu();
  while(option != 0)
    {
      if(option == 1)
	{
	  printf("Please enter name to add to system or enter another option.\n");
	  //scanf("%[^\n]s", in);
	  fgets(in, 200, stdin);
	  InsertName(root,in);
	  //%*c
	}
      else if(option == 2)
	{
	  printf("Please enter name to delete from the system or enter another option.\n");
	  //scanf("%[^\n]s", in);
	  fgets(in, 200, stdin);
	  DeleteName(root,in);
	}
      else if(option == 3)
	{
	  printf("Printing names in system:\n");
	  PrintInorder(root);
	  printf("Names printed. Please enter an option.\n");
	}
      else
	{
	  printf("Please choose an option.\n");
	}
      scanf("%d", &option);
    }
  fi = fopen("employees.txt", "w");          /* opening file employees.txt to write to */
  PrintPreorder(root);
  fclose(fi);                               /* closing file wmployees.txt */
  return 0;
}
