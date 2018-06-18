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
				cout << i << " ," << j << ": " << Gtab[i][j] << endl;
				node * nowy1 = new node;
				nowy1->n = j;
				nowy1->next = NULL;
				nowy1->w = Gtab[i][j];
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




void Prim(int weight[], int parent[], node * Glists[V], int v) // v - wierzcho³ek startowy
{
	for (int i = 0; i < V; i++)
	{
		parent[i] = -1;
		weight[i] = INT_MAX;
	}
	weight[v] = 0;
	for (int i = 0; i < V; i++)
	{
		int u;
		int min = INT_MAX;
		for (int i = 0; i < V; i++)
		{
			if (weight[i] < min && weight[i] >= 0) //bo odwiedzone wierzcho³ki bêd¹ mia³y nadan¹ wagê = -1
			{
				u = i;
				min = weight[i];
			}
		}
		for (node * temp = Glists[u]; temp != NULL; temp = temp->next)
		{
			if (weight[temp->n] > temp->w)
			{
				weight[temp->n] = temp->w;
				parent[temp->n] = u;
			}
		}
		weight[u] = -1;
	}
}



int main()
{
	int Gts[V][V] = { { 0, 5, 7, 10, 1 },{ 5, 0, 8, 1, 1 },{ 7, 8, 0, 8, 1 },{ 10, 1, 8, 0, 1 },{ 1, 1, 1, 1, 0 } };
	node * Gs[V];
	for (int i = 0; i < V; i++)
		Gs[i] = NULL;
	tab_to_lists(Gts, Gs);
	int weight[V];
	int parent[V];
	Prim(weight, parent, Gs, 3);
	for (int i = 0; i < V; i++)
		cout << i << " " << parent[i] << endl;
	int a;
	cin >> a;

}
