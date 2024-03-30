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
 
