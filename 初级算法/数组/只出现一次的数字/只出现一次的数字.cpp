/******************
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1

���� [2,2,1]
��� 1
ʾ�� 2

���� [4,1,2,1,2]
��� 4
********************/
int singleNumber(int* nums, int numsSize) {
        int num = 0;
        for (int i = 0; i < numsSize; i++) {
            num = num ^ nums[i];
        }
        return num;
    }
	
//������Դhttps://www.cnblogs.com/zfLee/p/9330127.html
//����������λ����������루&�����ǣ�~������|�������^��https://blog.csdn.net/chijiandi/article/details/79022473