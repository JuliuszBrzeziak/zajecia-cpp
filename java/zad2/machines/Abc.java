public class Abc {
    
    public static void main(String[] args) {


       Test<Double> testa = new Multi(3.0);

       System.out.println(testa.test(4.0));

       plot(0,4,testa);
    }


    public static void plot(double xmin, double xmax, Test<Double> f) {
        int n = 20;
        double x = xmin;
        double dx = (xmax - xmin) / n;
        System.out.println(dx);
        System.out.println("x0" + x);
        for(int i = 0; i < 20; i++){
            System.out.println("f" + f.test(x));
            System.out.println("x" + x);
            x += dx;
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
 

