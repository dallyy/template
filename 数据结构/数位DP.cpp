class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), memo[n][2];
        memset(memo, -1, sizeof(memo)); // -1 表示还没有计算过
        function<int(int, bool)> dfs = [&](int i, bool hold) -> int {
            if (i < 0) return hold ? INT_MIN : 0;
            int &res = memo[i][hold];
            if (res != -1) return res; // 之前计算过
            if (hold) return res = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i]);
            return res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
        };
        return dfs(n - 1, false);
    }
};
//https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/description/
class Solution {
public:
    int findIntegers(int n) {
auto s=bitset<32>(n).to_string();
int m=s.size(),f[m][2];
memset(f,-1,sizeof f);
function<int(int ,bool ,bool)>dfs=[&](int i,bool pre,bool limit){
    if(i==m)return 1;
    if(!limit&&f[i][pre]>0)return f[i][pre];
    int res=0,up=limit?s[i]-'0':1;
    for(int d=0;d<=up;++d) {
        if(pre&&d==1)continue;
        res+=dfs(i+1,d==1,limit&&d==up);
    }
    if(!limit) f[i][pre]=res;;
    return res;
};
return dfs(0,false,true);
    }
};
//https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        int m = s.length(), memo[m][1 << 10];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m)
                return is_num; // is_num 为 true 表示得到了一个合法数字
            if (!is_limit && is_num && memo[i][mask] != -1)
                return memo[i][mask];
            int res = 0;
            if (!is_num) // 可以跳过当前数位
                res = f(i + 1, mask, false, false);
            int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
                if ((mask >> d & 1) == 0) // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            if (!is_limit && is_num)
                memo[i][mask] = res;
            return res;
        };
        return n - f(0, 0, true, false);
    }
};
//https://leetcode.cn/problems/numbers-with-repeated-digits/?envType=problem-list-v2&envId=188q2gjJ
