#include <iostream>
#include <vector>

using namespace std;

void dfs(int vertex, vector< vector< int >>& graph, vector< int >& is_visited) {
    is_visited[vertex] = 1;
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (!is_visited[graph[vertex][i]]) {
            dfs(graph[vertex][i], graph, is_visited);
        }
    }
}


int main() {
    int vertexes_number;
    int start_vertex;
    cin >> vertexes_number >> start_vertex;

    vector< vector< int >> graph(vertexes_number);
    for (int i = 0; i < vertexes_number; i++) {
        for (int j = 0; j < vertexes_number; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                graph[i].push_back(j);
            }
        }
    }

    vector< int > is_visited(vertexes_number);
    dfs(start_vertex - 1, graph, is_visited);
    int result = 0;
    for (int i = 0; i < vertexes_number; i++) {
        result += is_visited[i];
    }
    cout << result << endl;
}
