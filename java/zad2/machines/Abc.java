public class Abc {
    
    public static void main(String[] args) {

        
 
    /*
        Computation<Integer> cmp = new Multi(3){
            @Override
            public Integer compute(Integer b){
                return this.a * b;
            }
        };
        System.out.println(cmp.compute(3.0));*/

        
       // Computation<Integer> cmp = new Multi(3);
       Test testa = new Multi(3);

       System.out.println(testa.test());
    
}}

class Multi implements Test {
    private int a;
    public Multi(int a){
        this.a = a;
    }


        @Override
        public int test(){
            return 2;
            };


}
 

