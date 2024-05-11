class Solution {
    vector<int>to_sort(int k,vector<vector<int>>matx){
        vector<int>order,p(k,0);
        vector<vector<int>>g(k);
        for(auto &k:matx){
            int x=k[0]-1,y=k[1]-1;
            p[y]++;
            g[x].push_back(y);
        }
        queue<int>q;
        for(int i=0;i<k;++i)if(!p[i])q.emplace(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            order.push_back(x);
            for(int k:g[x]) if(--p[k]==0)q.push(k);
        }
        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>ans(k,vector<int>(k));
        auto row=to_sort(k,rowConditions),col=to_sort(k,colConditions);
        if(row.size()<k||col.size()<k)return{};
        vector<int>pos(k);
        for(int i=0;i<k;++i)pos[col[i]]=i;
        for(int i=0;i<k;++i) ans[i][pos[row[i]]]=row[i]+1;
        return ans;
    }
};
//https://leetcode.cn/problems/build-a-matrix-with-conditions/?envType=problem-list-v2&envId=188q2gjJ
