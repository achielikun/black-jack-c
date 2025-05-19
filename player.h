#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"


typedef struct {
    Card cards[10];
    int numCards;
    int totalValue;
} Player;


void addCardToHand(Player *player, Card card);
void printHand(Player *player, const char *name);
void initializePlayer(Player *player);

#endif
