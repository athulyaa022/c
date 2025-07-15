#include<stdio.h>

struct poly {
    int coeff;
    int exp;
};

int main() {
    struct poly p1[10], p2[10], p3[20];
    int m, n;
    int i, j, k = 0;

    printf("Enter no of terms of 1st and 2nd polynomial: ");
    scanf("%d%d", &m, &n);

    for(i = 0; i < m; i++) {
        printf("Enter the coefficient and exponent of term %d of 1st polynomial: ", i + 1);
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }

    for(j = 0; j < n; j++) {
        printf("Enter the coefficient and exponent of term %d of 2nd polynomial: ", j + 1);
        scanf("%d%d", &p2[j].coeff, &p2[j].exp);
    }

    i = 0; j = 0;
    while(i < m && j < n) {
        if(p1[i].exp == p2[j].exp) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++; j++; k++;
        } else if(p1[i].exp > p2[j].exp) {
            p3[k] = p1[i];
            i++; k++;
        } else {
            p3[k] = p2[j];
            j++; k++;
        }
    }

    while(i < m) {
        p3[k] = p1[i];
        i++; k++;
    }

    while(j < n) {
        p3[k] = p2[j];
        j++; k++;
    }

    printf("The resultant polynomial: ");
    for(i = 0; i < k; i++) {
        printf("%dx^%d", p3[i].coeff, p3[i].exp);
        if(i < k - 1) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
