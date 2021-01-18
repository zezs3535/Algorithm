public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t=scanner.nextInt();
		for (int i = 0; i < t; i++) {
			int m=0;
			for(int j=0;j<10;j++) {
				int tmp=scanner.nextInt();
				if(m<=tmp)m=tmp;
			}
			System.out.println("#"+(i+1)+" "+m);
		}
		scanner.close();
	}
