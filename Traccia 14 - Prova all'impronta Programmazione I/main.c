//
//  main.c
//  Traccia 14 - Prova all'impronta Programmazione I
//
//  Created by Roberto Vecchio on 18/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//
//Sviluppare una function C che, data come parametro di input una stringa che rappresenta un testo in italiano, determina e restituisce come parametri di output la parola di lunghezza minima contenuta nel testo e la posizione di inizio della parola nella stringa. Nel testo le parole sono separate da un unico spazio.

#include <stdio.h>
#include <string.h>
#include <limits.h>

void wordWithAandE(char *, char *, unsigned long *);

int main(int argc, const char * argv[]) {
    char phrase[150];
    unsigned long index;
    char token[100];
    
    printf("inserisci la frase:\n");
    fgets(phrase, 4096, stdin);
    
    wordWithAandE(phrase, token, &index);
    
    printf("%s, %lu", token, index);
    
    
    return 0;
}

void wordWithAandE(char *word, char *maxTok, unsigned long *index){
    unsigned long len,len_min = INT_MAX;
    char separators[] = {' ','\0','\t','\n'};
    char *token = strtok(word, separators);
    
    while (token != NULL) {
        
        len = strlen(token);
        
        if (len < len_min) {
            len_min = len;
            strcpy(maxTok, token);
            *index = token - word;
            printf("\n\n%s\n\n%s\n\n", maxTok, token);
        }
        token = strtok(NULL," \n");
    }
}
