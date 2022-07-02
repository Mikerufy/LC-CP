class Solution {
public:
    const int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        long long a = 0;
        long long b = 0;
        sort(hc.begin(),hc.end());
        a = max(a,(long long)hc[0]);
        for(int i=1;i<hc.size();i++){
            a = max(a,(long long)(abs(hc[i]-hc[i-1])));
        }
        a = max(a,(long long)(h-hc[hc.size()-1]));
        sort(vc.begin(),vc.end());
        b = max(b,(long long)vc[0]);
        for(int i=1;i<vc.size();i++){
            b = max(b,(long long)(abs(vc[i]-vc[i-1])));
        }
        b = max(b,(long long)(w-vc[vc.size()-1]));
        long long ans = (long long)((a * b)%mod);
        return ans;
    }
};