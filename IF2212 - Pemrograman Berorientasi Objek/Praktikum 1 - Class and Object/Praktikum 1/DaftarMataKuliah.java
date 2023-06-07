/*
 * Nama: Frendy Sanusi
 * NIM: 18221041
 * Tanggal: 31 Januari 2023
 * Topik Praktikum: Praktikum 1 - Class and Object
 * Deskripsi: Melakukan pendataan mata kuliah baru pada semester ini.
 */

import java.util.Scanner;

public class DaftarMataKuliah {
	public static void main (String[] args) {
		// build Scanner object
		Scanner myInput = new Scanner(System.in);
		
		// scan
		String kode = myInput.nextLine();
		String nama = myInput.nextLine();
		int sks = myInput.nextInt();
		String dosen = myInput.next();
		int kapasitas = myInput.nextInt();
		int tambahan = myInput.nextInt();
		
		System.out.printf("Kode Mata Kuliah: %s\n", kode);
		System.out.printf("Nama Mata Kuliah: %s\n", nama);
		System.out.printf("SKS Mata Kuliah: %d\n", sks);
		System.out.printf("Nama Dosen: %s\n", dosen);
		System.out.printf("Kapasitas Kuliah: %d\n", kapasitas);
		System.out.printf("Total Revisi Kapasitas Kuliah: %d\n", kapasitas+tambahan);
	}
}
