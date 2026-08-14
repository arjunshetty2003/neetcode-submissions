class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m -1;

        while (top <= bottom) {
            int vmid = top + (bottom - top) / 2;
            int left = 0;
            int right = n - 1;

            if (matrix[vmid][left] <= target && target <= matrix[vmid][right]) {
                while (left <= right) {
                    int hmid = left + (right - left) / 2;
                    if (matrix[vmid][hmid] == target)
                        return true;
                    else if (matrix[vmid][hmid] < target)
                        left = hmid + 1;
                    else
                        right = hmid - 1;
                }

                return false;
            }
            else if (target < matrix[vmid][left])
                bottom = vmid - 1;
            else if (matrix[vmid][right] < target)
                top = vmid + 1;
        }

        return false;
    }
};
