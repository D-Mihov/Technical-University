public class GenericSort {
    public static void main(String[] args) {
        Integer[] intArray = {Integer.valueOf(23), Integer.valueOf(44), Integer.valueOf(21)};

        Double[] doubleArray = {Double.valueOf(1.2), Double.valueOf(5.6), Double.valueOf(9.2)};

        Character[] charArray = {Character.valueOf('d'), Character.valueOf('k'), Character.valueOf('y')};

        String[] stringArray = {"Daniel", "Toni", "Filip"};

        sort(intArray);
        sort(doubleArray);
        sort(charArray);
        sort(stringArray);

        System.out.println("Sorted Integer objects: ");
        printList(intArray);
        System.out.println("Sorted Double objects: ");
        printList(doubleArray);
        System.out.println("Sorted Character objects: ");
        printList(charArray);


    }

    public static <E extends Comparable<E>> void sort(E[] list){
        E currentMin;
        int currentMinIndex;

        for(int i = 0; i < list.length - 1; i++){
            currentMin = list[i];
            currentMinIndex = i;

            for(int j = i + 1; j < list.length; j++){
                if(currentMin.compareTo(list[j]) > 0){
                    currentMin = list[j];
                    currentMinIndex = j;
                }
            }

            if(currentMinIndex != i){
                list[currentMinIndex] = list[i];
                list[i] = currentMin;
            }
        }
    }

    public static void printList(Object[] list){
        for(int i = 0; i < list.length; i++)
            System.out.println(list[i] + " ");
        System.out.println();
    }
}
