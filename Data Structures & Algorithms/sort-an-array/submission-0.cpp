class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r){
        vector<int> left(nums.begin()+l, nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1, nums.begin()+r+1);
        int i=0, j=0;
        int k = l;

        while(i<left.size() && j<right.size()){
            if(left[i] <= right[j])
                nums[k++] = left[i++];
            else if(left[i] > right[j])
                nums[k++] = right[j++];
        }

        while(i<left.size())
            nums[k++] = left[i++];
        while(j<right.size())
            nums[k++] = right[j++]; 
    }
    void mergesort(vector<int>& nums, int l, int r){
        if(l >= r)
            return;
        int mid = l+(r-l)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};