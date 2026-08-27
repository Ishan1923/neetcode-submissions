class Solution {
public:
    struct comp{

        bool operator()(const pair<char, int>& a, const pair<char, int>& b){
            return a.second < b.second;
        }

    };
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<char, int>, vector<pair<char, int>> ,comp> pq;
        unordered_map<char, int> freq;
        for(auto& task : tasks) freq[task]++;
        for(auto& [task, f] : freq){
            pq.push({task, f});
        }
        vector<char> GanttChart;
        while(!pq.empty()){
            auto [task, f] = pq.top();
            pq.pop();

            vector<pair<char, int>> buffer;

            GanttChart.push_back(task);
            f--;

            if(f > 0){
                buffer.push_back({task, f});
            }

            for(int i = 0; i < n; i++){
                if(!pq.empty()){
                    auto [next_task, next_f] = pq.top();
                    pq.pop();
                    GanttChart.push_back(next_task);
                    next_f--;
                    if(next_f > 0){
                        buffer.push_back({next_task, next_f});
                    }
                }
                else if(!buffer.empty()){
                    GanttChart.push_back(' ');
                }
            }

            for(int i = 0; i < buffer.size(); i++){
                pq.push(buffer[i]);
            }

            if(pq.empty()) break;

        }


        return GanttChart.size(); 


    }
};
