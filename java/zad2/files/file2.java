
import java.io.*;

public class file2 {

    public static void main(String[] args) {
        File file = new File("test.txt");
        String filePath = "test2.txt";
            int number = 1234567;
            //FileWriter fileWriter = null;

        try (var br = new BufferedReader(new FileReader(file));
            FileWriter fileWriter = new FileWriter(filePath);
        ) {
            String line;

            while ((line = br.readLine()) != null) {
                System.out.println(line);
                fileWriter.write(Integer.toString(number));
            }
        } catch (FileNotFoundException e) {
            System.out.println("Can't find file " + file.toString());
        } catch (IOException e) {
            System.out.println("Unable to read file " + file.toString());
        }

    }

}