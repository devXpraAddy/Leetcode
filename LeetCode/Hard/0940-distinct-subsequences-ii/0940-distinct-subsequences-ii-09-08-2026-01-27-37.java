class Solution {

    public int distinctSubseqII(String s) {

        // Modulo value to prevent overflow
        final long MOD = 1000000007;

        // dp[i] = number of distinct subsequences
        // ending with the character ('a' + i)
        long[] dp = new long[26];

        // Total number of distinct non-empty subsequences
        long total = 0;

        // Process every character of the string
        for (char c : s.toCharArray()) {

            // Convert character into an index
            // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
            int i = c - 'a';

            // Store the previous number of subsequences
            // ending with this character
            long old = dp[i];

            // Create new subsequences ending with c
            //
            // total -> extend every existing subsequence with c
            // +1    -> create the subsequence containing only c
            dp[i] = total + 1;

            // Update the total count
            //
            // + dp[i] -> add newly created subsequences
            // - old   -> remove duplicate subsequences
            // + MOD   -> keep the value non-negative
            total = (total + dp[i] - old + MOD) % MOD;
        }

        // Return the number of distinct non-empty subsequences
        return (int) total;
    }
}