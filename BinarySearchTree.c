#include "BinarySearchTree.h"
//Malloc a new BinarySearchTreeImp and return it's address.
BinarySearchTree newBinarySearchTree()
{
BinarySearchTree t = (BinarySearchTree)malloc(sizeof(BinarySearchTreeImp));
t->pRoot = NULL;
return t;
}

//helper for free nodes in tree
void freePostOrder(NodeT *p)
{
if(p == NULL) return;
freePostOrder(p->pLeft);
freePostOrder(p->pRight);
free(p);
}

//Free the BinarySearchTree and any nodes that still exist in the tree.
void freeBinarySearchTree(BinarySearchTree tree)
{
freePostOrder(tree->pRoot);
}


//Allocate a new node and store "value" as the Element in the node. Return the address of the node.
NodeT *allocateNode(Element value)
{
NodeT* n = (NodeT*)malloc(sizeof(NodeT));
n->element = value;
n->pLeft = NULL;
n->pRight = NULL;
return n;
}

//Recursive algorithm for searching for a node with key value equal to searchValue. Return a pointer to the node if you find it or return NULL if it does not exist.
NodeT *search(NodeT *p, int searchValue, double balValue)
{
if(p == NULL)
return NULL;
else
{
if(p->element.key == searchValue){
p->element.balance += balValue;   
return p;
}
else if(searchValue < p->element.key)
return search(p->pLeft, searchValue, balValue);
else
return search(p->pRight, searchValue, balValue);
}
}

//Create a node to store the given Element and add it as a leaf in the BinarySearchTree. Do not worry about balancing the tree for this project.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.
int insert(BinarySearchTree tree, Element value)
{
NodeT* n = allocateNode(value);
NodeT* curr;
if(tree->pRoot == NULL)
{
tree->pRoot = n;
return TRUE;
}
else
{
curr = tree->pRoot;
while(curr != NULL)
{
if(curr->element.key == value.key)
return FALSE;
else if(value.key < curr->element.key)
{
if(curr->pLeft == NULL)
{
curr->pLeft = n;
return TRUE;
}
else
curr = curr->pLeft;
}
else
{
if(curr->pRight == NULL)
{
curr->pRight = n;
return TRUE;
}
else
curr = curr->pRight;
}
}
}
return FALSE;
}

//Recursivly print the key values of all nodes in the subtree rooted at p in increasing order.
void printInOrder(NodeT *p)
{
if(p == NULL ) return;
  
printInOrder(p->pLeft);
printf("%d %.2f\n", p->element.key,p->element.balance);
printInOrder(p->pRight);
}

//Recursivly print the key values of all nodes in the subtree rooted at p according to a preorder traversal.
void printPreOrder(NodeT *p)
{
if(p == NULL ) return;
printf("%d %.2f\n", p->element.key, p->element.balance);
printInOrder(p->pLeft);
printInOrder(p->pRight);
}