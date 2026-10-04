class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1size = s1.length();
        int s2size = s2.length();
        if(s1size > s2size) 
            return false;
        
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0; i<s1size; i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }

        int matched = 0;
        for(int i=0; i<26; i++)
            if(count1[i] == count2[i])
                matched++;
        if(matched == 26)
            return true;

        int left = 0;
        for(int right=s1size; right<s2size; right++){

            int idx = s2[right]-'a';
            count2[idx]++;
            if(count2[idx] == count1[idx]) matched++;
            else if(count1[idx]+1 == count2[idx]) matched--;

            int removed = s2[left]-'a';
            count2[removed]--;
            if(count1[removed] == count2[removed]) matched++;
            else if(count1[removed]-1 == count2[removed]) matched--;
            left++;

            if(matched == 26)
                return true;
        }

        return matched == 26;
    }
};
