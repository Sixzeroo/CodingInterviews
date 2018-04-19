class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res = INT_MIN;
        int sum = 0;
        // 通过数组的规律找连续最大和
        for(int i = 0; i < array.size(); i++)
        {
            sum = sum <= 0?array[i] : sum + array[i];
            res = max(res, sum);
        }
        return res;
    }
};