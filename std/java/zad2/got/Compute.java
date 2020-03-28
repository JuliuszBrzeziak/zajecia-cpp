class MyException extends Exception {
   String com;

   public MyException(String a, String b) {
      com = b;
      
   }


    @Override 
   public String getMessage(){
       return "komunikat";
   }
}


public class Compute {
    
    public static void main(String[] args) {

        //interfejs
       Computation<Double> testa = new Multi(3.0);
       System.out.println(testa.compute(4.0));



       double[] ar={0,0,0,0};
       apply(ar,testa);
       
       //klasa anonimowa
       Computation<Double> testb = new Computation<Double>(){
           @Override
        public Double compute(Double b){
            return b * 7;
            }

       };
       apply(ar,testb);
       //plot(0,20,testb);
       



        //lambda
        Bi runner = new Bi();

        Computation<Double> tt = ( a -> {
                System.out.println("Hello there.");
                System.out.println("And hello again.");
                return 7 + a*a;
            });

        apply(ar,tt);
        plot(0,20,tt);
    
    //metoda statyczna
    Computation<Double> li = Tri::trii;
    li.compute(3.0);

    //metoda niestatyczna
    Computation<Double> li2 = new Qua()::cuaa;
    li2.compute(4.0);
    apply(ar,li2);

    Div2 di = new Div2();
    //System.out.println(di.div(2,3));

          try {
         System.out.println(di.div(2,3));
         System.out.println(di.div(2,0));
      } catch(MyException ex1) {
         System.out.println(ex1.getMessage());
      }

    }


    public static void plot(double xmin, double xmax, Computation<Double> f) {
        int n = 20;
        double x = xmin;
        double dx = (xmax - xmin) / n;
        System.out.println(dx);
        System.out.println("x0 " + x);
        for(int i = 0; i < 20; i++){
            System.out.println("x " + x+"f " + f.compute(x));
           
            x += dx;
        }
     }

     public static void apply(double[] array, Computation<Double> f) {
         int arl = array.length;
         if(arl == 0){
             System.out.println("arl == 0");
         }    

         for(int i = 0; i<array.length;i++){
             array[i] = f.compute((double)i);
             System.out.println(array[i]);
             
         }
      }


}

 class Div2 {
   static double div(double a,double b) throws MyException {
      if (b == 0){
         throw new MyException("a","0");
         //System.out.println("No error in prog. no exception caught");
      }
      return a/b;
   }
 }

class Multi implements Computation<Double> {
    private Double a;
    public Multi(Double a){
        this.a = a;
    }


        @Override
        public Double compute(Double b){
            return b * a;
        };

}

class Bi implements Computation<Double>{
    public int run(Computation e) {
        //Double value = e.compute(5.0);
        System.out.println("Return value is: " );
        return 0;
    }


        @Override
        public Double compute(Double b){
            return b ;
        };


}


class Tri {
    private Double a,b;


    public static Double trii(Double c){
        return (c*c*c);
    }

}


class Qua {
    private Double a,b;


    public Double cuaa(Double c){
        return (c*c*c*c);
    }

}