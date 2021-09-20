#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define clear() system("cls");

int main(void)
{
    char endChoice[3] = {0};
    const int MIN = 1;
    srand(time(NULL));

    restartApp:do
    {
        int value = 0, mystery, numberOfTries = 0, levelChoice = 0, MAX;

        printf("-------------\nBienvenue\n-------------\n");

        printf("Quel niveau de difficulte veux-tu ? \n1. Facile (1 - 50)       2. Moyen (1 -125)      3. Difficile (1 - 250)\n4. Mode 2 joueurs\nTon choix : ");
        scanf("%d", &levelChoice);
        clear()

        switch (levelChoice) {
            case 1:
                MAX = 50;
                printf("Tres bien, tu as choisie 'Facile'\n");
            break;
            case 2:
                MAX = 125;
                printf("Tres bien, tu as choisie 'Moyen'\n");
            break;
            case 3:
                MAX = 250;
                printf("Tres bien, tu as choisie 'Difficile'\n");
            break;
            case 4:
                printf("Rentres le nombre MAX : ");
                scanf("%d", &MAX);
                printf("Tres bien, tu as choisie le nombre\n");
            break;
            default:
                printf("Je n'ai pas compris, ressayes \n"); 
                goto restartApp;
            break;
        }

        mystery = rand() % (MAX - MIN + 1) + MIN;
        printf("Trouves le nombre : ");
        scanf("%d", &value);

        while (value != mystery) {
            printf("Tu n'as pas encore le bon nombre \n");
            numberOfTries++;

            if (value < mystery) {
                printf("Indice : C'est plus\n");
            } else {
                printf("Indice : C'est moins\n");
            }
            printf("Rententes : ");
            scanf("%d", &value);
        }

        if (value == mystery) {
            printf("-----------\nBravo !\n-----------\n");
            printf("Tu as fait %d essais avant de trouver\n\n", numberOfTries);
        }

        printf("Veux-tu faire une autre partie ? \nReponds 'oui' sinon réponds autre chose\nTon choix : ");
        scanf("%s", endChoice);

    } while (strcmp(endChoice, "oui") == 0);

    return 0;
}
