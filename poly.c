#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coeff,expox,expoy,expoz;
    struct node *link;

};
typedef struct node *node;
node createnode(int c,int ex,int ey,int ez)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->expox = ex;
    temp->expoy = ey;
    temp->expoz = ez;
    temp->link = NULL;
    return temp;

}
node createheadnode()
{
    node temp = (node)malloc(sizeof(struct node));
    temp->coeff = 0;
    temp->expox = -1;
    temp->expoy = -1;
    temp->expoz = -1;
    temp->link = temp;
    return temp;
}
node insertrear(int c, int x, int y, int z, node head)
{
    node temp = createnode(c, x, y, z);
    if (head->link == head)
    {
        head->link = temp;
    }
    else
    {
        node cur = head;
        while (cur->link != head)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
    temp->link = head;
    head->coeff = (head->coeff) + 1;
    return head;
}
node createpoly(node poly)
{
    int x,y,z,coeff,i,n;
    printf("enter the number of terms\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the coefficient:\n");
        scanf("%d",&coeff);
        printf("enter the exponent of x:\n");
        scanf("%d",&x);
        printf("enter the exponent of y:\n");
        scanf("%d", &y);
        printf("enter the exponent of z:\n");
        scanf("%d", &z);
        poly = insertrear(coeff,x,y,z,poly);
    }
    return poly;
    printf("\n");
}

double evaluate(int x,int y,int z,node head)
{
    double sum = 0.00;
    if(head->link == head)
    {
        printf("list is empty\n");
    }
    else
    {
        node cur = head->link;
        while(cur!=head)
        {
            sum = sum+cur->coeff*pow(x,cur->expox)*pow(y,cur->expoy)*pow(z,cur->expoz);
            cur = cur->link;
        }
        printf("\n");
    }
    return sum;
}
void display(node head)
{
    if(head->link == head)
    {
        printf("list is empty\n");
    }
    else
    {
        node cur = head->link;
        while(cur!=head)
        {
            if(cur->coeff > 0)
            {
                printf("+%dx^%dy^%dz^%d\t",cur->coeff,cur->expox,cur->expoy,cur->expoz);
            }
            else
            {
                printf("%dx^%dy^%dz^%d\t",cur->coeff, cur->expox,cur->expoy,cur->expoz);
            }
            cur = cur->link;
        }
        printf("\n");
    }
}
node add(node a,node b)
{
    node starta,startb;
    starta = a;
    startb = b;
    node c = createheadnode();
    a = a->link;
    b = b->link;

    int sum = 0;
    while(a!=starta && b!=startb)
    {
        if((a->expox == b->expox)&&(a->expoy == b->expoy)&&(a->expoz == b->expoz))
        {
            sum = a->coeff+b->coeff;
            c = insertrear(sum,a->expox,a->expoy,a->expoz,c);
            a = a->link;
            b = b->link;
        }
        else if(a->expox > b->expox)
        {
            c = insertrear(a->coeff, a->expox, a->expoy, a->expoz, c);
            a = a->link;
        }
        else if ((a->expox == b->expox) && (a->expoy > b->expoy))
        {
            c = insertrear(a->coeff, a->expox, a->expoy, a->expoz, c);
            a = a->link;
        }
        else if ((a->expox == b->expox) && (a->expoy == b->expoy) && (a->expoz > b->expoz))
        {
            c = insertrear(a->coeff, a->expox, a->expoy, a->expoz, c);
            a = a->link;
        }
        else
        {
            c = insertrear(b->coeff, b->expox, b->expoy, b->expoz, c);
            b = b->link;
        }
    }
    while(a!=starta)
    {
        c = insertrear(a->coeff, a->expox, a->expoy, a->expoz, c);
        a = a->link;
    }
    while(b!=startb)
    {
        c = insertrear(b->coeff, b->expox, b->expoy, b->expoz, c);
        b = b->link;
    }
    return c;
}
int main()
{
    node poly = NULL;
    poly = createheadnode();
    poly = createpoly(poly);
    display(poly);
    double res = 0.00;
    int x,y,z;
    printf("enter the values for x,y and z");
    scanf("%d%d%d",&x,&y,&z);
    res = evaluate(x,y,z,poly);
    printf("the evaluated result is %.2lf\n",res);
    node polya=NULL,polyb=NULL;
    polya  = createheadnode();
    polya = createpoly(polya);
    display(polya);
    polyb = createheadnode();
    polyb = createpoly(polyb);
    display(polyb);
    node polysum;
    polysum = add(polya,polyb);
    display(polysum);
    printf("\n");
    return 0;
}