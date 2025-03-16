#include "dijkstras.h"
int main(){
    Graph small;
    Graph medium;
    Graph large;
    Graph largest;
    file_to_graph("src/small.txt", small);
    file_to_graph("src/medium.txt", medium);
    file_to_graph("src/large.txt", large);
    file_to_graph("src/largest.txt", largest);
    vector<int> previous(small.numVertices);
    for(int i = 0; i < small.numVertices; ++i){
        vector<int> result = dijkstra_shortest_path(small,0,previous);
        print_path(extract_shortest_path(result, previous, i), result[i]);
    }
    vector<int> previous1(medium.numVertices);
    for(int i = 0; i < medium.numVertices; ++i){
        vector<int> result1 = dijkstra_shortest_path(medium,0,previous1);
        print_path(extract_shortest_path(result1, previous1, i), result1[i]);
    }
    cout << "hello" << endl;
    vector<int> previous2(large.numVertices);
    for(int i = 0; i < large.numVertices; ++i){
        vector<int> result2 = dijkstra_shortest_path(large,0,previous2);
        for(int j : result2)
            cout << j << endl;
        print_path(extract_shortest_path(result2, previous2, i), result2[i]);
    }
    vector<int> previous3(largest.numVertices);
    for(int i = 0; i < largest.numVertices; ++i){
        vector<int> result3 = dijkstra_shortest_path(largest,0,previous3);
        print_path(extract_shortest_path(result3, previous3, i), result3[i]);
    }
}