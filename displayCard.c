#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define int Delay 1000;

#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\x06"
   #define CLUB    "\x05"
   #define HEART   "\x03"
   #define DIAMOND "\x04"
#else
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#endif

//form a struct to hold the characteristics of each card
typedef struct CardInfo {
    char cardstr[25];
    int val;
    bool AceGiven;
} CardInfo;

char getcard**() {
    //rand used to generate a face and value of a card in a 52-card deck
    int suit = rand() % 2 + 1;
    int val = rand() % 10 + 2;
    char valf = char(val);
    Cardinfo card;
    card.AceGiven = false;

    if(suit==1) 
    {
        char suitchar[6] = SPADE;
    }
    else if(suit==2) 
    {
        char suitchar[6] = HEART;
    }
    else if(suit==3) 
    {
        char suitchar[6] = DIAMOND;
    }
    else 
    {
        char suitchar[6] = CLUB;
    }
    if(val==11) 
    {
        valf = 'J';
        val = 10; 
    }
    else if(val==12) 
    {
        valf = 'Q';
        val = 10; 
    }
    else if(val==13) 
    {
        valf = 'K';
        val = 10; 
    }
    else if(val==14) 
    {
        valf = 'A';
        val = 11; 
        card.AceGiven = true; 
    }
   
    card.cardstr = ("[%s %s]", valf, suitchar); 

    //remove duplicate cards using recursion
    if(card not in usedcards) 
    {
        usedcards.append(card);
        return(card); 
    }
    else 
    {
        return(getcard**()); 
    }
}

void int main() { return 0; }
