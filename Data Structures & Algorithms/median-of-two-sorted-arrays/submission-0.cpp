class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = min(n1, n2);
        int m = (n1 + n2 + 1) / 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int mid2 = m - mid;

            int l1, r1, l2, r2;
            if(n1 < n2){
                l1 = (mid == 0)     ? INT_MIN : nums1[mid - 1];
                r1 = (mid >= n1)    ? INT_MAX : nums1[mid];
                l2 = (mid2 == 0)    ? INT_MIN : nums2[mid2 - 1];
                r2 = (mid2 >= n2)   ? INT_MAX : nums2[mid2];
            }
            else{
                l1 = (mid == 0)     ? INT_MIN : nums2[mid - 1];
                r1 = (mid >= n2)    ? INT_MAX : nums2[mid];
                l2 = (mid2 == 0)    ? INT_MIN : nums1[mid2 - 1];
                r2 = (mid2 >= n1)   ? INT_MAX : nums1[mid2];
            }

            if(l1 <= r2 && l2 <= r1){
                if((n1 + n2) % 2 != 0){
                    return max(l1, l2);
                }
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > r2){
                high = mid - 1;
            }
            else if(l2 > r1){
                low = mid + 1;
            }
        }

        return 0.0;
    }
};
