class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int htop = 0;
        int hbottom = matrix.size() - 1;

        int ncol = matrix[0].size() - 1;

        while (htop <= hbottom) {
            int hmid = htop + (hbottom - htop)/2;

            if (matrix[hmid][0] <= target && target <= matrix[hmid][ncol]) {
                int left = 0;
                int right = ncol;

                while (left <= right) {
                    int mid = left + (right - left)/2;

                    if (matrix[hmid][mid] == target)
                       return true;
                    else if (matrix[hmid][mid] < target)
                       left = mid + 1;
                    else 
                       right = mid - 1;
                }

                return false;

            }
            else if (target > matrix[hmid][ncol]) {
                htop = hmid + 1;
            }
            else {
                hbottom = hmid - 1;
            }
        }
        return false;
    }
};
