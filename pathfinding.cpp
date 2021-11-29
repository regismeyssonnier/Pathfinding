// Dijkstra.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;
#include <vector>


const int N = 100;
int SG[N][N], SG2[N][N];
int P[N][N];
int RS[N];
 
int S_depart;
int S_fin;

struct Sommet {

    vector<Sommet*> voisin;
    int num;
    bool mark;

};

vector<Sommet*> G, G2;
vector<int> G3;

const int TG = 6;

void Display_SG(int I) {

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < TG;j++) {
            cout << SG[i][j] << " ";
        }
        cout << endl;
    }

}

void Display_SG2(int I) {

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < TG; j++) {
            cout << SG2[i][j] << " ";
        }
        cout << endl;
    }

}

void Init_SG() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            SG[i][j] = -1; SG2[i][j] = -1;
            P[i][j] = -1;
        }
    }
}

void Init_G() {

    for (int i = 0; i < TG; i++) {
        Sommet* s = new Sommet();
        s->num = i;
        s->mark = false;
        G.push_back(s);
    }

    for (int i = 0; i < TG; i++) {
        RS[i] = -1;
    }
    
    //1 2 5
    G[0]->voisin.push_back(G[1]);
    G[0]->voisin.push_back(G[2]);
    G[0]->voisin.push_back(G[5]);
    P[0][1] = 7;
    P[0][2] = 9;
    P[0][5] = 14;

    // 0 2 3
    G[1]->voisin.push_back(G[0]);
    G[1]->voisin.push_back(G[2]);
    G[1]->voisin.push_back(G[3]);
    P[1][0] = 7;
    P[1][2] = 10;
    P[1][3] = 15;

    // 0 1 3 5
    G[2]->voisin.push_back(G[0]);
    G[2]->voisin.push_back(G[1]);
    G[2]->voisin.push_back(G[3]);
    G[2]->voisin.push_back(G[5]);
    P[2][0] = 9;
    P[2][1] = 10;
    P[2][3] = 11;
    P[2][5] = 2;

    //  1 2 4
    G[3]->voisin.push_back(G[1]);
    G[3]->voisin.push_back(G[2]);
    G[3]->voisin.push_back(G[4]);
    P[3][1] = 15;
    P[3][2] = 11;
    P[3][4] = 6;

    //  3 5
    G[4]->voisin.push_back(G[3]);
    G[4]->voisin.push_back(G[5]);
    P[4][3] = 6;
    P[4][5] = 9;
  
    //  0 2 4
    G[5]->voisin.push_back(G[0]);
    G[5]->voisin.push_back(G[2]);
    G[5]->voisin.push_back(G[4]);
    P[5][0] = 14;
    P[5][2] = 2;
    P[5][4] = 9;

    SG[0][0] = 0;
    S_depart = 0;
    S_fin = 4;

}


int main()
{
    std::cout << "Hello World!\n";



    Init_SG();
    Init_G();

    int sommet = S_depart;
    int I = 1, R = 0, C = 0;
    bool stop = false;

    int distance = 0;
    while (!stop) {

        int min = 1000000;
        
        //update distance
        for (int i = 0; i < G[sommet]->voisin.size(); i++) {
            
            if ((G[sommet]->voisin[i]->num == S_fin) && (distance == 0)) {
                R = S_fin;
                SG2[I][G[sommet]->voisin[i]->num] = sommet;
               
                break;
            }
            else if (!G[sommet]->voisin[i]->mark) {
                if (SG[I][G[sommet]->voisin[i]->num] == -1) {
               
                   SG[I][G[sommet]->voisin[i]->num] = P[G[sommet]->num][G[sommet]->voisin[i]->num]+ SG[I-1][G[sommet]->num];
                   SG2[I][G[sommet]->voisin[i]->num] = sommet;
                }
                else {
                    if ((P[G[sommet]->num][G[sommet]->voisin[i]->num] + SG[I - 1][G[sommet]->num]) <
                        SG[I][G[sommet]->voisin[i]->num]) {
                        SG[I][G[sommet]->voisin[i]->num] = P[G[sommet]->num][G[sommet]->voisin[i]->num] + SG[I - 1][G[sommet]->num];
                        SG2[I][G[sommet]->voisin[i]->num] = sommet;
                        
                    }

                }

                if (SG[I][G[sommet]->voisin[i]->num] < min) {
                    min = SG[I][G[sommet]->voisin[i]->num];
                    R = G[sommet]->voisin[i]->num;
                }

            }
            
            

        }

        G[sommet]->mark = true;
        distance++;
        G3.push_back(G[sommet]->num);
       
        I++;
        min = 1000000;
        int r = 0;
        for (int i = 0; i < TG; i++) {
            if ((!G[i]->mark) && (i != R)) {
                SG[I][i] = SG[I - 1][i];
                SG2[I][i] = SG2[I - 1][i];
            }

            if (SG2[I - 1][i] != -1) {
                RS[i] = SG2[I - 1][i];
            }
            
           /* if ((SG[I - 1][i] < min) && (SG[I - 1][i] != -1)) {
                min = SG[I-1][i];
                r = i;
            }*/

        }

                    
        
        //Display_SG(I);

        if (G[sommet]->num == S_fin) {
            stop = true;
            break;
        }

        

        sommet = R;


    }


    /*for (int i = 0; i < G3.size(); i++) {
        cout << G3[i] << endl;
    }*/

      
    sommet = S_fin;
    G3.clear();
    G3.push_back(sommet);
  
  
    while (true) {
        int s = RS[sommet];
      
        G3.push_back(s);
        sommet = s;
        if (sommet == S_depart)
            break;

    }

   
    /*for (int i = 0; i < TG; i++) {
        cout << "rs-" <<  RS[i] << " ";
    }
    cout << endl;*/
        
    cout <<"-------" << endl;
    for (int i = G3.size()-1; i >= 0; i--) {
        cout << G3[i] << endl;
    }
    cout << "-------" << endl;
   /* Display_SG2(I);

    for (int i = 0; i < G.size(); i++) {
        delete G[i];
    }*/
    

}

