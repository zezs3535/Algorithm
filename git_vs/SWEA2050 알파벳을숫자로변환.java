public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		for(int i=0;i<s.length();i++) {
			System.out.print(s.charAt(i)-'A'+1+" ");
		}
	}
