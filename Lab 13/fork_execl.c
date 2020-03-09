//fork and execl code to overcome problem of getting stuck in child process by using wait()
#include <unistd.h>
#include <stdio.h>
#include "sys/types.h"
#include <sys/wait.h>
int main(){
        
pid_t pid_value;
    int status = 0;
    pid_value= fork();
        if(pid_value!=0) {
                wait(&status);
                printf ( " I am the parent my Process ID is %d, myParents PID is %d, \n ",getpid(),getppid());
                printf( "Using the wait ensures that my child finishes first. \n ");
        }else {
        printf ( " I am the child, my Process ID is %d , my Parents PID is %d \n",getpid(),getppid());
        sleep(2);
        printf ( " Using execl to display running processes \n");
        execl ( "/bin/ps","ps",(char*)0);
        printf( "Due to the execl, you should not be able to read this ?\n " ) ;
        }
return 0;
} 
