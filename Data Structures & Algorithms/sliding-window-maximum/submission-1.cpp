class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0;

        priority_queue<pair<int, int>> win;

        vector<int> ans;

        while(r < n){

            win.push({nums[r], r});
            // mx_num = max(mx_num, nums[r]);

            int l = r - k + 1;

            while(!win.empty() && win.top().second < l){
                win.pop();
            }

            if(r >= k - 1){
                ans.push_back(win.top().first);
            }

            r++;

        }

        return ans;
    }
};
