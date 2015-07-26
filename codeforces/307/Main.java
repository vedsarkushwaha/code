import java.util.Scanner;

public class Main {

    private Scanner scanner;
    private int mod;

    private Main(Scanner scanner) {
        this.scanner = scanner;
    }

    public static void main(String[] args) {
        Main main = new Main(new Scanner(System.in));
        main.solve();
    }

    private void solve() {
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        int l = scanner.nextInt();
        mod = scanner.nextInt();
        if (mod == 1 || l < 63 && 1l << l <= k) {
            System.out.println(-1);
            return;
        }
        if (l==0) {
            if (k==0) System.out.println(1);
            else System.out.println(0);
            return;
        }
        long pow2 = fastPower(2, n);
        long fib = fibonacci(n + 1);
        // System.out.println(pow2);
        // System.out.println(fib);
        System.out.println((pow2 - fib + mod)% mod);
        long res = 1;
        for (int i = 0; i < l; i++)
            if (((k >> i) & 1) == 0) res = res * fib % mod;
            else
                res = res * (pow2 - fib) % mod;
        if (res < 0) res += mod;
        // System.out.println(res);
    }

    private long fibonacci(long n) {
        Matrix matrix = new Matrix(new long[][]{{1, 1}, {1, 0}});
        matrix = fastPower(matrix, n);
        return matrix.matrix[0][0];
    }

    private long fastPower(long base, long exponent) {
        if (exponent == 0) return 1;
        long x = fastPower(base, exponent >> 1);
        x = x * x % mod;
        if ((exponent & 1) != 0) x = x * base % mod;
        return x;
    }

    private Matrix fastPower(Matrix base, long exponent) {
        if (exponent == 1) return base;
        Matrix x = fastPower(base, exponent >> 1);
        x = multiplyMatrix(x, x);
        if ((exponent & 1) != 0) x = multiplyMatrix(x, base);
        return x;
    }

    private Matrix multiplyMatrix(Matrix a, Matrix b) {
        Matrix matrix = new Matrix();
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    matrix.matrix[i][k] = (matrix.matrix[i][k] + a.matrix[i][j] * b.matrix[j][k]) % mod;
        return matrix;
    }

    private class Matrix {

        private long[][] matrix;

        public Matrix() {
            matrix = new long[2][2];
        }

        public Matrix(long[][] c) {
            matrix = c.clone();
        }
    }
}