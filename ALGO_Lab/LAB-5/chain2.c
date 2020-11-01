#include<stdio.h>
#include<stdlib.h>


void main(int argc,char const *argv[])
{

    FILE *fp;	
    int n,i,j,k,l,q;

    fp=fopen(argv[1],"r");
	
	fscanf(fp,"%d",&n);

    n=n+1;
	
	int p[n],m[n][n];

	for(i=0;i<n;i++)
        fscanf(fp,"%d",&p[i]);

	for(i=1;i<n;i++)
		m[i][i]=0;

	for(l=2;l<n;l++)
	{
		for(i=1;i<(n-l+1);i++)
		{
			j=i+l-1;
            m[i][j]=99999999;

			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				
				if(q<m[i][j])
				{
					m[i][j]=q;
				}
			}
		}
	}
    
    printf("Mnimum number of Multiplication Required  %d \n",m[1][n-1]);

}
	
	
