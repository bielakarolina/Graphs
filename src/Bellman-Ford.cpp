#include <iostream>
#include <limits>
using namespace std;

struct node
{
	int n;			// nr wierzcho³ka
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
			if (Gtab[i][j] != 0)
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



bool Bellman_Ford(node * G[], int d[], int parent[], int s)
{
	for (int i = 0; i < V; i++)
	{
		d[i] = INT_MAX/2;		// ¿eby przy relaksacji nie przekroczyæ zakresu
		parent[i] = NULL;
	}
	d[s] = 0;
	for (int i = 0; i < V; i++)
	{
		for (node * temp = G[i]; temp != NULL; temp = temp->next)
		{
			int v = temp->n;
			if (d[i] + temp->w < d[v])
			{
				d[v] = d[i] + temp->w;
				parent[v] = i;
			}
		}
	}
	for (int i = 0; i < V; i++)						// weryfikacja
	{
		for (node * temp = G[i]; temp != NULL; temp = temp->next)
			if (d[i] + temp->w < d[temp->n])				// mamy cykl ujemny
				return false;
	}
	return true;
}




int main()
{

	int Gt[V][V] = { { 0, 4, 0, 1, 0 },{ 4, 0, 0, 0, 1 },{ 0, 0, 0, 0, 1 },{ 1, 0, 0, 0, 1 },{ 0, 1, 1, 1, 0 } };

	node * G[V];			// tablica list s¹siedztwa
	for (int i = 0; i < V; i++)
		G[i] = NULL;

	tab_to_lists(Gt, G);
	int d[V];
	int parent[V];
	bool BF = Bellman_Ford(G, d, parent, 0);
	if (!BF) cout << "Ujemne wagi krawedzi" << endl;
	for (int i = 0; i < V; i++)
		cout << i << ": " << d[i] << endl;

	int a;
	cin >> a;

}
