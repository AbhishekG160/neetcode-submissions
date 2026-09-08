class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)
            return false;
        map<int, int> freq;
        for(int i:hand)
            freq[i]++;
        
        for(auto it = freq.begin(); it != freq.end(); it++){
            int val = it->first;
            int count = it->second;
            if(count > 0){
                for(int j=0; j<groupSize; j++){
                    int next = val+j;
                    if(freq[next] < count)
                        return false;
                    freq[next] -= count;
                }
            }
        }

        return true;
    }
};
