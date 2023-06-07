/**
 * @author 18221041 Frendy Sanusi
 */
public class DelayedCharacterPrinting {
    public static void printDelayed(int delayMillisec, String word) throws InterruptedException {
		new Thread(new Runnable() {
			public void run() {
				try {
					int len = word.length();
					for (int i = 0; i < len; i++) {
						Thread.sleep(delayMillisec);
						System.out.println(word.charAt(i));
					}
				}
				catch (Exception e) {
				}
			}
		});
		
    }
}
