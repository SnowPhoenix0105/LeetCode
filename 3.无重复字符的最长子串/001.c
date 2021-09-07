int lengthOfLongestSubstring(char * s){
    int count = 0;
    int max = 0;
    int i;
    while(s[count]!='\0'){
        for(i=0; i<count; i++){
            if(s[i]==s[count]){
                max = count>max ? count : max;
                s++;
                count-=2;
                break;
            }
        }
        count++;
    }
    return max>count?max:count;
}

int main(int argv,char*args){
    char* s = "pwwkew";
    return lengthOfLongestSubstring(s);
}