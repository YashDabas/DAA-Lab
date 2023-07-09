#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int *stk;
} stack;

void push(stack *s, int data)
{
    s->stk[(s->top)++] = data;
}

int pop(stack *s)
{
    return s->stk[(s->top)--];
}

int *visited;
void dfsTopoFind(int **adjMatrix, stack *s, int noVertex, int start)
{
    visited[start] = 1;
    for (int i = 0; i < noVertex + 1; i++)
    {
        if (adjMatrix[start][i] && !visited[i])
        {
            dfsTopoFind(adjMatrix, s, noVertex, i);
        }
    }
    push(s, start);
}

void dfsPrint(int **adjMatrix, int noVertex, int start, int *visited)
{
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < noVertex + 1; i++)
    {
        if (adjMatrix[start][i] && !visited[i])
        {
            dfsPrint(adjMatrix, noVertex, i, visited);
        }
    }
}

stack *topologicalSort(int **adjMatrix, int noVertex)
{
    stack *s = calloc(1, sizeof(stack));
    s->stk = calloc(noVertex + 2, sizeof(int));
    s->top = -1;

    for (int i = 0; i < noVertex + 1; i++)
    {
        if (!visited[i])
        {
            dfsTopoFind(adjMatrix, s, noVertex, i);
        }
    }
    
    return s;
}

void stronglyConnectedComponents(int **adjMatrix, int noVertex)
{

    int **transposeAdjMatix = calloc(noVertex + 1, sizeof(int *));
    for (int i = 0; i < noVertex + 1; i++)
    {
        transposeAdjMatix[i] = calloc(noVertex + 1, sizeof(int));
    }

    for (int i = 0; i < noVertex + 1; i++)
    {
        for (int j = 0; j < noVertex + 1; j++)
        {
            if (adjMatrix[i][j])
            {
                transposeAdjMatix[j][i] = 1;
            }
        }
    }

    stack *s = topologicalSort(adjMatrix, noVertex);
    visited = calloc(noVertex + 1, sizeof(int));

    while (s->top >= 0)
    {
        int start = pop(s);
        if (!visited[start])
        {
            dfsPrint(transposeAdjMatix, noVertex, start, visited);
            printf("\n");
        }
    }
}

int main()
{
    int noVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &noVertex);
    visited = calloc(noVertex + 1, sizeof(int));
    int **adjMatrix = calloc(noVertex + 1, sizeof(int *));
    for (int i = 0; i < noVertex + 1; i++)
    {
        adjMatrix[i] = calloc(noVertex + 1, sizeof(int));
    }
    int noEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &noEdges);
    for (int i = 0; i < noEdges; i++)
    {
        int start;
        int end;
        printf("Enter the edge: ");
        scanf("%d %d", &start, &end);
        adjMatrix[start][end] = 1;
    }

    stronglyConnectedComponents(adjMatrix, noVertex);

    return 0;
}