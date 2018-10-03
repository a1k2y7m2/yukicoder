import java.util.*;

public class distance{
	public static int calculate_max(int[] A){
		return A[A.length-1] - A[0];
	}

	public static int calculate_min(int[] A){
		int min_dis = calculate_max(A);
		try{
			for (int i = 0; i<A.length-1; i++){
				if (A[i+1]-A[i] < min_dis) {min_dis = A[i+1]-A[i];}
			}
		}catch(IndexOutOfBoundsException e){
			e.printStackTrace();
		}
		return min_dis;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		// Read input
		int N = sc.nextInt();
		int A[];
		A = new int[N];
		for (int i = 0; i<N; i++){
			A[i] = sc.nextInt();
		}

		// Make output
		System.out.println(calculate_min(A));
		System.out.println(calculate_max(A));
	}
}