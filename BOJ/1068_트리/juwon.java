import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class 트리_1068 {

	static List<Integer> [] tree;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		tree = new ArrayList[N];

		int root = 0;

		int deleteNode = Integer.parseInt(br.readLine());

		for(int i = 0; i < N; i++){
			tree[i] = new ArrayList<>();
		}

		for(int i = 0; i < N; i++){
			int parentNode = Integer.parseInt(st.nextToken());
			if(parentNode != -1){
				tree[parentNode].add(i);
			}else{
				root = i;
			}
		}

		int i = countLeaf(deleteNode, root);
		System.out.println(i);
	}
	static int countLeaf(int deleteNode, int root){
		Queue<Integer> que = new LinkedList<>();
		int res = 0;

		if(deleteNode == root) return 0;

		que.add(root);

		while (!que.isEmpty()){
			int node = que.poll();
			int cnt = 0;

			for (Integer integers : tree[node]) {
				if( integers != deleteNode){
					que.add(integers);
					cnt++;
				}
			}
			if(cnt == 0){
				res++;
			}
		}
		return res;
	}

}
