#include<stdio.h>
void tower(int n,char beg,char aux,char end)
{
    if(n==1)
    {
        printf("move disk %d from peg %c to peg %c\n",n,beg,end);
        return;
    }
    else
    {
        tower(n-1,beg,end,aux);
        printf("move disk %d from peg %c to peg %c\n",n,beg,end);
        tower(n-1,aux,beg,end);
    }
}
int main()
{
    int n;
    printf("enter the no of disks\n");
    scanf("%d",&n);
    printf("the sequence involved is:\n");
    tower(n,'A','B','C');
    return 0;
}