#include "logic.h"
#include "card.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initializePlayer(Player *player) {
    player->numCards = 0;
    player->totalValue = 0;


void addCardToHand(Player *player, Card card) {
    player->cards[player->numCards] = card;
    player->numCards++;
    player->totalValue += card.value;


    if (player->totalValue > 21) {
        for (int i = 0; i < player->numCards; i++) {
            if (player->cards[i].rank == ACE && player->cards[i].value == 11) {
                player->cards[i].value = 1;
                player->totalValue -= 10;
                break;
            }
        }
    }
}


void printHand(Player *player, const char *name) {
    printf("%s's hand:\n", name);
    for (int i = 0; i < player->numCards; i++) {
        const char *rankName;
        const char *suitName;

        switch (player->cards[i].rank) {
            case ACE: rankName = "Ace"; break;
            case TWO: rankName = "2"; break;
            case THREE: rankName = "3"; break;
            case FOUR: rankName = "4"; break;
            case FIVE: rankName = "5"; break;
            case SIX: rankName = "6"; break;
            case SEVEN: rankName = "7"; break;
            case EIGHT: rankName = "8"; break;
            case NINE: rankName = "9"; break;
            case TEN: rankName = "10"; break;
            case JACK: rankName = "Jack"; break;
            case QUEEN: rankName = "Queen"; break;
            case KING: rankName = "King"; break;
            default: rankName = "Unknown"; break;
        }

        switch (player->cards[i].suit) {
            case HEARTS: suitName = "Hearts"; break;
            case DIAMONDS: suitName = "Diamonds"; break;
            case CLUBS: suitName = "Clubs"; break;
            case SPADES: suitName = "Spades"; break;
            default: suitName = "Unknown"; break;
        }

        printf("  %s of %s (Value: %d)\n", rankName, suitName, player->cards[i].value);
    }
    printf("Total value: %d\n\n", player->totalValue);
}



}
