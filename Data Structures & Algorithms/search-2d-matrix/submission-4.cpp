class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //   int i=0, j=0;
          int m = matrix.size(), n = matrix[0].size();
        //   while(i<m && j<n){
        //     if(matrix[i][j] == target)
        //         return true;
        //     if(i+1<m && matrix[i+1][j] <= target){
        //         i++;
        //         continue;
        //     }
        //     else if(j+1<n && matrix[i][j+1] <= target){
        //         j++;
        //         continue;
        //     }
        //     else return false;
        //   }
        //   return false;

        int low = 0, high = m-1;
        int row = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid][0]<=target and matrix[mid][n-1]>=target){
                row = mid;
                break;
            }
            if(matrix[mid][0] > target) high = mid-1;
            else low = mid+1;
        }

        if(row == -1)
            return false;

        low = 0; 
        high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[row][mid] == target) 
                return true;
            if(matrix[row][mid] < target)
                low = mid+1;
            else high = mid-1;
        }

        return false;
    }
};
