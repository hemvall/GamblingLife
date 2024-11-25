#define NB_CardS 52

typedef struct {
    int value;    // 1 = As, 2-10, 11 = Valet, 12 = Dame, 13 = Roi
    char color;  // 'C' = Cœur, 'D' = Carreau, 'T' = Trèfle, 'P' = Pique
} Card;

Card hitCard(Card deck[], int* index) {
    if (*index >= NB_CardS) {
        printf("Plus de cartes dans le deck !\n");
        exit(EXIT_FAILURE);
    }
    Card Card_tiree = deck[*index];
    (*index)++;
    return Card_tiree;
}

void showCard(Card Card) {
    const char* values[] = { "", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi" };
    const char* colors[] = { "Cœur", "Carreau", "Trefle", "Pique" };
    printf("%s de %s\n", values[Card.value],
        (Card.color == 'C') ? "Coeur" :
        (Card.color == 'D') ? "Carreau" :
        (Card.color == 'T') ? "Trefle" : "Pique");
}

void createDeck(Card deck[]) {
    const char colors[] = { 'C', 'D', 'T', 'P' };
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            deck[index].value = j;
            deck[index].color = colors[i];
            index++;
        }
    }
}

void sortDeck(Card deck[], int taille) {
    srand(time(NULL));
    for (int i = 0; i < taille; i++) {
        int j = rand() % taille;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}