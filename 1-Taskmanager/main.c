#include <stdio.h>
#include <stdlib.h>
#define MAX_TASKS 500

char tasks[MAX_TASKS][500];  // Tableau pour stocker les t�ches
int numTasks = 0;  // Nombre de t�ches actuellement dans le tableau

void add_task() {
    if (numTasks >= MAX_TASKS) {
        printf("La liste de t�ches est pleine !\n");
        return;
    }

    printf("Entrez une nouvelle t�che : ");
    fgets(tasks[numTasks], sizeof(tasks[numTasks]), stdin);

    // Supprime le caract�re de nouvelle ligne � la fin de la t�che
    tasks[numTasks][strcspn(tasks[numTasks], "\n")] = '\0';

    numTasks++;
    printf("T�che ajout�e avec succ�s !\n");
}

void modify_task() {
    int index;

    if (numTasks == 0) {
        printf("La liste de t�ches est vide !\n");
        return;
    }

    printf("Entrez l'indice de la t�che � modifier : ");
    scanf("%d", &index);

    if (index >= 0 && index < numTasks) {
        printf("Entrez la nouvelle t�che : ");
        getchar();  // Consomme le caract�re de nouvelle ligne restant
        fgets(tasks[index], sizeof(tasks[index]), stdin);
        tasks[index][strcspn(tasks[index], "\n")] = '\0';
        printf("T�che modifi�e avec succ�s !\n");
    } else {
        printf("Indice de t�che invalide !\n");
    }
}

void delete_task() {
    int index, i;

    if (numTasks == 0) {
        printf("La liste de t�ches est vide !\n");
        return;
    }

    printf("Entrez l'indice de la t�che � supprimer : ");
    scanf("%d", &index);

    if (index >= 0 && index < numTasks) {
        for (i = index; i < numTasks - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }

        numTasks--;
        printf("T�che supprim�e avec succ�s !\n");
    } else {
        printf("Indice de t�che invalide !\n");
    }
}

void show_tasks() {
    int i;

    if (numTasks == 0) {
        printf("La liste de t�ches est vide !\n");
        return;
    }

    printf("Liste des t�ches :\n");
    for (i = 0; i < numTasks; i++) {
        printf("%d. %s\n", i, tasks[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter une t�che\n");
        printf("2. Modifier une t�che\n");
        printf("3. Supprimer une t�che\n");
        printf("4. Afficher les t�ches\n");
        printf("5. Quitter\n");

        printf("Entrez le num�ro de votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                modify_task();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                show_tasks();
                break;
            case 5:
                exit(0);
            default:
                printf("Choix invalide !\n");
        }
    }

    return 0;
}


