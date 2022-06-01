// FloydWarshall.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

using namespace std;


const int MAXG = 6;
vector<vector<int>> adj(MAXG, vector<int>(MAXG, 0));
vector<vector<int>> path(MAXG);

void Create_Graph() {
    adj[0][1] = 7;
    adj[0][2] = 9;
    adj[0][5] = 14;

    adj[1][0] = 7;
    adj[1][2] = 10;
    adj[1][3] = 15;

    adj[2][0] = 9;
    adj[2][1] = 10;
    adj[2][3] = 11;
    adj[2][5] = 2;

    adj[3][1] = 15;
    adj[3][2] = 11;
    adj[3][4] = 6;

    adj[4][3] = 6;
    adj[4][5] = 9;

    adj[5][0] = 14;
    adj[5][2] = 2;
    adj[5][4] = 9;

}


void FloydWarshall(int x) {

    int distance[MAXG][MAXG];
    int n = MAXG;
    vector<int>par(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) distance[i][j] = 0;
            else if (adj[i][j]) distance[i][j] = adj[i][j];
            else distance[i][j] = 1000000;
        }
    }

    for (int k =0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j =0; j < n; j++) {
                distance[i][j] = min(distance[i][j],distance[i][k] + distance[k][j]);
                
            }
        }
    }

 


    cout << "Distance : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //int d = distance[i][j]
            cout << i << " to " << j << " : " << distance[i][j] << endl;
        }

    }

  

}


int main()
{
    Create_Graph();
    FloydWarshall(4);

}

