#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "treap.h"
using namespace std;


int main()
{srand(time(nullptr));
    int vecPerechi[] = { 10,40,20,50,30,60};
    Nod *a,*b;
    Nod* rad = build(vecPerechi,sizeof(vecPerechi)/sizeof(int));
    rad = inserare(rad,15);
    rad = inserare(rad,25,69);
    cout<<cautare(rad,11);
    ///inorder(rad);
    ///afisare(rotDr(rad->right));      ///rotatiile s ar putea sa dea segfault
    ///afisare(rotSt(rad->left));       ///sunt implementate auxiliar
    ///afisare(rad);                    ///nu sa le folosesti asa oricand
    ///rad = stergere(rad,40);
    ///afisareSplit(rad,30);
    ///split(rad,a,b,30);
    ///afisare(join(a,b));
    ///rad = reuniune(a,b);
    ///dezalocare(rad);
    ///cout<<*minim(rad);
    ///cout<<*maxim(rad);
//dezalocare(a);
//dezalocare(b);
return 0;
}
