class Solution {
    private static final int MOD = 1_000_000_007;

    public int assignEdgeWeights(int[][] edges) {
        int n = edges.length + 1;

        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        boolean[] visited = new boolean[n + 1];
        Queue<Integer> queue = new ArrayDeque<>();

        queue.offer(1);
        visited[1] = true;

        int maxDepth = -1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            maxDepth++;

            for (int i = 0; i < size; i++) {
                int node = queue.poll();

                for (int next : graph.get(node)) {
                    if (!visited[next]) {
                        visited[next] = true;
                        queue.offer(next);
                    }
                }
            }
        }

        return power(2, maxDepth - 1);
    }

    private int power(long base, int exp) {
        long result = 1;

        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exp >>= 1;
        }

        return (int) result;
    }
}