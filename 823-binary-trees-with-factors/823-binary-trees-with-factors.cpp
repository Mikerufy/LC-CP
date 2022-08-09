class Solution {
    unordered_set<int> set;
    unordered_map<int, long long> map;
    long long mod = 1e9+7;
public:
    long long findCount(vector<int> &arr, int num1) {
        if(map.find(num1) != map.end()) return map[num1];
		// for each number, at least counts itself as leaf
        long long cnt = 1;
        for(int num2: arr) {
			// find sub-nodes
            if(num2 <= num1 && num1 % num2 == 0 && set.count(num1 / num2)) {
                cnt += findCount(arr, num2) * findCount(arr, num1 / num2);
            }
        }
        return map[num1] = cnt;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long ans = 0;
        set.insert(arr.begin(), arr.end());
        for(int num: arr) {
            ans += findCount(arr, num);
            ans %= mod;
        }
        return ans;
    }
};