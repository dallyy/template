class Solution {
    // lower_bound ������С������ nums[i] >= target �� i
    // �������Ϊ�գ������������� < target���򷵻� nums.size()
    // Ҫ�� nums �Ƿǵݼ��ģ��� nums[i] <= nums[i + 1]

    // ������д��
    int lower_bound(vector<int> &nums, int target) {
        int left = 0, right = (int) nums.size() - 1; // ������ [left, right]
        while (left <= right) { // ���䲻Ϊ��
            // ѭ����������
            // nums[left-1] < target
            // nums[right+1] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // ��Χ��С�� [mid+1, right]
            } else {
                right = mid - 1; // ��Χ��С�� [left, mid-1]
            }
        }
        return left;
    }

    // ����ҿ�����д��
    int lower_bound2(vector<int> &nums, int target) {
        int left = 0, right = nums.size(); // ����ҿ����� [left, right)
        while (left < right) { // ���䲻Ϊ��
            // ѭ����������
            // nums[left-1] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // ��Χ��С�� [mid+1, right)
            } else {
                right = mid; // ��Χ��С�� [left, mid)
            }
        }
        return left; // ���� left ���� right ���У���Ϊѭ�������� left == right
    }

    // ������д��
    int lower_bound3(vector<int> &nums, int target) {
        int left = -1, right = nums.size(); // ������ (left, right)
        while (left + 1 < right) { // ���䲻Ϊ��
            // ѭ����������
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid; // ��Χ��С�� (mid, right)
            } else {
                right = mid; // ��Χ��С�� (left, mid)
            }
            // Ҳ��������д
            // (nums[mid] < target ? left : right) = mid;
        }
        return right;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target); // ʹ������һ��д������
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1}; // nums ��û�� target
        }
        // ��� start ���ڣ���ô end �ض�����
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};

