class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int sum1 = 1, sum2 = 1, len = A.size();
        vector<int> res(A.size(), 1);
        // 两边下手，使得时间复杂度变为O(n)
        for(int i = 1; i < A.size(); i++)
        {
            sum1 *= A[i - 1];
            sum2 *= A[len - i];
            res[i] *= sum1;
            res[len - i - 1] *= sum2;
        }
        return res;
    }
};