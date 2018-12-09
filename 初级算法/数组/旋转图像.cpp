/*************
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
************/

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    //对角线以上进行a[i][j]<==>a[j][i]
    for(int i=0;i<matrixRowSize;i++)
        for(int j=i+1;j<matrixRowSize;j++){
                int t;
                t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
        }
    //倒置每一行

    for(int i=0;i<matrixRowSize;i++){
        printf("i=%d\n",i);
        for(int j=0;j<matrixRowSize/2;j++){
            int t;
            t=matrix[i][j];
            printf("%d,%d<==>%d,%d\n",i,j,i,matrixRowSize-j-1);
            printf("a=%d<==>b=%d\n",matrix[i][j],matrix[i][matrixRowSize-j-1]);
            matrix[i][j]=matrix[i][matrixRowSize-j-1];
            matrix[i][matrixRowSize-j-1]=t;
            printf("t=%d\n",t);
            printf("a=%d<==>b=%d\n\n",matrix[i][j],matrix[i][matrixRowSize-j-1]);
        }
    }
    
}