class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1->n values possible and n+1 nodes 
        // map values to indices
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0]; 
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
