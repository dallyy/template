
//01����
void test_1_wei_bag_problem()

{

    vector<int> weight = {1, 3, 4};

    vector<int> value = {15, 20, 30};

    int bagWeight = 4;



    // ��ʼ��

    vector<int> dp(bagWeight + 1, 0);

    for (int i = 0; i < weight.size(); i++)

    { // ������Ʒ

        for (int j = bagWeight; j >= weight[i]; j--)

        {                                                     // ������������(һ��Ҫ����)

            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); //��ȡ����ȡ��i��

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
//https://leetcode.cn/problems/coin-change/description/����ȫ����
class Solution {
public:
int coinChange(vector<int> &coins, int amount)
{
    vector<long long> dp(amount + 1, INT_MAX); //��dp����ÿ��λ�ø���ֵΪINT_MAX��Ϊ������ж��Ƿ�������amount,Ҫ��long long ����
    dp[0] = 0;  //dp[i]:������ֵi���õ���С����
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
//https://leetcode.cn/problems/combination-sum-iv/submissions/519727465/ ��ϱ���
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
