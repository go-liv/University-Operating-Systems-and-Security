#include "cache_handle.h"

//Simple file display to show how easy it is to use the cached reader functions

int main(){
  char character;

  //Open a file
  bufferStruct* f = file_open("text",20);  

  printf("\n\n");

  //While there are useful bytes coming from it
  while((character=return_character(f))!=EOF)
    //Print them
    printf("%c",character);

  printf("\n\n");
  //Then close the file
  file_close(f);

  //And finish
  return 0;
}
