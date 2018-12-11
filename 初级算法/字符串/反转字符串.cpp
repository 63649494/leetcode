/***************
编写一个函数，其作用是将输入的字符串反转过来。

示例 1:

输入: "hello"
输出: "olleh"
示例 2:

输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"
************/
char* reverseString(char* s) {
    int size=strlen(s);//居然直接用strlen，太恶心了
    printf("%d",size);
    for(int j=0;j<size/2;j++){
        int t;
        t=s[j];
        s[j]=s[size-j-1];
        s[size-j-1]=t;
        }
    return s;
}