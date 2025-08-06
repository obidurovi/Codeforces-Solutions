#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

void dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; // Skip if we already found a better way

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<vector<Edge>> graph(n + 1);
        vector<int> horses(h);

        for (int i = 0; i < h; ++i) {
            cin >> horses[i];
        }

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Dijkstra for Marian starting from vertex 1
        vector<int> distMarian(n + 1, INF);
        dijkstra(1, graph, distMarian);

        // Dijkstra for Robin starting from vertex n
        vector<int> distRobin(n + 1, INF);
        dijkstra(n, graph, distRobin);

        // Calculate the minimum time to meet
        int minMeetingTime = INF;

        for (int horsePos : horses) {
            // Marian can ride to horsePos, then ride to any vertex
            int timeMarian = distMarian[horsePos] + distRobin[horsePos] / 2; // Robin can ride too
            if (timeMarian < minMeetingTime) {
                minMeetingTime = timeMarian;
            }
        }

        // If they can only walk, check the direct meeting time
        for (int i = 1; i <= n; ++i) {
            if (distMarian[i] != INF && distRobin[i] != INF) {
                minMeetingTime = min(minMeetingTime, max(distMarian[i], distRobin[i]));
            }
        }

        if (minMeetingTime == INF) {
            cout << -1 << '\n';
        } else {
            cout << minMeetingTime << '\n';
        }
    }

    return 0;
}
