class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int first = rotateArray[0], l = 0, r = rotateArray.size()-1;
        int m ;
        while(l<r)
        {
            m = l + (r-l)/2;
            if(m == 0 || rotateArray[m] < rotateArray[m-1])
                return rotateArray[m];
            else if(rotateArray[m] > first)
                l = m+1;
            else
                r = m-1;
        }
        return rotateArray[l];
    }
};