#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//form a struct to hold the characteristics of each card
typedef struct CardDetials {
    char *face;
    char *suitchar;
    int val;
    int AceGiven;
} CardInfo;

static CardInfo usedcards[(20*sizeof(CardInfo))];

int cardNotInUsedCards(CardInfo card, CardInfo usedcards[]);
CardInfo getcard(CardInfo usedcards[]);

int cardNotInUsedCards(CardInfo card, usedcards[])
{
    int ElementNotPresent = 1;
    for(int i = 0; i < sizeof(usedcards); i += sizeof(card))
    {
        if(usedcards[i].face == card.face && usedcards[i].suitchar == card.suitchar) 
        { 
            ElementNotPresent = 0;
            break; 
        }
    }
    return(ElementNotPresent);
}

CardInfo getcard(CardInfo usedcards[]) 
{
    CardInfo thiscard;
    thiscard.AceGiven = 0;
    
    //get face
    const char *faces[] = {
        "1","2","3","4","5","6","7","8","9","10",
        "J","Q","K","A"
    };
    int faces_table_size = 14;
    srand(time(NULL)); 
    int face_index = rand() % faces_table_size;
    thiscard.face = faces[face_index];
   
    //get suit
    const char *suits[] = {
        "\xE2\x99\xA0", "\xE2\x99\xA3", "\xE2\x99\xA5", "\xE2\x99\xA6"
    };
    int suit_table_size = 4;
    int suit_index = rand() % suit_table_size;
    thiscard.suitchar = suits[suit_index];
    
    //get value based on face
    if(face_index < 10){ thiscard.val = face_index+1; }
    else if(face_index >= 10 && face_index < 13){ thiscard.val = 10; }
    else {thiscard.val = 11; thiscard.AceGiven = 1; }
    
    //remove duplicate cards using recursion
    if(cardNotInUsedCards(thiscard, usedcards)) 
    {
        usedcards[pos] = thiscard;
        pos += sizeof(thiscard);
    }
    else 
    {
        getcard(usedcards); 
    }
}

int main()
{
  CardInfo card1 = getcard(usedcards);
  CardInfo card2 = getcard(usedcards);
  
  printf("[%s %s]   [%s %s]\nTotal Value: %x", card1.face, card1.suitchar, card2.face, card2.suitchar, (card1.val+card2.val));
    
  return(0);
}
