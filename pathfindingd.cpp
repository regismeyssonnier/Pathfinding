#include <iostream>
using namespace std;
#include <queue> 
#include <vector>
#include <limits>

int MAXG = 6;
vector<vector<pair<int,int>>> adj(MAXG);
vector<vector<int>> path(MAXG);

void Create_Graph(){
    adj[0].push_back({7, 1});
    adj[0].push_back({9, 2});
    adj[0].push_back({14, 5});
    
    adj[1].push_back({7, 0});
    adj[1].push_back({10, 2});
    adj[1].push_back({15, 3});
    
    adj[2].push_back({9, 0});
    adj[2].push_back({10, 1});
    adj[2].push_back({11, 3});
    adj[2].push_back({2, 5});
    
    adj[3].push_back({15, 1});
    adj[3].push_back({11, 2});
    adj[3].push_back({6, 4});
    
    adj[4].push_back({6, 3});
    adj[4].push_back({9, 5});
    
    adj[5].push_back({14, 0});
    adj[5].push_back({2, 2});
    adj[5].push_back({9, 4});
    
}
void Pathfinding(int x){
    
    int n = MAXG;
    
    int distance[n];
    priority_queue<pair<int, int>> q;
    vector<bool> processed(n, false);
    vector<vector<int>> node(n);
    vector<int>par(n, -1);
    
    for (int i = 0; i < n; i++) distance[i] = numeric_limits<int>::max();
    distance[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        
        for (auto u : adj[a]) {
        
            int b = u.second, w = u.first;
           
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
                par[b] = a;
            
                
            }
           
        }
      
    }
    
    
    
    int j = 0;
    while(j < n){
        
        int i = j;
        while(true){
            path[j].push_back(par[i]);
            i = par[i];
            if(i == x || i == -1)break;
        }
        
        j++;
    }
    
    cout << "Path : " << endl;
    for(int i = 0;i < n;i++){
        cout << i << " : ";
        for(int j = 0;j < path[i].size();j++){
            cout << path[i][j] << " " ;
        }cout << endl;
    }
    
        
    cout << "Distance : " << endl;
    for (int i = 0; i < n; i++){
        cout << i << " to " << x  << " : "<< distance[i]<<endl;
        
        
    }
    
    for(int j = 0;j < par.size();j++){
            cout << " <- " << par[j]; 
    }
    
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	Create_Graph();
	Pathfinding(4);
	
	
	return 0;
}
