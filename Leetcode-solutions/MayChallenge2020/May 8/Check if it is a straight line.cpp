class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cs) {
        size_t n = cs.size(); 
        int x1 = cs[0][0], y1 = cs[0][1], x = cs[1][0] - x1, y = cs[1][1] - y1;
        for (int i = 2; i < n; i ++) 
            if (x * (cs[i][1] - y1) != y * (cs[i][0] - x1)) 
                return false; 
        return true; 
    }
};
