#include<stdio.h>
#include<stdlib.h>

int maximum(int,int);

void main(int argc,char const *argv[])
{
    FILE *fi,*fo;
    int w,n,i,j,wi=0,a,b;
	int max,n1;
	
    
    if(argc!=3)
     {
        printf("Please enter correct no of arguments \n");
        exit(0);    
    }

    fi=fopen(argv[1],"r");
    fo=fopen(argv[2],"w+");

    fscanf(fi,"%d",&w);
	fscanf(fi,"%d",&n);
    
    // For simplicity, consider index of weight & value starting from 1.

    int value[n+1];
    int weight[n+1];

    for(i=1;i<=n;i++)
        fscanf(fi,"%d",&value[i]);
        
	for(i=1;i<=n;i++)
		fscanf(fi,"%d",&weight[i]);

	
    int knapsack[n+1][w+1];
	 
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if( i==0 || j==0)
                knapsack[i][j]=0;
            else
            {
                wi=weight[i];

			    if( (j-wi)>=0)
				    a=value[i]+knapsack[i-1][j-wi];
			    else
				    a=0;

			    b=knapsack[i-1][j];
			    knapsack[i][j]=	maximum(a,b);
            }
		}
	} 

    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
            printf("%d ",knapsack[i][j]);

        printf("\n");
    } */

    max=knapsack[n][w];
	fprintf(fo,"%d\n",max);
    
    int vector[n+1];
    n1=n;

    for(i=0;i<=n;i++)
        vector[i]=0;
    
    while(max!=0)
    {
        if( knapsack[n1][w]== (knapsack[n1-1][w-weight[n1]]+value[n1]) )
        {
            vector[n1]=1;
            w=w-weight[n1];
            max=max-value[n1];
            n1=n1-1;
        } 
        else
            n1=n1-1;       
    }

    
    for(i=1;i<=n;i++)
      fprintf(fo,"%d ",vector[i]);

    fprintf(fo,"\n");

   for(i=1;i<=n;i++)
    {
      if(vector[i]==1)
        fprintf(fo,"%d ",i);
    }
    
    fprintf(fo,"\n\n");

		

}


int maximum(int a,int b)
{

	if(a>b)
		return a;
	else
		return b;

}
