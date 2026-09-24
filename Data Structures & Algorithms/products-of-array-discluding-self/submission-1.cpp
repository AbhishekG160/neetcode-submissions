class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftprod(n);
        leftprod[0] = nums[0];
        vector<int> rightprod(n);
        rightprod[n-1] = nums[n-1];

        for(int i=1; i<n; i++)
            leftprod[i] = leftprod[i-1]*nums[i];
        for(int i=n-2; i>=0; i--)
            rightprod[i] = rightprod[i+1]*nums[i];

        vector<int> result(n);
        for(int i=0; i<n; i++){
            int leftside = (i>0)?leftprod[i-1]:1;
            int rightside = (i<n-1)?rightprod[i+1]:1;
            result[i] = leftside*rightside;
        }
        return result;
    }
};
