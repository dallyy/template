struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
//https://leetcode.cn/problems/largest-component-size-by-common-factor/?envType=list&envId=188q2gjJ
constexpr int mx = 1e5;
int d[mx+1]{},sr[mx+1],ind[mx+1],j=0,ans;
vector<int>pre;
int _=[](){
for(int i=2;i<=mx;++i){
    if(d[i]==0)d[i]=i,pre.emplace_back(i);
    for(int k=0;k<pre.size()&&i<=mx/pre[k];++k){
        d[pre[k]*i]=pre[k];
        if(i%pre[k]==0)break;
    }
}
return 0;
}();
class Solution {
    int find(int x) {
    return x==ind[x]?x:find(ind[x]);
}
void unit(int x,int y){
    int a=find(x),b=find(y);
    if(a==b)return;
    if(sr[a]<sr[b]) swap(a,b);  
    ind[b]=a;
    sr[a]+=sr[b];
    ans=max(ans,sr[a]);
    return;
}
public:
    int largestComponentSize(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end())+1;
        iota(ind,ind+m,0);
        memset(sr,0,sizeof sr);
        ans=1;
        for(int x:nums) sr[x]=1;
        for(int xx:nums){
            int t=xx;
            while(t>1){
                unit(xx,d[t]);
                t/=d[t];
            }
        }
        return ans;
    }
};
//https://leetcode.cn/problems/minimum-cost-walk-in-weighted-graph/
class Solution {
public:
    int f[100005];
    int val[100005];
    int find(int x){
        if(f[x] == x) return x;
        else return f[x] = find(f[x]);
    }
    
    void Union(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        f[y] = x;
        val[x] &= val[y];
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        int m = edges.size();
        for(int i=0;i<n;i++){
            f[i] = i;
            val[i] = (1<<30) - 1;
        }
        
        for(auto e:edges){
            int u = e[0], v = e[1], w = e[2];
            Union(u,v);
            u = find(u);
            val[u] &= w;
        }
        
        for(auto q:query){
            int x = q[0], y = q[1];
            if(x == y){
                ans.push_back(0);
                continue;
            }
            
            x = find(x);
            y = find(y);
            if(x != y){
                ans.push_back(-1);
                continue;
            }
            
            ans.push_back(val[x]);
        }
        return ans;
    }
};


