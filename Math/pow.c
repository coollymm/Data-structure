/*
 * Leetcode: 50. Pow(x, n)
 * tag: math 二分
 * language: C
 * data: 2020/5/11
 */

/*
 * 特殊值的处理 Pow(0, n) = 0 | Pow(x, 0) = 1
 * 负数处理 Pow(x, -n) = 1 / Pow(x, n) 但注意 n == INT_MIN时 (-n) 溢出
 */


//迭代
double myPow(double x, int n){
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        if (n == INT_MIN) {
            double temp = myPow (x, -(n + 1)) * x;
            return 1 / temp;
        }
        return 1 / myPow (x, -n);
    }
    double ret = 1;
    double a = x;
    while (n) {
        if (n & 1 == 1) {
            ret *= a;
        }
        // 对 n 进行二进制拆分
        n >>= 1;
        a *= a;
    }
    return ret;
}

//递归
double myPow(double x, int n){
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (n == -1) {
        return 1/x;
    }
    if (n == 1) {
        return x;
    }
    double half = myPow (x, n / 2);
    double remain = myPow (x, n % 2);
    double ret = remain * half * half;
    return ret;
}