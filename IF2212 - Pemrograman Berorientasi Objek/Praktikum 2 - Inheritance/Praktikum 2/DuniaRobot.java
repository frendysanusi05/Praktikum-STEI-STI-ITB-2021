/**
 * DuniaRobot.java
 * Menghitung harga dan spesifikasi masing-masing model robot
 * @author 18221041 Frendy Sanusi
 */

import java.util.Scanner;

public class DuniaRobot {
	public static void main (String[] args) {
		// build Scanner object
		Scanner myInput = new Scanner(System.in);
		
		// scan
		int type = myInput.nextInt();
		
		if (type == 1) { // bumblebee
			int numberOfParts = myInput.nextInt();
			int totalTransformation = myInput.nextInt();
			boolean isActive = myInput.nextBoolean();
			Bumblebee obj = new Bumblebee(numberOfParts, isActive);
			for (int i = 0; i < totalTransformation; i++) {
				obj.addTransformation();
			}
			System.out.println(obj.toString());
			System.out.println("Jumlah transformasi: " + obj.getTotalTransformation());
			System.out.println("Harga robot: " + obj.getPrice());
		}
		else if (type == 2) { // sirik
			long price = myInput.nextLong();
			int totalModel = myInput.nextInt();
			Sirik obj = new Sirik(price);
			for (int i = 0; i < totalModel; i++) {
				obj.addModel();
			}
			System.out.println(obj.toString());
			System.out.println("Jumlah model: " + obj.getTotalModel());
			System.out.println("Harga robot: " + obj.getPrice());
		} else {
			int mileage = myInput.nextInt();
			boolean isActive = myInput.nextBoolean();
			WallE obj = new WallE(mileage, isActive);
			System.out.println(obj.toString());
			System.out.println("Jumlah mileage: " + obj.getMileage());
			System.out.println("Harga robot: " + obj.getPrice());
		}
	}
}
