//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct Masina {
//    int id;
//    int nrLocuri;
//    char* marca;
//    float capacitateC;
//    char normaPoluare;
//};
//
//struct Masina initializare(int id, int nrLocuri, const char* marca, float capacitateC, char normaPoluare) {
//    struct Masina a;
//    a.id = id;
//    a.nrLocuri = nrLocuri;
//    a.capacitateC = capacitateC;
//    a.normaPoluare = normaPoluare;
//    a.marca = (char*)malloc(strlen(marca) + 1);
//    strcpy_s(a.marca, strlen(marca)+1, marca);
//    return a;
//}
//
//void afisare(struct Masina a) {
//    printf("Id masina: %d\n Nr locuri:%d\n Capacitate: %f\n Marca: %s Norma de poluare: %c\n", a.id, a.nrLocuri, a.capacitateC, a.marca, a.normaPoluare); // printf = functie care are un nr variabil de parametrii
//}
//\
//void modifica_nrLocuri(struct Masina* s, int nrNou) {
//    if (nrNou > 0) {
//        s->nrLocuri = nrNou;
//    }
//
//
//}
//
//void dezalocare(struct Masina* a) {
//    free(a->marca);
//    (*a).marca = NULL;
//
//}
//
//int main()
//{
//    struct Masina masina = initializare(1, 5, "Dacia", 1.5, '4'); //'4' ocupa un nr diferit de biti decat "4"
//    afisare(masina);
//    modifica_nrLocuri(&masina, 6);
//    dezalocare(&masina);
//    afisare(masina);
//    printf("\n%d", sizeof(struct Masina*));
//    printf("\n%d", sizeof(masina));
//
//
//}