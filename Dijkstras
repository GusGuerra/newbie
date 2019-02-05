vector < pair <int, int > > g[MAXN];
int dist[MAXN];

void dijkstra(int s) {

    memset(dist, INF, sizeof dist);
    
    priority_queue < pair < int, int > > pq;
    
    dist[s] = 0;
    
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int x = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if (d > dist[x]) continue;

        for (int i = 0 ; i < g[x].size() ; i++) {
            int y = g[x][i].first;
            int nd = g[x][i].second + d;

            if (dist[y] > nd) {
                dist[y] = nd;
                pq.push(make_pair(-nd, y));
            }
        }
    }
}
