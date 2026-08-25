class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0;
        int total_cost = 0;
        int total = 0;
        int start_idx = 0;

        for(int i = 0; i < n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }

        if(total_gas < total_cost) return -1;

        for(int i = 0; i < n; i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                total = 0;
                start_idx = i + 1;
            }
        }

        return start_idx;

    }
};
