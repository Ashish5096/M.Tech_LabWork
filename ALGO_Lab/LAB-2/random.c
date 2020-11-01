#include<stdio.h>
#include<stdlib.h>


void main(int argc,char const *argv[])
{
	int n,x;
	FILE *fp;
	
    // First argument file name
	fp=fopen(argv[1],"w+");

    // Second argument, no of elements 
    sscanf(argv[2],"%d",&n);

	fprintf(fp,"%d\n",n);

	srand(6);
	
	for(int i=0;i<n;i++)
	{
		x=rand()%200;
		fprintf(fp,"%d\n",x);
	}
	
	fclose(fp);	
}
