class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {   
        for(int i=0;i<matrix.size();i++){
            vector<int> c;
            int sum = 0;
            for(int j=0;j<matrix[i].size();j++){
                sum+=matrix[i][j];
                c.push_back(sum);
            }
            v.push_back(c);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1;i<=row2;i++){
            if(!col1)
                sum+=v[i][col2];
            else
                sum+= (v[i][col2] - v[i][col1-1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */