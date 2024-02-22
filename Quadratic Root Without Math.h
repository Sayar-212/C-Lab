#include <stdio.h>

float square_root(float num) {
    if (num == 0 || num == 1)
        return num;
    float precision = 0.000001; 
    float start = 0, end = num;
    float mid;
    while (end - start > precision) {
        mid = (start + end) / 2;
        if (mid * mid > num)
            end = mid;
        else
            start = mid;
    }
    return (start + end) / 2;
}
int main() {
    float a, b, c, discriminant, root1, root2;
    printf("Enter coefficients (a, b, and c) of the quadratic equation (ax^2 + bx + c): ");
    scanf("%f %f %f", &a, &b, &c);
    discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        root1 = (-b + square_root(discriminant)) / (2 * a);
        root2 = (-b - square_root(discriminant)) / (2 * a);
        printf("Roots are real and distinct: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and repeated: %.2f\n", root1);
    } else {
        // Complex roots
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex: %.2f + %.2fi and %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
    return 0;
}
