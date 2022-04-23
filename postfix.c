#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
char stack[MAX];
int top =-1;
void push(int elem)
{
    stack[++top] = elem;
}
void main()
{
    int k=0,op1,op2;
    char postfix[100],ch;
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    while((ch=postfix[k++])!='\0')
    {
        if(isalpha(ch))
        {
            printf("invalid expression\n");
        }
        else if(isdigit(ch))
        {
            push(ch-48);
        }
        else
        {
            op1 = stack[top--];
            if(top<=-1)
            {
                printf("invalid expression\n");
                return;
            }
            op2 = stack[top--];
            switch(ch)
            {
                case '+':push(op1+op2);
                break;
                case '-':push(op1-op2);
                break;
                case '*':push(op1*op2);
                break;
                case '/':push(op1/op2);
                break;
                case '%':push(op1%op2);
                break;
                case '^':push(pow(op1,op2));
                break;

            }
        }
    }
    if(top!=0)
    {
        printf("invalid\n");
        return;
    }
    else
    {
        printf("the result is %d\n",stack[top]);
    }

}