#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(int argc,char const *argv[])
{
	int *input,size,i,j,temp,flag=0;
    FILE *fi,*fo;
    clock_t start, end;
    double sec = 0;

    if(argc!=3)
     {
        printf("Please enter correct no of arguments \n");
        exit(0);    
    }

    fi=fopen(argv[1],"r");

    fscanf(fi,"%d",&size);

    input=(int *)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    {
        fscanf(fi,"%d",&input[i]);
    }
	
    start = clock();

	for(i=0;i<size && flag==0 ;i++)
	{
		flag=1;
		for(j=0;j<size-i-1;j++)
		{
			if(input[j]>input[j+1])
			{
				temp=input[j];
				input[j]=input[j+1];
				input[j+1]=temp;
				flag=0;
			}
		}
	}

    end=clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time required to sort:- %f\n ",sec);
    
    fo=fopen(argv[2],"w+");

    for(i=0;i<size;i++)
    {
        fprintf(fo,"%d\n",input[i]);
    }
	
}
