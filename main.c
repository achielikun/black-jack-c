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

    playGame();

    return 0;
}
