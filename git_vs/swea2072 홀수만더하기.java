public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t=scanner.nextInt();
		for (int i = 0; i < t; i++) {
			int sum=0;
			for(int j=0;j<10;j++) {
				int num=scanner.nextInt();
				if(num%2==1) {
					sum+=num;
				}
			}
			System.out.println("#"+(i+1)+" "+sum);
		}
		scanner.close();
	}
