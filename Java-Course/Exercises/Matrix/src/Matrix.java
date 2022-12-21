import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Matrix {
    public static void main(String[] args) throws IOException {

        BufferedWriter writer = new BufferedWriter(new FileWriter("resources"));

        int[][][] matrix = {
                {{22, 23, 24}, {32, 33, 34}, {42, 43, 44}},
                {{11, 16, 45}, {43, 55, 99}, {60, 22, 29}},
                {{15, 17, 77}, {11, 66, 43}, {31, 52, 29}}
        };

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                for(int k = 0; k < matrix[0][0].length; k++)
                {
                    writer.write(String.valueOf(matrix[i][j][k]) + "");
                }
                writer.newLine();
            }
            writer.newLine();
        }
        writer.close();
    }
}