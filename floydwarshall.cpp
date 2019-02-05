//All pairs shortest path on weighted graphs
// w/ positive or negative weights

int n;

int dist[MAXN][MAXN];

void fw(){
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
