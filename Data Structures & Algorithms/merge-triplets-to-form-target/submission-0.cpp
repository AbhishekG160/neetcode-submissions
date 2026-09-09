class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // any triplet with any value > target -> IGNORE
        bool gota=false, gotb=false, gotc=false;
        int a = target[0], b = target[1], c = target[2];
        for(auto& t:triplets){
            if(t[0]>a || t[1]>b || t[2]>c)
                continue;
            if(t[0] == a) gota = true;
            if(t[1] == b) gotb = true;
            if(t[2] == c) gotc = true;
            
            if(gota && gotb && gotc)  
                return true;
        }
        return false;
    }
};
