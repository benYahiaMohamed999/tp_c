int nb_ocurence(list l,int x){
    int nb=0;
    list p;
    for(p=l;p;p=p->suiv){
        if(p->info==x)
        nb++;
    }
    return nb;
}