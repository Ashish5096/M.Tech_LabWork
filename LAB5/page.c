#include<stdio.h>
#include<stdlib.h>

void Enqueue(int [],int,int,int *,char [],int m,int n,int [m][n]);
void display(int [],int,int,int m,int n,int [m][n]);

void main(int argc,char const *argv[])
{
	FILE *fi;
	int pageSize,virtualSpace,physicalSpace,n,page,faultCount=0,i;
	int NofPages,NFrames;

	fi=fopen(argv[1],"r");
	fscanf(fi,"%d",&pageSize);
	fscanf(fi,"%d",&virtualSpace);
	fscanf(fi,"%d",&physicalSpace);
	fscanf(fi,"%d",&n);

	NofPages=virtualSpace/pageSize;
	NFrames=physicalSpace/pageSize;
	
	
	int ref[n],page_Table[NofPages][3],frameQueue[NFrames];
    char c[n];

	for(i=0;i<n;i++)
    {
		fscanf(fi,"%d",&ref[i]);
        fscanf(fi," %c",&c[i]);
    }

    for(i=0;i<NofPages;i++)
    {
		page_Table[i][0]=-1;
        page_Table[i][1]=0;
        page_Table[i][2]=0;
    }
    


	for(i=0;i<NFrames;i++)
		frameQueue[i]=-1;
	
	

	for(i=0;i<n;i++)
	{
		page=ref[i]/pageSize;
		Enqueue(frameQueue,page,NFrames,&faultCount,c,NofPages,3,page_Table);
	}

	printf("\n\nTherefore total no of page fault %d\n",faultCount);	
}

void Enqueue(int Q[],int page,int NFrames,int *pf,char c[],int m,int n,int page_Table[m][n])
{
	int i,temp=0;
	static int count=0;
	  
    	
    if(page_Table[page][1]==0)
	{
	    temp=Q[count % NFrames];
        if(temp!=-1)
        {
            page_Table[temp][1]=-1;            
            page_Table[temp][1]=0;
            page_Table[temp][2]=0;
        }

        Q[count % NFrames] =page;
        page_Table[page][0]= count % NFrames;
        page_Table[page][1]=1;

        if( c[page] == 'W')
            page_Table[page][2]=1;
		count++;
		*pf=*(pf)+1;
		display(Q,NFrames,*(pf),m,n,page_Table);
	}
}

void display(int Q[],int NFrames,int pf,int m,int n,int page_Table[m][n])
{
	int i;
    printf("\n\nPAGE FAULT NO:- %d \n",pf);
	printf("\nFrame Table \n");
	for(i=NFrames-1;i>=0;i--)
		printf("%d\n",Q[i]);
    printf("\nPage Table \n");
    printf("Page NO Frame No Reference Bit Dirty Bit \n");
    for(i=0;i<m;i++)
    {
        printf("%d \t %d\t\t%d \t %d\n",i,page_Table[i][0],page_Table[i][1],page_Table[i][2]);
    }
    
    
}
