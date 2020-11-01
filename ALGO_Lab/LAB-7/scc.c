#include<stdio.h>
#include<stdlib.h>


void DFS(int u,int n,int visited [],int t1 [],int t2 [],int adj[n+1][n+1]);
int max(int ,int [],int []);
int flag=0;

void main(int argc,char const *argv[])
{
	int n,m,i,u,v,w,j,x,count=0;
	FILE *fi;

	fi=fopen(argv[1],"r");
	
	fscanf(fi,"%d",&n);
	fscanf(fi,"%d",&m);

	int adj[n+1][n+1],adj1[n+1][n+1],t1[n+1],t2[n+1],f1[n+1],f2[n+1],visited[n+1];

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
	}

	for(i=0;i<=n;i++)
	{
		visited[i]=0;//parent[i]=0;
		t1[i]=t2[i]=0;
	}

	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			DFS(i,n,visited,t1,t2,adj);
	}
	
	for(i=1;i<=n;i++)
	{
		visited[i]=0;//parent[i]=0;
		f1[i]=f2[i]=0;
	}
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			adj1[i][j]=adj[j][i];
		}
	}
	
    flag=1;
	for(i=1;i<=n;i++)
	{
		x=max(n,t2,visited);
        if(x==0)
            break;
		DFS(x,n,visited,f1,f2,adj1); 
        printf("\n");
        count++;   
	}

    printf("Number of components %d \n",count); 
    
	
}


void DFS(int u,int n,int visited [],int t1 [],int t2 [],int adj[n+1][n+1])
{
	int v;
    static int T=0;

	visited[u]=1;
	T++;
	t1[u]=T;
    
    if(flag==1)  
     printf("%d ",u); 
	for(v=1;v<=n;v++)
	{
		if(adj[u][v]!=0 && visited[v]==0)
		{
			DFS(v,n,visited,t1,t2,adj);
		}
	}

	T++;
	t2[u]=T; 
    
}

int max(int n,int t2[],int visited[])
{
	int i,x=0;

	for(i=1;i<=n;i++)
	{
		if(t2[i]>t2[x] && visited[i]==0)
			x=i;
	}
	
	return x;
}

