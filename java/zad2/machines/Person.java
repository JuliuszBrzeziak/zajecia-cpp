public class Person implements Info, Info2 {
    
    private String name;
    
    public Person(String name) {
        this.name = name;
    }

    public void greet() {
        System.out.println("Hello there.");
    }

    @Override
    public void showInfo() {
        System.out.println("Person name is: " + name);
    }

    @Override
    public Integer showInfo2(Integer a) {
        System.out.println("Person name is: " + a);
    }
}
