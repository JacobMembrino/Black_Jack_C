#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define Delay 100000;
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

//form a struct to hold the characteristics of each card
typedef struct {
    char face[2];
    char suitchar[9];
    int val;
    int AceGiven;
} CardInfo;

static int scoresheet[] = {0,0,0,0};
static int pos = 0;
static CardInfo usedcards[20];

int cardNotInUsedCards(CardInfo card, CardInfo usedcards[]);
CardInfo getcard(CardInfo usedcards[]);
void displayCard(CardInfo card);
int *user_play(int Pcard1_val, int Pcard2_val, int PnumAces);
int dealer_play(CardInfo Dealercard1, CardInfo Dealercard2, int DnumAces);
void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s);

int cardNotInUsedCards(CardInfo card, usedcards)
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
    Cardinfo card;
    card.AceGiven = 0;
   
    //rand used to generate a face and value of a card in a 52-card deck
    int cardNum = rand() % 10 + 2;
    if(cardNum < 10) { card.face = char(cardNum); card.val = cardNum; }
    else if(cardNum == 10) { card.face = "10"; card.val = 10; }
    else if(cradNum == 11) { card.face = 'J'; card.val = 10; }
    else if(cradNum == 12) { card.face = 'Q'; card.val = 10; }
    else if(cradNum == 13) { card.face = 'K'; card.val = 10; }
    else { card.face = 'A'; card.val = 11; card.AceGiven = 1; }
   
    int suit = rand() % 2 + 1;
   
    if(suit==1) { card.suitchar = SPADE; }
    else if(suit==2) { card.suitchar = HEART; }
    else if(suit==3) { card.suitchar = DIAMOND; }
    else { card.suitchar = CLUB; }
    
    //remove duplicate cards using recursion
    if(cardNotInUsedCards(card, usedcards)) 
    {
        usedcards[pos] = card;
        pos += sizeof(card);
    }
    else 
    {
        getcard(usedcards); 
    }
}

void displayCard(CardInfo card)
{
    char *cardStr = (char*)malloc(18 * sizeof(char));
    snprintf("\n[%s %s]\n", card.face, card.suitchar) 
}

int user_play[3] (int Pcard1_val, int Pcard2_val, int PnumAces) 
{
    int Aces = PnumAces;
    int total_val = card1_val + card2_val;
    int Nat21 = 0;
    int Busted = 0;
    int return_list[] = {0,0,0};
    
    //check for nat 21
    if(total_val == 21)
    {
        usleep(Delay);  // sleep for 100 milliSeconds
        print("\n\nYou Got a Natural 21!!");
        Nat21 = 1;
        usleep(Delay);  // sleep for 100 milliSeconds
        return_list[0] = total_val; 
        return_list[1] = Busted; 
        return_list[2] = Nat21;
        return(return_list);
    }

    //start user play
    while(1) 
    {
        printf("\nYou may either: Hit (h) or Stand (s) (score:{total_val}): ");
        char inp = getchar();
        printf( "\nYou entered: ");
        putchar( inp );
        if(inp == 'h')
        {
            usleep(Delay);  // sleep for 100 milliSeconds
            CardInfo newCard = getcard(usedcards); 
            displaycard(newCard);
            usleep(Delay);  // sleep for 100 milliSeconds
        
            if(newCard.AceGiven) { Aces +=1; }
            total_val += newCard.val;
        
            if(total_val > 21 and Aces == 0) 
            {
                printf("\nBUST! (%x)\n", total_val);        
                usleep(Delay);  // sleep for 100 milliSeconds
                
                Busted = 1;
                total_val = 0;
                break; 
            }
            else if(total_val > 21 and Aces > 0) 
            { 
                //count ace as 1
                Aces -= 1;
                total_val -= 10; 
            }
            else if(total_val == 21) 
            {
                printf("\nYour Score is 21!!");
                usleep(Delay);  // sleep for 100 milliSeconds
                break; 
            }
        }
        else if(inp == 's') 
        {
            printf("\nFinal Score: %x\n", total_val);
            break; 
        }
        else 
        {
            printf("Enter a valid action\n"); 
        }
    }
    return_list[0] = total_val; 
    return_list[1] = Busted; 
    return_list[2] = Nat21;
    return(return_list);
}
    
