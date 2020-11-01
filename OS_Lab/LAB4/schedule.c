#include<stdio.h>
#include<stdlib.h>

void Round_Robin_Sch(int,int [],int [],int [],int);
void Priority_Sch(int,int [],int [],int [],int [],int);

void sort(int [],int []);
void Enqueue(int,int []);
int Dqueue(int []);
int top=-1;

void main(int argc, char const *argv[])
{
	FILE *fi;
	int n,i,TimeQuantum;

	fi=fopen(argv[1],"r");
	fscanf(fi,"%d",&n);
	fscanf(fi,"%d",&TimeQuantum);
	
	int priority_val[n],AT[n],BT[n],queue[n];;

	for(i=0;i<n;i++)
	{

		fscanf(fi,"%d",&priority_val[i]);
		fscanf(fi,"%d",&AT[i]);
		fscanf(fi,"%d",&BT[i]);
	}
	
	Round_Robin_Sch(n,AT,BT,queue,TimeQuantum);
    top=-1;
    Priority_Sch(n,priority_val,AT,BT,queue,TimeQuantum);

}

void Round_Robin_Sch(int n,int AT[],int BT[],int queue[],int TimeQuantum)
{
	int time=0,i,CT[n],temp,j,flag=0,BT1[n],RQ[n],k;

    printf("\n Results for Round Robin Scheduling \n");
    printf("-------------------------------------------\n\n");
	
	for(j=0;j<n;j++)
    {
		BT1[j]=BT[j];
        RQ[j]=0;
        
        if(time>=AT[j])
        {
		    Enqueue(j,queue);
            RQ[j]=1;
        }
    }

         	
	while(top!=-1)
	{
        i=Dqueue(queue);
        flag=TimeQuantum;	
        printf("(%d, P%d) ",time,i+1);
        
        while(flag)
        {   
			BT1[i]=BT1[i]-1;
            time=time+1;
                
		    if(BT1[i]>0)
			{  
                for(j=0;j<n;j++)
                   if( RQ[j]==0 && time>=AT[j] )
                   {
                       Enqueue(j,queue);
                       RQ[j]=1;
                   }
			}
            else if(BT1[i]==0)
            {
               CT[i]=time; 
                break; 
            }
			
            flag--;
        }
        
        if(BT1[i]>0)
            Enqueue(i,queue);		
	}

    printf("\n\nProcess  AT  BT  CT  TAT  WT\n\n");
	for(k=0;k<n;k++)
	  printf("P%d \t %d   %d   %d  %d  %d \n",k+1,AT[k],BT[k],CT[k],(CT[k]-AT[k]),(CT[k]-AT[k]-BT[k]));

}


void Priority_Sch(int n,int priority_val[],int AT[],int BT[],int queue[],int TimeQuantum)
{
	int time=0,i,CT[n],temp,j,preempt=1,BT1[n],RQ[n],k;

    
    printf("\n Results for Priority Scheduling \n");
    printf("-------------------------------------------\n\n");    

    for(j=0;j<n;j++)
    {
		BT1[j]=BT[j];
        RQ[j]=0;

        if(time>=AT[j])
        {
		    Enqueue(j,queue);
            RQ[j]=1;
        }
    }

    
    sort(priority_val,queue);
    
    while(top!=-1)
	{
            preempt=1;
            i=Dqueue(queue);	
            
            printf("(%d, P%d) ",time,i+1);


            while(preempt)
            {
            
			    temp=BT1[i]-1;
                time=time+1;
                
                
		        if(temp>=0)
			    {
				    BT1[i]=temp;
                    CT[i]=time;
                    for(j=0;j<n;j++)
                        if( RQ[j]==0 && time>=AT[j] )
                        {
                            Enqueue(j,queue);
                            RQ[j]=1;
                        }

                    sort(priority_val,queue);
                    
                    if(priority_val[i] > priority_val[queue[0]] && BT1[i]!=0)
                    {
                        preempt=0;
                        Enqueue(i,queue);
                        sort(priority_val,queue);
                    }
                    if(BT1[i]==0)
                        preempt=0;
                   
                    
			    }
			    
			}		

	}

    printf("\n\n Process  AT  BT  CT  TAT  WT\n\n");
	for(k=0;k<n;k++)
	  printf(" P%d \t  %d   %d   %d  %d  %d \n",k+1,AT[k],BT[k],CT[k],(CT[k]-AT[k]),(CT[k]-AT[k]-BT[k]));


}


void sort(int priority_val[],int queue[])
{
    int i,temp,min,j;
    
    for(i=0;i<=top;i++)
    {
        min=i;
        for(j=i+1;j<=top;j++)
        {
            if( priority_val[queue[min]] > priority_val[queue[j]] )
                min=j;
        }
        
        temp=queue[i];
        queue[i]=queue[min];
        queue[min]=temp;   
    }

}

void Enqueue(int x,int queue[])
{
	top++;
	queue[top]=x;
}


int Dqueue(int queue[])
{
	int temp,i;

	temp=queue[0];

	for(i=0;i<top;i++)
		queue[i]=queue[i+1];

	top--;
    
    return temp;
}
