class Solution {
public:
    static int comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int c=0;
        int def=INT_MIN;
        int n=properties.size();
        for(int i=n-1;i>=0;i--){
            if(def>properties[i][1]){
                c++;
            }
            def=max(def,properties[i][1]);
        }
        return c;
    }
};