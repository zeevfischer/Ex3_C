#include <stdio.h>
#include <math.h>
#include <string.h>
#include "function.h"
#include <ctype.h>
#include <string.h>

#define TXT 1024
#define WORD  30

int main()
{
   char word[WORD];
   char txt[TXT];
   int i = 0;
   char temp;
   
   // // scan Word
   scanf ("%s\n" , word);
   // // scan txt
   // scanf ("%1023s" , txt);

   // scan word
   // scanf ("%c" , &temp);
   // while (temp != ' ')
   // {
   //    word[i] = temp;
   //    i++;
   //    scanf ("%c" , &temp);
   // }
   // word[i]='\0';

   // scan txt
   i=0;
   scanf ("%c" , &temp);
   while (temp != '~')
   {
      txt[i] = temp;
      i++;
      scanf ("%c" , &temp);
   }
   txt[i]='\0';
   
   printf("Gematria Sequences: ");
   WordGimatry(word,txt,strlen(word),strlen(txt));
   printf("Atbash Sequences: ");
   atbash(word,txt,strlen(word),strlen(txt));
   printf("Anagram Sequences: ");
   permetation(word,txt,strlen(word),strlen(txt));
}