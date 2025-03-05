#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char* nume;
    float* Note;
    int nrNote;
    float MediaGenerala;
};


struct Student initializare(int id, char* nume, float* Note, int nrNote, float MediaGenerala) {
    struct Student s;
    s.id = id;
    s.MediaGenerala = MediaGenerala;
    s.nrNote = nrNote;

   
    s.nume = (char*)malloc(strlen(nume) + 1);
    if (s.nume != NULL) {
        strcpy_s(s.nume,strlen(nume)+1, nume);
    }

  
    s.Note = (float*)malloc(nrNote * sizeof(float));
    if (s.Note != NULL) {
        for (int i = 0; i < nrNote; i++) {
            s.Note[i] = Note[i];
        }
    }

    return s;
}


void afisare(struct Student s) {
    printf("\nId: %d\nNume: %s\nMediaGenerala: %.2f\nNote: ", s.id, s.nume, s.MediaGenerala);
    for (int i = 0; i < s.nrNote; i++) {
        printf("%.2f ", s.Note[i]);
    }
    printf("\n");
}


void modifica_Media(struct Student* s, float Media) {
    if (Media > 0) {
        s->MediaGenerala = Media;
    }
}


void dezalocare(struct Student* s) {
    free(s->nume);
    s->nume = NULL;
    free(s->Note);
    s->Note = NULL;
}


int main() {
    float note[] = { 9.3, 8.5, 7.2 };
    struct Student stud = initializare(1, "Student", note, 3, 9.8);

    afisare(stud);
    modifica_Media(&stud, 3.5);
    afisare(stud);
    dezalocare(&stud);

    return 0;
}
