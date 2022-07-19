#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

//form a struct to hold the characteristics of each card
typedef struct CardDetials {
    char *face;
    char *suitchar;
    int val;
    int AceGiven;
} CardInfo;

static int scoreSheet[] = {0,0,0,0};
static int pos = 0;
static CardInfo usedcards[(20*sizeof(CardInfo))];

int cardInUsedCards(CardInfo card, CardInfo usedcards[]);
CardInfo getcard(CardInfo usedcards[]);

int cardInUsedCards(CardInfo card, CardInfo arrused[])
{
    int len = sizeof(*arrused) / sizeof card;
    int ElementPresent = 0;
    for(int i = 0; i < len; i += sizeof card)
    {
        if(arrused[i].face == card.face && arrused[i].suitchar == card.suitchar) 
        { 
            ElementPresent = 1;
            break; 
        }
    }
    return(ElementPresent);
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
        "\x03", "\x04", "\x05", "\x06"
    };
    int suit_table_size = 4;
    int suit_index = rand() % suit_table_size;
    thiscard.suitchar = suits[suit_index];
    
    //get value based on face
    if(face_index < 10){ thiscard.val = face_index+1; }
    else if(face_index >= 10 && face_index < 13){ thiscard.val = 10; }
    else {thiscard.val = 11; thiscard.AceGiven = 1; }
    
    //remove duplicate cards using recursion
    //if(cardInUsedCards(thiscard, usedcards)) 
    if(0)
    {
        getcard(usedcards); 
    }
    else 
    {
        usedcards[pos] = thiscard;
        pos += sizeof(thiscard); 
    }
}

int main(void)
{
    card1 = getcard(usedcards);
    card2 = getcard(usedcards);
    printf("[%s %s]", card1.face, card1.suitchar);
    printf("[%s %s]", card1.face, card1.suitchar);
} 
