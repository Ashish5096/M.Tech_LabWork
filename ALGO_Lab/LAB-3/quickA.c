#include<stdio.h>
#include<stdlib.h>

void Quick_sort(int [],int ,int);
int partition(int [],int, int);

int cp=0,sp=0;
void main(int argc,char const *argv[])
{
        FILE *fi,*fo;
        int n,i,*arr;

        if(argc!=3)
        {
            printf("Please enter correct no of arguments \n");
            exit(0);    
        }

        fi=fopen(argv[1],"r");

        fscanf(fi,"%d",&n);

        arr=(int *)malloc(n*sizeof(int));

        for(i=0;i<n;i++)
        {
                fscanf(fi,"%d",&arr[i]);
        }

        Quick_sort(arr,0,n-1);



        /*for(i=0;i<n;i++)
        {
                printf("%d\n",arr[i]);
        }*/
        
        fo=fopen(argv[2],"w+");

        fprintf(fo,"Number of comparisons %d \n",cp);
        fprintf(fo,"Number of Swaps %d \n",sp);


                                                                                                                                            
}


void Quick_sort(int p[],int a,int b)
{
        int q;

        if(a<b)
        {
                q=partition(p,a,b);
                Quick_sort(p,a,q-1);
                Quick_sort(p,q+1,b);
        }

}

int partition(int A[],int a, int b)
{
        int pivot,temp;
        int i,j;


        pivot=a;

        i=a+1,j=b;
        while(1)
        {
                while( A[pivot] >=A[i] )
                {
                        i++;
                        cp++;
                }                                                                                                
                while( (A[pivot] < A[j]) && j>=a)
                {
                        j--;
                        cp++;
                }
                if(i<j)
                {
                        temp=A[i];
                        A[i]=A[j];
                        A[j]=temp;
                        sp++;
                }
                else
                {
                        temp=A[j];
                        A[j]=A[pivot];
                        A[pivot]=temp;
                        sp++;
                        break;
                }
        }

        return j;
}



