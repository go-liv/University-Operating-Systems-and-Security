//fork and execl code to overcome problem of getting stuck in child process by using wait()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys/types.h"
#include <sys/wait.h>
int main(){        
    pid_t pid_value;
    int status = 0;
    char* directory;
    char* command;
    int selection;

    while(1)
    {
        printf("\n|------------------------------------------------------------|\n");
        printf("| Welcome to the linux commands menu.                        |\n");
        printf("| To use a command just type the number on the command line. |\n");
        printf("|----------------------List of commands----------------------|\n");
        printf("| 1 -> ps                                                    |\n");
        printf("| 2 -> date                                                  |\n");
        printf("| 3 -> pwd                                                   |\n");
        printf("| 4 -> ls                                                    |\n");
        printf("|                                                            |\n");
        printf("| 0 -> exit                                                  |\n");        
        printf("|------------------------------------------------------------|\n");

        scanf("%d", &selection);

        if(selection == 1){ directory = "/bin/ps"; command = "ps";}
        if(selection == 2){ directory = "/bin/date"; command = "date";}
        if(selection == 3){ directory = "/bin/pwd"; command = "pwd";}
        if(selection == 4){ directory = "/bin/ls"; command = "ls" ;}
        if(selection == 5){ printf("Command inexistant.\n"); exit(0);}
        if(selection == 0){ printf("Smell you later.\n"); exit(0);}


        pid_value= fork();
        if(pid_value!=0)
        {
            wait(&status);
            printf ( " I am the parent my Process ID is %d, myParents PID is %d, \n ",getpid(),getppid());
            printf( "Using the wait ensures that my child finishes first. \n ");
        }
        else 
        {
            printf ( " I am the child, my Process ID is %d , my Parents PID is %d \n",getpid(),getppid());
            sleep(2);
            printf ( " Using execl to display running processes \n");
            execl ( directory, command,(char*)0);
            printf( "Due to the execl, you should not be able to read this ?\n " ) ;
        }
    }

    return 0;
} 
