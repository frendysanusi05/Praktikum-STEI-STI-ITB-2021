/**
* KebunBinatang.java
* Program kebun binatang
* @author 18221041 Frendy Sanusi
*/

import java.util.Scanner;

public class KebunBinatang {
    public static void main(String[] args) {
        // build Scanner object
        Scanner myInput = new Scanner(System.in);
        
        // scan
        int type = myInput.nextInt();
        
        if (type == 1) { // elang
            int basePower = 5;
            int children = myInput.nextInt();
            int jumlahTelur = myInput.nextInt();
            Elang obj = new Elang(basePower);
            obj.increaseChild(children);
            for (int i = 0; i < jumlahTelur; i++) {
                obj.bertelur();
            }
            System.out.printf("Number of Legs: %d, Child: %d\n", obj.getNumberOfLegs(), obj.getNumberOfChildren());
            System.out.println("Jumlah Telur: " + obj.getJumlahTelur());
            System.out.println("Animal Power: " + obj.getAnimalPower());
        }
        else if (type == 2) { // gajah
            int basePower = 10;
            int children = myInput.nextInt();
            int jumlahGading = myInput.nextInt();
            Gajah obj = new Gajah(basePower, jumlahGading);
            obj.increaseChild(children);
            System.out.printf("Number of Legs: %d, Child: %d\n", obj.getNumberOfLegs(), obj.getNumberOfChildren());
            System.out.println("Jumlah Gading: " + obj.getJumlahGading());
            System.out.println("Animal Power: " + obj.getAnimalPower());
        } else { // serigala
            int basePower = 10;
            int children = myInput.nextInt();
            boolean kawanan = myInput.nextBoolean();
            Serigala obj = new Serigala(basePower, kawanan);
            obj.increaseChild(children);
            System.out.printf("Number of Legs: %d, Child: %d\n", obj.getNumberOfLegs(), obj.getNumberOfChildren());
            if (kawanan) System.out.println("Serigala berada di dalam kawanan");
            else System.out.println("Serigala tidak berada di dalam kawanan");
            System.out.println("Animal Power: " + obj.getAnimalPower());
        }
    }
}