package creamy;

public class NestedIfElse {
    public static void main(String[] args) {
        System.out.println();
        int x = 10, y = 20, z = 30;
        if (x >= y) {
            if (x >= z) {
                System.out.println(x + " is largest.");
            } else {
                System.out.println(z + " is largest.");
            }
        } else {
            if (y >= z) {
                System.out.println(y + " is largest.");
            } else {
                System.out.println(z + " is largest.");
            }
        }
        System.out.println();
    }
}
