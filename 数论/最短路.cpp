
// Dijkstra算法
class Graph {

    vector<vector<pair<int, int>>> g; // 邻接表

public:

    Graph(int n, vector<vector<int>> &edges) : g(n) {

        for (auto &e : edges) {

            g[e[0]].emplace_back(e[1], e[2]);

        }

    }



    void addEdge(vector<int> e) {

        g[e[0]].emplace_back(e[1], e[2]);

    }



    int shortestPath(int start, int end) {

        // dis[i] 表示从起点 start 出发，到节点 i 的最短路长度

        vector<int> dis(g.size(), INT_MAX);

        dis[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.emplace(0, start);

        while (!pq.empty()) {

            auto [d, x] = pq.top();

            pq.pop();

            if (x == end) { // 计算出从起点到终点的最短路长度

                return d;

            }

            if (d > dis[x]) { // x 之前出堆过，无需更新邻居的最短路

                continue;

            }

            for (auto &[y, w] : g[x]) {

                if (d + w < dis[y]) {

                    dis[y] = d + w; // 更新最短路长度

                    pq.push({dis[y], y});

                }

            }

        }

        return -1; // 无法到达终点

    }

};
//Floyd 算法
class Graph {

    const int INF = INT_MAX / 3;

    vector<vector<int>> f;

public:

    Graph(int n, vector<vector<int>> &edges) : f(n, vector<int>(n, INF)) {

        for (int i = 0; i < n; i++) {

            f[i][i] = 0;

        }

        for (auto &e : edges) {

            f[e[0]][e[1]] = e[2]; // 添加一条边（题目保证没有重边和自环）

        }

        for (int k = 0; k < n; k++) {

            for (int i = 0; i < n; i++) {

                if (f[i][k] == INF) continue;

                for (int j = 0; j < n; j++) {

                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

                }

            }

        }

    }



    void addEdge(vector<int> e) {

        int x = e[0], y = e[1], w = e[2], n = f.size();

        if (w >= f[x][y]) { // 无需更新

            return;

        }

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                f[i][j] = min(f[i][j], f[i][x] + w + f[y][j]);

            }

        }

    }



    int shortestPath(int start, int end) {

        int ans = f[start][end];

        return ans < INF ? ans : -1;

    }

};

