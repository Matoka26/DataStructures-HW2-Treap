#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Nod{
public:
    int key;
    int prio;
    Nod* left;
    Nod* right;

    Nod(){
    this->key = 0 ;
    this-> prio = 0;
    this->left = NULL;
    this->right = NULL;
    }

    Nod(int key,int prio, Nod* left,Nod* right){
        this->key = key;
        this->prio = prio;
        this->left = left;
        this->right = right;
    }
    bool operator ==(const Nod& obj){
    if(this->key = key && this->prio == prio && this->left == left && this->right == right) return 1;
    return 0;
    }
    friend ostream& operator<<(ostream& out,const Nod &obj){
        Nod gol;
        if(gol == obj){out<<NULL; return out;}
        out<<endl<<'('<<obj.key<<','<<obj.prio<<')'<<endl;
        out<<"CopSt:"<<obj.left<<endl;
        out<<"CopDr:"<<obj.right<<endl;
        out<<"Adresa:"<<&obj<<endl;
        return out;
    }
};

Nod* nodNou(int key){
    Nod* nou = new Nod(key,rand()%100,NULL,NULL);
    return nou;
}
Nod* nodNou(int key,int prio){
    Nod* nou = new Nod(key,prio,NULL,NULL);
    return nou;
}


Nod* cautare(Nod* &rad , int key){
    if(rad == NULL) return NULL;
    if(rad->key == key) return rad;
    if(rad->key < key) cautare(rad->right ,key);
    else cautare(rad->left ,key);
}

Nod* rotDr(Nod* &nod){
    Nod* aux = nod->left;
    Nod* aux2 = aux->right;
    aux->right =  nod;
    nod->left = aux2;
    return aux;
}
Nod* rotSt(Nod* &nod){
    Nod* aux = nod->right;
    Nod* aux2 = aux->left;
    aux->left = nod;
    nod->right = aux2;
    return aux;
}

void afisare(Nod* rad){
    if(rad != NULL){
        cout<<*rad<<endl;
        afisare(rad->left);
        afisare(rad->right);
    }
}

void inorder(Nod* root)
{
    if (!root)
        return;

    inorder(root->left);
    cout <<'('<< root->key<<','<<root->prio<<')' << " ";
    inorder(root->right);
}
Nod* inserare(Nod* rad,int key){
    if(rad == NULL){
        rad = nodNou(key);
        return rad;
    }
    if(key <= rad->key){
        rad->left = inserare(rad->left,key);
        if(rad->left->prio > rad->prio)
            rad = rotDr(rad);
    }
    else{
        rad->right = inserare(rad->right,key);
        if(rad->right->prio > rad->prio)
            rad = rotSt(rad);
    }
    return rad;
}
Nod* inserare(Nod* rad,int key,int prio){
    if(rad == NULL){
        rad = nodNou(key,prio);
        return rad;
    }
    if(key <= rad->key){
        rad->left = inserare(rad->left,key,prio);
        if(rad->left->prio > rad->prio)
            rad = rotDr(rad);
    }
    else{
        rad->right = inserare(rad->right,key,prio);
        if(rad->right->prio > rad->prio)
            rad = rotSt(rad);
    }
    return rad;
}
Nod* build(int v[], int n){
    if (n == 0)
        return NULL;
    Nod* rad = NULL;

    for (int i = 0; i < n; i++)
        rad = inserare(rad, v[i],rand()%100);

    return rad;
}
Nod* minim(Nod* &rad){
    if(rad->left != NULL)
        return minim(rad->left);
    else
        return rad;
}
Nod* maxim(Nod* &rad){
    if(rad->right != NULL)
        return maxim(rad->right);
    else
        return rad;
}

Nod* stergere(Nod* &nod,int key){
    if(nod == NULL) return NULL;    //arborele e gol

    if(key < nod->key)                 //caut keya
        nod->left = stergere(nod->left , key);
    else if(key > nod->key)
        nod->right = stergere(nod->right , key);

    else if(key == nod->key){            //am gasit keya
        if(nod->left ==NULL){           //n are copil in stanga,il ridic pe ala din dreapta
            Nod* aux = nod->right;
            delete nod;
            nod = aux;
        }
        else if(nod->right == NULL){    //n are copil in dreapta,il ridic pe ala din stanga
            Nod* aux = nod->left;
            delete nod;
            nod = aux;
        }
    else if(nod->left->prio < nod->right->prio){
        nod = rotSt(nod);
        nod->left = stergere(nod->left,key);
        }
    else if(nod->right->prio <= nod->left->prio){
        nod = rotDr(nod);
        nod->right = stergere(nod->right , key);
        }
    }
    return nod;
}
Nod* dezalocare(Nod* &nod){
    if(nod != NULL){
        if(nod->left != NULL)
            dezalocare(nod->left);
        if(nod->right != NULL)
            dezalocare(nod->right);
    cout<<"cox ";
    delete nod;
    nod = NULL;
    }
}
int main()
{srand(time(nullptr));
    int vecPerechi[] = { 10,40,20,50,30,60};
    Nod* rad = build(vecPerechi,sizeof(vecPerechi)/sizeof(int));
    rad = inserare(rad,15);
    rad = inserare(rad,25,69);
    //cout<<cautare(rad,11);
    //inorder(rad);
    //cout<<*rotDr(rad->right);
    //afisare(rad);
    //cout<<*minim(rad);
    //cout<<*maxim(rad);
    //afisare(rad);
    //rad = stergere(rad,40);
    //afisare(rad);
    //inorder(rad);
    //dezalocare(rad);

}
