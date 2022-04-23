#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
char stack[MAX];
int top=-1;
void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return(stack[top--]);
}
int precidence(char e)
{
    switch(e)
    {
        case '(': return 1;
        case '#': return 0;
        case '+': 
        case '-': return 2;
        case '*': 
        case '/': 
        case '%': return 3;
        case '^': return 4;
        default:printf("invalid switch\n");
        exit(0);
    }
}
void main()
{
    char infix[100],postfix[100],ch;
    char trash;
    int i=0,k=0,pr;
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch == '(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch == ')')
        {
            while(stack[top]!='(')
            {
                if(stack[top]=='#')
                {
                    printf("Invaiddddd\n");
                    exit(0);
                }
                postfix[k++] = pop();
            }
            trash = pop();
        }
        else
        {
            pr = precidence(ch);
            if(ch == '^')
            {
                pr++;
            }
            while(precidence(stack[top])>=pr)
            {
                postfix[k++] = pop();
            }
            push(ch);
        }
       
    }
    while(stack[top]!='#')
    {
        if(stack[top] == '(')
        {
            printf("invalid expression\n");
            exit(0);
        }
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("the result is:%s\n",postfix);
}