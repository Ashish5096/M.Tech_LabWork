#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{

        char *args[]={"./Q3exec",NULL}; //A null terminated array of character pointers 

        execvp(args[0],args);

        /*All statements are ignored after execvp() call as this whole  
        process(execDemo.c) is replaced by another process (EXEC.c) 
        */
        printf("\nEnding-----");

}

