public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t=scanner.nextInt();
		for (int i = 0; i < t; i++) {
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			System.out.print("#"+(i+1));
			if(a>b)System.out.println(" >");
			else if(a<b)System.out.println(" <");
			else {
				System.out.println(" =");
			}
		}
		scanner.close();
	}
