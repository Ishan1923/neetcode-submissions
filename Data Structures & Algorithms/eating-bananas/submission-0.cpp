class Solution {
public:
    using ll = long long;

    bool isPossible(ll k, const vector<int>& piles, const int h){
        ll hours = 0;

        for(int i = 0; i < piles.size(); i++){
            hours += (piles[i] + k - 1) / k;
            if(hours > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll low = 1;
        ll high = INT_MAX;
        ll ans = high;

        while(low <= high){
            ll mid = low + (high - low) / 2;

            if(isPossible(mid, piles, h)){
                ans = mid;
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }

        }

        return ans;

    }
};
