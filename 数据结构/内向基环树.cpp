class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size(),ans=-1;
        vector<int>time(n,0);
        for(int i=0,time_clock=1;i<n;++i){
            if(time[i]) continue;
            for(int j=i,clock=time_clock;j>=0;j=edges[j]){
                if(time[j]){
                    if(time[j]>=clock)ans=max(ans,time_clock-time[j]);
                    break;
                }
                time[j]=time_clock++;
            }
        }
        return ans;
    }
};
//https://leetcode.cn/problems/longest-cycle-in-a-graph/?envType=problem-list-v2&envId=188q2gjJ
