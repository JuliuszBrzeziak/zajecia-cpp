class MyException extends Exception {
   String com;

   public MyException(String a, String b) {
      com = b;
      
   }

   public String toString() {
      return "CustomException[" + com + "]";
   }

    @Override 
   public String getMessage(){
       return "komunikat";
   }
}

public class Div2 {
   static double compute(double a,double b) throws MyException {
      if (b == 0){
         throw new MyException("a","0");
         //System.out.println("No error in prog. no exception caught");
      }
      return a/b;
   }

   public static void main(String args[]) {
   
      try {
         compute(5,1);
         compute(12,0);
      } catch(MyException ex1) {
         System.out.println(ex1.getMessage());
      }
   }
}