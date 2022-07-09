void solve(int ind, vector<int>& arr, int n, vector<int>& ans, int sum, int target) {
if (ind == n && sum==target) {
ans.push_back(sum);
return;
}
//element is picked
solve(ind + 1, arr, n, ans, sum + arr[ind], target);
//element is not picked
solve(ind + 1, arr, n, ans, sum, target);
}
vector<vector<int>> combinationSum(vector<int>& arr, int target) {
vector<vector<int>> ans;
int n = arr.size();
solve(0, arr, n, ans, 0, target);
return ans;
}