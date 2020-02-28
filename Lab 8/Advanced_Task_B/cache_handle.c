#include "cache_handle.h"

char* vowels[10] = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"};
int wordIran = 0;
int wordTehran = 0;
int wordEmail = 0;

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

    printf("\nBuffer refilled\n");
    buff->refillCount += 1;
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
  initBuffer->refillCount = 0;
  initBuffer->bytesRead = 0;
  initBuffer->countIran = 0;
  initBuffer->countTehran = 0;
  initBuffer->countEmail = 0;

  buffer_refill(initBuffer);
  return initBuffer;
}




//------------------------------------------------------------------
char return_character(bufferStruct* buff){
  printf("prev   %c", buff->prev_char);

  buff->character = buff -> buffer[buff -> alongBuffer];

  if(buff->character == '.')
    buff->countSentences +=1;

  if(buff->character == '\0' || buff -> buffer[buff -> alongBuffer - 1] == '\0')
      buff->prev_char = buff->prev_char;
  else  
    buff->prev_char = buff->buffer[buff->alongBuffer-1];

  for(int i = 0; i < 10; i++)
  {
    if(buff -> buffer[buff -> alongBuffer] == *vowels[i])
      buff -> countVowels += 1;
  }

  // We need to check if the current point in the buffer is the last one that the buffer contains
  // If so then we need to reload the buffer with the next 20 characters and get alongBuffer to point back to the 
  //beggining of the buffer
  if(buff -> alongBuffer == buff -> bufferLength)
  {
    buffer_refill(buff);
    buff -> alongBuffer = 0;
  }
  // If it is not the last character in the buffer then we need to go to the next one so it can be 
  //printed on the next run
  else
    buff -> alongBuffer += 1;

  buff->bytesRead += sizeof(buff -> alongBuffer - 1);
  
  
  //Iran word appearances
  if(buff->character == 'r' & (buff->prev_char == 'I' || buff->prev_char == 'i'))
    wordIran += 1;
  if(buff->character == 'a' & buff->prev_char == 'r' & wordIran == 1)
    wordIran += 1;
  if(buff->character == 'n' & buff->prev_char == 'a' & wordIran == 2)
    wordIran += 1;
  if(wordIran == 3)
  {
    wordIran = 0;
    buff->countIran +=1;
  }

  //Tehran word appearances
  if(buff->character == 'e' & (buff->prev_char == 'T' || buff->prev_char == 't'))
    wordTehran += 1;
  if(buff->character == 'h' & buff->prev_char == 'e' & wordTehran == 1)
    wordTehran += 1;
  if(buff->character == 'r' & buff->prev_char == 'h' & wordTehran == 2)
    wordTehran += 1;
  if(buff->character == 'a' & buff->prev_char == 'r' & wordTehran == 3)
    wordTehran += 1;
  if(buff->character == 'n' & buff->prev_char == 'a' & wordTehran == 4)
    wordTehran += 1;
  if(wordTehran == 5)
  {
    wordTehran= 0;
    buff->countTehran +=1;
  }  

  //Email word appearances
  if(buff->character == 'm' & (buff->prev_char == 'E' || buff->prev_char == 'e'))
    wordEmail += 1;
  if(buff->character == 'a' & buff->prev_char == 'm' & wordEmail == 1)
    wordEmail += 1;
  if(buff->character == 'i' & buff->prev_char == 'a' & wordEmail == 2)
    wordEmail += 1;
  if(buff->character == 'l' & buff->prev_char == 'i' & wordEmail == 3)
    wordEmail += 1;
  if(wordEmail == 4)
  {
    wordEmail= 0;
    buff->countEmail +=1;
  }  


  // In the end we just need to return the character that was being pointed to at the beggining
  return buff->character;
}



