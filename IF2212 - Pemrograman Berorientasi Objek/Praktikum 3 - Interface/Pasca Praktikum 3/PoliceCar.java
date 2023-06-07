/* @author 18221041 Frendy Sanusi */

public class PoliceCar implements TrackableVehicle {
    private String plateNumber;
    private Point gpsPosition;
    private int speed;
    private String direction;
    private int wheel;
    private String fuelType;
    private boolean started;

    public PoliceCar(String plateNumber, Point gpsPosition, int speed, int wheel, String fuelType) {
        this.plateNumber = plateNumber;
        this.gpsPosition = gpsPosition;
        direction = "North";
        this.speed = speed;
        this.wheel = wheel;
        this.fuelType = fuelType;
        started = false;
    }

    public int getNumberOfWheels() {
        return wheel;
    }

    public int getMaxSpeed() {
        return speed;
    }

    public String getFuelType() {
        return fuelType;
    }

    public String getPlateNumber() {
        return plateNumber;
    }

    public Point getGPSPosition() {
        return gpsPosition;
    }

    public String getDirection() {
        return direction;
    }

    public boolean getStarted() {
        return started;
    }

    public void start() {
        started = true;
    }

    public void stop() {
        started = false;
    }

    public void turn(String direction) {
        this.direction = direction;
    }
}