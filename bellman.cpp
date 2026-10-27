//GARVIT GANGWAR , 25/DA/027
#include <iostream>
using namespace std;

#define INF 9999

struct Edge
{
    int source;
    int destination;
    int weight;
};

int main()
{
    Edge edge[20];

    int vertices, edges;
    int distance[10];
    int source;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter source, destination and weight of each edge:\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> edge[i].source
            >> edge[i].destination
            >> edge[i].weight;
    }

    cout << "Enter source vertex: ";
    cin >> source;

    // Initialize distances
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INF;
    }

    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= vertices - 1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = edge[j].source;
            int v = edge[j].destination;
            int w = edge[j].weight;

            if (distance[u] != INF &&
                distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycle
    for (int j = 0; j < edges; j++)
    {
        int u = edge[j].source;
        int v = edge[j].destination;
        int w = edge[j].weight;

        if (distance[u] != INF &&
            distance[u] + w < distance[v])
        {
            cout << "\nNegative-weight cycle exists!\n";
            return 0;
        }
    }

    // Display shortest distances
    cout << "\nShortest distances from vertex "
         << source << ":\n";

    for (int i = 0; i < vertices; i++)
    {
        if (distance[i] == INF)
            cout << "To vertex " << i << " = INF\n";
        else
            cout << "To vertex " << i
                 << " = " << distance[i] << endl;
    }

    return 0;
}
