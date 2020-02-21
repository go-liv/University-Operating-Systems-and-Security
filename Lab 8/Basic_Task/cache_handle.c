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
    int len=fread(buff->buffer, sizeof(char), buff->bufferLength, buff->file);
    //If we didn't fill the buffer, fill up with EOF
    if(len<buff->bufferLength)
      for(int i=len;i<buff->bufferLength;i++)	
	      buff->buffer[i]=EOF;  //Accessing like an array!
    return len;
  }
  
}

void file_close(bufferStruct* buff){
  free(buff->buffer);
  fclose(buff->file);
}


bufferStruct* file_open(char * filename, int buffersize){

  //Info on malloc
  //http://www.space.unibe.ch/comp_doc/c_manual/C/FUNCTIONS/malloc.html
  FILE* f;
  if ((f = fopen(filename, "r")) == NULL){
    fprintf(stderr, "Cannot open %s\n", filename);
    return 0;
  }

  bufferStruct* initBuffer=(bufferStruct*)malloc(sizeof(bufferStruct));
  initBuffer->file=f;
  initBuffer->bufferLength=buffersize;
  initBuffer->alongBuffer=buffersize; //Start off with no characters, so refill will work as expected
  initBuffer->buffer=(char*)malloc(sizeof(char)*buffersize);

  buffer_refill(initBuffer);
  return initBuffer;
}




//------------------------------------------------------------------
char return_character(bufferStruct* buff){
  // First we need to check if the current point in the buffer is the last one that the buffer contains
  // If so then we need to reload the buffer with the next 20 characters and get alongBuffer to point back to the 
  //beggining of the buffer
  if(buff -> alongBuffer == buff -> bufferLength)
  {
    buffer_refill(buff);
    buff -> alongBuffer = EOF;
  }
  // If it is not the last character in the buffer then we need to go to the next one so it can be 
  //printed on the next run
  else
    buff -> alongBuffer += 1;

  // In the end we just need to return the character that was being pointed to at the beggining
  return buff -> buffer[(buff -> alongBuffer) - 1];
}



