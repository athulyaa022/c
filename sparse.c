#include <stdio.h>
int toConvert(int mat[10][10],int rows, int cols,int spar[50][3]){
    int k = 1; 
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                spar[k][0] = i; 
                spar[k][1] = j; 
                spar[k][2] = mat[i][j]; 
                k++;
            }
        }
    }
    spar[0][0] = rows;
    spar[0][1] = cols;
    spar[0][2] = k - 1; 
}

void printSparse(int spar[50][3]) {
    int count = spar[0][2]; 
    for (int i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", spar[i][0], spar[i][1], spar[i][2]);

    }
}
void addSpar(int a[50][3], int b[50][3], int result[50][3]) {
    int i = 1, j = 1, k = 1;
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Addition not posible\n");
        return;
    }

    result[0][0] = a[0][0];
    result[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++;
        } else {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        k++;
    }

     while (i <= a[0][2]) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }

    result[0][2] = k - 1; 
}

void tranSpar(int spar[50][3], int result[50][3]) {
    int k = 1;

    result[0][0] = spar[0][1]; 
    result[0][1] = spar[0][0]; 
    result[0][2] = spar[0][2]; 

    for (int col = 0; col < spar[0][1]; col++) {
        for (int i = 1; i <= spar[0][2]; i++) {
            if (spar[i][1] == col) {
                result[k][0] = spar[i][1]; 
                result[k][1] = spar[i][0];
                result[k][2] = spar[i][2];
                k++;
            }
        }
    }
}
int main() {
    int m1[10][10], m2[10][10];
    int t1[50][3], t2[50][3], sum[50][3], transposed[50][3];
    int rows, cols;

    
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    
    printf("Enter matrix A (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &m1[i][j]);

    
    printf("Enter matrix B (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &m2[i][j]);

    
    toConvert(m1, rows, cols, t1);
    toConvert(m2, rows, cols, t2);

    printf("\nSparse matrix representation of A:\n");
    printSparse(t1);

    printf("\nSparse matrix representation of B:\n");
    printSparse(t2);

    
    addSpar(t1, t2, sum);
    printf("\nSum of two sparse matrices:\n");
    printSparse(sum);

    
    tranSpar(sum, transposed);
    printf("\nTranspose:\n");
    printSparse(transposed);

    return 0;
