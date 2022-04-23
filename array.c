#include<stdio.h>
#include<stdlib.h>
int i,n,a[20];
void create()
{
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display()
{
    printf("the elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void insert()
{
    int pos,elem;
    printf("enter the element to be inserted\n");
    scanf("%d",&elem);
    printf("enter the position where the element is to be inserted\n");
    scanf("%d",&pos);
    pos--;
    if(pos>0 && pos<n)
    {
        for(i=n-1;i>=pos;i--)
        {
            a[i+1] = a[i];
        }
        a[pos] = elem;
        n++; 
    }

}
void delete()
{
    int pos,trash;
    printf("enter the position where the element is to be inserted\n");
    scanf("%d",&pos);
    pos--;
    if(pos>0 && pos<n)
    {
        for(i=pos;i<n;i++)
        {
            a[i] = a[i+1];
        }
        n--;
        trash = a[pos];
        printf("the deleted element is %d",a[pos]);
        
    }
}
void main()
{
    int op;
    while (1)
    {
        printf("enter the option\n1.create\n2.insert\n3.delete\n4.display\n5.exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:create();
            break;
            case 2:insert();
            break;
            case 3:delete();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            default:printf("invalid option\n");
        }
    }
    
}