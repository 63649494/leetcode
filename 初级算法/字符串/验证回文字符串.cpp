/****************
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
******************/
bool isPalindrome(char* s) {
    
    int slen=strlen(s);
    if(slen==0||slen==1) return true;
    char t[slen];
    int tlen=0;
    for(int i=0;i<slen;i++)
        if(s[i] >='a' && s[i]<='z' ||  s[i] >='A' && s[i]<='Z'  ||  s[i] >='0' && s[i]<='9'){
            t[tlen]=s[i];
            printf("%c\n",t[tlen]);
            tlen++;
        }
    tlen=tlen-1;
    if(tlen==-1)
        return true;
    //printf("longth is %d\n",i);
    for(int j=0;j<=(tlen/2);j++){   //中间的不是终止条件而是符合条件
        printf("%c %c\n",t[j],t[tlen-j]);
        if(t[j] >='A' && t[j]<='Z'){
            if(t[j]==t[tlen-j]||t[j]==t[tlen-j]-32)
            continue;
            else return false;
            }
        else if(t[j] >='a' && t[j]<='z'){
            if(t[j]==t[tlen-j]||t[j]==t[tlen-j]+32)
            continue;
            else return false;
            }
        else{
            if(t[j]==t[tlen-j])
            continue;
            else return false;
        }
    }
    return true;
}


//0P差了32