/**
 * Gajah.java
 * Memodelkan kelas Gajah
 * @author 18221041 Frendy Sanusi
 */

public class Gajah extends Animal {

    private long basePower;
    private long jumlahGading;

    public Gajah(long basePower, int jumlahGading) {
        // Konstruktor, jumlah gading minimal 0 maksimal 2
        super(4);
        this.basePower = basePower;
        if (jumlahGading >= 2) this.jumlahGading = 2;
        else if (jumlahGading <= 0) this.jumlahGading = 0;
        else this.jumlahGading = jumlahGading;
    }

    public long getJumlahGading(){
        // Mengembalikan jumlahGading
        return jumlahGading;
    }

    @Override
    public long getAnimalPower() {
        // Mengembalikan kekuatan Gajah dengan formula 3 * basePower * (1 + jumlahGading)
        return 3 * basePower * (1 + jumlahGading);
    }
}
