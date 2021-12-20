#include <stdio.h>
#include <stdlib.h>

void DFS(int G[][7], int start, int n)
{
    int i = start, j;
    static int visited[7] = {0};
    if (visited[i] == 0)
    {
        printf("%d ", i);
        visited[i] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    DFS(G, 6, 7);
    printf("\n");
}