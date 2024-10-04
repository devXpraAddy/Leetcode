class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i = 0;
        int j = skill.size() - 1;
        long long result = 0;

        while (i < j) {
            if (skill[i] + skill[j] != skill[i + 1] + skill[j - 1]) {
                return -1;
            } else {
                result += skill[i] * skill[j];
                i++;
                j--;
            }
        }
        return result;
    }
};
