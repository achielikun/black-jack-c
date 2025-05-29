#include "logic.h"
#include "card.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));

    int money;
    printf("What do you want your starting balance to be? ");
    scanf("%d", &money);
    printf("Your starting balance is: %d\n\n", money);

   int playing = 1;
    while (playing && money > 0) {
        int bet;
        printf("Your current balance is %d.\n", money);
        printf("Place your bet (0 to quit): ");
        scanf("%d", &bet);

        if (bet == 0) {
            playing = 0;
            continue;
        }

        if (bet < 0 || bet > money) {
            printf("Invalid bet amount. Please try again.\n\n");
            continue;
        }

        money -= bet;
        int outcome = playGame();


        if (outcome == OUTCOME_TIE) {
            money += bet;
            printf("It's a tie. Your bet is returned.\n");
        }
        else if (outcome == OUTCOME_WIN) {
            money += bet * 2;
            printf("You win! You get %d.\n", bet * 2);
        }
        else if (outcome == OUTCOME_BLACKJACK) {
            int winnings = bet + (bet * 3) / 2;
            money += winnings;
            printf("Blackjack! You get %d.\n", winnings);
        }


        printf("Your balance is now %d.\n\n", money);
    }

    printf("Game over. Your final balance: %d\n", money);
    getchar();
    getchar();


    return 0;
}

