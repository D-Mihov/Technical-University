import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Choose option: ");
        System.out.println("Enter dollars - 1");
        System.out.println("Enter euro - 2");
        System.out.println("Enter rubles - 3");
        System.out.println("Enter leva - 4");
        int enterOption = Integer.parseInt(scanner.nextLine());

        System.out.println("Enter the amount: ");
        int sum = Integer.parseInt(scanner.nextLine());

        System.out.println("Choose option: ");
        System.out.println("Convert to dollars - 1");
        System.out.println("Convert to euro - 2");
        System.out.println("Convert to rubles - 3");
        System.out.println("Convert to leva - 4");
        int convertOption = Integer.parseInt(scanner.nextLine());

        Map<Integer, Map<Integer, Double>> currencies = new HashMap<>();
        fillCurrenciesMap(currencies);

        if (enterOption == convertOption) {
            System.out.println("You can't convert the same currencies!");
        } else {
            System.out.println(currencies.get(enterOption).get(convertOption));
            double result = (sum * currencies.get(enterOption).get(convertOption) * 100.0) / 100.0;
            System.out.printf("Result: %.2f", result);
        }

    }

    private static void fillCurrenciesMap(Map<Integer, Map<Integer, Double>> currencies) {
        currencies.put(1, new HashMap<>());
        currencies.put(2, new HashMap<>());
        currencies.put(3, new HashMap<>());
        currencies.put(4, new HashMap<>());

        currencies.get(1).put(2, 1.03);
        currencies.get(1).put(3, 57.3);
        currencies.get(1).put(4, 2.02);

        currencies.get(2).put(1, 0.97);
        currencies.get(2).put(3, 55.47);
        currencies.get(2).put(4, 1.96);

        currencies.get(3).put(1, 0.017);
        currencies.get(3).put(2, 0.018);
        currencies.get(3).put(4, 0.035);

        currencies.get(4).put(1, 0.49);
        currencies.get(4).put(2, 0.51);
        currencies.get(4).put(3, 28.36);
    }
}