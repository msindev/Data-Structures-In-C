#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void dfs(int graph[][MAX],int visit[],int n,int start)
{
    visit[start]=1;
    int i;
    printf("%d ",start);
    for(i=0;i<n;i++)
    {
        if(graph[start][i]==1&&visit[i]==0)
        {
            dfs(graph,visit,n,i);
        }

    }
}

void bfs(int graph[][MAX], int visit[], int n, int start);

int main()
{
    int i,n,j;
    printf("Enter the total number of nodes:\n");
    scanf("%d",&n);
    int graph[MAX][MAX],visit[n],count=0;
    printf("Enter the values of adjacency matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("The adjacency matrix is: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
         printf("\n");
    }
    for(i=0;i<n;i++)
        visit[i]=0;
    printf("The dfs traversal of the graph is: \n");
    for(i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            printf("Traversal for component %d: ", count+1);
            dfs(graph,visit,n,i);
            count++;
            printf("\n");
        }
    }
        if(count==1)
        {
            printf("\nConnected graph\n");
        }
        else
            printf("\nNot connected and number of components is %d\n",count);

}
