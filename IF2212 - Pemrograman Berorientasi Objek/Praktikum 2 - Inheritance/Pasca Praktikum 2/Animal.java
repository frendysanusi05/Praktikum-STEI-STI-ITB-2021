/**
 * Animal.java
 * Memodelkan hewan di suatu kerajaan hewan
 * @author 18221041 Frendy Sanusi
 */

public abstract class Animal {

    private int numberOfLegs;
    private long children;

    public Animal(int numberOfLegs) {
        // Konstruktor, set children = 0
        this.numberOfLegs = numberOfLegs;
        this.children = 0;
    }

    public int getNumberOfLegs() {
        // Mengembalikan atribut numberOfLegs
        return numberOfLegs;
    }

    public long getNumberOfChildren() {
        // Mengembalikan atribut children
        return children;
    }

    public void increaseChild(long inc) {
        // Meningkatkan nilai atribut children
        children += inc;
    }

    public String toString() {
        // Mengembalikan informasi hewan dengan format: "Number of Legs: {numberOfLegs}, Children: {children}"
        return String.format("Number of Legs: %d, Children: %d", numberOfLegs, children);
    }

    public abstract long getAnimalPower();
}
