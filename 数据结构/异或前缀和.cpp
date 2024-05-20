class Solution {
    const int D = 10; // s �е��ַ�������
public:
    int longestAwesome(string s) {
        int n = s.size();
        vector<int> pos(1 << D, INT_MAX); // n ��ʾû���ҵ����ǰ׺��
        pos[0] = -1; // pre[-1] = 0
        int ans = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            pre ^= 1 << (s[i] - '0');
            for (int d = 0; d < D; d++) {
                ans = max(ans, i - pos[pre ^ (1 << d)]); // ����
            }
          if((i-pos[pre])%2==0)  ans = max(ans, i - pos[pre]); // ż��
            if (pos[pre] == INT_MAX) { // �״�����ֵΪ pre ��ǰ׺���ͣ���¼���±� i
                pos[pre] = i;
            }
        }
        return ans;
    }
};
//https://leetcode.cn/problems/find-longest-awesome-substring/description/
