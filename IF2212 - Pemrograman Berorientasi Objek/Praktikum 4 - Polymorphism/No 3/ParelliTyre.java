public class ParelliTyre implements Tyre {
    private int pressure;
    private int width;

    public ParelliTyre(int pressure, int width) {
        // Konstruktor
        this.pressure = pressure;
        this.width = width;
    }

    @Override
    public int getTyrePressure() {
        // Mengembalikan pressure
        return pressure;
    }

    @Override
    public int getTyreWidth() {
        // Mengembalikan width
        return width;
    }

    @Override
    public Boolean isSlickTyre() {
        // Mengembalikan isSlick
        return true;
    }
}
