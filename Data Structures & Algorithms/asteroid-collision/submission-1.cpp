class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i:asteroids){
            bool curr_destroyed = false;
            while(!st.empty() && st.back()>0 && i<0){
                // collision
                if(st.back() < abs(i))
                    st.pop_back();
                else if(st.back() > abs(i)){
                    curr_destroyed = true;
                    break;
                }
                else{
                    curr_destroyed = true;
                    st.pop_back();
                    break;
                }
            }
            if(!curr_destroyed)
                st.push_back(i);
        }
        return st;
    }
};