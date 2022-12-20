package com.example.saving_information;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import com.opencsv.CSVReader;
import com.opencsv.exceptions.CsvException;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class SaveInfoController {
    @FXML
    private TextField firstNameTextField;
    @FXML
    private TextField lastNameTextField;
    @FXML
    private TextField phoneNumberTextField;
    @FXML
    private TextField emailTextField;
    @FXML
    private Button cancelButton;



    public void cancelButtonOnAction(ActionEvent e)
    {
        Stage stage = (Stage) cancelButton.getScene().getWindow();
        stage.close();
    }

    public void saveButtonOnAction(ActionEvent e) throws IOException {
        saveInfo();
    }
    public void saveInfo()throws IOException{
        BufferedWriter writer = new BufferedWriter(new FileWriter("information.txt"));

        Person info = new Person(firstNameTextField.getText(), lastNameTextField.getText(), phoneNumberTextField.getText(), emailTextField.getText());

        writer.write(info.getFName());
        writer.newLine();
        writer.write(info.getLName());
        writer.newLine();
        writer.write(info.getPhoneNumber());
        writer.newLine();
        writer.write(info.getEmail());

        writer.close();

    }


}