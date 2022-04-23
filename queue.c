#include<stdio.h>
#include<stdlib.h>
#define MAX 5
char q[MAX];
int f=-1,r=-1;

void insert()
{
    if(f == (r+1)%MAX)
    {
        printf("queue overflow\n");
        return;
    }
        char c;
        printf("enter the character to be inserted\n");
        scanf("%*c%c",&c);
        r = (r+1)%MAX;
        q[r] = c;
        if(f == -1)
        {
            f++;
        }
}
void delete()
{
    if(f == -1)
    {
        printf("queue underflow\n");
        return;
    }
    else
    {
       char trash = q[f];
       if(f == r)
       {
           f = r = -1;
       }
       f = (f+1)%MAX;

    }

}
void display()
{
    if(f == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    else
    {
        int i = f;
        while(i!=r)
        {
            printf("the contents are %c\n",q[i]);
            i = (i+1)%MAX;
        }
        printf("the contents are %c\n",q[r]); 
    }
}
void main()
{
    int op;
    while (1)
    {
        printf("enter the option\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("invalid option\n");
        }
    }
}