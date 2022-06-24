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
    char *face[2];
    char *suitchar[6];
    int val;
    bool AceGiven;
} CardInfo;

CardInfo getcard();
void displayCard(CardInfo card);
int *user_play(int card1_val, int card2_val, bool numAces);
int *dealer_play(char card1**, char card2**, int numAces);
void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s);
int cardNotInUsedCards(char *card, char *arr[]);

int cardNotInUsedCards(char *card, char *arr[])
{
    for(int i = 0; i < sizeof(*arr[]); i++)
    {
        if(*arr[i] == val) return 0;
    }
    return 1;
}

CardInfo getcard() {
   
    Cardinfo card;
    card.AceGiven = false;
   
    //rand used to generate a face and value of a card in a 52-card deck
    int cardNum = rand() % 10 + 2;
    if(cardNum < 10) { card.face = char(cardNum); card.val = cardNum; }
    else if(cardNum == 10) { card.face = "10"; card.val = 10; }
    else if(cradNum == 11) { card.face = 'J'; card.val = 10; }
    else if(cradNum == 12) { card.face = 'Q'; card.val = 10; }
    else if(cradNum == 13) { card.face = 'K'; card.val = 10; }
    else { card.face = 'A'; card.val = 11; card.AceGiven = true; }
   
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
    snprintf("[%s %s]", valf, suitchar) 
}

int user_play* (int card1_val, int card2_val, int numAces) {
    int Aces = numAces;
    int total_val = card1_val + card2_val;
    bool Nat21 = false;
    bool Busted = false;
    
    //check for nat 21
    if(total_val == 21)
    {
        #ifdef _WIN32
        Sleep(Delay);
        #else
        usleep(Delay*1000);  // sleep for 100 milliSeconds
        #endif
        
        print("\n\nYou Got a Natural 21!!");
        Nat21 = true;
        
        #ifdef _WIN32
        Sleep(Delay);
        #else
        usleep(Delay*1000);  // sleep for 100 milliSeconds
        #endif
        
        return(total_val, Busted, Nat21); 
    }
    
    while(1) 
    {
        printf("\nYou may either: Hit (h) or Stand (s) (score:{total_val}): ");
        char inp = getchar();
        printf( "\nYou entered: ");
        putchar( inp );
        if(inp == 'h')
        {
            print();
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            disp* = getcard(); 
        }
        
            if(disp[3]) {Aces +=1;}
        
            //displaycard(disp[0], disp[1]);
            //printf("{" + card + "}\n"); 
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            total_val += disp[2];
        
            if(total_val > 21 and Aces == 0) {
                print(f"\nBUST! ({total_val})\n");
                
                #ifdef _WIN32
                Sleep(Delay);
                #else
                usleep(Delay*1000);  // sleep for 100 milliSeconds
                #endif
                
                Busted = true;
                total_val = 0;
                break; 
            }
            else if(total_val > 21 and Aces > 0) { //count ace as 1
                Aces -= 1;
                total_val -= 10; }
            else if(total_val == 21) {
                print("\nYour Score is 21!!");
                
                #ifdef _WIN32
                Sleep(Delay);
                #else
                usleep(Delay*1000);  // sleep for 100 milliSeconds
                #endif
                break; 
            }
            else {}
            
        else if(inp == 's') 
        {
            printf("\nFinal Score: %x\n", total_val);
            break; 
        }
        else 
        {
            printf("Enter a valid action\n"); 
        }
    return(total_val, Busted, Nat21);
    }
}
    
int dealer_play*(char card1**, char card2**, int numAces) 
{
    Aces = numAces;
    score = card1[2] + card2[2];
    printf("*"*30);
    
    #ifdef _WIN32
    Sleep(Delay);
    #else
    usleep(Delay*1000);  // sleep for 100 milliSeconds
    #endif
    
    printf("\nDealer's Cards:\n");
    //displaycard(card1[0], card1[1]);
    //printf("{" + card + "}\n"); 
    //displaycard(card2[0], card2[1]);
    //printf("{" + card + "}\n");
    printf("\n");
    printf("*"*30);
    printf();
    
    #ifdef _WIN32
    Sleep(Delay);
    #else
    usleep(Delay*1000);  // sleep for 100 milliSeconds
    #endif
    
    while(1) {
        if(score < 21) { //prevents Dealer's score from double printing
            print(f"Dealer's Score: {score}\n"); }
        if(score < 17) {
            
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
        
            disp = getcard();
            if(disp[3]) { Aces +=1; }
            //displaycard(disp[0], disp[1]);
            //printf("{" + card + "}\n");
            print("\n");
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            score += disp[2];
        }
        else if(17<=score<=20) {
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            print("Dealer must stand\n");
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
        
            break; 
        }
        else if(score == 21) {
            print("Dealer got 21!\n");
            
            #ifdef _WIN32
            Sleep(Delay);
            #else
            usleep(Delay*1000);  // sleep for 100 milliSeconds
            #endif
            
            break; 
        }
        else if(score > 21 and Aces > 0) 
        { 
            Aces -= 1; //count ace as 1
            score -= 10; 
        }
        else
        {
            print("Dealer Busts!\n");
            score = 0;
            break; 
        } 
    }
    return(score); 
    }
}

