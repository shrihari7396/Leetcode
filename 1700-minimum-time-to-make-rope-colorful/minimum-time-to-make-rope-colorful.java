import java.util.ArrayList;
import java.util.List;

class Solution {
    private static class Pair<T, V> {
        public T first;
        public V second;
        Pair(T first, V second) {
            this.first = first;
            this.second = second;
        }
    }

    public int minCost(String colors, int[] neededTime) {
        int n = colors.length();
        List<Pair<Integer, Integer>> subarrays = new ArrayList<>();

        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && colors.charAt(i) == colors.charAt(j + 1)) {
                j++;
            }
            if (j > i) { // only if there’s a group
                subarrays.add(new Pair<>(i, j));
            }
            i = j + 1;
        }

        int[] prefixSum = new int[n + 1];
        for (int k = 0; k < n; k++) {
            prefixSum[k + 1] = prefixSum[k] + neededTime[k];
        }

        int ans = 0;
        for (Pair<Integer, Integer> p : subarrays) {
            ans += process(p, prefixSum, neededTime);
        }
        return ans;
    }

    private int process(Pair<Integer, Integer> p, int[] prefixSum, int[] neededTime) {
        int sum = prefixSum[p.second + 1] - prefixSum[p.first];
        int maxVal = 0;
        for (int i = p.first; i <= p.second; i++) {
            maxVal = Math.max(maxVal, neededTime[i]);
        }
        return sum - maxVal;
    }
}
