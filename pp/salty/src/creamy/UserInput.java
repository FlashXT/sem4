// user input

package creamy;

import java.util.Scanner;

public class UserInput {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter float: ");
        float myFloat = input.nextFloat();
        System.out.println("Float entered: " + myFloat);

        System.out.println("Enter Double: ");
        double myDouble = input.nextDouble();
        System.out.println("Double entered: " + myDouble);

        System.out.println("Enter text: ");
        String myString = input.next();
        System.out.println("Text entered: " + myString);
        input.close();
    }
}
