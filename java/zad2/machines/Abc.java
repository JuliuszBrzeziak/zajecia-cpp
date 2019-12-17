public class Abc {
    public static void main(String[] args) {
 
        Sum<Integer,Integer,Integer> addTwoIntegers  = new Sum<Integer, Integer, Integer>() {
            @Override
            public Integer sum(Integer number1, Integer number2) {
                return number1 + number2;
            }
        };
 
        Sum<String,String,String> addTwoStrings  = new Sum<String, String, String>() {
            @Override
            public String sum(String string1, String string2) {
                return string1.concat(string2);
            }
        };

        Computation<Double> cmp = new Computation<Double>(){
            @Override
            public Double compute(Double number1){
                return 3 * number1;
            }
        };
 
        System.out.println(addTwoIntegers.sum(10,30));
        System.out.println(addTwoStrings.sum("Hello!","World"));
        System.out.println(cmp.compute(3.0));
 
    }
}

class Multi {
    int a;
    public Multi(int a){
        this.a = a;
    }
}
 
interface Sum<T,U,V>{
      V sum(T number1, U number2);
}

 
interface Computation<T>{
      T compute(T number1);
}