#include "dijkstras.h"
struct compare{
    bool operator()(const pair<int,int> & x, const pair<int,int> & y) const {
        return x.second > y.second;
    }
};
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> minHeap;
    minHeap.push({source,0});
    while(!minHeap.empty()){
        int u = minHeap.top().first;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(Edge edge : G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    int next = destination;
    if(distances[destination] == INF)
        return path;
    for(int i = 0; next != -1; ++i){
        path.push_back(next);
        next = previous[next];
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    for(int i : v)
        cout << i << " ";
    cout << endl;
    cout << "Total cost is " << total << endl;
}