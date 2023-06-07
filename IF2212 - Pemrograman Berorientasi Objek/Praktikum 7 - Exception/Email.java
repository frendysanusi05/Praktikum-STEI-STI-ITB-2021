public class Email {
    private String email; 
    public Email(String email) {
		this.email = email;
    };
    
    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */
        int address = 0;
        int lenBefore = 0;
        int lenAfter = 0;
        int dot = 0;
        for (int i = 0; i < email.length(); i++) {
			if (email.charAt(i) != '@') {
				if (address == 0) lenBefore++;
				else {
					
					if (email.charAt(i) == '.' && lenAfter != 0 && i != email.length()-1) {
						dot++;
					}
					lenAfter++;
				}
			}
			else {
				address++;
			}
		}
		
		if (address == 1 && lenBefore != 0 && dot == 1) return true;
		else {
			if (email.length() == 0) throw new InvalidEmailException("Email tidak boleh kosong");
			else if (address == 0) throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
			else if (lenBefore == 0) throw new InvalidEmailException("@ tidak boleh di awal email");
			else throw new InvalidDomainException();
		}
    }

}

class InvalidEmailException extends Exception {
	private String message;
    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        this.message = message;
    }
    
    public String getMessage() {
		return message;
	}
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid
        return "Email harus memiliki domain yang valid";
    }
}
