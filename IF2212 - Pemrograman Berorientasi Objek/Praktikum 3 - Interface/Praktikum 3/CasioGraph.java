/* @author 18221041 Frendy Sanusi */

public class CasioGraph implements GraphCalculator {
	private Point point;
	private int batteryLevel;
	private boolean status;
	
	public CasioGraph(int x, int y) {
		point = new Point(x, y);
		batteryLevel = 100;
		status = false;
	}
	
	public int add(int a, int b) {
		/* Menambahkan nilai kedua parameter */
		if (batteryLevel <= 0) status = false;
		if (!status) return -1;
		else {
			batteryLevel -= 10;
			return a + b;
		}
	}
	
	public int substract(int a, int b) {
		/* Mengurangi nilai parameter pertama sebesar parameter kedua */
		if (batteryLevel <= 0) status = false;
		if (!status) return -1;
		else {
			batteryLevel -= 10;
			return a - b;
		}
	}
	
	public int multiply(int a, int b) {
		/* Mengalikan nilai kedua parameter */
		if (batteryLevel <= 0) status = false;
		if (!status) return -1;
		else {
			batteryLevel -= 10;
			return a * b;
		}
	}
	
	public double divide(int a, int b) {
		/* Membagi nilai parameter pertama dengan parameter kedua */
		if (batteryLevel <= 0) status = false;
		if (!status) return -1;
		else {
			batteryLevel -= 10;
			return a/b;
		}
	}
	
	public void start() {
		/* Menghidupkan kalkulator. Apabila battery = 0, maka kalkulator tidak dapat hidup */
		if (batteryLevel <= 0) status = false;
		else status = true;
	}
	
	public void stop() {
		/* Mematikan kalkulator */
		status = false;
	}
	
	public int checkBattery() {
		/* Memeriksa battery kalkulator */
		return batteryLevel;
	}
	
	public void shiftX(int a) {
		/* Menambahkan nilai X pada point sebesar parameter */
		if (batteryLevel <= 0) status = false;
		if (status) {
			point.setX(point.getX() + a);
			batteryLevel -= 10;
		}
	}
	
	public void shiftY(int a) {
		/* Menambahkan nilai Y pada point sebesar parameter */
		if (batteryLevel <= 0) status = false;
		if (status) {
			batteryLevel -= 10;
			point.setY(point.getY() + a);
		}	
	}
	
	public double distance(int a, int b) {
		/* Menghitung jarak titik pada kelas dengan titik pada parameter dengan rumus V(x1 - x2)^2 + (y1 - y2)^2 */
		if (batteryLevel <= 0) status = false;
		if (!status) return -1;
		else {
			batteryLevel -= 10;
			return (double)Math.sqrt((Math.pow(point.getX()-a,2)) + (Math.pow(point.getY()-b,2)));
		}
	}
	
	public boolean getStatus() {
		/* Mengembalikan status kalkulator */
		return status;
	}
	
	public Point getPoint() {
		/* Mengembalikan nilai point yang disimpan oleh kalkulator */
		return point;
	}
	
	public void charge() {
		/* Menambahkan batteryLevel hingga 100 */
		batteryLevel = 100;
		status = true;
	}
}
