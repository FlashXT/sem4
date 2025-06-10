package creamy;

public class TableWhile {
    public static void main(String[] args) {
        System.out.println();
        int i = 1;
        while (i <= 10) {
            int j = 1;
            while (j <= 10) {
                System.out.print(i * j + " ");
                j++;
            }
            System.out.println();
            i++;
        }
        System.out.println();
    }
}
