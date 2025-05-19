#include "logic.h"
#include "card.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void GenerateCard(Card *card) {
    switch (card->rank) {
        case ACE:   card->value = 11; break;
        case TWO:   card->value = 2; break;
        case THREE: card->value = 3; break;
        case FOUR:  card->value = 4; break;
        case FIVE:  card->value = 5; break;
        case SIX:   card->value = 6; break;
        case SEVEN: card->value = 7; break;
        case EIGHT: card->value = 8; break;
        case NINE:  card->value = 9; break;
        case TEN:
        case JACK:
        case QUEEN:
        case KING:  card->value = 10; break;
        default:    card->value = 0; break;
    }


Card getRandomCard() {
    Rank randomRank = (Rank)(rand() % NUM_RANKS + 1);
    Suit randomSuit = (Suit)(rand() % NUM_SUITS);

    Card card = {randomRank, randomSuit, 0};
    GenerateCard(&card);
}


}
