public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t=scanner.nextInt();
		int[] days={31,28,31,30,31,30,31,31,30,31,30,31};
		for(int i=0;i<t;i++) {
			String s = scanner.next();
			int month = (s.charAt(4)-'0')*10+(s.charAt(5)-'0');
			int day = (s.charAt(6)-'0')*10+(s.charAt(7)-'0');
			System.out.print("#"+(i+1)+" ");
			if(month==0 || day>days[month-1]) {
				System.out.println("-1");
			}
			else {
				System.out.println(s.substring(0,4)+"/"+s.substring(4,6)+"/"+s.substring(6,8));
			}
		}
	}
