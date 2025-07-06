class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> mp;

public:
    int cnt;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]]++;
        }
    }

    void add(int index, int val) {
        mp[nums2[index]]--; 
        nums2[index] += val;
        mp[nums2[index]]++; 
        }

    int count(int tot) {
        int cnt = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int comp = tot - nums1[i];
            if (mp.find(comp) != mp.end()) {
                cnt += mp[comp];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_ 2 = obj->count(tot);
 */