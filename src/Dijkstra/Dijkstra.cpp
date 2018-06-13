//
// Created by Karolina on 13.06.2018.
//

#include <iostream>
#include <limits>
using namespace std;

struct node
{
    int n;			// nr wierzchołka
    int w;
    node * next;
};


const int V = 5;



void tab_to_lists(int Gtab[V][V], node * G[V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (Gtab[i][j] == 1)
            {
                cout << i << " ," << j << endl;
                node * nowy1 = new node;
                nowy1->n = j;
                nowy1->w = Gtab[i][j];
                nowy1->next = NULL;
                if (G[i] != NULL)
                {
                    node * prev1 = G[i];
                    while (prev1->next != NULL)
                        prev1 = prev1->next;
                    prev1->next = nowy1;
                }
                else
                {
                    G[i] = nowy1;
                }
            }
        }
    }
}



void Dijkstra(node * G[], int d[], int parent[], bool visited[], int s)
{
    for (int i = 0; i < V; i++)
    {
        d[i] = INT_MAX;
        parent[i] = NULL;
        visited[i] = false;
    }
    d[s] = 0;
    for (int i = 0; i < V; i++)
    {
        int min = INT_MAX;
        int u = 0;
        for (int j = 0; j < V; j++)
        {
            if (!visited[i] && d[i] < min)
            {
                u = i;
                min = d[i];
            }
        }
        for (node * temp = G[u]; temp != NULL; temp = temp->next)
        {
            int v = temp->n;
            if (d[u] + temp->w < d[v])
            {
                d[v] = d[u] + temp->w;
                parent[v] = u;
            }
        }
        visited[u] = true;
    }
}




int main()
{

    int Gt[V][V] = { { 0, 1, 0, 1, 0 },{ 1, 0, 0, 0, 1 },{ 0, 0, 0, 0, 1 },{ 1, 0, 0, 0, 1 },{ 0, 1, 1, 1, 0 } };

    node * G[V];			// tablica list sąsiedztwa
    for (int i = 0; i < V; i++)
        G[i] = NULL;

    tab_to_lists(Gt, G);
    int d[V];
    int parent[V];
    bool visited[V];
    Dijkstra(G, d, parent, visited, 0);
    for (int i = 0; i < V; i++)
        cout << i << ": " << d[i] << endl;

    int a;
    cin >> a;

}
