class Machine implements Computation {
    private String name;
    private int code;
    
    public Machine() {
        //this("Arnie", 0);
        
        System.out.println("Constructor running!"+code);
    }
    
    public Machine(String name) {
        this(name, 0);
        
        System.out.println("Second constructor running %d" + name + code);
        // No longer need following line, since we're using the other constructor above.
        //this.name = name;
    }
    
    public Machine(String name, int code) {
        
        System.out.println("Third constructor running");
        this.name = name + "elo";
        //this.code = code;
        System.out.println("elosss");
        
    }

    public void getName(){
        System.out.println(this.name);
    }

    //@Override
    public interface Computation {
    void compute();
}


}


public class zad2 {
    public static void main(String[] args) {
/*
       Computation<Double> cmp = new Computation<Double>(){
            @Override
            public Double compute(Double a){
                return a * 3;
            }
        };*/
        Machine machine1 = new Machine();

        machine1.getName();

        Machine machine2 = new Machine("Bertie");

         machine2.getName();
        
        Machine machine3 = new Machine("Chalky", 7);
    }

}