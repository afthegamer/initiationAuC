#include <stdio.h>

void parcourirTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("Element %d: %d\n", i, tableau[i]);
    }
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    parcourirTableau(tableau, taille);

    return 0;
}