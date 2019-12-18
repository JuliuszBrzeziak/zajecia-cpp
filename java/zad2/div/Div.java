//package pl.samouczekprogramisty.kursjava.exception;
import java.io.*;

public class Div {
    public static void main(String[] args) {
        
        Div d = new Div();


        

            d.dig(1,0);
        }

    }

    public static double dig(double a, double b) throws IOException {
        try {
            Div0 instance = new Div0(1.0,b);
        }
        catch (IOException e) {
                        
System.out.println("asssaaa");
            e.printStackTrace();
        }
        return a/b;
    }

    private void methodWithCheckedException() throws IOException {
        throw new IOException();
    }
}
class Div0 extends java.lang.Exception {

    String com;
    public  Div0(double a, double b) throws IOException {
        if(b==0.0){
            System.out.println("asssaaa");
            throw new IOException();
        };
    }
}