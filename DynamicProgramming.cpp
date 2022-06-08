// DynamicProgramming.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0)), path(n + 1, vector<ll>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];

		}
	}

	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll p = numeric_limits<ll>::max();
			if (i - 1 > 0 && j - 1 > 0)p = path[i - 1][j - 1];
			if (i - 1 > 0)p = min(p, path[i - 1][j]);
			if (j - 1 > 0)p = min(p, path[i][j - 1]);
			if (p == numeric_limits<ll>::max())p = 0;

			path[i][j] = p + a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << path[i][j] << " ";

		}cout << endl;
	}

	cout << path[n][m] << endl;

}

/*
5 5
1 56 87 541 10
1 1 50 60 54
3 0 2 65 98
121 0 0 1 65
157 98 0 0 1



*/