class Solution {
public:
	// 采用直线查找的形式
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if(m == 0) return false;
        int n = array[0].size();
        int i = 0, j = n-1;
        while(i<m && j>=0)
        {
            while(j>=0 && array[i][j] > target)
                j--;
            if(j == -1) return false;
            else if(array[i][j] == target) return true;
            while(i<m && array[i][j] < target)
                i++;
            if(i == m) return false;
            else if(array[i][j] == target) return true;    
        }
        return false;
    }
};