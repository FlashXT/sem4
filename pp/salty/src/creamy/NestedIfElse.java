package creamy;

public class NestedIfElse {
    public static void main(String[] args) {
        int x = 10, y = 20, z = 30;
        if (x >= y) {
            if (x >= z) {
                System.out.println(x + " is the largest number.");
            } else {
                System.out.println(z + " is the largest number.");
            }
        } else {
            if (y >= z) {
                System.out.println(y + " is the largest number.");
            } else {
                System.out.println(z + " is the largest number.");
            }
        }
    }
}
