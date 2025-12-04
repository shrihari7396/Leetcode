class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.size();
        int l = 0, r = n - 1;

        // Cars moving left on the left edge never collide
        while (l < n && dir[l] == 'L') l++;

        // Cars moving right on the right edge never collide
        while (r >= 0 && dir[r] == 'R') r--;

        int collisions = 0;

        for (int i = l; i <= r; i++) {
            if (dir[i] != 'S') {
                collisions++; // L or R → will definitely collide
            }
        }

        return collisions;
    }
};
