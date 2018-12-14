/****************
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
******************/
bool isAnagram(char* s, char* t) {
        int i = 0, j = 0;
    int slen = strlen(s);
    int tlen = strlen(t);
    int sreq[26] = { 0 };//如果输入字符串包含 unicode 字符,则大小改为255
    int treq[26] = { 0 };
    if(slen!=tlen)
        return false;
    for (i = 0; i < slen; i++) {
        sreq[s[i] - 'a']++;//s中对应字母出现次数加一
    }
    for (i = 0; i < tlen; i++) {
        treq[t[i] - 'a']++;
    }
    for (j = 0;j < 26;j++){
        printf("%d %d\n",sreq[j],treq[j]);
        if(sreq[j]!=treq[j])
            return false;
    }
    return true;
}



/************
以下为因没读懂题意失败的解法

相邻交换字符串，不能隔着不同的


bool isAnagram(char* s, char* t) {
    //判断长度是否一样
    int slen=strlen(s);
    int tlen=strlen(t);
    int m=0,q=0;
    if(slen!=tlen)
        return false;
    //扫描t同时于s中的同位置元素
    for(int i=0;i<tlen;i++){
        //若相同继续扫描
        //若不同，q+1,则记录位置到m，继续搜索，如果再遇到不同的则此时q==1,且s应该等于t[m]，不同则返回false，再继续搜索
            //如果遇到不同的此时q==2,则返回false
        if(t[i]!=s[i]){
            q=q+1;
                printf("i=%d q=%d\n",i,q);
                if(q%2==1){//第奇数次不同，记录
                    printf("第奇数次不同，记录 ");
                    m=i;
                    printf("m=%d\n",m);
                    }   
                else{//第偶数次不同，比较
                    printf("第偶数次不同，比较 ");
                    printf("t[i]=%c s[m]=%c q=%d m=%d i=%d\n",t[i],s[m],q,m,i);
                    if(t[i]!=s[m]||t[m]!=s[i])
                        return false;
                }
            }
    }
    if(q%2==1){
    printf("q=%d\n",q);
    return false;   
    }
    return true;
}
************/