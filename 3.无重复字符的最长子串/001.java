import java.io.LineNumberInputStream;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int base=0;
        int max = 0;
        int offset = 0;
        byte[] str = s.getBytes();
        main_loop:
        while(base+offset<s.length()){
            for(int i=0; i<offset; i++){
                if(str[base+i]==str[base+offset]){
                    max = max>offset ? max : offset;
                    offset--;
                    base++;
                    continue main_loop;
                }
            }
            offset++;
        }
        return max>offset?max:offset;
    }
}