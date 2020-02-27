#include "cache_handle.h"


//http://www.phim.unibe.ch/comp_doc/c_manual/C/SYNTAX/struct.html
//http://vergil.chemistry.gatech.edu/resources/programming/c-tutorial/structs.html


int buffer_refill(bufferStruct* buff){
  //Refills a buffer
  //Only works when completely used buffer
  if(buff->alongBuffer!=buff->bufferLength)
    return 0;
  else{
    buff->alongBuffer=0;
    int len=read(buff->file, buff->buffer, buff->bufferLength);
    printf("-- File read. --\n\n");
    //If we didn't fill the buffer, fill up with EOF
    if(len<buff->bufferLength)
      for(int i=len;i<buff->bufferLength;i++)	
	buff->buffer[i]=EOF;  //Accessing like an array!
    return len;
  }
  
}

void file_close(bufferStruct* buff){
  free(buff->buffer);
  close(buff->file);
  printf("-- File closed. --\n\n");
}


bufferStruct* file_open(char * filename, int buffersize){

  //Info on malloc
  //http://www.space.unibe.ch/comp_doc/c_manual/C/FUNCTIONS/malloc.html
  int f = open(filename, O_RDONLY | O_CREAT);
  if (&f == NULL){
    fprintf(stderr, "Cannot open %s\n", filename);
    return 0;
  }

  bufferStruct* initBuffer=(bufferStruct*)malloc(sizeof(bufferStruct));
  initBuffer->file=f;
  initBuffer->bufferLength=buffersize;
  initBuffer->alongBuffer=buffersize; //Start off with no characters, so refill will work as expected
  initBuffer->buffer=(char*)malloc(sizeof(char)*buffersize);

  buffer_refill(initBuffer);
  printf("-- File opened. --\n\n");
  return initBuffer;
}




//------------------------------------------------------------------
char return_character(bufferStruct* buff){
  // your code goes here
  // remember that this needs to return a char (a byte, put another way..)
  return EOF; // this is just so the compile works...
}



