#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int Data;
  struct TreeNode* Lchild;
  struct TreeNode* Rchild;
} Tree;
Tree* criaTree();
void adiciona(Tree** t, int num);
void posfixo(Tree* node);
void infixo(Tree* node);
void prefixo(Tree* node);

int main()
{
    int n, x, i, j, num;
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        Tree* t = criaTree();
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &num);
            adiciona(&t, num);
        }
        printf("Case %d:\n", i+1);
        printf("Pre.:");
        prefixo(t);
        printf("\n");
        printf("In..:");
        infixo(t);
        printf("\n");
        printf("Post:");
        posfixo(t);
        printf("\n\n");
        free(t);
    }
    return 0;
}

Tree* criaTree()
{
  return NULL;
}

void adiciona(Tree** t, int num)
{
    if(*t == NULL)
    {
        *t = (Tree*)malloc(sizeof(Tree)); 
        (*t)->Lchild = NULL; 
        (*t)->Rchild = NULL;
        (*t)->Data = num;
    } 
    else 
    {
        if(num < (*t)->Data)
        {
            adiciona(&(*t)->Lchild, num);
        }
        if(num > (*t)->Data)
        {
            adiciona(&(*t)->Rchild, num);
        }
    }
}
void posfixo(Tree* node)
{
    if (node == NULL)
    {
        return;
    }
    posfixo(node->Lchild);
    posfixo(node->Rchild);
    printf(" %d", node->Data);
}
void infixo(Tree* node)
{
    if (node == NULL)
    {
        return;
    }
    infixo(node->Lchild);
    printf(" %d", node->Data);
    infixo(node->Rchild);
}
void prefixo(Tree* node)
{
    if (node == NULL)
    {
        return;
    }
    printf(" %d", node->Data);
    prefixo(node->Lchild);
    prefixo(node->Rchild);
}
