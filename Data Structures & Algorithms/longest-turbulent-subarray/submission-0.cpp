class Solution {
public:
    int comp(int& a, int& b){
        if(a == b)  return 0;
        if(a > b) return -1;
        return 1;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        // every elem - 1 lenght
        // same elems val -> reset to 1
        // continuous inc or dec -> reset to 2 
                // a,b,c -> all inc -> just keep the b,c
        int len = 1;
        int maxlen = 1;
        // if 2 inc then the third one should be dec 
        // 1 if the prev 2 were inc
        // -1 if the prev 2 were dec
        // 0 if the prev 2 were same
        // wanted inc then dec or dec then inc -> both gives -1 on multiply
        int prev = 0;
        int n = arr.size();
        for(int i=1; i<n; i++){
            int compare  = comp(arr[i-1], arr[i]);
            if(compare == 0) {
                // same
                prev = 0;
                len = 1;
            }
            else if(compare*prev < 0){
                len++;
                prev = compare;
            }
            else{
                len = 2;
                prev = compare;
            }
            maxlen = max(maxlen , len);
        }
        return maxlen;
    }
};