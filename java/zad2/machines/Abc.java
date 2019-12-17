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
       
            Runner runner = new Runner();/*
            runner.test( a -> {
                System.out.println("Hello there.");
                System.out.println("And hello again.");
                return 7 + a;
            });*/

        Test<Double> tt = ( a -> {
                System.out.println("Hello there.");
                System.out.println("And hello again.");
                return 7 + a*a;
            });
    

    Test<Double> li = Lin::linn;
    li.test(3.0);

    Test<Double> li2 = new Lin2()::linn2;
    li2.test(4.0);
    apply(ar,li2);





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

class Runner implements Test<Double>{
    public int run(Test e) {
        //Double value = e.test(5.0);
        System.out.println("Return value is: " );
        return 0;
    }


        @Override
        public Double test(Double b){
            return b ;
        };


}


class Lin {
    private Double a,b;

    

    public static Double linn(Double c){
        return (c*c*c);
    }

}


class Lin2 {
    private Double a,b;


    public Double linn2(Double c){
        return (c*c*c*c);
    }

}