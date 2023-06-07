/**
 * DaftarMahasiswa.java
 * Melakukan pendataan mahasiswa baru
 * @author 18221041 Frendy Sanusi
 */

import java.util.Scanner;

public class DaftarMahasiswa {
    public static void main(String[] args) {
        // build Scanner object
        Scanner myInput = new Scanner(System.in);
        
        // scan
        String nama = myInput.nextLine();
        String nim = myInput.nextLine();
        int sks = myInput.nextInt();
        int sks_tambahan = myInput.nextInt();

        // build Mahasiswa object
        Mahasiswa mhs = new Mahasiswa(nama, nim, sks);
        
        System.out.printf("Nama mahasiswa: %s\n", nama);
        System.out.printf("NIM mahasiswa: %s\n", nim);
        System.out.printf("SKS mahasiswa: %d\n", sks);
        System.out.printf("Jumlah mahasiswa: %d\n", mhs.getJumlahMahasiswa());
        System.out.printf("Total Revisi SKS mahasiswa: %d\n", sks+sks_tambahan);
    }
}