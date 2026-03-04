#include <stdio.h>

int visited[5][4];   // A: 0-4, B: 0-3

int min(int x, int y)
{
    if(x < y) return x;
    return y;
}

int goalFound = 0;

void DFS(int a, int b)
{
    if(a < 0 || b < 0 || a > 4 || b > 3 || visited[a][b] || goalFound)
        return;

    printf("(%d,%d)\n", a, b);

    if(a == 2 || b == 2)
    {
        printf("Goal reached!\n");
        goalFound = 1;
        return;
    }

    visited[a][b] = 1;

    int transfer;

    // Fill A
    DFS(4, b);

    // Fill B
    DFS(a, 3);

    // Empty A
    DFS(0, b);

    // Empty B
    DFS(a, 0);

    // Pour A -> B
    transfer = min(a, 3 - b);
    DFS(a - transfer, b + transfer);

    // Pour B -> A
    transfer = min(b, 4 - a);
    DFS(a + transfer, b - transfer);
}

int main()
{
    printf("DFS Search:\n");
    DFS(0,0);
    return 0;
}
