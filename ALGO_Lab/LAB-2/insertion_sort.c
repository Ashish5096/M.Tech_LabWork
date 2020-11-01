#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void insertionsort(int x[],int n);
void main(int argc,char const *argv[])
{
    FILE *fi,*fo;
    int *x,n,i;
    clock_t start, end;
    double sec = 0;
    

    if(argc!=3)
     {
        printf("Please enter correct no of arguments \n");
        exit(0);    
    }

    fi=fopen(argv[1],"r");

    fscanf(fi,"%d",&n);

    x=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        fscanf(fi,"%d",&x[i]);
    }

    start = clock();
 
    insertionsort(x,n);

    end=clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time required to sort:- %f\n ",sec);

    fo=fopen(argv[2],"w+");

    for(i=0;i<n;i++)
    {
        fprintf(fo,"%d\n",x[i]);
    }
                                                                                                                                   

}
void insertionsort(int x[],int n)
{
    int y,k,i;

    for(k=1;k<n;k++)
    {
        y=x[k];
        for(i=k-1;i>=0&&y<x[i];i--)
            x[i+1]=x[i];

        x[i+1]=y;
    }
    
}
