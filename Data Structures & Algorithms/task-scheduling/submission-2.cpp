class Solution {
public:


    // TC: O(N), SC: O(N)

    // struct comp{

    //     bool operator()(const pair<char, int>& a, const pair<char, int>& b){
    //         return a.second < b.second;
    //     }

    // };
    // int leastInterval(vector<char>& tasks, int n) {
    //     priority_queue<pair<char, int>, vector<pair<char, int>> ,comp> pq;
    //     unordered_map<char, int> freq;
    //     for(auto& task : tasks) freq[task]++;
    //     for(auto& [task, f] : freq){
    //         pq.push({task, f});
    //     }
    //     vector<char> GanttChart;
    //     while(!pq.empty()){
    //         auto [task, f] = pq.top();
    //         pq.pop();

    //         vector<pair<char, int>> buffer;

    //         GanttChart.push_back(task);
    //         f--;

    //         if(f > 0){
    //             buffer.push_back({task, f});
    //         }

    //         for(int i = 0; i < n; i++){
    //             if(!pq.empty()){
    //                 auto [next_task, next_f] = pq.top();
    //                 pq.pop();
    //                 GanttChart.push_back(next_task);
    //                 next_f--;
    //                 if(next_f > 0){
    //                     buffer.push_back({next_task, next_f});
    //                 }
    //             }
    //             else if(!buffer.empty()){
    //                 GanttChart.push_back(' ');
    //             }
    //         }

    //         for(int i = 0; i < buffer.size(); i++){
    //             pq.push(buffer[i]);
    //         }

    //         if(pq.empty()) break;

    //     }


    //     return GanttChart.size(); 


    // }


    //TC: O(n), SC: O(1); faster than prev
    int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    for(char t : tasks) freq[t]++;

    int maxFreq = 0;
    for(auto& [t, f] : freq) maxFreq = max(maxFreq, f);

    int maxCount = 0;
    for(auto& [t, f] : freq) if(f == maxFreq) maxCount++;

    int partCount = maxFreq - 1;          // number of "gaps" between the most frequent task's occurrences
    int partLength = n - (maxCount - 1);  // slots per gap, after placing other max-freq tasks in it
    int emptySlots = partCount * max(0, partLength);
    int availableTasks = tasks.size() - maxFreq * maxCount;
    int idles = max(0, emptySlots - availableTasks);

    return tasks.size() + idles;
}
};
