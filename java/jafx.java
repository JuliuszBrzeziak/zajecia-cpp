import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class jafx extends Application {

    @Override
    public void start(Stage stage) {
        String javaVersion = System.getProperty("java.version");
        String javafxVersion = System.getProperty("javafx.version");
        Label l = new Label("Jak leci?");
        Scene scene = new Scene(new StackPane(l), 640, 480);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}

//[juliuszb@juliusz-pc java]$ javac --module-path /home/juliuszb/javafx-sdk-11.0.2/lib --add-modules=javafx.controls jafx.java
//[juliuszb@juliusz-pc java]$ java --module-path /home/juliuszb/javafx-sdk-11.0.2/lib --add-modules=javafx.controls jafx

