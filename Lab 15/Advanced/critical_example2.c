//critical_example2.c
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "ops_sems.h"

int main(int argc, char argv[]){
int id; 
FILE *lyrics; 
char line[200];
int flag = 1;

//Use our source file as the "key"
  id=ops_semget("critical_example2.c",1);

  lyrics = fopen("hole_in_bucket.txt", "w");

  int pid=fork();  
  if(pid){
    //P1
    while(flag == 1){
      //This part is equal to the basic exercise:
      //in each printf instance we need to tell the process to sleep so that we can in fact assure that the next process will not print anything before we signal the semaphore
      //so what happens is that by forking the process we first will go with the process 1 (we can call it henry) and after that process signals the semaphore
      //we can then pass to the process 2 (liza process), the code will do that between processes until we finish both processes
//printing to terminal
      ops_wait(id);
      printf("Henry Part 1:\nThere's a hole in the bucket, dear Liza, dear Liza,\nThere's a hole in the bucket, dear Liza, a hole.\n\n");
//printing to file
      fprintf(lyrics, "Henry Part 1:\nThere's a hole in the bucket, dear Liza, dear Liza,\nThere's a hole in the bucket, dear Liza, a hole.\n\n");
      sleep(1);
      ops_signal(id);


      ops_wait(id);
      printf("Henry Part 2:\nWith what shall I fix it, dear Liza, dear Liza?\nWith what shall I fix it, dear Liza, with what?\n\n");
      fprintf(lyrics, "Henry Part 2:\nWith what shall I fix it, dear Liza, dear Liza?\nWith what shall I fix it, dear Liza, with what?\n\n");
      sleep(1);
      ops_signal(id);


      ops_wait(id);
      printf("Henry Part 3:\nThe straw is too long, dear Liza, dear Liza,\nThe straw is too long, dear Liza, too long.\n\n");
      fprintf(lyrics, "Henry Part 3:\nThe straw is too long, dear Liza, dear Liza,\nThe straw is too long, dear Liza, too long.\n\n");
      sleep(1);
      ops_signal(id);


      ops_wait(id);
      printf("Henry Part 4:\nWith what shall I cut it, dear Liza, dear Liza?\nWith what shall I cut it, dear Liza, with what?\n\n");
      fprintf(lyrics, "Henry Part 4:\nWith what shall I cut it, dear Liza, dear Liza?\nWith what shall I cut it, dear Liza, with what?\n\n");
      sleep(1);
      ops_signal(id);

      flag=0;
    }
  }else{
    //P2
    while(flag == 1){
//printing to the terminal
      ops_wait(id);
      fprintf(stderr, "Liza Part 1:\nThen fix it, dear Henry, dear Henry, dear Henry,\nThen fix it, dear Henry, dear Henry, fix it.\n\n");
//printing to file
      fprintf(lyrics, "Liza Part 1:\nThen fix it, dear Henry, dear Henry, dear Henry,\nThen fix it, dear Henry, dear Henry, fix it.\n\n");
      sleep(1);
      ops_signal(id);


      ops_wait(id);
      fprintf(stderr, "Liza Part 2:\nWith straw, dear Henry, dear Henry, dear Henry,\nWith straw, dear Henry, dear Henry, with straw.\n\n");
      fprintf(lyrics, "Liza Part 2:\nWith straw, dear Henry, dear Henry, dear Henry,\nWith straw, dear Henry, dear Henry, with straw.\n\n");
      sleep(1);
      ops_signal(id);


      ops_wait(id);
      fprintf(stderr, "Liza Part 3:\nThen cut it, dear Henry, dear Henry, dear Henry,\nThen cut it, dear Henry, dear Henry, cut it.\n\n");
      fprintf(lyrics, "Liza Part 3:\nThen cut it, dear Henry, dear Henry, dear Henry,\nThen cut it, dear Henry, dear Henry, cut it.\n\n");
      sleep(1);
      ops_signal(id);


      ops_wait(id);
      fprintf(stderr, "Liza Part 4:\nWith an axe, dear Henry, dear Henry, dear Henry,\nWith an axe, dear Henry, dear Henry, an axe.\n\n");
      fprintf(lyrics, "Liza Part 4:\nWith an axe, dear Henry, dear Henry, dear Henry,\nWith an axe, dear Henry, dear Henry, an axe.\n\n");
      sleep(1);
      ops_signal(id);

    
      flag=0;
    }
    
  }

  fclose(lyrics);
  
}

