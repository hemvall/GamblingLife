#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Items/CardsActions.C"


int main() {
    Card deck[NB_CardS];
    createDeck(deck);
    sortDeck(deck, NB_CardS);

    int index = 0; // Suivi des Cards tirées

    printf("Tirage de 5 cartes :\n");
    for (int i = 0; i < 5; i++) {
        Card Card = hitCard(deck, &index);
        showCard(Card);
    }

    return 0;
}
