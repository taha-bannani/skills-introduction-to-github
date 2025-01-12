#include "lib.h"
#include <stdio.h>

void afficherMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher les voitures disponibles\n");
    printf("3. Rechercher une voiture par marque\n");
    printf("4. Quitter\n");
    printf("Choisissez une option : ");
}


void ajouterVoiture(FILE *file) {
    Voiture v;
    printf("\nID : ");
    scanf("%d", &v.id);
    printf("Marque : ");
    scanf("%s", v.marque);
    printf("Modèle : ");
    scanf("%s", v.modele);
    printf("Type de carburant : ");
    scanf("%s", v.carburant);
    printf("Nombre de places : ");
    scanf("%d", &v.places);
    printf("Transmission (automatique/manuelle) : ");
    scanf("%s", v.transmission);
    printf("Prix par jour : ");
    scanf("%f", &v.prix_par_jour);
    printf("Disponibilité (1 = disponible, 0 = non disponible) : ");
    scanf("%d", &v.disponible);

    fprintf(file, "%d,%s,%s,%s,%d,%s,%.2f,%d\n", v.id, v.marque, v.modele,
            v.carburant, v.places, v.transmission, v.prix_par_jour, v.disponible);
    printf("Voiture ajoutée avec succès !\n");
}

void afficherVoitures(FILE *file) {
    Voiture v;
    rewind(file);
    printf("\n--- Liste des voitures disponibles ---\n");
    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%d\n",
                  &v.id,&v.marque,&v.modele,&v.carburant,
                  &v.places,&v.transmission, &v.prix_par_jour, &v.disponible) != EOF) {
        if (v.disponible) {
            printf("ID: %d, Marque: %s, Modèle: %s, Carburant: %s, Places: %d, Transmission: %s, Prix: %.2f\n",
                   v.id, v.marque, v.modele, v.carburant,
                   v.places, v.transmission, v.prix_par_jour);
        }
    }
}


void rechercherVoiture(FILE *file) {
    char marque[50];
    Voiture v;
    int trouve = 0;

    printf("\nEntrez la marque à rechercher : ");
    scanf("%s", marque);

    rewind(file);
    printf("\n--- Résultats de la recherche ---\n");
    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%d\n",
                  &v.id, v.marque, v.modele, v.carburant,
                  &v.places, v.transmission, &v.prix_par_jour, &v.disponible) != EOF) {
        if (strcmp(v.marque, marque) == 0) {
            printf("ID: %d, Marque: %s, Modèle: %s, Carburant: %s, Places: %d, Transmission: %s, Prix: %.2f\n",
                   v.id, v.marque, v.modele, v.carburant,
                   v.places, v.transmission, v.prix_par_jour);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune voiture trouvée pour la marque : %s\n", marque);
    }
}
