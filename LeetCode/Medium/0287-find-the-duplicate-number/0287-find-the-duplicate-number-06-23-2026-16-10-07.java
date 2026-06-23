class Solution {
    public int findDuplicate(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(Integer num: nums){
            if(mp.containsKey(num)){
                return num;
            }
            mp.put(num, 1);
        }
        return -1;
    }
}