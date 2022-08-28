class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> v[mat[0].size()], u[mat.size()];

	    for (int i = 0; i < mat[0].size(); i++) {
		    for (int j = i, k = 0; j < mat[0].size() and k < mat.size(); j++, k++) {
			    v[i].push_back(mat[k][j]);
		    }
		    sort(v[i].begin(), v[i].end());
            for (int j = i, k = 0; j < mat[0].size() and k < mat.size(); j++, k++) {
			     mat[k][j] = v[i][k];
		    }
	    }
	    for (int i = 1; i < mat.size(); i++) {
		    for (int j = i, k = 0; j < mat.size() and k < mat[0].size(); j++, k++) {
			    u[i].push_back(mat[j][k]);
		    }
		    sort(u[i].begin(), u[i].end());
            for (int j = i, k = 0; j < mat.size() and k < mat[0].size(); j++, k++) {
			     mat[j][k] = u[i][k];
		    }
	    }    

	    return mat;
    }
};