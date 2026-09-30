class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxh;
        if(a>0) maxh.push({a, 'a'});
        if(b>0) maxh.push({b, 'b'});
        if(c>0) maxh.push({c, 'c'});

        string result = "";
        while(!maxh.empty()){
            auto [count1, char1] = maxh.top();
            maxh.pop();
            int n = result.length();
            if(n>=2 && result[n-1]==char1 && result[n-2]==char1){
                // use another
                if(maxh.empty())
                    break;
                auto [count2, char2] = maxh.top();
                maxh.pop();
                result += char2;
                count2 -= 1;
                if(count2 > 0)
                    maxh.push({count2, char2});
                maxh.push({count1, char1});
            }
            else {
                // use this 
                result += char1;
                count1 -= 1;
                if(count1 > 0)
                    maxh.push({count1, char1});
            }
        }
        return result;
    }
};