public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t=scanner.nextInt();
		for (int i = 0; i < t; i++) {
			float sum=0;
			for(int j=0;j<10;j++) {
				int num=scanner.nextInt();
				sum+=num;
			}
			System.out.println("#"+(i+1)+" "+Math.round(sum/10));
		}
		scanner.close();
	}
