class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n<=k)
            return arr;
        
        // window of k size
        deque<int> result;
        for(int i=0; i<k; i++)
            result.push_back(arr[i]);
        int left = 0;
        for(int right=k; right<n; right++){
            if((abs(arr[right]-x) < abs(arr[left]-x))){
                result.pop_front();
                result.push_back(arr[right]);
                left++;
            }
            // else break;
        }
        return vector<int>(result.begin(), result.end());
    }
};