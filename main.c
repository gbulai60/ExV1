//Varianta 1
//Lista de cărți
//Structura unui nod:
//typedef struct Carte {
//    char titlu[100];
//    char autor[50];
//    int an_publicare;
//    struct Carte* next;
//} Carte;
//Trebuie să avem posibilitatea de a face:
//Inserarea unei cărți la sfârșitul listei.
//Ștergerea unei cărți după titlu.
//Afișarea tuturor cărților scrise de un anumit autor.
//Actualizarea anului de publicare pentru o carte dată.

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

typedef struct Carte {
    char titlu[100];
    char autor[50];
    int an_publicare;
    struct Carte* next;
} Carte;
int isEmpty(Carte *head){
    if(head==NULL) return 1;
    else return 0;
}
Carte *insert(Carte *head,char titlu[100],char autor[50],int an_publicare){
    Carte *new=(Carte*)malloc(sizeof (Carte));
    Carte *end=head;
    strcpy(new->titlu, titlu);
    strcpy(new->autor, autor);
    new->an_publicare=an_publicare;
    new->next=NULL;
    if(isEmpty(head)) return new;
    else{
        while(end->next!=NULL)
        end=end->next;
        end->next=new;
        return head;
    }
}
Carte *deleteForTitle(Carte *head,char titlu[100]){
    if(isEmpty(head)) {
        printf("\nLista este goala");
        return NULL;
    }
    else {
        Carte *start = head;
        while (start->next != NULL) {
            if (strcmp(start->titlu, titlu)==0) {
                Carte *aux = start;
                start = start->next;
                head = start;
                free(aux);
            } else if (strcmp(start->next->titlu, titlu)==0) {
                Carte *aux = start->next;
                start->next = aux->next;
                free(aux);
            }
            start = start->next;
        }
        return head;
    }
}
void printByAuthor(Carte *head){
    char autor[50];
    printf("\nIntroduceti numele autorului:");
    fflush(stdin); gets(autor);
    int i=1;
    while (head!=NULL){
        if(strcmp(head->autor,autor)==0){
            printf("\n\nCartea %d\nTitlu %s\nAutor: %s\nAn publicare: %d",i++,head->titlu,head->autor,head->an_publicare);
        }
        head=head->next;
    }
}
void actualizareAnPublicare(Carte *head,Carte *carteData){
    int an_publicare=-1;
    while (head!=NULL){
        if(head==carteData){
            printf("\n\nIntroduceti valoarea noua a anului publicarii:");
            scanf("%d",&an_publicare);
            head->an_publicare=an_publicare;
        }
        head=head->next;
    }
    if(an_publicare==-1) printf("Nu a fost gasita cartea in lista!");
}
int main() {
    int a = 1,b=1;
    Carte* head = NULL;
    while(a != 0){
        system("cls");
        printf("\nMeniu:\n");
        printf("1. Inserarea unei carti la sfarsitul listei.\n");
        printf("2. Stergerea unei carti dupa titlu.\n");
        printf("3. Afisarea tuturor cartilor scrise de un anumit autor.\n");
        printf("4. Actualizarea anului de publicare pentru o carte data.\n");
        printf("0. Iesire din program.\n");
        printf("Introduceti un numar din meniu : ");
        scanf("%d", &a); system("cls");
        switch(a){
            case 1:
                while(b != 0){
                    printf("\nDoriti sa adaugati o carte? [DA/NU] [1/0]");
                    scanf("%d",&b);
                    if(b != 0) {
                        char titlu[100];
                        char autor[50];
                        int an_publicare;
                        printf("\nIntroduceti titlul cartii: "); fflush(stdin); gets(titlu);
                        printf("\nIntroduceti autorul cartii : ");  fflush(stdin);gets(autor);
                        printf("\nIntroduceti anul publicarii : ");scanf("%d",&an_publicare);
                        head= insert(head,titlu,autor,an_publicare);
                    }
                }
                getch();
                break;
            case 2: {
                system("cls");
                char titlu[100];
                printf("\nIntroduceti titlul cartii: "); fflush(stdin); gets(titlu);
                head  = deleteForTitle(head,titlu);
                getch();
                break;
            }
            case 3: {
                printByAuthor(head);
                getch();
            } break;
            case 4: {
                system("cls");
                char titlu[100];
                printf("\nIntroduceti titlul cartii cautate: "); fflush(stdin); gets(titlu);
                Carte * carteCautata,*start=head;
                while (start!=NULL){
                    if(strcmp(start->titlu,titlu)==0) carteCautata=start;
                    start=start->next;
                }
                if(carteCautata!=NULL) actualizareAnPublicare(head,carteCautata);
                else printf("\nNU a fost gasita cartea cu titlul %s",titlu);
                getch();
            } break;

        }
    }
}
