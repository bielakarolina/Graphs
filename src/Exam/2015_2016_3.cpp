//
// Created by Karolina on 18.06.2018.
//
//
//### 2015/2016 - Egzamin 2 - Zad. 3
//
//Dana jest następująca struktura opisująca drzewo:
//```cpp
//struct Tree{
//    Tree *parent;           // rodzic, lub NULL jeśli to korzen
//    Tree *left, *right;     // lewe i prawe dziecko
//    int w_left, w_right;    // wagi krawędzi do lewego i do prawego dziecka (dodatnie)
//};
//```
//
//Proszę opisać (bez implementacji) możliwie jak najszybszy algorytm, który mając na wejściu drzewo opisane
// przez strukturę `Tree` znajduje długość najdłuższej ścieżki między dwoma węzłami drzewa (prosta ścieżka to taka,
// która nie odwiedza żadnego węzła więcej niż raz).
//
//(Na potrzeby algorytmu mogą państwo uzupełnić strukturę `Tree` o dalsze pola.)
