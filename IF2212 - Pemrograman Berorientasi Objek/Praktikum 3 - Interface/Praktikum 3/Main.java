public class Main {
	public static void main(String[] args) {
		CasioGraph casio = new CasioGraph(1,5);
		casio.start();
		
		System.out.printf("Baterai: %d\n", casio.checkBattery());
		for (int i = 0; i < 15; i++) {
			System.out.println(casio.add(7,6));
		}
		casio.charge();
		System.out.println(casio.add(7,6));
	}
}
