#include <stdio.h>

int visited[5][4];
int goalFound = 0;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void DLS(int a, int b, int depth, int limit)
{
    if(a < 0 || b < 0 || a > 4 || b > 3 || visited[a][b] || goalFound)
        return;

    printf("(%d,%d) depth=%d\n", a, b, depth);

    if(a == 2 || b == 2)
    {
        printf("Goal reached!\n");
        goalFound = 1;
        return;
    }

    if(depth == limit)
        return;

    visited[a][b] = 1;

    int transfer;

    // Fill A
    DLS(4, b, depth+1, limit);

    // Fill B
    DLS(a, 3, depth+1, limit);

    // Empty A
    DLS(0, b, depth+1, limit);

    // Empty B
    DLS(a, 0, depth+1, limit);

    // Pour A -> B
    transfer = min(a, 3 - b);
    DLS(a - transfer, b + transfer, depth+1, limit);

    // Pour B -> A
    transfer = min(b, 4 - a);
    DLS(a + transfer, b - transfer, depth+1, limit);
}

int main()
{
    int limit = 10;   // large enough to reach solution

    printf("Depth Limited Search (limit=%d)\n", limit);

    DLS(0,0,0,limit);

    return 0;
}
