#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>



typedef struct ordinateur 
{
    int code;
    char marque[16];
    float prix;
}ord;


int trouve(ord *t,int x,int n){
    ord *p;
    for(p=t;p<t+n;p++){
        if(p->code==x)
        return 1;


    }
    return 0;
}


void ajout_ord(ord *t,int *n,ord z){
    ord *p,*q;
    p=t;
    while (p<t+*n && strcmp(p->marque,z.marque)<0)
    {
        p++;
    }
    //decalge:
    for(q=t+*n;q>p;p--){
        *q=*(q-1);

    }
    *p=z;
    *n=*n+1;
    

}

void remplir(ord t[],int n){
    ord *p;
    for(p=t;p<t+n;p++){
        printf("\n ordinateur %d\n",p-t+1);
        do{
            printf("code");
            scanf("%d",&p->code);
        }while(p->code<=0 || trouve(t,p->code,p-t)==1);
    
    printf("marque");
    scanf("%s",p->marque);
    do{
        printf("prix");
        scanf("%f",&p->prix);
    }while(p->prix<=0);
    }

}

int saisie(){
    int n;
    do{
        printf("donner n");
        scanf("%d",&n);
    }while(n<=0);
    return n;
}

void convertToUpper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}


/*void affiche_dell(ord *t,int n){
    ord *p;
    printf("\n les code des ord de marque DELL");
    if(strcmp(strupr(p->marque),"DELL")==0){
        printf("\n %d \t",p->code);

    }
}
*/

int different(ord *t ,int n){
    return 1;

}

void supprimer(ord *t,int *n){
    ord *p,*q;
    for(p=t,q=t;p<t+*n;p++){
        if(p->prix<3000){
            *q=*p;
            q++;
        }
        *n=q-t;
    }
}



void afficher(ord *t,int n){
    ord *p;
    for(p=t;p<t+n;p++){
        printf("\n ord %d:\t%d\t%s\t%f",
        p-t+1,p->code,p->marque,p->prix);
    }

}

int marq_distinct(ord *t,int n){

    int nb=n;
    ord *p,*q;
    for(p=t;p<t+n-1;p++){
        for(q=p+1;q<t+n;q++){
            if(strcmp(p->marque,q->marque)==0){
                nb--;
                break;
            }
        }
    }

}

void modif_prix(ord *t,int n,int x,float y){
    ord *p;
    p=t;
    while (p<t+n && p->code !=x)
    {
        p++;
    }
    if(p->code==x){
        p->prix=y;
    }
    
}


void trie(ord*t,int n){
    ord *p,x;
    int permut;
    do{
        permut=0;
        for(p=t;p<t+n-1;p++){
            if(strcmp(p->marque,(p+1)->marque)>0){
                x=*p;
                *p=*(p+1);
                *(p+1)=x;
                permut=1;
            }
            
        }
        n--;
    }while(permut&&n);
}



int main(){
    ord *t,z;
    int n,x;
    float y;
    n=saisie();
    t=(ord*)malloc(n*sizeof(ord));
    remplir(t,n);
    afficher(t,n);
    //affiche_dell(t,n);
    printf("nb de marche diffirent%d",different(t,n));
    supprimer(t,&n);
    printf("\n le tableaux apres supprision:\n");
    afficher(t,n);
    printf("\n code de l;ord modifcation \n");
    scanf("%d",&x);
    if(trouve(t,x,n)){
        printf("\n new prix");
        scanf("%f",&y);
        modif_prix(t,n,x,y);
        printf("\n le tableau apres modification:");
        afficher(t,n);
    }else
        printf("\n code in existant \n");
    trie(t,n);
    afficher(t,n);
    printf("\n ordinateur a ajouter \n");
    do{
        printf("code");
        scanf("%d",&z.code);
    }while(z.code<=0|| trouve(t,z.code,n));
    printf("marque");
    scanf("%s",z.marque);
    printf("prix");
    scanf("%f",&z.prix);
    ajout_ord(t,&n,z);
    printf("\n tab apres insertion ");
    afficher(t,n);

     




    return 0;


}