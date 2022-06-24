#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define Delay 1000;

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
typedef struct {
    char *face[2];
    char *suitchar[6];
    int val;
    int AceGiven;
} CardInfo;

static int *scoresheet = [0,0,0,0];

int cardNotInUsedCards(char *card, char *arr[]);
CardInfo getcard();
void displayCard(CardInfo card);
int *user_play(int Pcard1_val, int Pcard2_val, int PnumAces);
int dealer_play(CardInfo Dealercard1, CardInfo Dealercard2, int DnumAces);
void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s);

int cardNotInUsedCards(char *card, char *arr[])
{
    for(int i = 0; i < sizeof(*arr[]); i++)
    {
        if(*arr[i] == val) return 0;
    }
    return 1;
}

CardInfo getcard() 
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
        getcard(); 
    }
}

void displayCard(CardInfo card)
{
    char *cardStr = (char*)malloc(8 * sizeof(char));
    snprintf("\n[%s %s]\n", valf, suitchar) 
}

int *user_play(int Pcard1_val, int Pcard2_val, int PnumAces) 
{
    int Aces = PnumAces;
    int total_val = card1_val + card2_val;
    int Nat21 = 0;
    int Busted = 0;
    
    //check for nat 21
    if(total_val == 21)
    {
        #ifdef _WIN32
        Sleep(Delay);
        #else
        usleep(Delay*1000);  // sleep for 100 milliSeconds
        #endif
        
        print("\n\nYou Got a Natural 21!!");
        Nat21 = 1;
        
        #ifdef _WIN32
        Sleep(Delay);
        #else
        usleep(Delay*1000);  // sleep for 100 milliSeconds
        #endif
        
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
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            CardInfo newCard = getcard(); 
            displaycard(newCard);
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            if(newCard.AceGiven) { Aces +=1; }
            total_val += newCard.val;
        
            if(total_val > 21 and Aces == 0) 
            {
                print(f"\nBUST! ({total_val})\n");
                
                #ifdef _WIN32
                Sleep(Delay);
                #else
                usleep(Delay*1000);  // sleep for 100 milliSeconds
                #endif
                
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
                
                #ifdef _WIN32
                Sleep(Delay);
                #else
                usleep(Delay*1000);  // sleep for 100 milliSeconds
                #endif
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
    int *return_list = [total_val, Busted, Nat21];
    return(return_list);
}
    
int dealer_play(CardInfo Dealercard1, CardInfo Dealercard2, int DnumAces) 
{
    Aces = DnumAces;
    CardInfo Dealercard1 = Dcard1;
    CardInfo Dealercard2 = Dcard2;
    dealer_score = Dcard1.val + Dcard2.val;

    printf("******************************\n");
    
    #ifdef _WIN32
    Sleep(Delay);
    #else
    usleep(Delay*1000);  // sleep for 100 milliSeconds
    #endif
    
    printf("\nDealer's Cards:\n");
    displaycard(Dcard1);
    displaycard(Dcard2);

    #ifdef _WIN32
    Sleep(Delay);
    #else
    usleep(Delay*1000);  // sleep for 100 milliSeconds
    #endif

    printf("******************************\n");
    
    while(1) 
    {
        if(dealer_score < 21) 
        { //prevents Dealer's score from double printing
            print(f"Dealer's Score: {score}\n");
        }
        if(dealer_score < 17) 
        {
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            print("Dealer must hit\n");
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            DnewCard = getcard();
            displaycard(DnewCard);
            if(DnewCard.AceGiven) { Aces +=1; }
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            dealer_score += DnewCard.val;
        }
        else if(17 <= dealer_score <=20 ) 
        {
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            print("\nDealer must stand\n");
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            break; 
        }
        else if(dealer_score == 21) 
        {
            print("\nDealer got 21!\n");
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
            
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
    CardInfo *UsedCards;
    int *numAces = [0,0]; //tracks aces for [dealer, player]
    d_card1 = getcard();  //face, suit, val, AceGiven
    d_card2 = getcard();
    p_card1 = getcard();
    p_card2 = getcard();
   
    //Gameplay Loop starts here
    while(1) 
    {
        //dealer recieves 1 card up, 1 down
        //player recieves 2 cards
        d_card1 = getcard();  //card, color, val, AceGiven
        d_card2 = getcard();
        p_card1 = getcard();
        p_card2 = getcard();
    
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
                
                #ifdef _WIN32
                Sleep(Delay);
                #else
                usleep(Delay*1000);  // sleep for 100 milliSeconds
                #endif

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
