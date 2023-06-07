import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner myInput = new Scanner(System.in);

		ArrayList<String> arr = new ArrayList<String>();

		String text1 = myInput.nextLine();
		String[] temp1 = text1.split(" ");

		String text2 = myInput.nextLine();
		String[] temp2 = text2.split(" ");

		for (String x : temp1) {
			for (String y : temp2) {
				if (x.equals(y)) {
					if (!(arr.contains(x))) arr.add(x);
				}
			}
		}

		int i = 0;
		System.out.print("[");
		for (String str : arr) {
			System.out.print(str);
			if (i != arr.size()-1) System.out.print(", ");
			i++;
		}
		System.out.print("]\n");
	}
}
