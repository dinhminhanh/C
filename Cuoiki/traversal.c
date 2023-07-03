
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "traversal.h"

void inorderprint(tree_t tree)
{
    if (tree != NULL)
    {
        inorderprint(tree->left);
        printf("%s\n", tree->element.name);
        inorderprint(tree->right);
    }
}

void postorderprint(tree_t tree)
{
    if (tree != NULL)
    {
        postorderprint(tree->left);
        postorderprint(tree->right);
        printf("%s ", tree->element.name);
    }
}

void preorderprint(tree_t tree)
{
    if (tree != NULL)
    {
        printf("%s ", tree->element.name);
        preorderprint(tree->left);
        preorderprint(tree->right);
    }
}

void f_inorderprint(tree_t tree, FILE *file)
{
    if (tree != NULL)
    {
        f_inorderprint(tree->left, file);
        fprintf(file, "%s\n", tree->element.name);
        f_inorderprint(tree->right, file);
    }
}

void check_inorderprint(tree_t tree, char name[])
{
    if (tree != NULL)
    {
        check_inorderprint(tree->left, name);
        if (strcmp(name, tree->element.name) == 0)
            printf("%s\n", tree->element.name);
        check_inorderprint(tree->right, name);
    }
}

// Pseudo Algorithm
//  void breadth_first (tree_t tree) {
//      Queue *queue;
//      if (tree!=NULL) {
//          EnQueue(tree,queue);
//          while (!Empty_Queue(*queue)) {
//              tree = DeQueue(queue);
//              printf("%s",tree->element.name);
//              if (tree->left!=NULL)
//                  EnQueue(tree->left,queue);
//              if (tree->right!=NULL)
//                  EnQueue(tree->right,queue);
//          }
//      }
//  }