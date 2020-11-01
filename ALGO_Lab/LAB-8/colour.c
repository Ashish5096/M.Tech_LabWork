#include<stdio.h>
#include<stdlib.h>


void DFS(int u,int n,int visited [],int adj[n+1][n+1],int colour []);
int count=1;

void main(int argc,char const *argv[])
{
	int n,m,i,u,v,j;
	FILE *fi;

	fi=fopen(argv[1],"r");
	
	fscanf(fi,"%d",&n);
	fscanf(fi,"%d",&m);

	int adj[n+1][n+1],adj1[n+1][n+1];
    int colour[n+1],visited[n+1];

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			adj[i][j]=0;
		}
	}

	for(i=0;i<m;i++)
	{
		fscanf(fi,"%d",&u);
		fscanf(fi,"%d",&v);
		adj[u][v]=1;
        adj[v][u]=1;
	}

	for(i=0;i<=n;i++)
	{
		visited[i]=0;
        colour[i]=0;
	}

	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			DFS(i,n,visited,adj,colour);
	}
	
	
    for(i=1;i<=n;i++)
    {
        printf("vertex %d  colour %d \n",i,colour[i]);
    }

    printf("Minimum no of colours required :- %d \n",count);
    
	
}


void DFS(int u,int n,int visited [],int adj[n+1][n+1],int colour [])
{
	int v,c,flag;

	visited[u]=1;

    for(c=1;c<=count;c++)
    {
        flag=0;
        for(v=1;v<=n;v++)
	    {
		    if(adj[u][v]!=0 && visited[v]==1)
		    {
			    if(colour[v]==c)
                {
                    flag=1;
                    break;
                }
		    }
	    }
        if(flag==0)  
            break;
    }

    colour[u]=c;
    if( flag==1 && c>count )
        count++;
         
	for(v=1;v<=n;v++)
	{
		if(adj[u][v]!=0 && visited[v]==0)
		{
			DFS(v,n,visited,adj,colour);
		}
	}
    
}
