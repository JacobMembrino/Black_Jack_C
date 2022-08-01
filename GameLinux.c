#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define Delay 100000;

//form a struct to hold the characteristics of each card
typedef struct CardDetials {
    char *face;
    char *suitchar;
    int val;
    int AceGiven;
} CardInfo;

static int scoresheet[] = {0,0,0,0};
static int pos = 0;
static CardInfo usedcards[(20*sizeof(CardInfo))];

int cardNotInUsedCards(CardInfo card, CardInfo usedcards[]);
CardInfo getcard(CardInfo usedcards[]);
void displayCard(CardInfo card);
int* user_play(int Pcard1_val, int Pcard2_val, int PnumAces);
int dealer_play(CardInfo Dealercard1, CardInfo Dealercard2, int DnumAces);
void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s);

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
    int NewCard = cardInUsedCards(thiscard, usedcards);
    if(NewCard) 
    {
        getcard(usedcards); 
    }
    else 
    {
        usedcards[pos] = thiscard;
        pos += sizeof(thiscard); 
    }
}

void displayCard(CardInfo card)
{
    printf("\n[%s %s]\n", card.face, card.suitchar);
}

int* user_play(int Pcard1_val, int Pcard2_val, int PnumAces) 
{
    int Aces = PnumAces;
    int total_val = Pcard1_val + Pcard2_val;
    int Nat21 = 0;
    int Busted = 0;
    int* return_list = calloc(3, sizeof(int));
    
    //check for nat 21
    if(total_val == 21)
    {
        usleep(Delay);  // sleep for 100 milliSeconds
        print("\n\nYou Got a Natural 21!!");
        Nat21 = 1;
        usleep(Delay);
        return_list[0] = total_val; 
        return_list[1] = Busted; 
        return_list[2] = Nat21;
        return(return_list);
    }

    //start user play
    while(1) 
    {
        printf("\nYou may either: Hit (h) or Stand (s) (score:{%x}): ", total_score);
        char inp = 'a';
        scanf("%c", &inp);
        printf("\nYou entered: ");
        printf("%c", inp);
        if(inp == 'h')
        {
            usleep(Delay);
            CardInfo newCard = getcard(usedcards); 
            displaycard(newCard);
            usleep(Delay);
        
            if(newCard.AceGiven) { Aces +=1; }
            total_val += newCard.val;
        
            if(total_val > 21 and Aces == 0) 
            {
                printf("\nBUST! (%x)\n", total_val);        
                usleep(Delay);
                
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
                usleep(Delay);
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
            printf("Dealer's Score: %d\n", dealer_score); 
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
    printf("User Score: {%d}, Dealer Score: {%d}\n", u_score, d_score);
    printf("Wins  :{%d} | Loses:{%x}\nNat21s:{%d} | Busts:{%x}\n", wins, loses, nat21s, busts);
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
        int* user_score = calloc(3, sizeof(int));
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
            char inp1 = 'a';
            scanf("%c", &inp1);
            printf("\nYou entered: ");
            printf("%c", inp1 );

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
    //free(*user_score);
    return(0);
}
