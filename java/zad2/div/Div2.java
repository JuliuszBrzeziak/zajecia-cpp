class MyException extends Exception {
   String com;

   public MyException(String a, String b) {
      com = x;
   }

   public String toString() {
      return "CustomException[" + com + "]";
   }
}

public class Div2 {
   static void compute(double a,double b) throws MyException {
      if (b == 0)
         throw new MyException("a","0");
         System.out.println("No error in prog. no exception caught");
   }

   public static void main(String args[]) {
   
      try {
         compute(5,1);
         compute(12,0);
      } catch(MyException ex1) {
         System.out.println(ex1);
      }
   }
}