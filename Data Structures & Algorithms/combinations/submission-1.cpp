class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& curr, int num, int limit, int k){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        if(num > limit)
            return;
        curr.push_back(num);
        helper(res, curr, num+1, limit, k);
        curr.pop_back();
        helper(res, curr, num+1, limit, k);
    }
    vector<vector<int>> combine(int n, int k) {
        int i=1;
        vector<vector<int>> results;
        vector<int> curr;
        helper(results, curr, i, n, k);
        return results;
    }
};