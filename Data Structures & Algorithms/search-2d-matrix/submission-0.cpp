class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int i=0, j=0;
          int m = matrix.size(), n = matrix[0].size();
          while(i<m && j<n){
            if(matrix[i][j] == target)
                return true;
            if(i+1<m && matrix[i+1][j] <= target){
                i++;
                continue;
            }
            else if(j+1<n && matrix[i][j+1] <= target){
                j++;
                continue;
            }
            else return false;
          }
          return false;
    }
};
