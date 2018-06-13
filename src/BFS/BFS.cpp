//
// Created by Karolina on 23.05.2018.
//

#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

struct node
{
    int n;			// nr wierzchołka
    int colour;
    int parent;
    int d;
    node * next;
};


const int V = 5;


void BFS(int s, node * G[V])		// s - wierzchołek startowy
{
    queue < int > Q;
    for (int i = 0; i < V; i++)
    {
        G[i]->colour = 0;			// wszystkie wierzchołki kolorujemy na biało
        G[i]->d = INT_MAX;
    }
    G[s]->d = 0;
    G[s]->colour = 1;		// wierzch. startowy - na czarno
    G[s]->parent = -1;
    Q.push(s);		// umieszcza s w kolejce

    while (!Q.empty())
    {
        int u = Q.front();
        cout << u << " ";
        Q.pop();

        for (node * i = G[u]; i != NULL; i = i->next)
        {
            int v = i->n;
            if (G[v]->colour == 0)
            {
                G[v]->colour = 1;
                Q.push(v);					// w kolejce są zawsze szare wierzchołki
                G[v]->parent = u;
                G[v]->d = G[u]->d + 1;
            }
        }
        G[u]->colour = 2;
    }
}


void tab_to_lists(int Gtab[V][V], node * G[V])			// tylko dla grafu nieskierowanego
{
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (Gtab[i][j] == 1)
            {
                cout << i << " ," << j << endl;
                node * nowy1 = new node;
                nowy1->n = j;
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
                node * nowy2 = new node;
                nowy2->n = i;
                nowy2->next = NULL;
                if (G[j] == NULL)
                {
                    G[j] = nowy2;
                }
                else
                {
                    node * prev2 = G[j];
                    while (prev2->next != NULL)
                        prev2 = prev2->next;
                    prev2->next = nowy2;
                }
            }
        }
    }
}


void tab_to_lists_skier(int Gtab[V][V], node * G[V])		// dla skierowanych i nieskierowanych
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



int main()
{

    int Gt[V][V] = { {0, 1, 0, 1, 0}, {1, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0} };

    node * G[V];
    for (int i = 0; i < V; i++)
        G[i] = NULL;

    tab_to_lists(Gt, G);

    int colour1[V];		// 0 - biały, 1 - szary, 2 - czarny
    int parent1[V];
    int d1[V];

    BFS(3, G);
    cout << endl;

    int Gts[V][V] = { {0, 0, 1, 0, 1}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0} };
    node * Gs[V];
    for (int i = 0; i < V; i++)
        Gs[i] = NULL;
    tab_to_lists_skier(Gts, Gs);

    int colour2[V];		// 0 - biały, 1 - szary, 2 - czarny
    int parent2[V];
    int d2[V];

    BFS(0, Gs);

    int a;
    cin >> a;

}
