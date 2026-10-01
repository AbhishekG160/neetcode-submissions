/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int sidelen, int r, int c){
        // every single node -> leaf
        if(sidelen == 1)
            return new Node(grid[r][c]==1 , true);

        int half = sidelen/2;
        Node* topleft = helper(grid, half, r, c);
        Node* topright = helper(grid, half, r, c+half);
        Node* bottomleft = helper(grid, half, r+half, c);
        Node* bottomright = helper(grid, half, r+half, c+half);

        bool allleaf = topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf;
        bool sameval = (topleft->val == topright->val) && (bottomleft->val == bottomright->val) && (topleft->val == bottomleft->val);

        if(allleaf && sameval){
            // merge them into a single node
            int leafval = topleft->val;
            delete topleft;
            delete topright;
            delete bottomleft;
            delete bottomright;
            return new Node(leafval == 1, true);
        }
        // make a parent node for these 4 
        return new Node(true, false, topleft, topright, bottomleft, bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)
            return nullptr;
        return helper(grid, n, 0, 0);
    }
};