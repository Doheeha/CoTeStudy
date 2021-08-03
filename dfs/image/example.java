package bfs.dfs.image;

import java.io.*;
import java.util.*;

public class example {
    static ArrayList<Integer>[] al;
    static boolean check[];

    static void bfs(int a) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(a);
        check[a] = true;

        while (!queue.isEmpty()) {
            int x = queue.poll();
            System.out.print(x + " ");
            for (int y : al[x]) {
                if (!check[y]) {
                    check[y] = true;
                    queue.add(y);
                }
            }
        }
    }

    static void dfs(int a) {
        if (check[a])
            return;

        check[a] = true;
        System.out.print(a + " ");
        for (int y : al[a])
            if (!check[y])
                dfs(y);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int V = Integer.parseInt(st.nextToken());

        al = new ArrayList[N + 1];
        for (int i = 0; i < N + 1; i++)
            al[i] = new ArrayList<Integer>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            al[a].add(b);
            al[b].add(a);
        }

        for (int i = 1; i < N + 1; i++) {
            Collections.sort(al[i]);
        }

        check = new boolean[N + 1];
        dfs(V);
        System.out.println();

        check = new boolean[N + 1];
        bfs(V);
    }
}
