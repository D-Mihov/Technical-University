import com.opencsv.CSVReader;
import com.opencsv.exceptions.CsvException;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try(CSVReader reader = new CSVReader(new FileReader("src/main/resources/addresses.csv"))) {
            List<String[]> result = reader.readAll();

            List<Address> addresses = new ArrayList<>();

            for (String[] item :
                    result) {
                String firstName = item[0];
                String lastName = item[1];
                String addressName = item[2];
                String townName = item[3];
                int townId = Integer.parseInt(item[4]);
                Address address = new Address(firstName, lastName, addressName, townName, townId);
                addresses.add(address);
            }
            System.out.println(addresses);
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (CsvException e) {
            throw new RuntimeException(e);
        }
    }
}
