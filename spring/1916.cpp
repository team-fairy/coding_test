#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int arr[n][n];
    int dist[n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            arr[i][j] = 0;
        dist[i] = 100000 * n;
    }

    for (int i=0; i<m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a-1][b-1] = cost;
    }
    int start, end;

    cin >> start >> end;
    dist[start-1] = 0;

    priority_queue<pair<int, int> > pq;

    pq.push(pair<int, int>(0, start-1));
    
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        int cost = -curr.first;
        int curr_node = curr.second;
        pq.pop();
        if (dist[curr_node] < cost)
            continue;
        for (int i=0; i<n; i++) {
            if (arr[curr_node][i] != 0 && cost + arr[curr_node][i] < dist[i]) {
                dist[i] = cost + arr[curr_node][i];
                pq.push(pair<int, int>(-dist[i], i));
            }
        }
    }

    printf("%d\n", dist[end-1]);

    return 0;
}