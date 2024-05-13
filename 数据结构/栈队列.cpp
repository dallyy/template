// 使用栈实现队列
// 同时维护滑动窗口的信息
// 可维护任意满足结合律的信息
// 所有操作（均摊）进行 $O(1)$ 次运算

template<typename T, typename Op, typename Alloc = std::allocator<T>>
class Queue {
public:
    using value_type = T;
    using size_type = unsigned;

private:
    Op op;
    value_type in_stk_sum;
    std::vector<value_type, Alloc> in_stk, out_stk;

public:
    Queue(const Op& op = {}) : op(op) {}

    template<typename U>
    void push(U&& val) {
        in_stk_sum = !in_stk.empty() ? op(in_stk_sum, val) : val;
        in_stk.emplace_back(std::forward<U>(val));
    }

    void pop() {
        if (!out_stk.empty())
            out_stk.pop_back();
        else {
            if (in_stk.size() > 1) {
                const auto ptr = in_stk.data();
                auto it = ptr + in_stk.size() - 1;
                out_stk.push_back(std::move(*it));
                while (--it != ptr) out_stk.push_back(op(std::move(*it), out_stk.back()));
            }
            in_stk.clear();
        }
    }

    value_type sum() const noexcept {
        if (in_stk.empty()) return out_stk.back();
        if (out_stk.empty()) return in_stk_sum;
        return op(out_stk.back(), in_stk_sum);
    }

    size_type size() const noexcept {
        return in_stk.size() + out_stk.size();
    }

    bool empty() const noexcept {
        return in_stk.empty() && out_stk.empty();
    }
};
//https://leetcode.cn/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/?envType=problem-list-v2&envId=188q2gjJ
class Solution {
public:
    int minOperations(const vector<int>& nums) {
        const int n = nums.size(), c = count(nums.begin(), nums.end(), 1);
        if (c != 0) return n - c;
        const auto f = [] (int x, int y) { return gcd(x, y); };
        const int d = reduce(nums.begin(), nums.end(), 0, f);
        if (d != 1) return -1;
        int len = INT_MAX;
        Queue<int, decltype(f)> q(f);
        for (int i = 0, j = 0;i < n;++i) {
            q.push(nums[i]);
            if (q.sum() == 1) {
                do {
                    ++j;
                    q.pop();
                } while (!q.empty() && q.sum() == 1);
                len = min(len, i - j);
            }
        }
        return len + n;
    }
};
