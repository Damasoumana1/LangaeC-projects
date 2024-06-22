#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un film
typedef struct {
    char titre[100];
    int heure;
    int minute;
} Film;

// Fonction pour afficher les films disponibles
void afficher_films(Film* films, int nombre_films) {
    printf("Films disponibles :\n");
    for (int i = 0; i < nombre_films; i++) {
        printf("%d. %s - Heure : %02d:%02d\n", i + 1, films[i].titre, films[i].heure, films[i].minute);
    }
}

// Fonction pour réserver des billets
void reserver_billets(Film* films, int nombre_films, int film_index, int nombre_billets) {
    if (film_index < 0 || film_index >= nombre_films) {
        printf("Index de film invalide.\n");
        return;
    }

    Film film = films[film_index];
    printf("Vous avez réservé %d billet(s) pour le film '%s' à %02d:%02d.\n", nombre_billets, film.titre, film.heure, film.minute);
}

int main() {
    // Déclaration des films disponibles
    Film films[3];
    strcpy(films[0].titre, "Avengers: Endgame");
    films[0].heure = 18;
    films[0].minute = 0;
    strcpy(films[1].titre, "Spider-Man: No Way Home");
    films[1].heure = 20;
    films[1].minute = 30;
    strcpy(films[2].titre, "Black Widow");
    films[2].heure = 22;
    films[2].minute = 0;
    strcpy(films[3].titre, "Woman King");
    films[3].heure = 22;
    films[3].minute = 30;

    int nombre_films = 4;

    printf("Bienvenue dans le système de réservation de billets de cinéma !\n");

    while (1) {
        printf("\nQue voulez-vous faire ?\n");
        printf("1. Afficher les films disponibles\n");
        printf("2. Reserver des billets\n");
        printf("0. Quitter\n");

        int choix;
        scanf("%d", &choix);

        if (choix == 1) {
            afficher_films(films, nombre_films);
        } else if (choix == 2) {
            afficher_films(films, nombre_films);

            int film_index;
            printf("Sélectionnez le numéro du film : ");
            scanf("%d", &film_index);
            film_index--;

            int nombre_billets;
            printf("Combien de billets voulez-vous réserver ? ");
            scanf("%d", &nombre_billets);

            reserver_billets(films, nombre_films, film_index, nombre_billets);
        } else if (choix == 0) {
            printf("Merci d'avoir utilisé notre système de réservation de billets de cinéma. À bientôt !\n");
            break;
        } else {
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}


