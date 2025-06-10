package creamy;

public class ForPyramid {
    public static void main(String[] args) {
        int term = 6;
        System.out.println();
        for (int i = 1; i <= term; i++) {
            for (int j = term; j >= i; j--) {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
