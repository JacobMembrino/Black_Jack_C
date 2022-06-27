#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define Delay 1000;
#define SPADE   "\x06"
#define CLUB    "\x05"
#define HEART   "\x03"
#define DIAMOND "\x04"

//form a struct to hold the characteristics of each card
typedef struct{
    char face[2];
    char suitchar[9];
    int val;
    int AceGiven;
} CardInfo;

static int scoresheet[4] = {0,0,0,0};

int cardNotInUsedCards(CardInfo card, CardInfo usedcards[]);
CardInfo getcard(UsedCards[]);
void displayCard(CardInfo card);
int *user_play(int Pcard1_val, int Pcard2_val, int PnumAces);
int dealer_play(CardInfo Dealercard1, CardInfo Dealercard2, int DnumAces);
void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s);

int cardNotInUsedCards(CardInfo card, usedcards[])
{
    for(int i = 0; i < sizeof(*usedcards[]); i++)
    {
        if(*usedcards[i] == val) { return 0; }
    }
    return 1;
}

CardInfo getcard(UsedCards[]) 
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
        usedcards.append(card); 
    }
    else 
    {
        getcard(UsedCards); 
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
    
    //check for nat 21
    if(total_val == 21)
    {
        Sleep(Delay);
        print("\n\nYou Got a Natural 21!!");
        Nat21 = 1;
        Sleep(Delay);

        return(total_val, Busted, Nat21); 
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
            Sleep(Delay);
            CardInfo newCard = getcard(UsedCards); 
            displaycard(newCard);
            Sleep(Delay);
        
            if(newCard.AceGiven) { Aces +=1; }
            total_val += newCard.val;
        
            if(total_val > 21 and Aces == 0) 
            {
                print(f"\nBUST! ({total_val})\n");
                Sleep(Delay);
                
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
                print("\nYour Score is 21!!");
                Sleep(Delay);
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
    int return_list[3] = [total_val, Busted, Nat21];
    return(return_list);
}
    
int dealer_play(CardInfo Dealercard1, CardInfo Dealercard2, int DnumAces) 
{
    Aces = DnumAces;
    CardInfo Dealercard1 = Dcard1;
    CardInfo Dealercard2 = Dcard2;
    dealer_score = Dcard1.val + Dcard2.val;

    printf("******************************\n");
    
    Sleep(Delay);
    
    printf("\nDealer's Cards:\n");
    displaycard(Dcard1);
    displaycard(Dcard2);

    Sleep(Delay);

    printf("******************************\n");
    
    while(1) 
    {
        if(dealer_score < 21) 
        { //prevents Dealer's score from double printing
            print(f"Dealer's Score: {score}\n");
        }
        if(dealer_score < 17) 
        {
            Sleep(Delay);
            print("Dealer must hit\n");
            Sleep(Delay);
        
            DnewCard = getcard(UsedCards);
            displaycard(DnewCard);
            if(DnewCard.AceGiven) { Aces +=1; }
            
            Sleep(Delay);
            dealer_score += DnewCard.val;
        }
        else if(17 <= dealer_score <=20 ) 
        {
            Sleep(Delay);
            print("\nDealer must stand\n");
            Sleep(Delay);
            break; 
        }
        else if(dealer_score == 21) 
        {
            print("\nDealer got 21!\n");
            Sleep(Delay);
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
    snprintf("User Score: {%d}, Dealer Score: {%d}\n", u_score, d_score);
    snprintf("Wins  :{%d} | Loses:{%d}\nNat21s:{%d} | Busts:{%d}\n", wins, loses, nat21s, busts);
    printf("------------------------------");
}

int main() 
{
    //Gameplay Loop starts here
    while(1) 
    {
        CardInfo UsedCards[sizeof(CardInfo) * 20];
        int numAces[2] = {0,0}; //tracks aces for [dealer, player]
        d_card1 = getcard(UsedCards);
        d_card2 = getcard(UsedCards);
        p_card1 = getcard(UsedCards);
        p_card2 = getcard(UsedCards);
    
        printf("******************************\n");
        printf("Dealer's Hand:\n");
        displaycard(d_card1);
        printf("[? ?]\n");

        if(d_card1.AceGiven || d_card2.AceGiven) { numAces[0] += 1; }
        else if(d_card1.AceGiven && d_card2.AceGiven) { numAces[0] += 2; }

        printf("\nPlayer's Hand:\n");
        displaycard(p_card1);
        displaycard(p_card2);

        if(p_card1.AceGiven || p_card2.AceGiven) { numAces[1] += 1; }
        else if(p_card1.AceGiven && p_card2.AceGiven) { numAces[1] += 2; }

        printf("******************************\n");

        //returns a list containg [score, busted boolean, Nat 21 boolean]
        int *user_score = user_play(p_card1.val, p_card2.val, numAces[1]);
    
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
            int dealer_score = dealer_play(d_card1, d_card2, numAces[0]);

            if(dealer_score > 0) //No need to print the score if it busts
            {
                printf("Dealer's Final Score: {dealer_score}\n"); 
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

        while(1)
        {
            printf("\nContinue? (y/n): ");
            char inp1 = getchar();
            printf( "\nYou entered: ");
            putchar( inp1 );

            if(inp1 == 'y') 
            {
                printf("\nStarting New Game...\n");
                Sleep(Delay);
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
        if(inp1 == 'h')
        {
            break;
        }
    }
    return(0);
}
