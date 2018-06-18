#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
	int n;
	node *next;
};

void utworz(node*&first, node*&last, int d) //d-dlugosc lancucha
{
	node*p = NULL;
	node*q = NULL;
	last = new node;  //towrzymy ostatni element
	last->n = d;
	last->next = q;
	q = last;

	for (int i = d - 1; i>0; i--)  //a teraz reszte
	{
		p = new node;
		p->n = i;
		p->next = q;
		q = p;
	}
	first = p;
}

void wypisz(node *first)
{
	int k = 30;
	node *r = first;
	while (r != NULL && k>0)
	{
		cout << endl << r->n;
		r = r->next;
		k--;
	}
}

int cykl(node*p)
{
	node*z = p;
	node*k = p;

	do
	{
		z = z->next;
		k = k->next->next;
	} while (z != k); //spotkaja sie tylko wtedy jak wpadna do cyklu

	k = k->next;
	int licznik = 1;
	while (k != z)
	{
		k = k->next;
		licznik++;
	}
	return licznik;
}

int main()
{
	node*first1 = NULL;
	node*first2 = NULL;
	node*last1 = NULL;
	node*last2 = NULL;

	int a, c, l;
	cout << "Podaj dlugosc calego lancucha: ";
	cin >> a;
	cout << endl << "Podaj dlugosc cyklu: ";
	cin >> c;
	l = a - c; //l to dlugosc lancucha bez cyklu
	utworz(first1, last1, l);
	utworz(first2, last2, c);
	last1->next = first2;
	last2->next = first2;

	wypisz(first1);
	cout << endl;
	cout << "Zbadana dlugosc cyklu: " << cykl(first1);
	_getch();
	return 0;
}