

#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* gauche;
    struct Noeud* droite;
} Noeud;


Noeud* nouveauNoeud(int valeur) {
    Noeud* noeud = (Noeud*)malloc(sizeof(Noeud));
    noeud->valeur = valeur;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    return noeud;
}

Noeud* inserer(Noeud* racine, int valeur) {
    if (racine == NULL) {
        return nouveauNoeud(valeur);
    }
    if (valeur < racine->valeur) {
        racine->gauche = inserer(racine->gauche, valeur);
    } else if (valeur > racine->valeur) {
        racine->droite = inserer(racine->droite, valeur);
    }
    return racine;
}

// Parcours infixe (in-order)
void parcoursInfixe(Noeud* racine) {
    if (racine != NULL) {
        parcoursInfixe(racine->gauche);
        printf("%d ", racine->valeur);
        parcoursInfixe(racine->droite);
    }
}





Noeud* minValueNode(Noeud* noeud) {
    Noeud* courant = noeud;
    while (courant && courant->gauche != NULL) {
        courant = courant->gauche;
    }
    return courant;
}


Noeud* supprimer(Noeud* racine, int valeur) {
    if (racine == NULL) {
        return racine;
    }
    if (valeur < racine->valeur) {
        racine->gauche = supprimer(racine->gauche, valeur);
    } else if (valeur > racine->valeur) {
        racine->droite = supprimer(racine->droite, valeur);
    } else {
        // Nœud avec un seul enfant ou aucun enfant
        if (racine->gauche == NULL) {
            Noeud* temp = racine->droite;
            free(racine);
            return temp;
        } else if (racine->droite == NULL) {
            Noeud* temp = racine->gauche;
            free(racine);
            return temp;
        }

        // Nœud avec deux enfants
        Noeud* temp = minValueNode(racine->droite);
        racine->valeur = temp->valeur;
        racine->droite = supprimer(racine->droite, temp->valeur);
    }
    return racine;
}






int main() {
    Noeud* racine = NULL;
    int valeurs[] = {20, 10, 30, 5, 15, 25, 35};
    int taille = sizeof(valeurs) / sizeof(valeurs[0]);

    // Insertion des valeurs dans l'arbre
    for (int i = 0; i < taille; i++) {
        racine = inserer(racine, valeurs[i]);
    }

    // Suppression d'une valeur dans l'arbre
    racine = supprimer(racine, 35);

    parcoursInfixe(racine);

    // Libération de la mémoire (ajouter une fonction pour libérer l'arbre)

    return 0;
}