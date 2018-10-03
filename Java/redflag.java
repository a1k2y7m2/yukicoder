import java.util.*;

public class redflag{
	private static int Count (String[] A){
		int count = 0;
		for (int i=0; i<A.length; i++){
			for (int j=0; j<A[i].length(); j++){
				if (A[i].charAt(j) == 'W'){count+=1;}
			}
		}

		return count;
	}

	public static void main(String[] args){
		//Read input
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();

		String A[] = new String[N];

		for(int i=0; i<N; i++){
			A[i] = sc.next();
		}

		System.out.println(Count(A));
	}
}