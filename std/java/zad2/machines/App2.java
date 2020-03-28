interface Executable {
    void execute();
}

class Runner {
    public void run(Executable e) {
        e.execute();
    }
}

public class App2 {

    public static void main(String[] args) {
            Runner runner = new Runner();
            runner.run( () -> System.out.println("Hello there.") );
            
        }
}
