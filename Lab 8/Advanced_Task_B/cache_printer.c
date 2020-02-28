#include "cache_handle.h"

//Simple file display to show how easy it is to use the cached reader functions

int main(){
  char character;

  //Open a file
  bufferStruct* f = file_open("text",20);  

  printf("\n\n");

  //While there are useful bytes coming from it
  while((character=return_character(f))!=EOF)
  {
    //  Print them, the star tells if jus one character was printed, if it has more than one char between *
    //it has a bug in the code
    printf("\n%c*",character);
    //I've noticed that a null character was being printed in the beggining of the buffer, so i'll just
    //subtract these from the total number of characters
    if(character != '\0')
      f->chars += 1;
  }


  //Printing number of bytes that were read in total and buffer refills
  printf("\n\n %d Bytes read.\n", f->bytesRead);
  printf("\n Buffer refilled %d times.\n", f->refillCount);  
  printf("\n %d vowels.\n", f->countVowels);   
  printf("\n %d other characters.\n", (f->chars - f->countVowels));
  printf("\n %i Iran appearances.\n", f->countIran);
  printf("\n %i Tehran appearances.\n", f->countTehran);
  printf("\n %i Email appearances.\n", f->countEmail);
  printf("\n %i Sentences.\n", f->countSentences);

  printf("\n\n");
  //Then close the file
  file_close(f);

  //And finish
  return 0;
}
