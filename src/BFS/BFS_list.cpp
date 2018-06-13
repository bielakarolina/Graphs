//
// Created by Karolina on 24.05.2018.
//
#include <iostream>
#include <queue>
#include <limits.h>


using namespace std;

struct Vertex{
    bool visited;
    int d;
    Vertex *parent;
    int n;
    Vertex * next;
};


const int V=5;
void BFS(Vertex **G, Vertex *s){

    for(int i=0;i<V;i++){
        G[i]->visited=false;
        G[i]->d=INT8_MAX;
        G[i]->parent=NULL;
    }
    queue <Vertex*> Q;
    s->d=0;
    s->visited=true;
    Q.push(s);

    while(!Q.empty()){
        Vertex *u=Q.front();
        cout << u->n << " ";
        Q.pop();
        for(Vertex * i = G[u->n]; i != NULL; i = i->next){
            Vertex *v = i;
            if(!v->visited){
                v->visited=true;
                v->d=u->d+1;
                v->parent=u;
                Q.push(v);
            }
        }
    }
}


void tab_to_lists_skier(int Gtab[V][V], Vertex **G)		// dla skierowanych i nieskierowanych
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (Gtab[i][j] == 1)
            {
                cout << i << " ," << j << endl;
                Vertex * nowy1 = new Vertex;
                nowy1->n = j;
                nowy1->next = NULL;
                if (G[i] != NULL)
                {
                    Vertex * prev1 = G[i];
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

    int Gts[V][V] = { {0, 0, 1, 0, 1}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0} };
    Vertex * Gs[V];
    for (int i = 0; i < V; i++)
        Gs[i] = NULL;
    tab_to_lists_skier(Gts, Gs);
    Vertex *s=new Vertex;
    s->n=0;


    int a;
    cin >> a;

}