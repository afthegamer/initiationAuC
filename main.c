#include <stdio.h>

int main() {
    int tableau[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Déclaration d'un tableau de 10 éléments
    int taille = sizeof(tableau) / sizeof(tableau[0]); // Calcul de la taille du tableau

    int debut = 0;
    for (int i = 0; i < taille; i++) {
        printf("Première version avant modification tableau[%d] = %d\n", i, tableau[i]);

        debut += tableau[i];
        printf("debut = %d\n", debut);
    }


    int debut2 = 0;

    // Modifier la valeur du trosième élément (indice 2)
    tableau[2] = 100;

    for (int i = 0; i < taille; i++) {
        printf("après modification tableau[%d] = %d\n", i, tableau[i]);

        debut2 += tableau[i];
        printf("debut = %d\n", debut2);
    }

    return 0;
}
