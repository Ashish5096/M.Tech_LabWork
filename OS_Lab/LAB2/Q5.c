#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *process,*resource,p,r,i,pr,re;
    char c;

    printf("Enter the number of process \n");
    scanf("%d",&p);

    printf("Enter the number of resource \n");
    scanf("%d",&r);

    process=(int *)malloc((p+1)*sizeof(int));
    resource=(int *)malloc((r+1)*sizeof(int));
    
    for(i=0;i<=p;i++)
        process[i]=-1;
    
    for(i=0;i<=r;i++)
        resource[i]=-1;



    while(1)
    {
        printf("Enter the process no and resource no you want to allocate to it \n");
        scanf("%d%d",&pr,&re);
        if(pr>=1 && pr<=p && re>=1 && re<=r)
        {
            if(process[pr-1]==-1 && resource[re-1]==-1)
            {
                process[pr-1]=re;
                resource[re-1]=pr;
                printf("Resource R%d assigned to process P%d sucessfully \n ",re,pr);
            }
            else if(process[pr-1]==re)
            {
                printf(" Duplicate Request \n");
            }
            else if (resource[re-1]!=-1)
            {
                printf("Resource R%d already assigned to Process P%d \n ",re,resource[re-1]);
            }
        }
        else
            printf(" Please enter correct process & resource no \n");

        printf("Do you want to continue with the process, Press Y to continue any other key to exit:-  ");
        scanf(" %c",&c);
        if(c!='Y' && c!='y')
           break;
    }


}
