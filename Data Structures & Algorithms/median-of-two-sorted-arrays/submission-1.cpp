class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> referenceArray;

        int l1 = 0;
        int n1 = nums1.size();

        int l2 = 0;
        int n2 = nums2.size();

        while (l1 < n1 && l2 < n2) {
            if (nums1[l1] < nums2[l2]) {
                referenceArray.push_back(nums1[l1]);
                l1++;
            }
            else {
                referenceArray.push_back(nums2[l2]);
                l2++;
            }
        }

        while (l1 < n1) {
            referenceArray.push_back(nums1[l1]);
            l1++;
        }

        while (l2 < n2) {
            referenceArray.push_back(nums2[l2]);
            l2++;
        }

        int n = referenceArray.size();

        if (n % 2 != 0)
            return referenceArray[n / 2];

        return (referenceArray[(n / 2) - 1] + referenceArray[n / 2]) / 2.0;
    }
};
