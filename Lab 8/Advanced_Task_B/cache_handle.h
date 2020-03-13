//FILE CACHE_HANDLE.H
#include <stdio.h>
#include <stdlib.h>

//The internals of this struct aren't important
//from the user's point of view
typedef struct{
  FILE* file;        //File being read
  int bufferLength;  //Fixed buffer length
  int alongBuffer;  //Current point in the buffer
  int chars;  
  char* buffer;      //A pointer to a piece of memory
                     //  same length as "bufferlength"
  char prev_char;
  char character; //alongBuffer when it is being returned
  int refillCount;
  int bytesRead;
  int countVowels;
  int countIran;
  int countTehran;
  int countEmail;
  int countSentences;
  int countAs;
  int countAlso;
  int countBut;
} bufferStruct;


//Open a file with a given size of buffer to cache with
bufferStruct* file_open(char* filename, int buffersize);


//Close an open file
void file_close(bufferStruct* buff);

//Read a byte.  Will return EOF if empty.
char return_character(bufferStruct* buff);



//---------------------------------------------------------

//Refill an empty buffer.  Not intended for users
int buffer_refill(bufferStruct* buff);


