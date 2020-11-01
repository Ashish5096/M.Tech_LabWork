#include<stdio.h>
#include<stdlib.h>


void main(int argc,char const *argv[])
{
	
	int np,nr,temp,i,j,flag,sum,k;
	FILE *fi;
	char str[100];

	fi=fopen(argv[1],"r");

	
	fscanf(fi,"%d",&np);
    nr=3;
	

	if( argc!=2)
	{
		printf(" Wrong number of arguments \n");
		exit(0);
	}

	int max[np][nr], allocation[np][nr],request[np][nr],need[np][nr],available[nr];
	int process[np],resource[nr];
	
	for(i=0;i<np;i++)
		process[i]=0;

	for(i=0;i<3;i++)
		fscanf(fi,"%d",&resource[i]);

	/*for(j=0;j<nr;j++)
		available[j]=5;
	
	resource[0]=10;
	resource[1]=5;
	resource[2]=7;*/

	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
			fscanf(fi,"%d",&allocation[i][j]);
		for(j=0;j<nr;j++)
			fscanf(fi,"%d",&request[i][j]);
		for(j=0;j<nr;j++)
			fscanf(fi,"%d",&max[i][j]);
	}
	
	printf("\n Available Table \n");
	for(j=0;j<nr;j++)
	{
		sum=0;		
		for(i=0;i<np;i++)
			sum=sum+allocation[i][j];
		
		available[j]=resource[j]-sum;
		printf("%d ",available[j]);
	}
	printf("\n");		

	printf("\n Allocation Table \n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
			printf("%d ",allocation[i][j]);
		printf("\n");
	}

	printf("\n Request Table \n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
			printf("%d ",request[i][j]);
		printf("\n");
	}

	printf("\n Max Table \n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
			printf("%d ",max[i][j]);
		printf("\n");
	}
	
	printf("\n Need Table \n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");	
	i=0;
	temp=0;
	while(1)
	{
	    temp=0;
	    if(process[i]==0 && temp==0)
	    {
		for(j=0;j<nr;j++)
		{
			if( request[i][j]>need[i][j] )
			{
				printf(" Process %d exceeds maximum claim \n",i);
				exit(0);
			}
		}

		flag=0;
		for(j=0;j<nr;j++)
		{
			if( request[i][j]>available[j] )
				flag=1;
		}
		
		if(flag==0)
		{
			process[i]=1;
			printf(" Process %d executes \n",i);
			for(j=0;j<nr;j++)
			{
				available[j]=available[j]+allocation[i][j];
				printf("%d ",available[j]);
			}
			printf("\n");
			
		}
		temp=1;
	   }

	   i++;
	   if( i > (np-1) )
		i=0;

	   for(k=0;k<np;k++)
	   { 
		if(process[k]==0)
		 temp=1;
	   }
	   if(temp==0)
		break;
	}






}
