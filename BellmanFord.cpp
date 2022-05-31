// BellmanFord.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

const int MAXG = 6;

vector<tuple<int, int, int>> edges;
vector<vector<int>> path(MAXG);

void Create_Graph() {

	edges.push_back({ 0, 1, 7});
	edges.push_back({ 0, 2, 9 });
	edges.push_back({ 0, 5, 14 });

	edges.push_back({ 1, 0, 7 });
	edges.push_back({ 1, 2, 10 });
	edges.push_back({ 1, 3, 15 });

	edges.push_back({ 2, 0, 9 });
	edges.push_back({ 2, 1, 10 });
	edges.push_back({ 2, 3, 11 });
	edges.push_back({ 2, 5, 2 });

	edges.push_back({ 3, 1, 15 });
	edges.push_back({ 3, 2, 11 });
	edges.push_back({ 3, 4, 6 });

	edges.push_back({ 4, 3, 6 });
	edges.push_back({ 4, 5, 9 });

	edges.push_back({ 5, 0, 14 });
	edges.push_back({ 5, 2, 2 });
	edges.push_back({ 5, 4, 9 });

}


void BellmanFord(int x) {

	int distance[MAXG];
	int n = MAXG;
	vector<int>par(n, -1);

	for (int i = 0; i < n; i++) distance[i] = 1000000;// numeric_limits<int>::max();
	distance[x] = 0;
	for (int i = 0; i < n - 1; i++) {
	
		for (const auto &e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			//cout << a << " " << b << " " << w << endl;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				par[b] = a;
			}
		}
	}

	int j = 0;
	while (j < n) {

		int i = j;
		while (true) {
			path[j].push_back(par[i]);
			i = par[i];
			if (i == x || i == -1)break;
		}

		j++;
	}

	cout << "Path : " << endl;
	for (int i = 0; i < n; i++) {
		cout << i << " : ";
		for (int j = 0; j < path[i].size(); j++) {
			cout << path[i][j] << " ";
		}cout << endl;
	}


	cout << "Distance : " << endl;
	for (int i = 0; i < n; i++) {
		cout << i << " to " << x << " : " << distance[i] << endl;


	}

	for (int j = 0; j < par.size(); j++) {
		cout << " <- " << par[j];
	}


}

int main()
{
	Create_Graph();
	BellmanFord(4);


 
}

