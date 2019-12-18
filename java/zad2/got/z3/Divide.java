class DivideByZeroException extends Exception {
   String com;

   public DivideByZeroException(String a, String b) {
      com = b;
      
   }


    @Override 
   public String getMessage(){
       return this.com;
   }
}

public class Divide {
   static double div(double a,double b) throws DivideByZeroException {
      if (b == 0){
         throw new DivideByZeroException("a","0");
         //System.out.println("No error in prog. no exception caught");
      }
      return a/b;
   }

   public static void main(String args[]) {
   
      try {
         div(5,1);
         div(12,0);
      } catch(DivideByZeroException ex1) {
         System.out.println(ex1.getMessage());
      }
   }
}