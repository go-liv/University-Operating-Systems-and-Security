#include "cache_handle.h"

//Simple file display to show how easy it is to use the cached reader functions

int main(){
  char character;

  //Open a file
  bufferStruct* f = file_open("text",20);  

  printf("\n\n");

  //While there are useful bytes coming from it
  while((character=return_character(f))!=EOF)
    //  Print them, the star tells if jus one character was printed, if it has more than one char between *
    //it has a bug in the code
    printf("%c*",character);

  //Printing number of bytes that were read in total and buffer refills
  printf("\n\n %d Bytes read.\n", f->bytesRead);
  printf("\n Buffer refilled %d times.\n", f->refillCount);  

  printf("\n\n");
  //Then close the file
  file_close(f);

  //And finish
  return 0;
}
