#include <iostream>
using namespace std;

struct node
{
	int n;			// nr wierzcho�ka
	node * next;
	int parent;
	bool visited;
	int times;
};


const int N = 5;



void DFSVisit(node * G[], int v, int &time)
{
	G[v]->visited = true;
	cout << v << " ";
	time++;
	for (node * temp = G[v]; temp != NULL; temp = temp->next)
	{
		int u = temp->n;
		if (!G[u]->visited)
		{
			G[u]->parent = v;
			DFSVisit(G, u, time);
		}
	}
	G[v]->times = time;
}



void DFS(node * G[])
{
	for (int i = 0; i < N; i++)
	{
		G[i]->visited = false;
		G[i]->times = -1;		// moment przetwarzania
	}
	int time = 0;
	for (int i = 0; i < N; i++)
	{
		if (!G[i]->visited)
			DFSVisit(G, i, time);
	}
}




void tab_to_G(int Gtab[N][N], node * G[N])
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
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


void tab_to_G_skier(int Gtab[N][N], node * G[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
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



void main()
{

	int Gt[N][N] = { { 0, 1, 0, 1, 0 },{ 1, 0, 0, 0, 1 },{ 0, 0, 0, 0, 1 },{ 1, 0, 0, 0, 1 },{ 0, 1, 1, 1, 0 } };

	node * G[N];
	for (int i = 0; i < N; i++)
		G[i] = NULL;

	tab_to_G(Gt, G);
	bool visited[N];
	int times[N];
	int parent[N];
	DFS(G);

	cout << endl;

	int Gts[N][N] = { { 0, 0, 1, 0, 1 },{ 0, 0, 1, 0, 0 },{ 0, 0, 0, 1, 0 },{ 1, 0, 0, 0, 0 },{ 0, 1, 0, 0, 0 } };
	node * Gs[N];
	for (int i = 0; i < N; i++)
		Gs[i] = NULL;
	tab_to_G_skier(Gts, Gs);

	DFS(Gs);

	int a;
	cin >> a;

}