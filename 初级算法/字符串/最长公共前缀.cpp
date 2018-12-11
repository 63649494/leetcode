#include<stdio.h>
/**********
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。


***********/
char* longestCommonPrefix(char** strs, int strsSize) {
    static char s[10]="";       //必须为静态变量，返回临时变量会乱码
    int m=0,p=0;
    for(int i=0;i<10;i++){
        printf("i=%d\n",i);
        for(int j=0;j<strsSize;j++)
            if(strs[j][i]==strs[0][i])
                {m++;
                printf("%d",m);
                }
        printf("\n");
        if(m==strsSize){
            printf("%d   ",m);
            printf("%c\n",strs[0][i]);
            s[i]=strs[0][i];
            p++;
            }
        else break;
        m=0;
        }
    s[p]='\0';
    for(int n=0;s[n]!='\0';n++)
        printf("%c",s[n]);
    printf("\n");
    return s;
}

int main(){
    char* a[10]={"flower","flow","flight"};
    char* s=longestCommonPrefix(a,3);
    for(int n=0;n<10;n++)
        printf("%c",s[n]);
    return 0;
    }
