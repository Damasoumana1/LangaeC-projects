#include <stdio.h>
#include <stdlib.h>
#define MAX_TASKS 500

char tasks[MAX_TASKS][500];  // Tableau pour stocker les tâches
int numTasks = 0;  // Nombre de tâches actuellement dans le tableau

void add_task() {
    if (numTasks >= MAX_TASKS) {
        printf("La liste de tâches est pleine !\n");
        return;
    }

    printf("Entrez une nouvelle tâche : ");
    fgets(tasks[numTasks], sizeof(tasks[numTasks]), stdin);

    // Supprime le caractère de nouvelle ligne à la fin de la tâche
    tasks[numTasks][strcspn(tasks[numTasks], "\n")] = '\0';

    numTasks++;
    printf("Tâche ajoutée avec succès !\n");
}

void modify_task() {
    int index;

    if (numTasks == 0) {
        printf("La liste de tâches est vide !\n");
        return;
    }

    printf("Entrez l'indice de la tâche à modifier : ");
    scanf("%d", &index);

    if (index >= 0 && index < numTasks) {
        printf("Entrez la nouvelle tâche : ");
        getchar();  // Consomme le caractère de nouvelle ligne restant
        fgets(tasks[index], sizeof(tasks[index]), stdin);
        tasks[index][strcspn(tasks[index], "\n")] = '\0';
        printf("Tâche modifiée avec succès !\n");
    } else {
        printf("Indice de tâche invalide !\n");
    }
}

void delete_task() {
    int index, i;

    if (numTasks == 0) {
        printf("La liste de tâches est vide !\n");
        return;
    }

    printf("Entrez l'indice de la tâche à supprimer : ");
    scanf("%d", &index);

    if (index >= 0 && index < numTasks) {
        for (i = index; i < numTasks - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }

        numTasks--;
        printf("Tâche supprimée avec succès !\n");
    } else {
        printf("Indice de tâche invalide !\n");
    }
}

void show_tasks() {
    int i;

    if (numTasks == 0) {
        printf("La liste de tâches est vide !\n");
        return;
    }

    printf("Liste des tâches :\n");
    for (i = 0; i < numTasks; i++) {
        printf("%d. %s\n", i, tasks[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter une tâche\n");
        printf("2. Modifier une tâche\n");
        printf("3. Supprimer une tâche\n");
        printf("4. Afficher les tâches\n");
        printf("5. Quitter\n");

        printf("Entrez le numéro de votre choix : ");
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


