#include<stdio.h>
#include<stdlib.h>
struct cellule
{ 
    int info;
    struct cellule *suiv;
};

typedef struct cellule *list;

list inst_tete(list l, int x) {
    list p;
    p = (list)malloc(sizeof(struct cellule));
    p->info = x;
    p->suiv = l;
    l = p;
    return l;
}

list inst_quequ(list l, int x) {
    list p, q;
    if (l == NULL)
        l = inst_tete(l, x);
    else {
        p = (list)malloc(sizeof(struct cellule));
        p->info = x;
        p->suiv = NULL;
        q = l;
        while (q->suiv != NULL) {
            q = q->suiv;
        }
        q->suiv = p;
    }
    return l;
}
list cree(list l, int n) {
    int i, x;
    for (i = 1; i <=n; i++) {
        printf("element %d ==> ", i);
        scanf("%d", &x);
        l = inst_quequ(l, x);
    }
    return l;
}

void affiche(list l){
    list p;
    p=l;
    while (p!=NULL)
    {
       printf(" %d \t ",p->info);
       p=p->suiv;
    }
}


list ins_apresk(list l,int x,int k){

    list p,q;int i;
    if(l){
        p=(list)malloc(sizeof(struct cellule));
        p->info=x;
        q=l;
        i=1;
        while (i<k && q)
        {
            i++;
            q=q->suiv;
        }
        p->suiv=q->suiv;
        q->suiv=p;

        
    }
    return l;

}
list sup_valuer(list l, int x) {
    list current = l; // Initialize a pointer to traverse the list
    list prev = NULL; // Initialize a pointer to keep track of the previous node

    // Traverse the list
    while (current != NULL) {
        // If the current node has the value x
        if (current->info == x) {
            // If the node to be removed is the head of the list
            if (prev == NULL) {
                list temp = current; // Save the current node
                current = current->suiv; // Move to the next node
                l = current; // Update the head of the list
                free(temp); // Free the memory of the removed node
            } else {
                prev->suiv = current->suiv; // Remove the current node from the list
                free(current); // Free the memory of the removed node
                current = prev->suiv; // Move to the next node
            }
        } else {
            // Move to the next node
            prev = current;
            current = current->suiv;
        }
    }
    return l; // Return the updated list
}


list trier(list l){
    int permut,x;list p;
    do{
        permut=0;
        p=l;
        while (p->suiv)
        {
            if(p->info>p->suiv->info){
                x=p->info;
                p->info=p->suiv->info;
                p->suiv->info=x;
                permut=1;
            }
            p=p->suiv;
        }
        
    }while(permut);
    return l;
}
list sup_premoc(list l, int x) {
    list p, q;
    p = l;
    q = l;
    while (p && p->info != x) {
        q = p;
        p = p->suiv;
    }
    if (p) {
        if (p == l) {
            l = l->suiv; // If the first node contains the value x, update the head of the list
        } else {
            q->suiv = p->suiv; // Link the previous node to the next node, bypassing p
            free(p); // Free the memory of the removed node
        }
    }
    return l; // Return the updated list
}

int nb_ocurence(list l,int x){
    int nb=0;
    list p;
    for(p=l;p;p=p->suiv){
        if(p->info==x)
        nb++;
    }
    return nb;
}
list sup_occ(list l,int x){
    int nb=nb_ocurence(l,x);
    if(nb){
        for(int i=1;i<=nb;i++){
            l=sup_premoc(l,x);

        }
    }
    return l;

}
void main(){
    
list l=NULL;
int n,x,k;
do{
    printf("taille de la list est =>");
    scanf("%d",&n);
}while(n<=0);
l=cree(l,n);
affiche(l);
printf("\n valeur a inserer");
scanf("%d",&x);
do{
    printf("apres quell position");
    scanf("%d",&k);
}while(k<1  || k>n);

l=ins_apresk(l,x,k);
printf("\n la list apres insertion");
affiche(l);
printf("\nla valeur a suprimer");
scanf("%d",&x);
l=sup_valuer(l,x);
printf("\n la list apres suppresion %d EST ==>",x);
affiche(l);
scanf("\n donner pour effacer ocurance %d",&x);
l=sup_occ(l,x);
printf("\n la list sans occurance \n");
affiche(l);


l=trier(l);
printf(" \n la list apres le trie \n");
affiche(l);




}