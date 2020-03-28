
import java.io.*;

public class file3 {

    public static void main(String[] args)throws IOException{
        File file = new File(args[0]);
        String filePath = args[1];
            int number = 1234567;
            int i = 0;
            //FileWriter fileWriter = null;


        FileWriter fileWriter =null;
        BufferedReader br=null;
        try { br = new BufferedReader(new FileReader(file));
             fileWriter = new FileWriter(filePath);
            String line;


            while ((line = br.readLine()) != null) {
                System.out.println(line);
                fileWriter.write(Integer.toString(i ));
                fileWriter.write(line+"\n");
                i++;
            }


        } finally {
            if (br != null) {
                br.close();
            }
            if (fileWriter != null) {
                fileWriter.close();
            }
        }
    }
    

}


