#include<string.h>
#include<stdio.h>
char str[100],pat[100],rep[100],ans[100];
int i,j,k,p,l,flag;
void read()
{
    printf("enter the main string\n");
    scanf("%[^\n]",str);
    printf("enter the pattern string\n");
    scanf("%*c%[^\n]",pat);
    printf("enter the replacement string\n");
    scanf("%*c%[^\n]",rep);
}
void patmch()
{
    while(str[i]!='\0')
    {
        if(str[j] == pat[p])
        {
            j++;
            p++;
            if(pat[p]=='\0')
            {
                flag = 1;
                for(k=0;rep[k]!='\0';k++)
                {
                    ans[l] = rep[k];
                    l++;
                }
                p=0;
                i=j;
            }
        }
        else
        {
            ans[l] = str[i];
            i++;
            l++;
            j=i;
            p=0;
        }
    }
}
void main()
{
    read();
    patmch();
    if(flag==1)
    {
        printf("match found\n");
        printf("result:%s\n",ans);
    }
    else
    {
        printf("match not found");
    }
}