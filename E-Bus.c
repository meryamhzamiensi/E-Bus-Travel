#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 10

int choix , x ;
typedef struct Date {
    int Jour;
    int Mois;
    int Annee;
} Date;

typedef struct SVoyageur {
    int code_voy;
    char nom[CMAX];
    char prenom[CMAX];
} SVoyageur;

typedef struct SBus {
    int code_bus;
    char etat;
    int matricule;
    int nbreplaces;
    int prixloc;
} SBus;

typedef struct SReservation {
    int code_res;
    int code_bus;
    int duree;
    struct Date d_reservation;
} SReservation;

typedef struct SCompteVoy {
    int code_cpt;
    int code_voy;
    int code_res;
    struct Date d_compte;
} SCompteVoy;

// Global arrays to store data
SCompteVoy comptes[50];
SVoyageur voyageurs[50];
SBus buss[20];
SReservation reservations[20];

// Function prototypes
void menu();
void sous_menu(int a);
void gerer_voyageur(int a);
void gerer_compte(int a);
void gerer_bus(int a);
void gerer_reservation(int a);

// Main function
int main() {
    while (1) {
        menu();
    }
    return 0;
}
void menu()
{
    printf("1- Gestion des voyageurs\n");
    printf("2- Gestion des comptes\n");
    printf("3- Gestion des bus\n");
    printf("4- Gestion des reservations\n");
    printf("5- Quitter le programme\n");
    printf("Choisir le menu : ");
    scanf("%d", &choix);
    sous_menu(choix);
}

