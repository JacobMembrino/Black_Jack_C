#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <random>
#include <time.h>

char[][] deal();
char[][] getcard();
void displaycard(char[] card, char[] color);
int[] user_play(int card1_val, int card2_val, Boolean numAces);
int[] dealer_play(char[][] card1, char[][] card2, int numAces);
void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s);
int main(void);

//form a struct to hold the characteristics of each card
static struct {
    char card[25];
    char color[6];
    int val;
    Boolean AceGiven;
} CardInfo[40];


char[][] deal() {
    //dealer recieves 1 card up, 1 down
    //player recieves 2 cards
    d_card1 = getcard();  //card, color, val, AceGiven
    d_card2 = getcard();
    p_card1 = getcard();
    p_card2 = getcard();
    return(p_card1, p_card2, d_card1, d_card2); 
}

char[][] getcard() {
    //random used to generate a face and value of a card in a 52-card deck
    int suit = random.randint(1, 4);
    int val = random.randint(2, 14);
    char valf = char(val);
    CardInfo.AceGiven = false;

    if(suit==1) {
        char suitchar[6] = '\u2660';
        CardInfo.color = 'BLACK'; }
    else if(suit==2) {
        char suitchar[6] = '\u2665';
        CardInfo.color = 'RED'; }
    else if(suit==3) {
        char suitchar[6] = '\u2666';
        CardInfo.color = 'RED'; }
    else {
        char suitchar[6] = '\u2663';
        CardInfo.color = 'BLACK'; }
    if(val==11) {
        valf = 'J';
        val = 10; }
    else if(val==12) {
        valf = 'Q';
        val = 10; }
    else if(val==13) {
        valf = 'K';
        val = 10; }
    else if(val==14) {
        valf = 'A';
        val = 11; 
        CardInfo.AceGiven = true; }
    card = ("[%s %s]", valf, suitchar); 

    //remove duplicate cards using recursion
    if(card not in usedcards) {
        usedcards.append(card);
        return(card, color, val, AceGiven); }
    else {
        return(getcard()); }
}

void displaycard(char[] card, char[] color) {
    //display cards (with color)  
    if(color == 'RED') {
        print(f"{Fore.RED}{card}{Style.RESET_ALL}", end='\t'); }
    else {
        print(f"{card}", end='\t'); }
    return; 
}

int[] user_play(int card1_val, int card2_val, int numAces) {
    int Aces = numAces;
    int total_val = card1_val + card2_val;
    Boolean Nat21 = false;
    Boolean Busted = false;
    
    //check for nat 21
    if(total_val == 21){
        time.sleep(1);
        print("\n\nYou Got a Natural 21!!");
        Nat21 = true;
        time.sleep(1);
        return(total_val, Busted, Nat21); }
    
    while(1) {
        printf("\nYou may either: Hit (h) or Stand (s) (score:{total_val}): ");
        char inp = scanf();
        if(inp == 'h')
            {
            print();
            time.sleep(0.5);
            disp = getcard(); 
            }
        
            if(disp[3]) {Aces +=1;}
        
            displaycard(disp[0], disp[1]);
            printf();
            time.sleep(1);
            total_val += disp[2];
        
            if(total_val > 21 and Aces == 0) {
                print(f"\nBUST! ({total_val})\n");
                time.sleep(1);
                Busted = true;
                total_val = 0;
                break; }
            else if(total_val > 21 and Aces > 0) { //count ace as 1
                Aces -= 1;
                total_val -= 10; }
            else if(total_val == 21) {
                print("\nYour Score is 21!!");
                time.sleep(1);
                break; }
            else { pass }
        else if(inp == 's') {
            printf("\nFinal Score: %x\n", total_val);
            break; }
        else {
            printf("Enter a valid action\n"); }
    return(total_val, Busted, Nat21); }
}
    
