/* Examination of creating two processes using fork: A Child process and a Parent process */
#include<stdio.h>
#include<unistd.h>
int main(){
pid_t pid;
        
 pid=fork();
        if(pid==0){
                printf("Child: %d \n", getpid());
        }else{
                printf("Parent: %d \n",  getpid());
        }
return 0;
}

