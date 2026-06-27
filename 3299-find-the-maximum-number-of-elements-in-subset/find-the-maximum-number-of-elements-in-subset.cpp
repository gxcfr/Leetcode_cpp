class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        long long mx = *max_element(nums.begin(), nums.end());

        for (int x : nums)
            cnt[x]++;

        int ans = cnt.count(1) ? cnt[1] - (cnt[1] % 2 == 0) : 1;

        for (int num : nums) {
            if (num == 1) continue;

            long long x = num;
            int len = 0;

            while (x <= mx && cnt.count(x) && cnt[x] >= 2) {
                len += 2;

                if (x > LLONG_MAX / x) break;   // prevent overflow
                x *= x;
            }

            ans = max(ans, len + (cnt.count(x) ? 1 : -1));
        }

        return ans;
    }
};