#include<stdio.h>
#include<stdlib.h>
int *HT,hi,n,m,i,j,count,key,flag;
void createht()
{
    HT = (int*)malloc(m*sizeof(int));
    if(m==0)
    {
        printf("no memory is allocated\n");
        return;
    }
    for(i=0;i<m;i++)
    {
        HT[i] = -1;
    }
}
void insertht(int key)
{
    hi = key%m;
    while(HT[hi]!=-1)
    {
        hi = (hi+1)%m;
        flag = 1;
    }
    if(flag == 1)
    {
        printf("collision detected and is avoided by linear probing\n");
        flag = 0;
    }
    HT[hi] = key;
    count++;

}
void displayht()
{
    if(n == 0)
    {
        printf("HT empty\n");
    }
    else
    {
        int i;
        for(i=0;i<m;i++)
        {
            printf("[%d]-->%d\n",i,HT[i]);
        }
    }
}
void main()
{
    printf("enter the value of n\n");
    scanf("%d",&n);
    printf("enter the 2digit memory location value\n");
    scanf("%d",&m);
    createht();
    
    for(i=0;i<n;i++)
    {
        printf("enter the 4 digit key value\n");
        scanf("%d",&key);
        if(count  == m)
        {
            printf("ht full\n");
            break;
        }
        else
        {
            insertht(key);
        }
    }
    displayht();

}