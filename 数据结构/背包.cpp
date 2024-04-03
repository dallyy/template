
//01背包
void test_1_wei_bag_problem()

{

    vector<int> weight = {1, 3, 4};

    vector<int> value = {15, 20, 30};

    int bagWeight = 4;



    // 初始化

    vector<int> dp(bagWeight + 1, 0);

    for (int i = 0; i < weight.size(); i++)

    { // 遍历物品

        for (int j = bagWeight; j >= weight[i]; j--)

        {                                                     // 遍历背包容量(一定要逆序)

            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); //不取或者取第i个

        }

    }

    cout << dp[bagWeight] << endl;

}
//https://leetcode.cn/problems/target-sum/description/
int findTargetSumWays(vector<int> &nums, int s)

{

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if ((sum + s) % 2 != 0 || sum < s)

        return 0;

    int target = (sum + s) / 2;

    vector<int> dp(target + 1);

    dp[0] = 1;

    for (int num : nums)

        for (int i = target; i >= num; i--)

            dp[i] += dp[i - num];

    return dp[target];

}
//https://leetcode.cn/problems/coin-change/description/，完全背包
class Solution {
public:
int coinChange(vector<int> &coins, int amount)
{
    vector<long long> dp(amount + 1, INT_MAX); //给dp数组每个位置赋初值为INT_MAX是为了最后判断是否能填满amount,要用long long 类型
    dp[0] = 0;  //dp[i]:换到面值i所用的最小数量
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

};
//https://leetcode.cn/problems/combination-sum-iv/submissions/519727465/ 组合背包
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
