
// Dijkstra�㷨
class Graph {

    vector<vector<pair<int, int>>> g; // �ڽӱ�

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

        // dis[i] ��ʾ����� start ���������ڵ� i �����·����

        vector<int> dis(g.size(), INT_MAX);

        dis[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.emplace(0, start);

        while (!pq.empty()) {

            auto [d, x] = pq.top();

            pq.pop();

            if (x == end) { // ���������㵽�յ�����·����

                return d;

            }

            if (d > dis[x]) { // x ֮ǰ���ѹ�����������ھӵ����·

                continue;

            }

            for (auto &[y, w] : g[x]) {

                if (d + w < dis[y]) {

                    dis[y] = d + w; // �������·����

                    pq.push({dis[y], y});

                }

            }

        }

        return -1; // �޷������յ�

    }

};
//Floyd �㷨
class Graph {

    const int INF = INT_MAX / 3;

    vector<vector<int>> f;

public:

    Graph(int n, vector<vector<int>> &edges) : f(n, vector<int>(n, INF)) {

        for (int i = 0; i < n; i++) {

            f[i][i] = 0;

        }

        for (auto &e : edges) {

            f[e[0]][e[1]] = e[2]; // ���һ���ߣ���Ŀ��֤û���رߺ��Ի���

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

        if (w >= f[x][y]) { // �������

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

