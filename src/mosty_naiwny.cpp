#include <iostream>
using namespace std;

struct node
{
	int n;			// nr wierzcho³ka
	node * next;
};


const int N = 5;



void DFSVisit(int Gt[][N], int v, bool visited[])
{
	visited[v] = true;
	for (int i = 0; i < N; i++)
	{
		if (Gt[v][i] != 0 && !visited[i])
			DFSVisit(Gt, i, visited);
	}
}



int skladowe(bool visited[], int Gt[][N])
{
	for (int i = 0; i < N; i++)
		visited[i] = false;
	int licznik = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			licznik++;
			DFSVisit(Gt, i, visited);
		}
	}
	return licznik;
}


int most(int Gt[][N], bool visited[], int mosty[][2], int &k)
{
	int all = skladowe(visited, Gt);
	int licznik = 0;
	for (int i = 0; i < N - 1; i++)				// dla grafu nieskierowanego
	{
		for (int j = i + 1; j < N; j++)
		{
			if (Gt[i][j] != 0)
			{
				int copy = Gt[i][j];
				Gt[i][j] = 0;
				int temp = skladowe(visited, Gt);
				cout << temp;
				
				if (temp > all)
				{
					mosty[k][0] = i;
					mosty[k][1] = j;
					k++;
					licznik++;
				}
				Gt[i][j] = copy;
			}
		}
	}
	return licznik;

}


void main()
{

	int Gt[N][N] = { { 0, 1, 0, 0, 0 },{ 1, 0, 1, 0, 0 },{ 0, 1, 0, 1, 0 },{ 0, 0, 1, 0, 1 },{ 0, 0, 0, 1, 0 } };

	bool visited[N];
	int mosty[N][2];	// lista par wierzcho³kow, miêdzy którymi s¹ mosty
	int k = 0;			// indeks w 'mosty'
	cout << most(Gt, visited, mosty, k) << endl;
	for (int i = 0; i < k; i++)
		cout << mosty[i][0] << ", " << mosty[i][1] << endl;
	int a;
	cin >> a;

}