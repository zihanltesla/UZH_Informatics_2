#include <stdio.h>
#include <stdlib.h>

#define N 10

/* print */
void printHT(int *HT) {
    for (int i = 0; i < N; ++i) {
        printf("%d,", HT[i]);
    }
    printf("\n");
}

int h(int k, int i) { return ((k + 4) + i) % N; }

int insertH(int *T, int k) {
    int index = h(k, 0);
    int c = 0;

    while (T[index] != -1 && c < N) {
        c++;
        index = h(k, c);
    }

    if (c >= N) {
        printf("full for %d\n", k);
        return -1; /* failure */
    }

    /* T[index].val = k; */
    /* T[index].status = 0; */
    T[index] = k;
    return 0; /* success */
}

int HTdelete(int *T, int k) {
    int index = h(k, 0);     /* index */
    int indexActual = index; /* save original index */
    int c = 0;               /* counter */

    while (c < N && T[index] != -1 && T[index] != k) {
        c++;
        index = h(k, c); /* newfloat */
    }

    if (c >= N || T[index] == -1) /* not found */
        return -1;

    /* delete */
    T[index] = -1;

    /* reorder */
    int j = (index + 1) % N; /* next index to examine for potential rehashing */
    /* check until the entire sequence has been traversed or unttil empty slot
     * is encountered*/
    while (j != indexActual && T[j] != -1) {
        if (h(T[j], 0) != j) {
            /* if this element is not at the correct position */
            int tmpK = T[j]; /* aha: tmp because might end up at same place? */
            T[j] = -1;
            insertH(T, tmpK);
        }
        j = (j + 1) % N;
    }

    return index;
}

int main(int argc, char *argv[]) {
    int T[N] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int vals[] = {32, 52, 33, 74, 96}; /* constraint: only positive */

    /* init hash table as of ex (a) */
    for (int i = 0; i < N; ++i) {
        /* struct elem * e = malloc(sizeof(struct elem)); */
        /* T[i] = &e */
        /* T[i].status = -1; */
        T[i] = -1;
    }
    for (int i = 0; i < 5; ++i)
        insertH(T, vals[i]);

    /* delete example val 33 */
    printf("Before del 33: ");
    printHT(T);

    HTdelete(T, 33);

    printf("After del 33:  ");
    printHT(T);

    return 0;
}
