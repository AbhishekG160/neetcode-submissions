class TimeMap {
    // key -> list({timestamp , value})
    unordered_map<string, vector<pair<int, string>>> keytotimeval;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keytotimeval[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = keytotimeval.find(key);
        if(it == keytotimeval.end())
            return "";

        auto& pairs = it->second; // got the list of pairs of time and val 
        int low=0, high=pairs.size()-1;
        string result = "";
        while(low <= high){
            int mid = low+(high-low)/2;
            if(pairs[mid].first <= timestamp){
                result = pairs[mid].second;
                low = mid+1;
            }
            else high = mid-1;
        }

        return result;
    }
};
