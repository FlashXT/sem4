// user input 2

package creamy;

import java.util.Scanner;

public class UserInput2 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter first number: ");
        int a = scn.nextInt();
        System.out.println("Enter second number: ");
        int b = scn.nextInt();
        System.out.println("Sum: " + (a + b));
        scn.close();
    }
}
