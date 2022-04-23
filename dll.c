#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data[100];
    struct node *rlink;
    struct node *llink;
};
typedef struct node *node;
node first = NULL;
node create()
{
    node temp = (node)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%s",temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
    return temp;
}
void insertFront()
{
    node temp = create();
    if(first == NULL)
    {
        first = temp;
        return;
    }
    temp->rlink = first;
    first->llink = temp;
    first = temp;
}
void insertEnd()
{
    node temp = create();
    if (first == NULL)
    {
        first = temp;
        return;
    }
    node cur = first;
    while (cur->rlink!=NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
}
void deleteFront()
{
    if(first == NULL)
    {
        printf("list empty\n");
        return;
    }
    node temp =first;
    first = first->rlink;
    temp->rlink = NULL;
    first->llink = NULL;
    free(temp);
    temp = NULL;
}
void deleteEnd()
{
    if (first == NULL)
    {
        printf("list empty\n");
        return;
    }
    node cur = first;
    while(cur->rlink!=NULL)
    {
        cur = cur->rlink;
    }
    cur->llink->rlink = NULL;
    free(cur);
    cur = NULL;
}
void display()
{
    if (first == NULL)
    {
        printf("list empty\n");
        return;
    }
    node cur = first;
    while (cur!= NULL)
    {
        printf("\n________\n");
        printf("---%s---\n",cur->data);
        printf("________\n");
        printf("\n");
        cur = cur->rlink;
    }
}
void main()
{
    int op, i, n;
    while (1)
    {
        printf("enter the option\n1.create\n2.insert front\n3.insert end\n4.delete front\n5.delete end\n6.display\n7.exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("enter the no of nodes\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("enter the details\n");
                insertEnd();
            }
            break;
        case 2:
            insertFront();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        }
    }
}