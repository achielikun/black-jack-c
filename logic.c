#include "logic.h"
#include "card.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int playGame() {
    Player player, dealer;
    initializePlayer(&player);
    initializePlayer(&dealer);


    addCardToHand(&player, getRandomCard());
    addCardToHand(&dealer, getRandomCard());
    addCardToHand(&player, getRandomCard());
    addCardToHand(&dealer, getRandomCard());

    printHand(&player, "Player");
    printHand(&dealer, "Dealer");


    int playerBlackjack = (player.totalValue == 21 && player.numCards == 2);
    int dealerBlackjack = (dealer.totalValue == 21 && dealer.numCards == 2);

    if (playerBlackjack && dealerBlackjack) {

        return OUTCOME_TIE;
    }
    else if (playerBlackjack) {

        return OUTCOME_BLACKJACK;
    }
    else if (dealerBlackjack) {

        printf("Dealer has blackjack! You lose.\n");

        return OUTCOME_LOSS;
    }


    char choice;
    while (1) {
        printf("Do you want to hit (h) or stand (s)? ");
        scanf(" %c", &choice);

        if (choice == 'h') {
            addCardToHand(&player, getRandomCard());
            printHand(&player, "Player");

            if (player.totalValue > 21) {
                printf("Bust! You lose.\n");
                return OUTCOME_LOSS;
            }
        }
        else if (choice == 's') {
            break;
        }
        else {
            printf("Invalid choice. Please enter 'h' or 's'.\n");
        }
    }


    printf("\nDealer's turn:\n");
    while (dealer.totalValue < 17) {
        addCardToHand(&dealer, getRandomCard());
        printHand(&dealer, "Dealer");

        if (dealer.totalValue > 21) {
            printf("Dealer busts! You win.\n");
            return OUTCOME_WIN;
        }
    }


    if (player.totalValue > dealer.totalValue) {

        return OUTCOME_WIN;
    }
    else if (player.totalValue < dealer.totalValue) {
            printf("Dealer wins!\n");

        return OUTCOME_LOSS;
    }
    else {

        return OUTCOME_TIE;
    }
}
