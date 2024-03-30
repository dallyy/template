class TreeAncestor {
    vector<vector<int>> pa;
public:
    TreeAncestor(int n, vector<int>& parent) {
 int m = 32 - __builtin_clz(n); // n 的二进制长度

        pa.resize(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)

            pa[i][0] = parent[i];

        for (int i = 0; i < m - 1; i++)

            for (int x = 0; x < n; x++)

                if (int p = pa[x][i]; p != -1)

                    pa[x][i + 1] = pa[p][i];

    }
    
    int getKthAncestor(int node, int k) {
for (; k && node != -1; k &= k - 1) // 也可以写成 ~node
            node = pa[node][__builtin_ctz(k)];
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
 
 //https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/description/
 //最近公共祖先模板
class TreeAncestor {

    vector<int> depth;

    vector<vector<int>> pa;

public:

    TreeAncestor(vector<pair<int, int>> &edges) {

        int n = edges.size() + 1;

        int m = 32 - __builtin_clz(n); // n 的二进制长度

        vector<vector<int>> g(n);

        for (auto [x, y]: edges) { // 节点编号从 0 开始

            g[x].push_back(y);

            g[y].push_back(x);

        }



        depth.resize(n);

        pa.resize(n, vector<int>(m, -1));

        function<void(int, int)> dfs = [&](int x, int fa) {

            pa[x][0] = fa;

            for (int y: g[x]) {

                if (y != fa) {

                    depth[y] = depth[x] + 1;

                    dfs(y, x);

                }

            }

        };

        dfs(0, -1);



        for (int i = 0; i < m - 1; i++)

            for (int x = 0; x < n; x++)

                if (int p = pa[x][i]; p != -1)

                    pa[x][i + 1] = pa[p][i];

    }



    int get_kth_ancestor(int node, int k) {

        for (; k; k &= k - 1)

            node = pa[node][__builtin_ctz(k)];

        return node;

    }



    // 返回 x 和 y 的最近公共祖先（节点编号从 0 开始）

    int get_lca(int x, int y) {

        if (depth[x] > depth[y])

            swap(x, y);

        // 使 y 和 x 在同一深度

        y = get_kth_ancestor(y, depth[y] - depth[x]);

        if (y == x)

            return x;

        for (int i = pa[x].size() - 1; i >= 0; i--) {

            int px = pa[x][i], py = pa[y][i];

            if (px != py) {

                x = px;

                y = py;

            }

        }

        return pa[x][0];

    }

};

 
