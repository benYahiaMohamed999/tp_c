#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Définition de la structure d'un noeud de la liste chaînée
struct ListNode {
    int val;
    struct ListNode *next;
};

// Fonction pour inverser une chaîne de caractères
char* INV_CH(char* chaine) {
    int longueur = strlen(chaine);
    char* inverse = (char*)malloc((longueur + 1) * sizeof(char)); // Allouer de la mémoire pour la chaîne inversée
    if (inverse == NULL) {
        printf("Erreur lors de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < longueur; i++) {
        inverse[i] = chaine[longueur - 1 - i];
    }
    inverse[longueur] = '\0'; // Terminer la chaîne avec le caractère nul
    return inverse;
}

// Fonction pour insérer un nouvel élément dans la liste chaînée
void insert(struct ListNode **head, int val) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

// Fonction pour afficher la liste chaînée
void printList(struct ListNode *head) {
    struct ListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Fonction pour fusionner deux listes chaînées triées
struct ListNode* mergeLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    if (l1 != NULL)
        current->next = l1;
    else
        current->next = l2;
    
    struct ListNode *result = dummy->next;
    free(dummy);
    return result;
}

// Structure de produit
struct produit {
    int numero;
    char* nom;
};

// Fonction principale
int main() {
    struct produit *p1,*s;

    
    // Création de deux listes chaînées
    struct ListNode* l1 = NULL;
    insert(&l1, 5);
    insert(&l1, 3);
    insert(&l1, 1);
    
    struct ListNode* l2 = NULL;
    insert(&l2, 6);
    insert(&l2, 4);
    insert(&l2, 2);

    // Affichage des listes chaînées initiales
    printf("Liste 1: ");
    printList(l1);
    printf("Liste 2: ");
    printList(l2);

    // Fusion des listes chaînées
    struct ListNode* mergedList = mergeLists(l1, l2);

    // Affichage de la liste chaînée fusionnée
    printf("Liste fusionnée triée : ");
    printList(mergedList);
    //invers chaine character
    char gg[] = "ruojnoB";
    printf("inverse == %s",INV_CH(gg));

    char str[200];
    char srr='x';
    printf("%c", toupper(srr));
puts("Entrez un nombre : ");
gets(str);
printf("Entree = %s \n", str);
printf("int = %d \n", atoi(str));
printf("long = %ld \n", atol(str));
printf("double = %f \n", atof(str));

    return 0;
}
