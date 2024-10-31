#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déclaration de la structure Contact
typedef struct {
    char nom[50];
    char telephone[15];
    char email[50];
} Contact;

void sauvegarderContacts(const Contact *contacts, int nombreContacts) {
    FILE *fichier = fopen("contacts.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < nombreContacts; i++) {
        fprintf(fichier, "%s %s %s\n", contacts[i].nom, contacts[i].telephone, contacts[i].email);
    }

    fclose(fichier);
    printf("Contacts sauvegardés avec succès.\n");
}
void chargerContacts(Contact *contacts, int *nombreContacts) {
    FILE *fichier = fopen("contacts.txt", "r");
    if (fichier == NULL) {
        printf("Aucun fichier de contacts trouvé, démarrage avec une liste vide.\n");
        return;
    }

    *nombreContacts = 0;
    while (fscanf(fichier, "%s %s %s", contacts[*nombreContacts].nom, contacts[*nombreContacts].telephone, contacts[*nombreContacts].email) == 3) {
        (*nombreContacts)++;
    }

    fclose(fichier);
    printf("Contacts chargés avec succès depuis le fichier.\n");
}


void ajouterContact(Contact *contacts, int *nombreContacts) {
    if (*nombreContacts >= 100) {
        printf("Limite de contacts atteinte.\n");
        return;
    }
    printf("Entrez le nom : ");
    scanf("%s", contacts[*nombreContacts].nom);
    printf("Entrez le téléphone : ");
    scanf("%s", contacts[*nombreContacts].telephone);
    printf("Entrez l'email : ");
    scanf("%s", contacts[*nombreContacts].email);

    (*nombreContacts)++;
    printf("Contact ajouté avec succès.\n");
}
void afficherContacts(const Contact *contacts, int nombreContacts) {
    for (int i = 0; i < nombreContacts; i++) {
        printf("Nom : %s, Téléphone : %s, Email : %s\n", contacts[i].nom, contacts[i].telephone, contacts[i].email);
    }
}
void rechercherContact(const Contact *contacts, int nombreContacts) {
    char nomRecherche[50];
    printf("Entrez le nom à rechercher : ");
    scanf("%s", nomRecherche);

    for (int i = 0; i < nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            printf("Contact trouvé : Nom : %s, Téléphone : %s, Email : %s\n", contacts[i].nom, contacts[i].telephone, contacts[i].email);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}
void supprimerContact(Contact *contacts, int *nombreContacts) {
    char nomSuppression[50];
    printf("Entrez le nom du contact à supprimer : ");
    scanf("%s", nomSuppression);

    for (int i = 0; i < *nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomSuppression) == 0) {
            for (int j = i; j < *nombreContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*nombreContacts)--;
            printf("Contact supprimé avec succès.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}
int main() {
    Contact contacts[100];
    int nombreContacts = 0;

    chargerContacts(contacts, &nombreContacts);

    int choix;

    do {
        printf("\n--- Gestionnaire de Contacts ---\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Supprimer un contact\n");
        printf("5. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterContact(contacts, &nombreContacts);
            break;
            case 2:
                afficherContacts(contacts, nombreContacts);
            break;
            case 3:
                rechercherContact(contacts, nombreContacts);
            break;
            case 4:
                supprimerContact(contacts, &nombreContacts);
            break;
            case 5:
                sauvegarderContacts(contacts, nombreContacts);
            printf("Au revoir !\n");
            break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