void sous_menu(int a)
{
    if (a==1)
    {
        printf("1- Ajouter\n");
        printf("2- Modifier\n");
        printf("3- Supprimer\n");
        printf("4- Afficher\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
        gerer_voyageur(x);
    }
     else if (a==2)
    {
        printf("1- Ajouter\n");
        printf("2- Rechercher\n");
        printf("3- Afficher la liste\n");
        printf("4- Supprimer\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
        gerer_compte(x);
    }
    else if (a==3)
    {
        printf("1- Ajouter\n");
        printf("2- Modifier\n");
        printf("3- Supprimer\n");
        printf("4- Afficher\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
        gerer_bus(x);
    }
    else if (a==4)
    {
        printf("1- Ajouter\n");
        printf("2- Rechercher\n");
        printf("3- Afficher la liste\n");
        printf("4- Supprimer\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
        gerer_reservation(x);
    }
    else if (a==5)
        exit(0);
    else
    {
        printf("\nmauvaix choix\n");
        menu() ;
    }
}

void gerer_voyageur(int a)
{
    if (a==1)
    {
        struct SVoyageur voyageur;
        FILE *file;

        printf("Code Voyageur : ");
        scanf("%d", &voyageur.code_voy);
        printf("Nom : ");
        scanf("%s", &voyageur.nom);
        printf("Prenom : ");
        scanf("%s", &voyageur.prenom);

        file = fopen("voyageur.txt", "a");
        fwrite(&voyageur, sizeof(voyageur), 1, file);

        if(fwrite != 0)
            printf("voyageur ajouté avec succes");
        else
            printf("erreur");
        fclose(file);
    }
    else if (a==2)
    {
        struct SVoyageur voyageur;
        struct SVoyageur nvVoyageur;
        FILE *file;

        printf("Code Voyageur à modifier : ");
        scanf("%d", &nvVoyageur.code_voy);
        printf("nv nom : ");
        scanf("%s", &nvVoyageur.nom);
        printf("nv prenom : ");
        scanf("%s", &nvVoyageur.prenom);

        file = fopen("voyageur.txt", "r");

        int nbVoy = 0;

        while(fread(&voyageur, sizeof(struct SVoyageur), 1, file)) {
            voyageurs[nbVoy] = voyageur;
            nbVoy++;
        }
        fclose(file);
        remove("voyageur.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nbVoy ; i++)
        {
            if (voyageurs[i].code_voy == nvVoyageur.code_voy)
                fwrite(&nvVoyageur, sizeof(voyageurs[i]), 1, nf);
            else
                fwrite(&voyageurs[i], sizeof(voyageurs[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "voyageur.txt");
    }
    else if (a==3)
    {
        struct SVoyageur voyageur;
        int code;
        FILE *file;

        printf("Code Voyageur à supprimer : ");
        scanf("%d", &code);

        file = fopen("voyageur.txt", "r");

        int nbVoy = 0;

        while(fread(&voyageur, sizeof(struct SVoyageur), 1, file)) {
            voyageurs[nbVoy] = voyageur;
            nbVoy++;
        }
        fclose(file);
        remove("voyageur.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nbVoy ; i++)
        {
            if (voyageurs[i].code_voy != code)
                fwrite(&voyageurs[i], sizeof(voyageurs[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "voyageur.txt");
    }
    else if (a==4)
    {
        FILE *file;
        struct SVoyageur voyageur;
        file = fopen("voyageur.txt", "r");
        int nbVoy = 0;
        while(fread(&voyageur, sizeof(struct SVoyageur), 1, file)) {
            voyageurs[nbVoy] = voyageur;
            nbVoy++;
        }
        fclose(file);
        for (int c=0 ; c<nbVoy ; c++)
        {
            printf("\nCode Voyageur : %d", voyageurs[c].code_voy);
            printf("\nNom: %s | %s", voyageurs[c].nom, voyageurs[c].prenom);
            printf("\n");
        }

    }
    else if (a==5)
        menu();
}

void gerer_compte(int a)
{
    if (a==1)
    {
        struct SCompteVoy compte;
        struct SCompteVoy compte0;
        FILE *file;
        FILE *f2;

        printf("Code Compte : ");
        scanf("%d", &compte.code_cpt);

        f2 = fopen("compte.txt", "r");
        int found = 0;
        while(fread(&compte0, sizeof(struct SCompteVoy), 1, f2) && found == 0) {
            if (compte0.code_cpt == compte.code_cpt)
                found = 1;
        }

        if(found == 1)
        {
            printf("code existant\n");
            return 0;
        }

        printf("Code Voyageur : ");
        scanf("%d", &compte.code_voy);
        printf("Date de creation du compte | ");
        printf("Jour : ");
        scanf("%d", &compte.d_compte.Jour);
        printf("Mois : ");
        scanf("%d", &compte.d_compte.Mois);
        printf("Annee : ");
        scanf("%d", &compte.d_compte.Annee);
        file = fopen("compte.txt", "a");
        fwrite(&compte, sizeof(compte), 1, file);

        if(fwrite != 0)
            printf("compte ajouté avec succes");
        else
            printf("erreur");
    }
    else if (a==2)
    {
        struct SCompteVoy compte;
        int code;
        FILE *file;

        printf("Code compte : ");
        scanf("%d", &code);

        file = fopen("compte.txt", "r");
        int found = 0;
        while(fread(&compte, sizeof(struct SCompteVoy), 1, file) && found == 0) {
            if (compte.code_cpt == code)
               {
                    printf("\n Code compte : %d", compte.code_cpt);
                    printf("\n Code voyageur : %d", compte.code_voy);
                    printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                    found = 1 ;
               }
        }
        if(found == 0)
            printf("code non existant\n");
        fclose(file);
    }
    else if (a==3)
    {
        struct SCompteVoy compte;
        FILE *file;

        file = fopen("compte.txt", "r");

        while(fread(&compte, sizeof(struct SCompteVoy), 1, file)) {
                    printf("\n Code compte : %d", compte.code_cpt);
                    printf("\n Code voyageur : %d", compte.code_voy);
                    printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                    printf("\n-----------------------------------------");
        }
        fclose(file);
    }
    else if (a==4)
    {
        struct SCompteVoy compte;
        int code;
        FILE *file;

        printf("Code Compte a supprimer : ");
        scanf("%d", &code);

        file = fopen("compte.txt", "r");

        int nb = 0;

        while(fread(&compte, sizeof(struct SCompteVoy), 1, file)) {
            comptes[nb] = compte;
            nb++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].code_cpt != code)
                fwrite(&comptes[i], sizeof(comptes[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "compte.txt");
    }
    else if (a==5)
        menu();
}
void gerer_bus(int a)
{
    if (a==1)
    {
        struct SBus bus;
        FILE *file;

        printf("Code Bus : ");
        scanf("%d", &bus.code_bus);
        printf("etat : ");
        scanf("%s", &bus.etat);
        printf("Matricule de Bus : ");
        scanf("%d", &bus.matricule);
        printf("Capacite : ");
        scanf("%d", &bus.nbreplaces);
        printf("Prix de location de bus : ");
        scanf("%d", &bus.prixloc);

        file = fopen("bus.txt", "a");
        fwrite(&bus, sizeof(bus), 1, file);

        if(fwrite != 0)
            printf("bus ajouté avec succes");
        else
            printf("erreur");
        fclose(file);
    }
    else if (a==2)
    {
        struct SBus bus;
        struct SBus nvbus;
        FILE *file;

        printf("Code bus à modifier: ");
        scanf("%d", &nvbus.code_bus);
        printf("nv etat : ");
        scanf("%s", &nvbus.etat);
        printf("matricule: ");
        scanf("%d", &nvbus.matricule);
        printf("prix de location à modifier: ");
        scanf("%d", &nvbus.prixloc);
        printf("Capacite à modifier: ");
        scanf("%d", &nvbus.nbreplaces);

        file = fopen("bus.txt", "r");

        int nbbus = 0;

        while(fread(&bus, sizeof(struct SBus), 1, file)) {
            buss[nbbus] = bus;
            nbbus++;
        }
        fclose(file);
        remove("bus.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nbbus ; i++)
        {
            if (buss[i].code_bus == nvbus.code_bus)
                fwrite(&nvbus, sizeof(buss[i]), 1, nf);
            else
                fwrite(&buss[i], sizeof(buss[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "bus.txt");
    }
    else if (a==3)
    {
        struct SBus bus;
        int code;
        FILE *file;

        printf("Code Bus à supprimer : ");
        scanf("%d", &code);

        file = fopen("bus.txt", "r");

        int nbbus = 0;

        while(fread(&bus, sizeof(struct SBus), 1, file)) {
            buss[nbbus] = bus;
            nbbus++;
        }
        fclose(file);
        remove("bus.txt");

        FILE *nf3;
        nf3 = fopen("nv3.txt", "a");
        for ( int i=0 ; i<nbbus ; i++)
        {
            if (buss[i].code_bus != code)
                fwrite(&buss[i], sizeof(buss[i]), 1, nf3);
        }
        fclose(nf3);
        rename("nv3.txt", "bus.txt");
    }
    else if (a==4)
    {
        FILE *file;
        struct SBus bus;
        file = fopen("bus.txt", "r");
        int nbbus = 0;
        while(fread(&bus, sizeof(struct SBus), 1, file)) {
            buss[nbbus] = bus;
            nbbus++;
        }
        fclose(file);
        for (int c=0 ; c<nbbus ; c++)
        {
            printf("\nCode Bus : %d", buss[c].code_bus);
            printf("\nEtat de Bus : %s", buss[c].etat);
            printf("\nMatricule : %d", buss[c].matricule);
            printf("\nCapacite : %d", buss[c].nbreplaces);
            printf("\nPrix de location de Bus : %d", buss[c].prixloc);
            printf("\n");
        }

    }
    else if (a==5)
        menu();
}

void gerer_reservation(int a)
{
    if (a==1)
    {
        struct SReservation reservation;
        struct SReservation reservation0 ;
        FILE *file;
        FILE *f3;

        printf("Code reservation : ");
        scanf("%d", &reservation.code_res);

        f3 = fopen("reservation.txt", "r");
        int found = 0;
        while(fread(&reservation0, sizeof(struct SReservation), 1, f3) && found == 0) {
            if (reservation0.code_res == reservation.code_res)
                found = 1;
        }

        if(found == 1)
        {
            printf("code existant\n");
            return 0;
        }

        printf("Code Reservation : ");
        scanf("%d", &reservation.code_res);
        printf("Duree de Reservation : ");
        scanf("%d", &reservation.duree);
        printf("Date de reservation | ");
        printf("Jour : ");
        scanf("%d", &reservation.d_reservation.Jour);
        printf("Mois : ");
        scanf("%d", &reservation.d_reservation.Mois);
        printf("Annee : ");
        scanf("%d", &reservation.d_reservation.Annee);
        file = fopen("reservation.txt", "a");
        fwrite(&reservation, sizeof(reservation), 1, file);

        if(fwrite != 0)
            printf("reservation ajouté avec succes");
        else
            printf("erreur");
    }
    else if (a==2)
    {
        struct SReservation reservation;
        int code;
        FILE *file;

        printf("Code reservation : ");
        scanf("%d", &code);

        file = fopen("reservation.txt", "r");
        int found = 0;
        while(fread(&reservation, sizeof(struct SReservation), 1, file) && found == 0) {
            if (reservation.code_res == code)
               {
                    printf("\n Code reservation : %d", reservation.code_res);
                    printf("\n Code bus : %d", reservation.code_bus);
                    printf("\n Duree de reservation : %d", reservation.duree);
                    printf("\n Date reservation %d / %d / %d", reservation.d_reservation.Jour, reservation.d_reservation.Mois, reservation.d_reservation.Annee);
                    found = 1 ;
               }
        }
        if(found == 0)
            printf("code non existant\n");
        fclose(file);
    }
    else if (a==3)
    {
        struct SReservation reservation;
        FILE *file;

        file = fopen("reservation.txt", "r");

        while(fread(&reservation, sizeof(struct SReservation), 1, file)) {
                    printf("\n Code reservation : %d", reservation.code_res);
                    printf("\n Duree de reservation : %d", reservation.duree);
                    printf("\n Code bus : %d", reservation.code_bus);
                    printf("\n Date reservation %d / %d / %d", reservation.d_reservation.Jour, reservation.d_reservation.Mois, reservation.d_reservation.Annee);
                    printf("\n-----------------------------------------");
        }
        fclose(file);
    }
    else if (a==4)
    {
        struct SReservation reservation;
        int code;
        FILE *file;

        printf("Code Reservation à supprimer : ");
        scanf("%d", &code);

        file = fopen("reservation.txt", "r");

        int nb = 0;

        while(fread(&reservation, sizeof(struct SReservation), 1, file)) {
            reservations[nb] = reservation;
            nb++;
        }
        fclose(file);
        remove("reservation.txt");

        FILE *nf4;
        nf4 = fopen("nv4.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (reservations[i].code_res != code)
                fwrite(&reservations[i], sizeof(reservations[i]), 1, nf4);
        }
        fclose(nf4);
        rename("nv4.txt", "reservation.txt");
    }
    else if (a==5)
        menu();
}
