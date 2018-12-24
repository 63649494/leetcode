/* 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6] */
void merge(int* nums1, int m, int* nums2, int n) {
//归并
    if(m==0){
        for(int i=0;i<n;i++)
        nums1[i]=nums2[i];
        return ;
    }
	int t[m];
	for(int i=0;i<m;i++){
		t[i]=nums1[i];
		}
	int a=0,b=0;
	for(int i=0;i<m+n;i++){
		if(b==n)
			nums1[i]=t[a++];
        else if(a==m)
            nums1[i]=nums2[b++];
		else if(t[a]<=nums2[b]){
			//printf("%d插入\n",t[a]);
			nums1[i]=t[a++];
			printf("a=%d\n",a);
		}
		else if(t[a]>nums2[b]){
			//printf("%d插入\n",nums2[b]);
			nums1[i]=nums2[b++];
            printf("b=%d\n",b);
		}
	}
}