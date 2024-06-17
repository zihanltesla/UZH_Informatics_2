#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define INF 1000

// store the graph in adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];

int primMST(int num_v) {
    int parent[MAX_VERTICES];  // nodes' parent
    int key[MAX_VERTICES];     // nodes' key
    int inMST[MAX_VERTICES];   // if node in the MST,which node is already in the MST
    
    // set all nodes: key = inf, inMST flag = 0 (not in mst)
    for (int i = 0; i < num_v; ++i) {
        key[i] = INF;
        inMST[i] = 0;
    }

    // start from node 0
    key[0] = 0;
    parent[0] = -1;

    int totalWeight = 0;
    for (int iter = 0; iter < num_v; iter++) {
        int u;
        int minKey = INF;
        // find a new vertex (not in MST) with minimum key value
        for (int v = 0; v < num_v; v++) {
            if (inMST[v]==0 && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        printf("Add node %d\n", u);
        // add the new vertex to the MST
        inMST[u] = 1;
        // add the optimal key value for adding this node
        totalWeight += key[u];

        // update the key value and parent for vertices not in the MST
        // v==0 is to check if the node is the starting node
        for (int v = 0; v < num_v; v++) {
            if (v == u || inMST[v] == 1 || graph[u][v] == INF) {
                continue;
            }

            int new_weight = graph[u][v];
            if (new_weight < key[v]) {
                parent[v] = u;
                key[v] = new_weight;
            }
        }
    }

    // optional, print the edges in the MST
    // printf("Edges in the minimum spanning tree:\n");
    // for (int i = 1; i < num_v; i++) {
    //     printf("%d - %d: %d\n", parent[i], i, key[i]);
    // }

    return totalWeight;
}

/* Input
9, 14
0, 1, 4
0, 7, 8
1, 2, 8
1, 7, 11
2, 3, 7
2, 5, 4
2, 8, 2
3, 4, 9
3, 5, 14
4, 5, 10
5, 6, 2
6, 7, 1
6, 8, 6
7, 8, 7
*/
/* Answer
The total weight of the MST is 37.
*/

int main() {
    int num_vertices, num_edges;
    // Enter the number of vertices
    scanf("%d, %d", &num_vertices, &num_edges);

   // set all initial value to infinity, 
   // and set the diagonal to 0 ( d[i, i]=0 )
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Enter the edges
    for (int i = 0; i < num_edges; i++) {
        int s, t, w;
        scanf("%d, %d, %d", &s, &t, &w);
        // undirect egde
        graph[s][t] = w;
        graph[t][s] = w;
    }

    // sanity check: print the adjacency matrix
    // for (int i = 0; i < num_vertices; i++) {
    //     for (int j = 0; j < num_vertices; j++) {
    //         if (graph[i][j] == INF)
    //             printf("x ");
    //         else
    //             printf("%d ", graph[i][j]);
    //     }
    //     printf("\n");
    // }

    int res = primMST(num_vertices);
    printf("The total weight of the MST is %d.\n", res);

    return 0;
}
        