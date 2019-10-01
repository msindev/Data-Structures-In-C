#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void bfs(int graph[][MAX],int visit[],int n,int start)
{
    int f=0,r=-1,i;
    int q[10],node;
    visit[start]=1;
    q[++r]=start;
    while(f<=r)
    {
        node=q[f++];
        for(i=0;i<n;i++)
        {
            if(graph[node][i]==1&&visit[i]==0)
            {
                visit[i]=1;
                q[++r]=i;
            }
        }
    }
}

int main()
{
     int i,n,j;
    printf("Enter the total number of nodes:\n");
    scanf("%d",&n);
    int graph[MAX][MAX],visit[n],count=0,start;
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
    printf("Enter the starting vertex\n");
    scanf("%d",&start);
    for(i=0;i<n;i++)
        visit[i]=0;
    printf("The bfs traversal of the graph is: \n");
    bfs(graph,visit,n,start);
    count++;
    printf("Traversal for node %d: ", count);
    for(i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
        	printf("\nTraversal for node %d: %d ", count+1, i+1);
            bfs(graph,visit,n,i);
			count++;
            //printf("\n");
		}
        else
            printf("%d ",i+1);
    }
    if(count==1)
        printf("\nConnected Graph\n");
    else
        printf("\nNot connected and number of components is %d.\n",count);
    return 0;
}
