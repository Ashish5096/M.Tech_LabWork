#include<stdio.h> 
#include <unistd.h>  
 
void main() 
{ 
    int pid;  
    int pid1,pid2; 
    pid = fork();  
 
    if (pid == -1) 
        printf("Error occurred \n"); 
    else if (pid == 0)  
    {  
        pid1=getpid(); 
        pid2=getppid(); 
        printf("\nChild process id : %d",pid1);  
        printf("\n Parent id of child process : %d", pid2);  
    }  
    
    printf("\n"); 
}