int dealer_play(CardInfo Dealercard1, CardInfo Dealercard2, int DnumAces) 
{
    int Aces = DnumAces;
    int dealer_score = Dealercard1.val + Dealercard2.val;

    printf("******************************\n");
    
    usleep(Delay);
    
    printf("\nDealer's Cards:\n");
    displaycard(Dealercard1);
    displaycard(Dealercard2);
    
    usleep(Delay);
    
    printf("******************************\n");
    
    while(1) 
    {
        if(dealer_score < 21) 
        { //prevents Dealer's score from double printing
            printf("Dealer's Score: %x\n", dealer_score); 
        }
        if(dealer_score < 17) 
        {
            usleep(Delay);  
            printf("Dealer must hit\n");
            usleep(Delay);
            
            CardInfo DnewCard = getcard(usedcards);
            displaycard(DnewCard);
            if(DnewCard.AceGiven) { Aces +=1; }
            
            usleep(Delay); 
            dealer_score += DnewCard.val;
        }
        else if(17 <= dealer_score <= 20 ) 
        {
            usleep(Delay);
            printf("\nDealer must stand\n");
            usleep(Delay);
            break; 
        }
        else if(dealer_score == 21) 
        {
            printf("\nDealer got 21!\n");
            usleep(Delay);
            break; 
        }
        else if(score > 21 & Aces > 0) 
        { 
            Aces -= 1; //count ace as 1
            score -= 10; 
        }
        else if(score > 21 & Aces == 0)
        {
            print("Dealer Busts!\n");
            dealer_score = 0;
            break; 
        } 
    }
    return(dealer_score); 
}

void scoreboard(int u_score, int d_score, int wins, int loses, int nat21s, int busts) 
{
    //scoreboard instance
    printf("------------------------------");
    snprintf("User Score: {%x}, Dealer Score: {%x}\n", u_score, d_score);
    snprintf("Wins  :{%x} | Loses:{%x}\nNat21s:{%x} | Busts:{%x}\n", wins, loses, nat21s, busts);
    printf("------------------------------");
}

int main() 
{
    //Gameplay Loop starts here
    while(1) 
    {
        int numAces[2] = {0,0}; //tracks aces for [dealer, player]
        CardInfo d_card1 = getcard(usedcards);
        CardInfo d_card2 = getcard(usedcards);
        CardInfo p_card1 = getcard(usedcards);
        CardInfo p_card2 = getcard(usedcards);
    
        printf("******************************\n");
        printf("Dealer's Hand:\n");
        displaycard(d_card1);
        printf("\n[? ?]\n");

        if(d_card1.AceGiven || d_card2.AceGiven) { numAces[0] += 1; }
        else if(d_card1.AceGiven && d_card2.AceGiven) { numAces[0] += 2; }

        printf("\nPlayer's Hand:\n");
        displaycard(p_card1);
        displaycard(p_card2);

        if(p_card1.AceGiven || p_card2.AceGiven) { numAces[1] += 1; }
        else if(p_card1.AceGiven && p_card2.AceGiven) { numAces[1] += 2; }

        printf("******************************\n");

        //returns a list containg [score, busted boolean, Nat 21 boolean]
        int *user_score[3];
        user_score = user_play(p_card1.val, p_card2.val, numAces[1]);
        int dealer_score = -1;
    
        if(user_score[1]) //you busted, skip dealer play
        {
            dealer_score = 1;
            scoreSheet[3] += 1;
            scoreSheet[1] += 1;
        }
        else if(user_score[2]) //you got a natural 21, skip dealer play
        {
            dealer_score = 0;
            scoreSheet[2] += 1;
        }
        else 
        {
            dealer_score = dealer_play(d_card1, d_card2, numAces[0]);

            if(dealer_score > 0) //No need to print the score if it busts
            {
                printf("Dealer's Final Score: {%x}\n", dealer_score);
            }

            if(dealer_score < user_score[0])
            {
                printf("You Win!\n");
                scoreSheet[0] += 1;
            }
            else if(dealer_score > user_score[0])
            {
                printf("Dealer Wins!\n");
                scoreSheet[1] += 1; 
            }
            else 
            {
                printf("Tie!!\n"); 
            }
        }

        scoreboard(user_score[0], dealer_score, scoreSheet[0], scoreSheet[1], scoreSheet[2], scoreSheet[3]);

        char inp1 = 'y';
        while(1)
        {
            printf("\nContinue? (y/n): ");
            char inp1 = getchar();
            printf("\nYou entered: ");
            putchar( inp1 );

            if(inp1 == 'y') 
            {
                printf("\nStarting New Game...\n");
                usleep(Delay);
                break;
            }
            else if(inp1 == 'n') 
            {
                printf("Thanks For Playing!\n"); 
                break;
            }
            else
            {
                printf("Enter (y/n)");
            }
        }  
        if(inp1 == 'n')
        {
            break;
        }
    }
    memset(usedcards, 0, sizeof(usedcards));
    return(0);
}
