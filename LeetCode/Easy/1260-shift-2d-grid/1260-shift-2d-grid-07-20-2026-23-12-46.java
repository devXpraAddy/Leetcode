class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        List<Integer> list = new ArrayList<>();
        int m = grid.length, n = grid[0].length;
        k = k % (m * n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                list.add(grid[i][j]);

        Collections.rotate(list, k);
        List<List<Integer>> outer = new ArrayList<>();
        for (int i = 0; i < list.size(); i += n)
            outer.add(new ArrayList<>(list.subList(i,
                    Math.min(i + n, list.size()))));
        return outer;
    }
}