void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s) 
{
    //scoreboard instance
    printf("------------------------------");
    printf("User Score: {%d}, Dealer Score: {%d}\n", u_score, d_score);
    printf("Wins  :{%d} | Loses:{%d}\nNat21s:{%d} | Busts:{%d}\n", wins, loses, nat21s, busts);
    printf("------------------------------");
}

//Gameplay Loop starts here
int main() {
    char usedcards** = [\0];
    int scoreSheet* = [0,0,0,0];
    int numAces* = [0,0]; //tracks aces for [player, dealer]
    d_card1 = getcard();  //card, color, val, AceGiven
    d_card2 = getcard();
    p_card1 = getcard();
    p_card2 = getcard();
    usedcards[] = [];
   
    while(1) {
        //dealer recieves 1 card up, 1 down
        //player recieves 2 cards
        d_card1 = getcard();  //card, color, val, AceGiven
        d_card2 = getcard();
        p_card1 = getcard();
        p_card2 = getcard();
        usedcards[] = [];
        int dealer_score = 0;
        char cards** = deal();
    
        printf("******************************");
        printf("\nDealer's Hand:");
        //displaycard(cards[2][0], cards[2][1]);
        //printf("{" + card + "}\n");

        if(cards[2][3] == true or cards[3][3] == true) { numAces[1] += 1; }
        else if(cards[2][3] == true and cards[3][3] == true) { numAces[1] += 2; }
        else {}

        printf("[? ?]");

        printf("\n\nPlayer's Hand:");

        //displaycard(cards[0][0], cards[0][1]);
        //printf("{" + card + "}\n");
        //displaycard(cards[1][0], cards[1][1]);
        //printf("{" + card + "}\n\n");

        if(cards[0][3] == true or cards[1][3] == true) { numAces[0] += 1; }
        else if(cards[0][3] == true and cards[1][3] == true) { numAces[0] += 2; }
        else {}
    
        //returns a list containg [score, busted boolean, Nat 21 boolean]
        user_score = user_play(cards[0][2], cards[1][2], numAces[0]);
    
        //skips dealer's play if you bust or get a Natural 21
        if(user_score[1]) {
            dealer_score = 1;
            scoreSheet[3] += 1;
            scoreSheet[1] += 1;
        }
        else if(user_score[2]){
            dealer_score = 0;
            scoreSheet[2]+=1;
        }
        else {
            dealer_score = dealer_play(cards[2], cards[3], numAces[1]);
            if (dealer_score > 0) { //No need to print the score if it busts
                printf("Dealer's Final Score: {dealer_score}\n"); }

            if(dealer_score < user_score[0]){
                printf("You Win!\n");
                scoreSheet[0]+=1;}
            else if(dealer_score > user_score[0]){
                printf("Dealer Wins!\n");
                scoreSheet[1]+=1; }
            else {
                printf("Tie!!\n"); }
        }
        scoreboard(user_score[0], dealer_score, scoreSheet[0], 
            scoreSheet[1], scoreSheet[3], scoreSheet[2]);
            
        printf("\nContinue? (y/n): ");
        char inp1 = getchar();
        printf( "\nYou entered: ");
        putchar( inp1 );
        while(inp1 != 'n') 
        {
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
            else
            {
                printf("Please enter y/n");
                char inp1 = getchar();
                printf( "\nYou entered: ");
                putchar( inp1 ); 
            }
        }
        if(inp1 == 'n') 
        {
                printf("Thanks For Playing!\n"); 
                break;
        }
    }
}
