                
class Solution {
    struct node{
        int no;
        int freq;
        node(int a,int b) //Constructor for value initialization for each node
        {
            no = a;
            freq = b;
        }
    };

    struct compare {    //Maintains MAX-HEAP based on frequency
        bool operator()(node const& a, node const& b)
        {
            return a.freq < b.freq;
        }
};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;   //Key->Number...Value->Freq
        //STEP-1: Store frequency of all elements in map
        for(int ele: nums)
            m[ele]+=1;
        
        //STEP-2: Now build a heap
        priority_queue<node,vector<node>,compare> heap; //Compare defines a max-heap based on frequency
        for(auto it: m)
            heap.push(node(it.first,it.second));
        
        vector<int> ans;    //Stores top-K elements
        //STEP-3: Pop top-k elemnts and store the numbers in ans vector
        while(k--)  
        {
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};
        
        
        
        
        
// vector<int> topKFrequent(vector<int>& nums, int k) {

//     int n = nums.size();
//         unordered_map<int,int> mpp;
        
//         set<int> s;
//         for(int i=0; i<n; i++){
//             mpp[nums[i]]++;
//             s.insert(nums[i]);
//         }
        
//         int size = s.size();
//         priority_queue<int, vector<int>, greater<int>> pq;
//         //cout<<*s.begin()<<endl;
//         int t=0;
//         for(auto i=s.begin(); i!=s.end(); i++){
//             //if(t<k){
//                 pq.push(mpp[*i]);
//             // cout<<mpp[*i]<<endl;
//             //     t++;
//             // }else{
//             //     if(mpp[*i]>pq.top()){
//             //         pq.push(mpp[*i]);
//             //         pq.pop();
//             //     }
//             // }
//         }
        
//         // int t=0;
//         // for(int i=0; i<=n; i++){
//         //     if(pq.find(nums[i]))
//         //     if(t<k){
//         //         pq.push(mpp[nums[i]]); 
//         //         t++;
//         //     }else{
//         //         if(mpp[i]>pq.top()){
//         //             pq.push(mpp[i]);
//         //             pq.pop();
//         //         }
//         //     }
//         // } 
        
//         vector<int> ans;
//         for(int i=0; i<k; i++){
//             ans.push_back(mpp[pq.top()]);
//             pq.pop();
//         }
        
//         return ans;
//     }