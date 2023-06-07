import java.util.*;

public class Main1 {
	public static void main(String[] args) {
		Scanner myInput = new Scanner(System.in);

		int Q = myInput.nextInt();

		TreeSet<Integer> TreeSet = new TreeSet<Integer>();
		ArrayList<String> arr = new ArrayList<String>();
		int param;

		for (int i = 0; i < Q; i++) {
			String text = myInput.next();
			switch(text) {
				case "add":
					param = myInput.nextInt();
					TreeSet.add(param);
					break;
				case "remove":
					param = myInput.nextInt();
					if (TreeSet.contains(param)) {
						TreeSet.remove(param);
					}
					else arr.add(String.format("Element %d is not in The TreeSet", param));
					break;
				case "first":
					if (TreeSet.size() != 0) {
						arr.add(TreeSet.first().toString());
					}
					else arr.add("EMPTY");
					break;
				case "last":
					if (TreeSet.size() != 0) {
						arr.add(TreeSet.last().toString());
					}
					else arr.add("EMPTY");
					break;
			}
		}

		for (String str : arr) System.out.println(str);
	}
}
