public class V8Engine implements Engine {
    private int engineCapacity;
    private Boolean isSupercharged;

    public V8Engine(int engineCapacity, Boolean isSupercharged) {
        // Konstruktor
        this.engineCapacity = engineCapacity;
        this.isSupercharged = isSupercharged;
    }

    @Override
    public int getEngineCapacity() {
        // Apabila isSupercharged true, engineCapacity + 250
        // else kembalikan engineCapacity
        if (isSupercharged) return engineCapacity + 250;
        else return engineCapacity;
    }

    @Override
    public String sound() {
        // Kembalikan ngengngeng
        return "ngengngeng";
    }
}
