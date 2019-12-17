public class Abc {
    
    public static void main(String[] args) {


       Test<Double> testa = new Multi(3.0);

       System.out.println(testa.test(4.0));

       double[] ar={0,0,0,0};
       apply(ar,testa);
       //plot(0,4,testa);
       Test<Double> testb = new Test<Double>(){
           @Override
        public Double test(Double b){
            return b * 7;
            }

       };
       apply(ar,testb);
    }


    public static void plot(double xmin, double xmax, Test<Double> f) {
        int n = 20;
        double x = xmin;
        double dx = (xmax - xmin) / n;
        System.out.println(dx);
        System.out.println("x0 " + x);
        for(int i = 0; i < 20; i++){
            System.out.println("f " + f.test(x));
            System.out.println("x " + x);
            x += dx;
        }
     }

     public static void apply(double[] array, Test<Double> f) {
         int arl = array.length;
         if(arl == 0){
             System.out.println("arl == 0");
         }    

         for(int i = 0; i<array.length;i++){
             array[i] = f.test((double)i);
             System.out.println(array[i]);
             
         }
      }


}

class Multi implements Test<Double> {
    private Double a;
    public Multi(Double a){
        this.a = a;
    }


        @Override
        public Double test(Double b){
            return b * a;
            };


}
 

