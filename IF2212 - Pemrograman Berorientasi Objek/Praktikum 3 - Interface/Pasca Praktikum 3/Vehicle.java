/* @author 18221041 Frendy Sanusi */

public interface Vehicle {
    public int getNumberOfWheels();
    public int getMaxSpeed();
    public String getFuelType();
    public void start();
    public void stop();
    public void turn(String direction);
}