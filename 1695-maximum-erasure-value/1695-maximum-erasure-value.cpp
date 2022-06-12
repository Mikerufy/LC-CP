class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int maxScore = 0;
		int currentSum = 0;
		vector<int> map(1e4 + 1);
		for(int right = 0, left = 0; right < nums.size(); right++) {
			currentSum += nums[right];
			map[nums[right]]++;
			
			while(map[nums[right]] == 2) {
				currentSum -= nums[left];
				map[nums[left++]]--;
			}
			
			maxScore = max(maxScore, currentSum);
		}

		return maxScore;
	}
};