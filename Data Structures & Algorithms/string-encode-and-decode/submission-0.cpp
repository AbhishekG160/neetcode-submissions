class Solution {
public:
    // length_of_string + # + string
    string encode(vector<string>& strs) {
        string result = "";
        for(string& s:strs)
            result += to_string(s.length())+'#'+s;
        return result;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> result;
        int i=0; 
        while(i<n){
            int j=i;
            while(s[j] != '#')
                j++;
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            result.push_back(s.substr(i, length));
            i = i+length;
        }
        return result;
    }
};
