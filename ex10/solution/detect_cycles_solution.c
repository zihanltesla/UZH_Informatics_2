#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

int h(int k, int n) { return (7 * k) % n; }

int detectCycle(struct Node *l) {
    /* init a hash table */
    int n = 10; /* obviously greater than total number of distinct nodes */
    int T[n];
    for (int i = 0; i < n; ++i)
        T[i] = -1;

    /* loop through the linked list and hash the value
       if a new hash of a value causes a collision and the value is the same,
       then we know there is a loop */
    struct Node *p = l; /* copy the head */
    int i;
    while (p) {
        printf("at %d\n", p->val);
        i = h(p->val, n); /* get hash value */

        /* because n > len(l), no counter */
        /* like normal insert using linear probing */
        /* this will become O(1) average if good enough distribution */
        while (T[i] != -1) {
            /* if the key is the same, we have a cycle */
            if (T[i] == p->val) {
                printf("found cycle\n");
                return 1;
            }
            /* if key is different, continue */
            i++;
        }
        T[i] = p->val; /* insert into hash table */
        p = p->next;   /* next node */
    }
    /* found no cycle, because all distinct elements */
    printf("found no cycle\n");
    return 0;
}

int main(int argc, char *argv[]) {
    struct Node *head;

    head = malloc(sizeof(struct Node));
    head->val = 1;

    head->next = malloc(sizeof(struct Node));
    head->next->val = 2;

    head->next->next = malloc(sizeof(struct Node));
    head->next->next->val = 3;

    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->val = 4;

    /* without cycle */
    head->next->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->next->val =
        11; /* maps to same slot, but should not trigger cycle */

    /* with cycle */
    /* head->next->next->next->next = head->next; */

    detectCycle(head);

    return 0;
}
