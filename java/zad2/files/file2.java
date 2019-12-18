
import java.io.*;

public class file2 {

    public static void main(String[] args) {
        File file = new File(args[0]);
        String filePath = args[1];
            int number = 1234567;
            int i = 0;
            //FileWriter fileWriter = null;

        try (var br = new BufferedReader(new FileReader(file));
            var fileWriter = new FileWriter(filePath);
        ) {
            String line;

            while ((line = br.readLine()) != null) {
                System.out.println(line);
                fileWriter.write(Integer.toString(i ));
                fileWriter.write(line+"\n");
                i++;
            }
        } catch (FileNotFoundException e) {
            System.out.println("Can't find file " + file.toString());
        } catch (IOException e) {
            System.out.println("Unable to read file " + file.toString());
        }

    }

}