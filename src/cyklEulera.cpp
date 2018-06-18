#include <iostream>
using namespace std;

const int N = 5;

void DFSVisit(int Gtab[][N], int v, int &k)
{
	cout << v << " ";
	for (int i = 0; i < N; i++)
	{
		if (Gtab[v][i] != 0)
		{
			k = i;
			Gtab[v][i] = 0;
			Gtab[i][v] = 0;
			DFSVisit(Gtab, i, k);
		}
	}
}



bool Euler(int Gtab[][N], int s)		// czy jest cykl Eulera
{
	int k = -1;
	DFSVisit(Gtab, s, k);
	cout << "Ostatni: " << k << endl;
	if (k == s) return true;
	else return false;
}

int main()
{
	int Gt[N][N] = { { 0, 1, 0, 0, 1 },{ 1, 0, 1, 0, 0 },{ 0, 1, 0, 1, 0 },{ 0, 0, 1, 0, 1 },{ 1, 0, 0, 1, 0 } };
	if (Euler(Gt, 0)) cout << "EULER";
	int a;
	cin >> a;
}
