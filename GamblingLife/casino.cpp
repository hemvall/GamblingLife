#include <iostream>
#include <string>

int burn = 21;
int houseHand = 0;
int playerHand = 0;
int playerBet = 0;
int playerBankroll = 0;
int playerAction = 0;
int tableJoined = 0;
int betCurrentRound = 0;
std::string tableDealer = "";

void emprunterLivre() {

}

int houseHit() {
    srand(time(NULL));
    rand();
    int cardGenerated = rand() % 11 + 1;

    return houseHand + cardGenerated;
}
// return player hand after random
int playerHit(){
    if (playerBet < playerBankroll) {
        srand(time(NULL));
        rand();
        int cardGenerated = rand() % 11 + 1;

        return playerHand + cardGenerated;
    }
}

int playerDoubleDown() {
    if (playerBet * 2 < playerBankroll) {
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
    printf("Your bankroll: %d $ \nBet : %d $\n", playerBankroll, betCurrentRound);
    printf("\nHouse's hand : %d", houseHand);
    printf("\nYour hand : %d", playerHand);

    printf("\nWhat will you do next ? (1 for Hit, 2 for Double, 3 to Stay)\n");
    scanf_s("%d", playerAction);
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
    //printf("%d", playerHit(playerBet, playerBankroll, playerHand));
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
