#include <stdio.h>

#define MAX 100

typedef struct {
    int a;
    int b;
} State;

State queue[MAX];
int front = 0, rear = 0;

int visited[5][4];   // A: 0-4, B: 0-3


void enqueue(State s)
{
    queue[rear++] = s;
}


State dequeue()
{
    return queue[front++];
}


int isGoal(State s)
{
    return (s.a == 2 || s.b == 2);
}


int min(int x, int y)
{
    if(x < y) return x;
    return y;
}


void BFS()
{
    State start = {0,0};
    enqueue(start);
    visited[0][0] = 1;

    while(front < rear)
    {
        State current = dequeue();

        printf("(%d,%d)\n", current.a, current.b);

        if(isGoal(current))
        {
            printf("Goal reached!\n");
            return;
        }

        State next[6];

        // Production Rules

        next[0] = (State){4, current.b};   // Fill Jug A
        next[1] = (State){current.a, 3};   // Fill Jug B
        next[2] = (State){0, current.b};   // Empty Jug A
        next[3] = (State){current.a, 0};   // Empty Jug B

        int transfer;

        // Pour A -> B
        transfer = min(current.a, 3 - current.b);
        next[4] = (State){current.a - transfer, current.b + transfer};

        // Pour B -> A
        transfer = min(current.b, 4 - current.a);
        next[5] = (State){current.a + transfer, current.b - transfer};


        for(int i = 0; i < 6; i++)
        {
            int a = next[i].a;
            int b = next[i].b;

            if(a >= 0 && a <= 4 && b >= 0 && b <= 3 && !visited[a][b])
            {
                visited[a][b] = 1;
                enqueue(next[i]);
            }
        }
    }
}


int main()
{
    printf("BFS Search:\n");
    BFS();
    return 0;
}
