#include<stdio.h>
int i,j,a[100][100],n,q[100],visited[100],reach[100],f=0,r=-1;
void bfs(int v)
{
    int u;
    q[++r] = v;
    visited[v] = 1;
    while(f<=r)
    {
        u = q[f++];
        for(i=1;i<=n;i++)
        {
            if(a[u][i] && !visited[i])
            {
                q[r++]=i;
                visited[i] = 1;
                printf("->%d",i);
            }
        }
    }
}
void dfs(int v)
{
    int i;
    reach[v] = 1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i]&& !reach[i])
        {
            printf("->%d",i);
            dfs(i);
        }
    }
}
void main()
{
    int v;
    printf("enter the no of vertex\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        visited[i] = 0;
        reach[i] = 0;
        q[i] = 0;
    }
    printf("enter the adjecent matrix representation\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the starting vertex\n");
    scanf("%d",&v);
    if(v<1 || v>n)
    {
        printf("Invalid\n");
        return;
    }
    printf("the bfs traversal is %d",v);
    bfs(v);
    printf("the dfs traversal is %d",v);
    dfs(v);
    printf("\n");
}