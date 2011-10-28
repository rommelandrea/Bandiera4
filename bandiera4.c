/* 
 * File:   bandiera4.c
 * Author: rommel
 *
 * Created on October 25, 2011, 11:44 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void riempiArrayCasuale(int [], int, int);
void ordinaColori(int [], int);
int ordinatoColori(int [], int);
void print(int [], int);
void swap(int [], int, int);

/**
 * riempie gli elementi dell'array con elementi compresi tra 0 e max
 * @param a array
 * @param length lunghezza dell'array
 * @param max valore massimo
 */
void riempiArrayCasuale(int a[], int length, int max) {
    srand(time(NULL));
    int i;

    for (i = 0; i < length; i++)
        a[i] = rand() % max;
}

/**
 * inverte due valori sull'array
 * @param a
 * @param i
 * @param j
 */
void swap(int a[], int i, int j) {
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/**
 * stampa l'array
 * @param a
 * @param length
 */
void print(int a[], int length) {
    int i;
    printf("stampo l'array\n");
    for (i = 0; i < length; i++) {
        printf("%d-->", a[i]);
    }
    printf("\n");
}

/**
 * ordina un array secondo l'algoritmo della bandiera a 4 colori
 * @param a array
 * @param length lunghezza array
 */
void ordinaColori(int a[], int length) {
    int i, j, k, l;
    i = j = 0;
    k = l = length - 1;
    
    while(j<=k){
        if(a[j]%4==0){
            swap(a, i, j);
            i++;
            j++;
        }
        if(a[j]%4==1 && j<=k){
            j++;
        }
        if(a[j]%4==2 && j<=k){
            swap(a, j, k);
            k--;
        }
        if(a[j]%4==3){
            swap(a, j, k);
            swap(a, k, l);
            k--;
            l--;
        }
    }
}

/**
 * 
 * @param a array 
 * @param length lunghezza array
 * @return 1 se è ordinato 0 altrimenti
 */
int ordinatoColori(int a[], int length){
    int i;
    for(i=1; i<length; i++){
        if(a[i-1]>a[i])
            return 0;
    }
    return 1;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int length = 20;
    int a[length];
    
    riempiArrayCasuale(a, length, 4);
    print(a, length);
    
    if(ordinatoColori(a, length) == 0)
        printf("l'array NON è ordinato\n");
    else
        printf("l'array è ordinato\n");
    
    ordinaColori(a, length);
    print(a, length);
    
    if(ordinatoColori(a, length) == 0)
        printf("l'array NON è ordinato\n");
    else
        printf("l'array è ordinato\n");
    
    return (EXIT_SUCCESS);
}

