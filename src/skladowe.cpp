#include <iostream>
using namespace std;

struct node
{
	int n;			// nr wierzcho³ka
	node * next;
};


const int N = 5;

// (chyba) liczy³o spójne sk³adowe

void DFSVisit(node * lists[], int v, bool visited[])
{
	visited[v] = true;
	for (node * temp = lists[v]; temp != NULL; temp = temp->next)
	{
		int u = temp->n;
		if (!visited[u])
			DFSVisit(lists, u, visited);
	}
}



int skladowe (bool visited[], node * lists[])
{
	for (int i = 0; i < N; i++)
		visited[i] = false;
	int licznik = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			licznik++;
			DFSVisit(lists, i, visited);
		}
	}
	return licznik;
}




void tab_to_lists(int Gtab[N][N], node * G[N])
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


void tab_to_lists_skier(int Gtab[N][N], node * G[N])
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



int main()
{

	int Gt[N][N] = { { 0, 0, 1, 0, 0 },{ 0, 0, 0, 0, 1 },{ 1, 0, 0, 0, 0 },{ 0, 0, 0, 0, 1 },{ 0, 1, 0, 1, 0 } };

	node * G[N];
	for (int i = 0; i < N; i++)
		G[i] = NULL;

	tab_to_lists(Gt, G);
	bool visited[N];
	int times[N];
	int parent[N];
	cout << skladowe(visited, G);

	int a;
	cin >> a;

}
