class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        vector<int> c;
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                c.push_back(matrix[j][i]);
            }
            v.push_back(c);
            c.clear();
        }
        return v;
    }
};