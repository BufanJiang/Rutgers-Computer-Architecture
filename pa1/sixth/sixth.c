#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left, *right;
} node;

void insertBSTree(node** root, int value)
{
    node *f, *p;
    p = *root;
    while(p)
    {
        if(p->data == value)
        {
            return;
        }
        f = p;
        p = (value < p->data) ? p->left : p->right;
    }
    p = (node*) malloc(sizeof(node));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    if(*root == NULL)
    {
        *root = p;
    }
    else
    {
        if(value < f->data)
        {
            f->left = p;
        }   
        else
        {
            f->right = p;
        }
        
    } 
}

void traverseBSTree(node* root)
{
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            traverseBSTree(root->left);
            printf("\t");
        }
        printf("%d", root->data);
        if(root->right != NULL)
        {
            printf("\t");
            traverseBSTree(root->right);
        }
    }
}

void freeBSTree(node* root)
{
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            freeBSTree(root->left);
        }
        if(root->right != NULL)
        {
            freeBSTree(root->right);
        }
        free(root);
    }
}


int main(int argc, char** argv)
{
    FILE* fp;
    char c;
    int num;
    node* tree = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("error\n");
        return 1;
    }

    while(!feof(fp))
    {
        if(fscanf(fp, "%c\t%d\n", &c, &num) == 2)
        {
            if(c == 'i')
            {
                insertBSTree(&tree, num);
            }
        }
    }
    fclose(fp);

    traverseBSTree(tree);
    printf("\n");

    freeBSTree(tree);
    return 0;
}