int[] dealer_play(char[][] card1, char[][] card2, int numAces) {
    Aces = numAces;
    score = card1[2] + card2[2];
    printf("*"*30);
    time.sleep(1);
    printf("\nDealer's Cards:\n");
    displaycard(card1[0], card1[1]);
    displaycard(card2[0], card2[1]);
    printf("\n");
    printf("*"*30);
    printf();
    time.sleep(1.5);
    
    while(1) {
        if(score < 21) { //prevents Dealer's score from double printing
            print(f"Dealer's Score: {score}\n"); }
        if(score < 17) {
            time.sleep(1);
            print("Dealer must hit\n");
            time.sleep(1);
            disp = getcard();
            if(disp[3]) { Aces +=1; }
            displaycard(disp[0], disp[1]);
            print("\n");
            time.sleep(1);
            score += disp[2];
        else if(17<=score<=20) {
            time.sleep(1);
            print("Dealer must stand\n");
            time.sleep(1);
            break; }
        else if(score == 21) {
            print("Dealer got 21!\n");
            time.sleep(1);
            break; }
        else if(score > 21 and Aces > 0) { //count ace as 1
            Aces -= 1;
            score -= 10; }
        else{
            print("Dealer Busts!\n");
            score = 0;
            break; } }
    return(score); 
    }
}

void scoreboard(int u_score, int d_score, int wins, int loses, int busts, int nat21s) {
    curScores = "User Score: {}, Dealer Score: {}".format(u_score, d_score) ;
    ScoreBoard = "Wins  :{:^8} | Loses:{:^8}\nNat21s:{:^8} | Busts:{:^8}".format(wins, loses, nat21s, busts) ;

    //scoreboard instance
    print("{:^}".format('-'*30));
    print(curScores);
    print();
    print(ScoreBoard);
    print("{:^}".format('-'*30));
    return(); 
}

//Gameplay Loop starts here
int main(void) {
    usedcards = [];
    scoreSheet = [0,0,0,0];
    numAces = [0,0]; //tracks aces for [player, dealer]

    while(1) {
        usedcards.clear();
        dealer_score = 0;
        cards = deal();
    
        print('*'*30);
        print("\nDealer's Hand:");
        displaycard(cards[2][0], cards[2][1]);

        if(cards[2][3] == true or cards[3][3] == true) { numAces[1] += 1; }
        else if(cards[2][3] == true and cards[3][3] == true) { numAces[1] += 2; }
        else { pass; }

        print("[? ?]");

        print("\n\nPlayer's Hand:");

        displaycard(cards[0][0], cards[0][1]);
        displaycard(cards[1][0], cards[1][1]);

        print("\n");

        if(cards[0][3] == true or cards[1][3] == true) { numAces[0] += 1; }
        else if(cards[0][3] == true and cards[1][3] == true) { numAces[0] += 2; }
        else{ pass; }
    
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
            if (dealer_score > 0){ //No need to print the score if it busts
                print(f"Dealer's Final Score: {dealer_score}\n");}

            if(dealer_score < user_score[0]){
                print("You Win!\n");
                scoreSheet[0]+=1;}
            else if(dealer_score > user_score[0]){
                print("Dealer Wins!\n");
                scoreSheet[1]+=1; }
            else {
                print("Tie!!\n"); }
        }
        scoreboard(user_score[0], dealer_score, scoreSheet[0], 
            scoreSheet[1], scoreSheet[3], scoreSheet[2]);
    
        inp1 = '';
        print("\nContinue? (y/n): ");
        inp1 = repr(readchar.readchar());
        while(inp1 != "b'n'") {
            if(inp1 == "b'y'") {
                print("\nStarting New Game...\n");
                time.sleep(1);
                break; 
            }
            else{
                print("Please enter y/n");
                inp1 = repr(readchar.readchar()); 
            }
        }
        if(inp1 == "b'n'") {
                print("Thanks For Playing!\n"); 
                break;
        }
    }
}
