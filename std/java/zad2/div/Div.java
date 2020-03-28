//package pl.samouczekprogramisty.kursjava.exception;
import java.io.*;

public class Div {
    public static void main(String[] args) {
        
        Div d = new Div();


        

                try {
                    System.out.println(d.dig(0,0));
            
        }
        catch (IOException e) {
            System.out.println("aaaa");
            e.printStackTrace();
        }

    }

    public static double dig(double a, double b) throws IOException {
        try {
            Div0 instance = new Div0(1.0,b);
        }
        catch (IOException e) {
            e.getMessage();
        }
        return a/b;
    }


}
class Div0 extends java.lang.Exception {

    String com;
    public  Div0(double a, double b) throws IOException {
        if(b==0.0){
            throw new IOException();
        };
    }
}