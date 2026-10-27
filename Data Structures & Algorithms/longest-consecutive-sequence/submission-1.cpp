class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int n:nums)
            st.insert(n);

        int maxlen = 0;
        for(int n:nums){
            if(st.count(n-1))
                continue;
            int curr = 1;
            int elem = n;
            while(st.count(elem+1)){
                curr += 1;
                elem += 1;
            }
            maxlen = max(maxlen, curr);
        }
        return maxlen;
    }
};
