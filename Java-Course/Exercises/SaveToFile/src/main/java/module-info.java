module com.example.saving_information {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;
    requires opencsv;


    opens com.example.saving_information to javafx.fxml;
    exports com.example.saving_information;
}