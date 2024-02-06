#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector< vector< int > > graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                graph[i].push_back(j);
            }
        }
    }

    int start_vertex, finish_vertex;
    cin >> start_vertex >> finish_vertex;
    start_vertex--;
    finish_vertex--;
    vector< int > parent(n - 1);
    parent[start_vertex] = start_vertex;

    queue< int > qu;
    qu.push(start_vertex);
    while (!qu.empty()) {
        int curr_vertex = qu.front();
        qu.pop();

        for (int i = 0 ; i < graph[curr_vertex].size(); i++) {
            if (parent[graph[curr_vertex][i]] == -1) {
                parent[graph[curr_vertex][i]] = curr_vertex;
                qu.push(graph[curr_vertex][i]);
            }
        }
    }

    if (parent[finish_vertex] == -1) {
        cout << -1 << endl;
        return 0;
    }

    vector< int > result;
    int curr_vertex = finish_vertex;
    while (curr_vertex != parent[curr_vertex]) {
        result.push_back(curr_vertex);
        curr_vertex = parent[curr_vertex];
    }
    result.push_back(curr_vertex);

    cout << result.size() - 1 << endl;
    if (result.size() == 1) { return 0; }
    for (int i = result.size() - 1; i >=0; i--) {
        cout << result[i] + 1 << ' ';
    }
    cout << endl;
    return 0;

}
