import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class 트리순회_1991 {

	// char A => 65, B => 66, C => 67...
	static class myNode {
		int left;
		int right;
		public myNode(int left, int right){
			this.left = left;
			this.right = right;
		}
	}
	
	static List<myNode>[] list;

	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt( br.readLine() );

		// 최하위 노드의 하위 노드를 순회해야하기 때문에 + 1
		list = new ArrayList[N + 1];

		for(int i = 1; i < N + 1; i++){
			list[i] = new ArrayList<>();
		}

		for(int i = 1; i < N + 1; i++){
			String [] s = br.readLine().split(" ");
			// 부모 노드 ( 둘다 . 인경우 최하위 노드)
			int data = s[0].charAt(0) - 65 + 1;
			// 하위 노드의 왼쪽
			int left = s[1].charAt(0) - 65 + 1;
			// 하위 노드의 오른쪽
			int right = s[2].charAt(0) - 65 + 1;
			list[data].add(new myNode(left, right));
		}
		preOrderTraversal(1);
		sb.append("\n");
		inOrderTraversal(1);
		sb.append("\n");
		postOrderTraversal(1);
		sb.append("\n");
		System.out.println(sb);
	}

	//	전위 순회 VLR
	static void preOrderTraversal(int start){
		for (myNode node : list[start]) {
			int leftNode = node.left;
			int rightNode = node.right;

			char dot = '.';
			char root = 'A';
			//V
			sb.append((char)(start + 'A' - 1));
			//L
			if(leftNode != (dot - root) + 1){
				preOrderTraversal(leftNode);
			}
			//R
			if( rightNode != (dot - root) + 1){
				preOrderTraversal(rightNode);
			}
		}
	}

	// 중위 순회 LVR
	static void inOrderTraversal(int start){
		for (myNode myNode : list[start]) {
			int leftNode = myNode.left;
			int rightNode = myNode.right;
			// L
			if(leftNode != -18){
				inOrderTraversal(leftNode);
			}
			// V
			sb.append((char)(start + 'A' - 1));

			// R
			if(rightNode != -18){
				inOrderTraversal(rightNode);
			}

		}
	}

	// 후위 순회 LRV
	static void postOrderTraversal(int start){
		for (myNode myNodes : list[start]) {
			int leftNode = myNodes.left;
			int rightNode = myNodes.right;
			// L
			if(leftNode != -18){
				postOrderTraversal(leftNode);
			}
			// R
			if(rightNode != -18){
				postOrderTraversal(rightNode);
			}
			// V
			sb.append((char)(start + 'A' - 1));
		}
	}
}
