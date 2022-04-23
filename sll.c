#include<stdio.h>
#include<stdlib.h>
int count;
struct node{
    char usn[10],name[20],branch[20],sem[20],phone[10];
    struct node *link;
};
typedef struct node *node;
node first = NULL;
node create()
{
    node temp = (node)malloc(sizeof(struct node));
    printf("enter usn\n");
    scanf("%s",temp->usn);
    printf("enter name\n");
    scanf("%s",temp->name);
    printf("enter branch\n");
    scanf("%s",temp->branch);
    printf("enter sem\n");
    scanf("%s",temp->sem);
    printf("enter phone number\n");
    scanf("%s",temp->phone);
    temp->link = NULL;
    return temp;
}
void insertfront()
{
    node temp = create();
    temp->link = first;
    first = temp;
}
void insertend()
{
    node temp = create();
    if(first == NULL)
    {
        first = temp;
    }
    else
    {
        node cur = first;
        while(cur->link!=NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
}
void deletefront()
{
    if(first == NULL)
    {
        printf("list empty\n");
        return;
    }
    node temp = first;
    first = first->link;
    temp->link = NULL;
    free(temp);
    temp = NULL;
}
void deleteEnd()
{
    if(first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(first->link == NULL)
    {
        free(first);
        first = NULL;
        return;
    }
    node cur = first;
    node prev = NULL;
    while (cur->link!=NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    free(cur);
    cur = NULL; 
}
void display()
{
    if(first == NULL)
    {
        printf("list empty\n");
        return;
    }
    node cur = first;
    while(cur!=NULL)
    {
        printf("usn:%s\n", cur->usn);
        printf("name:%s\n", cur->name);
        printf("branch:%s\n", cur->branch);
        printf("sem:%s\n", cur->sem);
        printf("phone:%s\n", cur->phone);
        cur = cur->link;
        count++;
    }
}
void main()
{
    int op,i,n;
    while(1)
    {
        printf("enter the option\n1.create\n2.insert front\n3.insert end\n4.delete front\n5.delete end\n6.display\n7.exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("enter the no of students\n");
            scanf("%d",&n);
            for(i = 0;i<n;i++)
            {
                printf("enter the student details\n");
                insertfront();
            }
            break;
            case 2:insertfront();
            break;
            case 3:insertend();
            break;
            case 4:deletefront();
            break;
            case 5:deleteEnd();
            break;
            case 6:display();
            break;
            case 7:exit(0);
        }

    }
}