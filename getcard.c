#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

static int pos = 0;
static CardInfo usedcards[(20*sizeof(CardInfo))];

typedef struct CardDetials {
    char face[3];
    char suitchar[12];
    int val;
    int AceGiven;
} CardInfo;

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
    srand(time(NULL)); //initialize rand
    face_index = rand() % faces_table_size;
    thiscard.face = faces[face_index];
    
    //get suit
    const char *suits[] = {
        "\x03", "\x04", "\x05", "\x06"
    };
    int suit_table_size = 4;
    srand(time(NULL)); //initialize rand
    thiscard.suitchar = suits[rand() % suit_table_size];
    
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
  CardInfo newcard = getcard(usedcards[]);
  printf("[%s %s]", newcard.face, newcard.suitchar);
  return(0);
}
