class Solution {
private:
    int modBinSearch(vector<int> &arr, int target, int left, int right) {
        if (left > right)
            return -1;
        
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] >= arr[left]) {
            if (arr[left] <= target && target <= arr[mid])
                return modBinSearch(arr, target, left, mid - 1);
            else
                return modBinSearch(arr, target, mid + 1, right);
        }
        else {
            if (arr[mid] <= target && target <= arr[right])
                return modBinSearch(arr, target, mid + 1, right);
            else
                return modBinSearch(arr, target, left, mid - 1);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        return modBinSearch(nums, target, left, right);
    }
};
