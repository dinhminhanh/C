#ifndef __TREE_H__
#define __TREE_H__

typedef struct element {
  char name[1000];
  int hh;
  int mm;
  int ss;
  int DD;
  int MM;
  int YYYY;
  int type;
  // Other elements
}elmType;
// whatever type of element

typedef struct nodeType {
  elmType element;
  // int count;
  struct nodeType *left, *right;
} node_t, *tree_t;

void makeNullTree(tree_t t);
node_t *create_node(elmType NewData);
int isEmptyTree(tree_t T);
tree_t LeftChild(tree_t n);
tree_t RightChild(tree_t n);
int IsLeaf(tree_t n);
int nb_nodes(tree_t T);
tree_t createfrom2(elmType v, tree_t l, tree_t r);
tree_t Add_Left(tree_t Tree, elmType NewData);
tree_t Add_Right(tree_t Tree, elmType NewData);

int treeHeight(tree_t Tree);
int countLeaves(tree_t Tree);
int countInternalNodes(tree_t Tree);
int countRightChildren(tree_t Tree);
int countLeftChildren(tree_t Tree);

void freeTree(tree_t Tree);

//BST functions
void InsertNode(elmType x,tree_t *root );
void InsertandCount(elmType x, tree_t *root);
void prettyPrint(tree_t tree);
elmType deleteMin(tree_t *root);
void deleteNode(elmType x, tree_t *root);
tree_t search(elmType x, tree_t root);

#endif