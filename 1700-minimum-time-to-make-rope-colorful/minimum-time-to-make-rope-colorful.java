
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    private static class Pair <T,V> {
        public T first;
        public V second;
        Pair(T first, V second) {
            this.first = first;
            this.second = second;
        }
    }
    public int minCost(String colors, int[] neededTime) {
        List<Pair<Integer, Integer>> subarrays = new ArrayList<>();
        int  i = 0;
        int j = i+1;
        int n = colors.length();
        while (i < n && j < n) {
            if(colors.charAt(i) == colors.charAt(j)) {
                j++;
            } else {
                subarrays.add(new Pair<>(i, j-1));
                i = j;
            }
        }
        if(i != j) {
            subarrays.add(new Pair<>(i, j-1));
        }
        int ans = 0;
        for(Pair<Integer, Integer> p : subarrays) {
            ans += process(p, neededTime);
        }
        return ans;
    }

    private int process(Pair<Integer, Integer> p, int[] neededTime) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i  = p.first; i <= p.second; i++) {
            pq.add(neededTime[i]);
        }
        int sum = 0;
        while (pq.size()!=1) {
            sum += pq.poll();
        }
        return sum;
    }
}