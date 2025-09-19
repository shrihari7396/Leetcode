import java.util.HashMap;
import java.util.Map;

class Solution {
    Map<Integer, Integer> m = new HashMap<>();
    public int climbStairs(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(m.containsKey(n)) {
            return m.get(n);
        }       
        m.put(n, climbStairs(n-1) + climbStairs(n-2));
        return m.get(n);
    }
}