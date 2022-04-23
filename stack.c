#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push()
{
    int elem;
    if(top == MAX-1)
    {
        printf("stack overflow\n");
        return;
    }
        printf("enter the element\n");
        scanf("%d",&elem);
        stack[++top] = elem;

}
void pop()
{
    if(top == -1)
    {
        printf("stack underflow");
        return;
    }
    else
    {
        int trash = stack[top--];
        printf("the deleted element is:%d",trash);
    }

}
void display()
{
    int i;
    if(top == -1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("the stack contents are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
void palindrome()
{
    int k=top,flag=0,i=0;
    if(top == -1)
    {
        printf("stack is empty\n");
        return;  
    }
    else
    {
        while(k>top/2)
        {
            if(stack[i++]==stack[k--])
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            printf("not a palindrome\n");
        }
        else
        {
            printf("palindrome\n");
        }
    }

}
void main()
{
    int op;
    while (1)
    {
        printf("enter the option\n1.push\n2.pop\n3.palindrome\n4.display\n5.exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:palindrome();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            default:printf("invalid option\n");
        }
    }
}