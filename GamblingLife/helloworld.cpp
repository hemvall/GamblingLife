#include <iostream>
#include <string>

int burn = 21;
int houseHand = 0;
int playerHand = 0;
int playerBankroll = 0;
int playerAction = 0;
int betCurrentRound = 0;
int tableJoined = 0;
bool playerPlaying = false;
std::string tableDealer = "";

    void Biblio() {
        struct Livre {
            int numSerie;
            char titre[50];
            char auteur[50];
            int anneePubli;
            bool estDispo; 
        };

        struct Livre bibliotheque1[3] = { 
            {5432, "Fleurs du mal", "Baudelaire", 1857, 1 }, 
            {3219, "Xyz", "Mr.?", 2005, 1 }, 
            {7121, "Les miserables", "Hugo", 1862, 0 } 
        };
        for (int i = 0; i < 3; i++) {
            printf("Numero de serie: %d, Titre: %s, Auteur: %s, Annee de publication: %d, Disponible: %s\n",
                bibliotheque1[i].numSerie, bibliotheque1[i].titre, bibliotheque1[i].auteur, bibliotheque1[i].anneePubli,
                bibliotheque1[i].estDispo ? "Oui" : "Non");
        }
        int livreUserEmprunte = 0;

        printf("Entrez le numero de serie du livre que vous souhaitez emprunter :");
        scanf_s("%d", &livreUserEmprunte);

        for (int i = 0; i < 3; i++) {
            if (livreUserEmprunte == bibliotheque1[i].numSerie) {
                bibliotheque1[i].estDispo = 0;
                printf("Vous avez bien emprunte le livre %d.", bibliotheque1[i].numSerie);
                break;
            }
            else {
                printf("Le livre que vous tentez d'emprunter n'existe pas ou a deja ete pris.");
                break;
            }
        }
    }

int houseHit() {
    srand(time(NULL));
    rand();
    int cardGenerated = rand() % 11 + 1;

    return houseHand + cardGenerated;
}
// return player hand after random
int playerHit(){
    if (betCurrentRound < playerBankroll) {
        srand(time(NULL));
        rand();
        int cardGenerated = rand() % 11 + 1;
        printf("%d", cardGenerated);
        playerHand = playerHand + cardGenerated;
        return playerHand;
    }
}

int playerDoubleDown() {
    if (betCurrentRound * 2 < playerBankroll) {
        return 0;
    }
}

void initiateHands() {
    playerHand = 0;
    houseHand = 0;
    srand(time(NULL));
    rand();
    int cardGenerated = rand() % 11 + 1;
    int cardGenerated2 = rand() % 11 + 1;

    playerHand += cardGenerated;
    houseHand += cardGenerated2;
}

void askForPlayerAction() {
    if (playerHand > 21) {
        printf("BUST");
        playerPlaying = false; 
    }
    printf("\nWhat will you do next ? (1 for Hit, 2 for Double, 3 to Stay)\n");
    scanf_s("%d", &playerAction);
    switch (playerAction) {
    case 1:
        playerHit();
        break;
    case 2:
        playerDoubleDown();
    case 3:
        while (houseHand < 17) {
            printf("%d", houseHit());
        }
    }
}

bool compareHands() {
    // compare hands, return true if won false if lost
    return false;
}

void startParty() {
    system("cls");
    initiateHands();
    printf("*You joined table %i*\n \n%s : Hello, I'm %s and I will be you Dealer tonight,\nI think we can start the game, make your bets !", tableJoined, tableDealer.c_str(), tableDealer.c_str());
    printf("\n\n*How much are you betting this round ? (You have %d $)* \n", playerBankroll);
    scanf_s("%d", &betCurrentRound);
    system("cls");

    while (betCurrentRound > playerBankroll) {
        printf("You can't bet more than you have, please change it.");
        scanf_s("%d", &betCurrentRound);
    }
    playerBankroll = playerBankroll - betCurrentRound;
    playerPlaying = true;
    printf("Your bankroll: %d $ \nBet : %d $\n", playerBankroll, betCurrentRound);
    printf("\nHouse's hand : %d", houseHand);
    printf("\nYour hand : %d", playerHand);

    while (playerPlaying) {
    askForPlayerAction();

    if (houseHand >= 17) {
        compareHands();
    }

    }

}

void joinTable() {
    printf("\n*Which table do you want to join ? (1-5)* \n");
    scanf_s("%d", &tableJoined);
    while(tableJoined < 1 && tableJoined > 5){
        printf("This table does not exist. Please choose one between 1 and 5");
    }

    switch (tableJoined) {
    case 1:
        tableDealer = "Roberto";
        break;
    case 2:
        tableDealer = "Alice";
        break;
    case 3:
        tableDealer = "Clara";
        break;
    case 4:
        tableDealer = "Javier";
        break;
    case 5:
        tableDealer = "Enide";
        break;
    }

    startParty();
}

void launchGame() {
    printf("Receptionist : Welcome to the Casino Barriere ! How much did you bring today ? :-) \n");
    scanf_s("%d", &playerBankroll);
    printf("Receptionist : %i euros ? Nice, you can join the table you want ! ", playerBankroll);

    joinTable();
};

void blackjack() {

    launchGame();
    //printf("%d", playerHit(betCurrentRound, playerBankroll, playerHand));
}
int main()
{
    blackjack();
    
    /*int userEntry;
    int nbLife = 3;
    bool userWon = false;
    srand(time(NULL));
    rand();
    int randomNb = rand() % 10 + 1;

    while (userWon != true) {

    printf("%s", "\nVeuillez entrer un nombre :");
    scanf_s("%d", &userEntry);
    if (userEntry == randomNb) {
        userWon = true;
        printf("%s", "C gagne");
    }
    else if (nbLife == 0){
        printf("tu as perdu, le nombre a trouver etait : %i", randomNb);
    }
    else {
        nbLife-=1;
        printf("Rate. Veuillez reessayer. Vies restantes : %i", nbLife);
    }
    }*/


    // %.1f 1 nb après virgule 
}
