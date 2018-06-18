#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int n;			// nr wierzcho³ka
	node * next;
};


const int V = 5;


bool czy_dwudzielny(node * G[V], int colour[V])		// s - wierzcho³ek startowy
{
	queue < int > Q;
	for (int i = 0; i < V; i++)
		colour[i] = 0;

	for (int i = 0; i < V; i++)
	{
		if (colour[i] == 0)
		{
			colour[i] = 1;		// wierzcho³ek startowy - na czerwono
			Q.push(i);			// wrzucamy wierzcho³ek do kolejki
			while (!empty(Q))
			{
				int v = Q.front();
				Q.pop();
				for (node * j = G[v]; j != NULL; j = j->next)
				{
					int u = j->n;
					if (colour[u] == colour[v]) return false;
					if (colour[u] == 0)
					{
						colour[u] = -colour[v];
						Q.push(u);
					}
				}
			}

		}
	}
	
	return true;	
}


void tab_to_lists(int Gtab[V][V], node * G[V])
{
	for (int i = 0; i < V - 1; i++)
	{
		for (int j = i + 1; j < V; j++)
		{
			if (Gtab[i][j] != 0)
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


void tab_to_lists_skier(int Gtab[V][V], node * G[V])
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (Gtab[i][j] != 0)
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



void main()
{

	int Gt[V][V] = { { 0, 1, 1, 1, 1 },{ 0, 1, 1, 1, 1 },{ 1, 1, 0, 0, 0 },{ 1, 1, 0, 0, 0 },{ 1, 1, 0, 0, 0 } };

	node * G[V];
	for (int i = 0; i < V; i++)
		G[i] = NULL;

	tab_to_lists(Gt, G);

	int colour1[V];	

	if (czy_dwudzielny(G, colour1)) cout << "DWUDZIELNY";
	else cout << "NIE JEST DWUDZIELNY";
	cout << endl;

	
	int a;
	cin >> a;

}