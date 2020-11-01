#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>

typedef struct student
{
	char first_name[10];
	char last_name[10];
	char reg[10];
	double sub[7];
}student;



void main(int argc,char const *argv[])
{
    int shMemSegID1,shMemSegID2,pid,n,i,j,status;
	char str[10];
	double no,sum,avg;
    size_t shmSize=sizeof(student);
    FILE *fi;
    key_t key=8964;
    student *head,*start,*ptr,*temp,*addr2;
    
    shMemSegID1=shmget(key,shmSize,0666|IPC_CREAT);

	if(shMemSegID1<0)
	{
			printf(" Error in SHM GET \n");
			exit(1);
	}

	//printf("SEGEMENT ID1 %d\n",shMemSegID1);

    start=shmat(shMemSegID1,NULL,0);
    //printf("ADDRESS 1 %p\n",start);	
    

	fi=fopen(argv[1],"r");
	fscanf(fi,"%d",&n);

    temp=start;
	for(i=0;i<n;i++)
	{
		ptr=(student *)malloc(sizeof(student));
		fscanf(fi,"%s",ptr->first_name);
		fscanf(fi,"%s",ptr->last_name);	
        fscanf(fi,"%s",ptr->reg);

        for(j=0;j<7;j++)
		{
				fscanf(fi,"%lf",&no);
				ptr->sub[j]=no;
		}
        
        memcpy(temp,ptr,sizeof(student));
        temp++;
    }
			
	pid=fork();
	if(pid==-1)
	{
		printf("Error Ocuured \n");
		exit(1);
	}
	else if(pid ==0)
	{
		 shMemSegID2=shmget(key,shmSize,0666);
		 if(shMemSegID2<0)
		 {
			printf(" Error in SHM GET \n");
			exit(1);
		 }
		 //printf("SEGMENT ID2 %d\n",shMemSegID2);

		 head=shmat(shMemSegID2,NULL,0);
		// printf("ADDRESS 2 %p\n",head);
        
         ptr=head;

         printf("Registration No \t Avg Attendance \t Granted or Not Ganted \n\n");
         for(i=0;i<n;i++)
	     {
            sum=avg=0.0;
            status=1;

            //printf("%s\n",ptr->first_name);
            //printf("%s\n",ptr->last_name);
            printf("%s  \t\t",ptr->reg);

            for(j=0;j<7;j++)
		    {
                sum=sum+ptr->sub[j];
                if( (ptr->sub[j]) <75)
                    status=0;
		    }
            avg=sum/7;
            if(status==1)
                printf(" %.2lf \t\t\t Granted \n",avg);
            else if(status ==0)
                printf(" %.2lf \t\t\t Not Granted \n",avg);

            
            ptr++;
         }

    }			
    
}
