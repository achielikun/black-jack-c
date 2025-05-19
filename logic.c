#include "logic.h"
#include "card.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void playGame() {
    Player player, dealer;
    initializePlayer(&player);
    initializePlayer(&dealer);


    addCardToHand(&player, getRandomCard());
    addCardToHand(&dealer, getRandomCard());
    addCardToHand(&player, getRandomCard());
    addCardToHand(&dealer, getRandomCard());

    printHand(&player, "Player");
    printHand(&dealer, "Dealer");


    char choice;
    while (1) {
        printf("Do you want to hit (h) or stand (s)? ");
        scanf(" %c", &choice);

        if (choice == 'h') {
            addCardToHand(&player, getRandomCard());
            printHand(&player, "Player");

            if (player.totalValue > 21) {
                printf("Bust! You lose.\n");
                return;
            }
        } else if (choice == 's') {
            break;
        } else {
            printf("Invalid choice. Please enter 'h' or 's'.\n");
        }
    }


    printf("\nDealer's turn:\n");
    while (dealer.totalValue < 17) {
        addCardToHand(&dealer, getRandomCard());
        printHand(&dealer, "Dealer");

        if (dealer.totalValue > 21) {
            printf("Dealer busts! You win.\n");
            return;
        }
    }

    if (player.totalValue > dealer.totalValue) {
        printf("You win!\n");
    } else if (player.totalValue < dealer.totalValue) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}
