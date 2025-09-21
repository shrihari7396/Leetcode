import java.util.Set;

class Solution {
    private boolean check(String s, char[] ch) {
        
        for(int i = 0; i < ch.length; i++) {
            if(s.contains(ch[i]+"")) {
                return true;
            }
        }
        return false;
    }
    public int canBeTypedWords(String text, String brokenLetters) {
        String[] list = text.split(" ");
        char[] chs = new char[brokenLetters.length()];
        for(int i = 0;i < brokenLetters.length(); i++) {
            chs[i] = brokenLetters.charAt(i);
        }
        int ans = 0;
        for(String it : list) {
            if(!check(it, chs)) ans++;
        }

        return ans;
    }
}