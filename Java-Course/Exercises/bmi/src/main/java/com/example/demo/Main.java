package com.example.demo;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.FileInputStream;
import java.util.Objects;

public class Main extends Application {

    private Stage stage;
    private final TextField txtMass = new TextField();
    private final TextField txtHeight = new TextField();
    private final Button btnCalc = new Button("Calculate BMI");

    @Override
    public void start(Stage stage) throws Exception {
        this.stage = stage;
        FileInputStream inputstream = new FileInputStream("src/main/resources/image/training.gif");
        Image i = new Image(inputstream);
        ImageView imageView = new ImageView();
        imageView.setImage(i);
        imageView.setFitHeight(300);
        imageView.setFitWidth(300);

        VBox vbox = new VBox(80);
        vbox.setPrefWidth(400);
        vbox.setPrefHeight(600);
        vbox.setAlignment(Pos.CENTER);
        vbox.setSpacing(5);
        this.txtMass.setMaxWidth(65);
        this.txtHeight.setMaxWidth(65);

        Label lblTitle = new Label("BMI Calculator");
        lblTitle.setFont(Font.font(30));
        vbox.getChildren().add(lblTitle);
        vbox.getChildren().add(imageView);
        Label l1 = new Label("Your mass (kg):");
        l1.setFont(Font.font(15));
        vbox.getChildren().add(l1);
        vbox.getChildren().add(txtMass);
        Label l2 = new Label("Your height (cm):");
        l2.setFont(Font.font(15));
        vbox.getChildren().add(l2);
        vbox.getChildren().add(txtHeight);

        vbox.getChildren().add(btnCalc);

        btnCalc.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent ev) {
                double mass;
                double height;
                try {
                    mass = Double.parseDouble(txtMass.getText());
                    height = Double.parseDouble(txtHeight.getText());
                } catch (NumberFormatException e) {
                    showMessage("Check your input.", "Error in number input");
                    return;
                }
                double result = calculateBMI(mass, height);
                Label l3 = new Label("Your BMI is: " + (Math.round(result * 100.0) / 100.0));
                l3.setFont(Font.font(15));
                vbox.getChildren().add(l3);
                //showMessage("Your BMI is: " + (Math.round(result * 100.0) / 100.0), "Your BMI result");
            }
        });
        Scene scene = new Scene(new Group(vbox));
        stage.setTitle("JavaFX BMI Calculator");
        stage.setScene(scene);
        stage.sizeToScene();
        stage.show();
    }

    protected double calculateBMI(double mass, double height) {
        return mass / Math.pow(height / 100.0, 2.0);
    }

    public static void main(String[] args) {
        Application.launch(args);
    }

    public void showMessage(final String message, final String title) {
        final Stage dialog = new Stage(StageStyle.UTILITY);
        dialog.setTitle(title);
        dialog.setResizable(false);
        dialog.initModality(Modality.WINDOW_MODAL);
        dialog.initOwner(this.stage);

        VBox vbox = new VBox(2);
        HBox pane = new HBox(10);

        dialog.setScene(new Scene(vbox));
        vbox.setAlignment(Pos.CENTER);

        vbox.getChildren().add(pane);
        pane.getChildren().add(new Label(message));
        Button btn = new Button("OK");
        btn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                dialog.close();
            }
        });
        pane.getChildren().add(btn);
        dialog.showAndWait();
    }
}