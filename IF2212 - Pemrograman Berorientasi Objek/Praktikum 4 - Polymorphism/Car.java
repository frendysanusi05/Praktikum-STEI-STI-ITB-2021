/**
 * Car.java
 * [Jelaskan kegunaan class ini]
 * @author 18221041 Frendy Sanusi
 */
public class Car {
    private int numberOfWheels;
    private int engineCapacity;
  
    public Car(int numberOfWheels,int engineCapacity) {
        this.numberOfWheels=numberOfWheels;
        this.engineCapacity=engineCapacity;

    }
  
    public int getNumberOfWheels() {
        return this.numberOfWheels;
    }
  
    public int getEngineCapacity() {
        return this.engineCapacity;
    }
    
    public String sound(){
        return "Ngenggg";
    }
    public String honk(){
        return "Din";
    }
    public String printDescription(){
        return String.format("Mobil ini memiliki %d roda dengan kapasitas mesin %d cc", this.numberOfWheels, this.engineCapacity);
    }
}

