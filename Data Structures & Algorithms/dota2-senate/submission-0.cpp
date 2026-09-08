class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        int n = senate.length();
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                r.push(i);
            else d.push(i);
        }

        while(!r.empty() && !d.empty()){
            if(r.front() < d.front())
                r.push(n+r.front());
            else
                d.push(n+d.front());
            r.pop();
            d.pop();
        }
        return (r.empty())?("Dire"):("Radiant");
    }
};