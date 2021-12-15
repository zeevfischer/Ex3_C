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
    bool try =false;
    for(int i = 0; i < sizeOfTxt; i++)
    {
        for(int j = 0; j < sizeOfWord; j++)
        {
            if(*temp == aToz[j])
            {
                toPrint[index] = *temp;
                index++;
                temp++;
                try =true;
            }
            else
            {
                if(try)
                {
                    txt++;
                    temp=txt;
                }
                index=last;
                break;
            }
            if(j == sizeOfWord-1)
            {
                toPrint[index]='~';
                index++;
                last = index;
                try=false;
            }
        }
        for(int j2 = 0; j2 < sizeOfWord; j2++)
        {
            if(*temp == revers[j2])
            {
                toPrint[index] = *temp;
                index++;
                temp++;
                try =true;
            }
            else
            {
                if(try)
                {
                    txt++;
                    temp=txt;
                }
                index=last;
                break;
            }
            if(j2 == sizeOfWord-1)
            {
                toPrint[index]='~';
                index++;
                last = index;
                try=false;
            }
        }
        index=last;
        txt++;
        temp=txt;
        try=false;

    }
    toPrint[index]='\0';
    printf("%s\n",toPrint);
}
// isupper('A')==256
void permetation (char *word , char *txt,int sizeOfWord,int sizeOfTxt)
{
    char toPrint[1024];
    int index;
    char txt_copy[sizeOfTxt+1];
    char word_copy[sizeOfWord+1];
    char *temp=txt;
    for(int k = 0; k < sizeOfTxt; k++)
    {
        txt_copy[k]=*temp;
        temp++;
    }
    txt_copy[sizeOfTxt]='\0';
    temp=word;
    for(int k = 0; k < sizeOfWord; k++)
    {
        word_copy[k]=*temp;
        temp++;
    }
    word_copy[sizeOfWord]='\0';
    //location = Case(char) upper case is after lower so a=0 A=26
    // value amount
    temp=word;
    int count_letter[52];
    int count_letter_temp[52];
    for(int i =0;i<52;i++)
    {
        count_letter[i]=0;
        count_letter_temp[i]=0;
    }
    //////////////////////////////
    for (int i = 0; i < sizeOfWord; i++)
    {
        if(isupper(*temp) == 256)
        {
            count_letter[Case(*temp)+25]++;
        }
        if(isupper(*temp) == 0)
        {
            count_letter[Case(*temp)-1]++;
        }
        temp++;
    }
    int kklsed=0;
    kklsed++;
    /////////////////////////////////////
    bool res =true;
    for (int i = 0; i < strlen(txt_copy)-strlen(word_copy); i++)
    {  
        if(Case(txt_copy[i])!=0)
        {
            res=true;
            for(int i =0;i<52;i++)
            {
                count_letter_temp[i]=0;
            }
            //enter temp string to int arr
            for(int j = i; j < i + strlen(word_copy); j++)
            {
                if(Case(txt_copy[j]) != 0)
                {
                    if(isupper(txt_copy[j]) == 256)
                    {
                        count_letter_temp[Case(txt_copy[j])+25]++;
                    }
                    if(isupper(txt_copy[j]) == 0)
                    {
                        count_letter_temp[Case(txt_copy[j])-1]++;
                    }
                }
            }
            // check
            for(int j =0 ;j < 52;j++)
            {
                if(count_letter[j] != count_letter_temp[j])
                {
                    res =false;
                    break;
                }
            }
            if(res)
            {
                for(int j = i ;j < i + strlen(word_copy);j++)
                {
                    toPrint[index]=txt_copy[j];
                    index++;
                }
                toPrint[index]='~';
                index++;
            }
        }
    }
    toPrint[index] = '\0';
    printf("%s\n",toPrint);
}