public class zad1{
    public static final double prec = 1.0e-5;
    
    public static double calculateSquareRoot(double x){

        double guess = 1.0;

        do{
            guess = (guess +/guess)/2.0
        } while ((guess*guess/x <1.0 -prec))||(guess*guess/x>1.0+prec));
        return guess;
    }
public static void main(String[] args){
    if(args.length<1)
        System.out.println("brak");
    else
        System.out.println(calculateSquareRoot(Double.parseDouble(args[0])));
}
}