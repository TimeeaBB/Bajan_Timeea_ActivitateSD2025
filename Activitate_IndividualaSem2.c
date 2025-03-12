#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include <string.h>

struct Laptop {  //Structura Laptop
	int id;
	char* producator;
	int memorieRAM;
	int capacitateSSD;
	char sistemOperare;
};
struct Laptop initializare(int id,char* producator,int memorieRAM,int capacitateSSD,char sistemOperare) {
	struct Laptop n;
	n.id = id;
	n.memorieRAM = memorieRAM;
	n.capacitateSSD = capacitateSSD;
	n.sistemOperare = sistemOperare;
	if (producator == NULL)   //Veirifcam daca avem sau nu producator
	{
		n.producator = NULL;
	}
	else
	{
		n.producator = (char*)malloc(strlen(producator) + 1);
		strcpy_s(n.producator, strlen(producator) + 1, producator);
	}
	return n;
}

// Fct Afisare laptop
void afisare(struct Laptop n) {
    printf("ID: %d\nProducator: %s\nRAM: %dGB\nSSD: %dGB\nSistem de Operare: %c\n\n",
        n.id, n.producator, n.memorieRAM, n.capacitateSSD, n.sistemOperare);
}

// Vector de laptopuri AFISARE
void afisareVector(struct Laptop* vector, int nrElemente) {
    for (int i = 0; i < nrElemente; i++) {
        afisare(vector[i]);
    }
}

// Copiazã primele N laptopuri într-un nou vector
struct Laptop* copiazaPrimeleNElemente(struct Laptop* vector, int nrElemente, int nrElementeCopiate) {
    if (nrElementeCopiate > nrElemente) {
        nrElementeCopiate = nrElemente;
    }

    struct Laptop* vectorNou = (struct Laptop*)malloc(nrElementeCopiate * sizeof(struct Laptop));
    for (int i = 0; i < nrElementeCopiate; i++) {
        vectorNou[i] = initializare(vector[i].id, vector[i].producator, vector[i].memorieRAM, vector[i].capacitateSSD, vector[i].sistemOperare);
    }
    return vectorNou;
}

// Dezalocare memorie
void dezalocare(struct Laptop** vector, int* nrElemente) {
    for (int i = 0; i < *nrElemente; i++) {
        free((*vector)[i].producator);
    }
    free(*vector);
    *vector = NULL;
    *nrElemente = 0;
}

// Copiazã laptopurile cu minim 16GB RAM (Asa mi-am propus ca si  exercitiu)
void copiazaAnumiteElemente(struct Laptop* vector, int nrElemente, int prag, struct Laptop** vectorNou, int* dimensiune) {
    *dimensiune = 0;

    // Determinãm câte laptopuri respectã condi?ia (minim 16GB RAM)
    for (int i = 0; i < nrElemente; i++) {
        if (vector[i].memorieRAM >= prag) {
            (*dimensiune)++;
        }
    }

    if (*dimensiune == 0) {
        *vectorNou = NULL;
        return;
    }

    *vectorNou = (struct Laptop*)malloc((*dimensiune) * sizeof(struct Laptop));

    int index = 0;
    for (int i = 0; i < nrElemente; i++) {
        if (vector[i].memorieRAM >= prag) {
            (*vectorNou)[index] = initializare(vector[i].id, vector[i].producator, vector[i].memorieRAM, vector[i].capacitateSSD, vector[i].sistemOperare);
            index++;
        }
    }
}

// Gãse?te primul laptop dupã producãtor
struct Laptop getPrimulElementConditionat(struct Laptop* vector, int nrElemente, const char* conditie) {
    for (int i = 0; i < nrElemente; i++) {
        if (strcmp(vector[i].producator, conditie) == 0) {
            return vector[i]; // Returnãm un shallow copy (fãrã alocare de memorie nouã)
        }
    }
    return initializare(-1, "Necunoscut", 0, 0, '-');
}

int main() {
    int nrElemente = 3;
    struct Laptop* vector = (struct Laptop*)malloc(nrElemente * sizeof(struct Laptop));

    vector[0] = initializare(1, "HP", 8, 512, 'W');
    vector[1] = initializare(2, "Apple", 16, 1024, 'M'); //mac
    vector[2] = initializare(3, "Lenovo", 32, 2048, 'W');

    printf("Laptopurile initiale:\n");
    afisareVector(vector, nrElemente);

    // Copiem primele 2 laptopuri
    struct Laptop* vectorCopiat;
    int nrElemCopiate = 2;
    vectorCopiat = copiazaPrimeleNElemente(vector, nrElemente, nrElemCopiate);
    printf("Primele %d laptopuri copiate:\n", nrElemCopiate);
    afisareVector(vectorCopiat, nrElemCopiate);
    dezalocare(&vectorCopiat, &nrElemCopiate);

    // Copiem laptopurile cu minim 16GB RAM
    printf("Laptopuri cu minim 16GB RAM:\n");
    copiazaAnumiteElemente(vector, nrElemente, 16, &vectorCopiat, &nrElemCopiate);
    afisareVector(vectorCopiat, nrElemCopiate);
    dezalocare(&vectorCopiat, &nrElemCopiate);

    // Gãsim un laptop dupã marcã (de exemplu APPLE)
    struct Laptop laptopGasit = getPrimulElementConditionat(vector, nrElemente, "Apple");
    printf("Laptop gasit dupa marca:\n");
    afisare(laptopGasit);

    // Dezalocare la final 
    dezalocare(&vector, &nrElemente);

    return 0;

}
