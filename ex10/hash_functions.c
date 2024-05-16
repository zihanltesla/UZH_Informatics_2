#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 150

int h1(int k) {
    /* h(k) = k mold 7 */
    return k % 7;
}

int h2(int k) {
    return (23 * k) % 127;
    /* it is possible to go higher, thus no collision, e.g.:  */
}

/* Implement */
int insertKeyH1(int *HT, int k) {
    /* TODO task 2.(a) */
    int index = h1(k);
    int colittions = 0;
    // printf("-----------------\n");
    // printf("k=%d\n",k);
    //为啥有个collitions<N
    while (HT[index] != -1 && colittions < N) {
        index= (index+1) % N;   //为啥N加在这里,是因为index不能超过hash表的大小吗?
        // printf("index=%d\n",index);
        colittions++;

    }

    if (colittions >= N) {
        return 0;
    }
    // printf("col=%d\n",colittions);
    HT[index] = k;
    return colittions;
}

/* Implement */
int insertKeyH2(int *HT, int k) {
    /* TODO task 2.(a) */
    int index = h2(k);
    int colittions = 0;

    //为什么是3??这个step要怎么选?
    int step = (51*k)%3;
    while (HT[index] != -1 && colittions < N) {
        index= (index+step) % N;   //为啥N加在这里,是因为index不能超过hash表的大小吗?
        // printf("index=%d\n",index);
        colittions++;

    }

    if (colittions >= N) {
        return 0;
    }
    // printf("col=%d\n",colittions);
    HT[index] = k;
    return colittions;
}

/* given */
void initHT(int *HT) {
    for (int i = 0; i < N; ++i) {
        HT[i] = -1;
    }
}

/* given */
void printHT(int *HT) {
    for (int i = 0; i < N; ++i) {
        printf("%d,", HT[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    clock_t start_time, end_time;
    int collisions = 0;
    int HT[N];
    int keys[100] = {73,  148, 29,  214, 101, 47,  92,  201, 164, 88,  133, 19,
                     176, 58,  123, 82,  209, 37,  147, 66,  112, 193, 79,  155,
                     11,  98,  181, 44,  119, 71,  207, 23,  162, 94,  136, 52,
                     185, 67,  144, 32,  199, 77,  120, 17,  158, 26,  191, 49,
                     105, 14,  173, 55,  129, 84,  201, 38,  168, 59,  112, 70,
                     141, 33,  196, 80,  117, 22,  153, 102, 66,  125, 47,  108,
                     31,  177, 14,  86,  172, 41,  95,  164, 75,  188, 57,  133,
                     16,  121, 74,  144, 39,  109, 168, 81,  201, 53,  97,  24,
                     137, 62,  116, 9};

    initHT(HT);

    start_time = clock();
    for (int i = 0; i < 100; ++i) {
        collisions += insertKeyH1(HT, keys[i]);
    }
    end_time = clock();

    printHT(HT);
    printf("H1: completed in %.2f clocks, %d collisions\n",
           (double)(end_time - start_time), collisions);

    /* improved hash function */
    initHT(HT);
    collisions = 0;

    start_time = clock();
    for (int i = 0; i < 100; ++i) {
        collisions += insertKeyH2(HT, keys[i]);
    }
    end_time = clock();

    printHT(HT);
    printf("H2: completed in %.2f clocks, %d collisions\n\n",
           (double)(end_time - start_time), collisions);

    return 0;
}
