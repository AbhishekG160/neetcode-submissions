class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char , int> freq;
        pair<int, char> maxm;
        for(char& c:s){
            freq[c]++;
            if(freq[c] > (n+1)/2)
                return "";
            if(freq[c] > maxm.first){
                maxm.first = freq[c];
                maxm.second = c;
            }
        }
        
        string result(n, ' ');
        int idx = 0;
        while(maxm.first > 0){
            result[idx] = maxm.second;
            idx += 2;
            maxm.first -= 1;
            freq[maxm.second]--;
        }

        for(auto& pair:freq){
            while(pair.second > 0){
                if(idx >= n) 
                    idx = 1;
                result[idx] = pair.first;
                idx += 2;
                pair.second -= 1;
            }
        }

        return result;
    }
};