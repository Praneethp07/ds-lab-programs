#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *rchild;
    struct node *lchild;
};
typedef struct node *node;
void preorder(node temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}
void inorder(node temp)
{
    if(temp!=NULL)
    {
        inorder(temp->lchild);
        printf("%d\t",temp->data);
        inorder(temp->rchild);
    }
}
void postorder(node temp)
{
    if(temp!=NULL)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d\t",temp->data);
    }
}
node insertbst(node root,node newnode)
{
   if(root->data == newnode->data)
   {
       printf("data already avaliable\n");
   }
   else if(root->data > newnode->data)
   {
       if(root->lchild  == NULL)
       {
           root->lchild = newnode;
       }
       else
       {
           insertbst(root->lchild,newnode);
       }
   }
   else
   {
       if(root->rchild == NULL)
       {
           root->rchild = newnode;
       }
       else
       {
           insertbst(root->rchild,newnode);
       }
   }
}
int search(node root, int key)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->data  == key)
    {
        return 1;
    }
    if(root->data > key)
    {
        return search(root->lchild,key);
    }
    else
    {
        return  search(root->rchild,key);
    }
}
node createnode(int elem)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->rchild = NULL;
    temp->lchild = NULL;
    temp->data = elem;
    return temp;
}
void main()
{
   int n,i,item,op,found=0,key;
   node newnode,root=0;
   while(1)
   {
       printf("Enter the option\n1.create\n2.traverse\n3.search\n4.exit\n");
       scanf("%d",&op);
       switch(op)
       {
           case 1:printf("enter the no of nodes\n");
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
               printf("enter the data\n");
               scanf("%d",&item);
               newnode = createnode(item);
               if(root == NULL)
               {
                   root = newnode;
               }
               else
               {
                   insertbst(root,newnode);
               }
           }
           break;
           case 2:if(root == NULL)
           {
               printf("tree empty\n");
           }
           else
           {
               printf("the inorder traversal is\n");
               inorder(root);
               printf("the preorder traversal is\n");
               preorder(root);
               printf("the postorder traversal is\n");
               postorder(root);
           }
           break;
           case 3:printf("enter the element to be searched\n");
           scanf("%d",&key);
           found = search(root,key);
           if(found == 1)
           {
               printf("key found\n");
           }
           else
           {
               printf("key not found\n");
           }
           break;
           case 4:exit(0);
           break;
           default:printf("invalid choice\n");
       }
   }
}
