#include <stdio.h>
#include "function.h"
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
// a = 97 z = 122 A = 65 Z = 90
// sizeof(גודל המערך)\sizeof(האיבר הראשון)
int Case(char C)
{
    int base_a = 'a';
    int base_A = 'A';
    int base_z = 'z';
    int base_Z = 'Z';
    if(C >= base_a && C <= base_z)
    {
        return C-base_a + 1;
    }
    else if(C >= base_A && C <= base_Z)
    {
        return C-base_A + 1;
    }
    return 0;
}
int sum_Word(char *word)
{
    int sum = 0;
    int base_a = 'a';
    int base_A = 'A';
    int base_z = 'z';
    int base_Z = 'Z';
    while (*word != '\0')
    {
        if(*word >= base_a && *word <= base_z)
        {
            sum += *word-base_a + 1;
        }
        if(*word >= base_A && *word <= base_Z)
        {
            sum += *word-base_A + 1;
        }
        word++;
    }
    return sum;
}
void WordGimatry(char *word , char *txt,int sizeOfWord,int sizeOfTxt)
{
    // this will get me the sum to check
    int sum = sum_Word(word);
    int count=0;
    // creat a string to print
    char toPrint[1024];
    int last = 0;
    int index = 0;
    // crate a new pointer to worck with 
    char *temp = txt;
    for(int i = 0; i < sizeOfTxt; i++)
    {
        for(int j = i; j < sizeOfTxt; j++)
        {
            if(count==0 && Case(*temp)==0)
            {
                break;
            }
            if(count < sum)
            {
                count += Case(*temp);
                toPrint[index] = *temp;
                index++;
                temp++;
            }
            if(count == sum)
            {
                toPrint[index]='~';
                index++;
                last = index;
                // count = 0;
                break;
            }
            if(count > sum)
            {
                // count = 0;
                // index = last;
                break;
            }
        }
        index = last;
        count=0;
        txt++;
        temp = txt;
    }
    if(count < sum)
    {
        index = last;
    }
    toPrint[index]='\0';
    printf("%s \n",toPrint);
}
void atbash(char *word , char *txt,int sizeOfWord,int sizeOfTxt) 
{
    char *temp = word;
    char aToz[sizeOfWord];
    char revers[sizeOfWord];
    for(int i=0;i<sizeOfWord;i++)
    {
        if(isupper(*temp)==0)
        {
            aToz[i]=26-Case(*temp)+97;
            revers[sizeOfWord-1-i]=26-Case(*temp)+97;    
        }
        if(isupper(*temp)==256)
        {
            aToz[i]=26-Case(*temp)+97-32;
            revers[sizeOfWord-1-i]=26-Case(*temp)+97-32;
        }
        temp++;
    }
    aToz[sizeOfWord]='\0';
    revers[sizeOfWord]='\0';
    // printf("%s\n",aToz);
    // printf("%s\n",revers);
    // printf("%d\n",isupper('a'));
    // printf("%d\n",isupper('B'));
    char toPrint[1024];
    temp = txt;
    int index = 0;
    int last = 0;
    for(int i = 0; i < sizeOfTxt; i++)
    {
        for(int j = 0; j < sizeOfWord; j++)
        {
            if(*temp == aToz[j])
            {
                toPrint[index] = *temp;
                index++;
                temp++;
            }
            else
            {
                index=last;
                break;
            }
            if(j == sizeOfWord-1)
            {
                toPrint[index]='~';
                index++;
                last = index;
            }
        }
        for(int j2 = 0; j2 < sizeOfWord; j2++)
        {
            if(*temp == revers[j2])
            {
                toPrint[index] = *temp;
                index++;
                temp++;
            }
            else
            {
                index=last;
                break;
            }
            if(j2 == sizeOfWord-1)
            {
                toPrint[index]='~';
                index++;
                last = index;
            }
        }
        index=last;
        txt++;
        temp=txt;
    }
    toPrint[index]='\0';
    printf("%s\n",toPrint);
}
