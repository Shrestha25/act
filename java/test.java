class Test {
    public static String solution(int i) {
        int element=3;
        String s="2";
        while(s.length()<i+5){
            int flag=1;
            for(int j=3;j*j<=element;j+=2){
                if(element%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                String s2=String.valueOf(element);
                s=s+s2;
            }
            element+=2;
        }
        System.out.println(s);
        return s.substring(i,i+5);
    }

	public static void main (String[] args) {
		String ans=solution(5);
        System.out.println(ans);
	}
}