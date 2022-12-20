public class GenericStack <E> {
    private java.util.ArrayList<E> list = new java.util.ArrayList<>();

    public int getSize(){
        return list.size();
    }

    public E peek(){
        return list.get(getSize() - 1);
    }

    public void push(E object){
        list.add(object);
    }

    public E pop(){
        E object = list.get(getSize() - 1);
        list.remove(getSize() - 1);
        return object;
    }

    public boolean isEmpty(){
        return list.isEmpty();
    }

    @Override
    public String toString(){
        return "stack: " + list.toString();
    }

    public static void main(String[] args) {

        GenericStack<String> stack1 = new GenericStack<>();
        stack1.push("orange");
        stack1.push("purple");
        stack1.push("brown");
        stack1.push("darkBlue");

        GenericStack<Double> stack2 = new GenericStack<>();
        stack2.push(2.5); // autoboxing 1 to an Integer object
        stack2.push(34.8);
        stack2.push(33.6);

        System.out.println("Is stack1 empty: " + stack1.isEmpty());
        System.out.println("Is stack2 empty: " + stack2.isEmpty());

        System.out.println("Before pop an element " + stack1);
        stack1.pop();
        System.out.println("After pop an element " + stack1);

    }
}
