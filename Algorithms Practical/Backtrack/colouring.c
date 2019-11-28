#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define V 4
void printSolution(int color[]);
bool isSafe (int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
           color[v] = c;
           if (graphColoringUtil (graph, m, color, v+1) == true)
             return true;
           color[v] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[V][V], int m)
{
    int *color = (int*)calloc(V,sizeof(int));
    if (graphColoringUtil(graph, m, color, 0) == false)
    {
      printf("Solution does not exist");
      return false;
    }
    printSolution(color);
    return true;
}
void printSolution(int color[])
{
    printf("Following are the assigned colors: ");
    for (int i = 0; i < V; i++)
      printf("%d ", color[i]);
    printf("\n");
}
int main()
{
	bool graph[V][V];
	printf("enter adjacency matrix for m-colouring (vertices = %d):\n",V);
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&graph[i][j]);
	printf("enter no. of colours: ");
	int m;
    scanf("%d",&m);
    graphColoring (graph, m);
    return 0;
}
