#include <iostream>
using namespace std;

struct edge {
	int u, v;
	int w;	// waga
};


struct node;
struct set {
	node * head;
	node * tail;
	int length;
};

struct node {
	node * next;
	int V;
};


const int N = 5;

void tab_to_list(int G[][N], edge list[], int &E)	// N - liczba wierzcho³ków, E - liczba krawêdzi
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (G[i][j] != 0)
			{
				edge nowy;
				nowy.u =  i;
				nowy.v = j;
				nowy.w = G[i][j];
				list[E] = nowy;
				E++;
			}
		}
	}
}


void swap(edge A[], int a, int b)
{
	int temp = A[a].u;
	A[a].u = A[b].u;
	A[b].u = temp;
	temp = A[a].v;
	A[a].v = A[b].v;
	A[b].v = temp;
	temp = A[a].w;
	A[a].w = A[b].w;
	A[b].w = temp;
}


set * makeset(int v, set * findset[]) // tworzy nowy zbiór (z jednego wierzcho³ka - v)
{
	set * S = new set;
	node * N = new node;

	findset[v] = S;
	N->next = NULL;
	N->V = v;
	S->head = N;
	S->tail = N;
	S->length = 1;

	return S;
}

void unionsets(set * &A, set * &B, set * findset[])		// scala listy, zwraca strukturê set z po³¹czonych list
{
	if (A->length <= B->length)
	{
		A->tail->next = B->head;
		A->tail = B->tail;
		A->length += B->length;
		node * temp = B->head;
		while (temp != NULL)
		{
			findset[temp->V] = A;
			temp = temp->next;
		}
		temp = A->head;
		while (temp != NULL)
		{
			findset[temp->V] = A;
			temp = temp->next;
		}
	}
	else
	{
		B->tail->next = A->head;
		B->tail = A->tail;
		B->length += A->length;
		node * temp = A->head;
		while (temp != NULL)
		{
			findset[temp->V] = B;
			temp = temp->next;
		}
		temp = B->head;
		while (temp != NULL)
		{
			findset[temp->V] = A;
			temp = temp->next;
		}

	}
}

void SelSort(edge A[], int E)
{
	for (int i = 0; i < E; i++) // od którego indeksu mamy ci¹g wyjœciowy, czyli od którego szukamy min; potem na to miejsce wstawiamy
	{							// gdy zostanie jeden element, bêdzie na swoim miejscu
		int min = i;
		for (int j = i + 1; j < E; j++)
			if (A[j].w < A[min].w) min = j; // szuka min wart. w ci¹gu wejœciowym
		int xw = A[min].w;
		int xu = A[min].u;
		int xv = A[min].v;
		for (int j = min; j > i; j--) // przesuwa elementy i robi miejsce na koncu wyjsciowego
		{
			A[j].w = A[j - 1].w;
			A[j].v = A[j - 1].v;
			A[j].u = A[j - 1].u;
		}
		A[i].w = xw;
		A[i].u = xu;
		A[i].v = xv;
	}
}

void Kruskal_(edge Gtab[],int E)
{
	SelSort(Gtab, E);
	set * findset[N]; // tablica reprezentantów
	for (int i = 0; i < N; i++)
		findset[i] = makeset(i, findset);		// tablica zamiast funkcji findset
	for (int i = 0; i < E; i++)
		if (findset[Gtab[i].u] != findset[Gtab[i].v])
		{
			unionsets(findset[Gtab[i].u], findset[Gtab[i].v], findset);
		//	cout << Gtab[i].u << " - " << Gtab[i].v << ", " << Gtab[i].w << endl;
		}
}


struct Edge {
	int u;
	int v;
	int c; //cost
};


void quickSort(Edge arr[], int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2].c;

	/* partition */
	while (i <= j) {
		while (arr[i].c < pivot)
			i++;
		while (arr[j].c > pivot)
			j--;
		if (i <= j) {
			Edge tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}



void _union(int V[], int a, int b) {
	V[b] = a;

}

int _find(int V[], int a) {
	if (V[a] != a) V[a] = _find(V, V[a]);
	return V[a];
}

void Kruskal(Edge E[], int e, int v) {
	quickSort(E, 0, e - 1);
	int P[v];
	for (int i = 0; i<v; i++) {
		P[i] = i;
	} //make set
	int w = 0;
	for (int i = 0; i<e; i++)
		if (_find(P, E[i].v) != _find(P, E[i].u)) {
			_union(P, E[i].v, E[i].u);
			cout << (E[i].v + 1) << "-" << (E[i].u + 1) << "\n";
			w += E[i].c;
		}
	std::cout << w;


}


void _Kruskal() {
	Edge Edges[14] = { { 0,1,37 },{ 0,2,2 },{ 2,3,7 },{ 3,1,1 },{ 1,8,12 },{ 8,9,21 },{ 9,6,1 },{ 6,5,2 },{ 6,4,41 },{ 4,7,14 },{ 7,2,2 },{ 7,5,20 },{ 5,9,8 },{ 5,3,10 } };
	Kruskal(Edges, 14, 10);
}




int main()
{
	edge Gtab[N*N];
	int E = 0;		// tu bêdzie liczba krawêdzi
	int G[N][N] = { {0, 5, 7, 10, 1}, {5, 0, 8, 1, 1}, {7, 8, 0, 8, 1}, {10, 1, 8, 0, 1}, {1, 1, 1, 1, 0} };
	tab_to_list(G, Gtab, E);
	cout << E << endl;
	for (int i = 0; i < E; i++)
	//	cout << Gtab[i].u << " " << Gtab[i].v << ", " << Gtab[i].w << endl;
	Kruskal_(Gtab, E);
	_Kruskal();
	int a;
	cin >> a;

}
