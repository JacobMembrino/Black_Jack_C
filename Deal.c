#include <stdlib.h>
#include <stdio.h>

char[][] deal();
char[][] getcard();
void displaycard(char[] card, char[] color);

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

int main() {
  return 0; }
