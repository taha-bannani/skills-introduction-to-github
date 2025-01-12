
#include "lib.h"
int main() {
    char nom_de_utilisateur[50];
    char mot_de_pass[50];
    const char nom_de_utilisateur_correct[] = "yuu";
    const char mot_de_pass_correct[] = "123";

    while (1) {
        printf("Entrer le nom : ");
        scanf("%s", nom_de_utilisateur);
        printf("Entrer mot de pass: ");
        scanf("%s", mot_de_pass);

        if (strcmp(nom_de_utilisateur, nom_de_utilisateur_correct) == 0 && strcmp(mot_de_pass, mot_de_pass_correct) == 0) {
            printf("Connexion réussie !\n");
            break;
        } else {
            printf("Nom d'utilisateur ou mot de passe non valide. Veuillez reessayer.\n");
        }


}

    FILE *file = fopen("voitures.csv", "a+");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    int choix;
    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterVoiture(file);
                break;
            case 2:
                afficherVoitures(file);
                break;
            case 3:
                rechercherVoiture(file);
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);

    fclose(file);
    return 0;
}
