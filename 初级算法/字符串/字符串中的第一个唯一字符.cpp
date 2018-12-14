/**************
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。
*****************/

/*********
int firstUniqChar(char* s) {
    int size=strlen(s);
   // printf("size=%d\n",size);
    if(size==1)
        return 0;
    for(int i=0;i<size;i++){
        //printf("\n%c开始查重\n",s[i]);
        int k=0;
        for(int j=0;j<size;j++){
           // printf("匹配第%d个\n",j);
            if(s[i]!=s[j]){
                k++;
                //printf("k=%d\n",k);
                if(k==size-1)
                    return i;
            }
        }
    }
    return -1;
}
*********/

int firstUniqChar(char* s) {
    int i = 0, j = 0;
    int len = strlen(s);
    int freq[26] = { 0 };
    for (i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    for (i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}