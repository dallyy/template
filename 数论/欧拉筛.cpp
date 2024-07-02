std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
//python3
https://leetcode.cn/problems/maximum-prime-difference/
MX = 101
not_prime = [True, True] + [False] * (MX - 2)
for i in range(2, isqrt(MX) + 1):
    if not_prime[i]: continue
    for j in range(i * i, MX, i):
        not_prime[j] = True  # j 是质数 i 的倍数

class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        i = 0
        while not_prime[nums[i]]:
            i += 1
        j = len(nums) - 1
        while not_prime[nums[j]]:
            j -= 1
        return j - i

