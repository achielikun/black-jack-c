#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, NUM_RANKS
} Rank;

typedef enum {
    HEARTS, DIAMONDS, CLUBS, SPADES, NUM_SUITS
} Suit;


typedef struct {
    Rank rank;
    Suit suit;
    int value;
} Card;


Card getRandomCard();
void GenerateCard(Card *card);

#endif
