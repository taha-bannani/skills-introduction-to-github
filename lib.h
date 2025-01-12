#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char marque[50];
    char modele[50];
    char carburant[20];
    int places;
    char transmission[20];
    float prix_par_jour;
    int disponible;
} Voiture;



#endif
