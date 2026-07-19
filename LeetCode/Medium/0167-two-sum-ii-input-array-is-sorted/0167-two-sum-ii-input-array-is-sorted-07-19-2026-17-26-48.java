class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i =0;i<numbers.length; i++){
            int comp = target - numbers[i];
            if(mp.containsKey(comp)){
                return new int[]{mp.get(comp) + 1, i+1};
            }
            mp.put(numbers[i], i);
        }
        throw new IllegalArgumentException("no match found");
    }
}