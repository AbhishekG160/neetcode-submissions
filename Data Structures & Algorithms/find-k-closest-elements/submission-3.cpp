class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // int n = arr.size();
        // if(n<=k)
        //     return arr;
        
        // // window of k size
        // deque<int> result;
        // for(int i=0; i<k; i++)
        //     result.push_back(arr[i]);
        // int left = 0;
        // for(int right=k; right<n; right++){
        //     if((abs(arr[right]-x) < abs(arr[left]-x))){
        //         result.pop_front();
        //         result.push_back(arr[right]);
        //         left++;
        //     }
        //     // else break;
        // }
        // return vector<int>(result.begin(), result.end());

        int l = 0;
        int r = arr.size()-1;
        while(r-l+1 > k){
            if(abs(arr[l] - x) > abs(arr[r] - x))
                l++;
            else r--;
        }
        return vector<int>(arr.begin()+l, arr.begin()+r+1);
    }
};