public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int[] nums = new int[n];
		for(int i=0;i<n;i++) {
			nums[i]=scanner.nextInt();
		}
		Arrays.sort(nums);
		System.out.println(nums[n/2]);
	}
