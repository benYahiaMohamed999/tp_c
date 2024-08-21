#include<stdio.h>
#include<string.h>
#include<ctype.h>




int calcule(char *ch){
    int nb=0;
    char *p;
    for(p=ch;*p;p++){
        if(isspace(*p))
            nb++;
    }

    return nb+1;
}


int calcule_2(char *ch){
    int dans_mot=0,nb=0;
    char *p;
    for(p=ch;*p;p++){
        if(isspace(*p))
            dans_mot=0;
        else
           if(dans_mot==0){
            nb++;
            dans_mot=1;
           }


    }
    return nb;
}

void main(){
    char *x[100];
    gets(x);
    printf("les caracter = %d \n",calcule_2(x));
   

}

