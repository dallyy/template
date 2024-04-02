//https://leetcode.cn/problems/sum-of-distances-in-tree/

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
         vector<vector<int>>g(n);
         for(auto &u:edges) g[u[0]].push_back(u[1]),g[u[1]].push_back(u[0]);
         vector<int>size(n,1),ans(n,0);
         function<void(int,int,int)>dfs=[&](int x,int fa,int depth){
             ans[0]+=depth;
             for(int y:g[x]){
                 if(y!=fa){
                     dfs(y,x,depth+1);
                    size[x]+=size[y];
                 }
             }
         };
         dfs(0,-1,0);
         function<void(int,int)>dfs1=[&](int x,int fa){
             for(int y:g[x]){
                 if(y!=fa) {
                     ans[y]=ans[x]+n-2*size[y];
                     dfs1(y,x);
                 }
             }
         };
         dfs1(0,-1);
         return ans;
    }
};
