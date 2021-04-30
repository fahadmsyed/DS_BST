#include "BinarySearchTree.h"

#include <stdio.h>
#include <string.h>
int main()
{
  
char filename[50];
FILE* fp;
char command[10];
Element e;
int val;
double bal;
BinarySearchTree tree = newBinarySearchTree();
printf("Enter input filename: ");
scanf("%s", filename);
fp = fopen(filename, "r");
if(fp == NULL)
{
printf("Error opening input file %s\n",filename );
return 1;
}
  
while(fscanf(fp, "%s", command) == 1)
{
if(strcmp(command, "CREATE") == 0)
{
fscanf(fp, "%d", &e.key);
if(insert(tree, e))
printf("%d 0.00 \n", e.key);
else
printf("Duplicate value %d. Did not insert. \n", e.key);
}
else if(strcmp(command, "SALE") == 0)
{
fscanf(fp, "%d", &val);
fscanf(fp, "%lf", &bal);
if(search(tree->pRoot, val, bal) == NULL)
printf("No account found with number %d.\n", val);
else
printf("%d %.2f\n", val, bal);
}
else if(strcmp(command, "PRINT") == 0)
{
fscanf(fp, "%s", command); //get the string whether inorder or preorder
if(strcmp(command, "INORDER") == 0)
{
printf("Printing Inorder! \n");
printInOrder(tree->pRoot);
printf("\n");
}
else
{
printf("Printing Preorder! \n");
printPreOrder(tree->pRoot);
printf("\n");
}
  
}
else
printf("Unknown command %s\n", command);
}
  
return 0;
}