
import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class JobQueue {

    private int[] jobs;
    PriorityQueue<Long> pq = new PriorityQueue<>();
    Map<Long, PriorityQueue<Long>> map = new HashMap();
    Map<Long, Job> mQueue = new HashMap();
    Long c = 0L;
    Long time = 0L;
    private FastScanner in;
    private PrintWriter out;

    static class Job {

        public Job(Long thread, Long start, Long end) {
            this.thread = thread;
            this.start = start;
            this.end = end;
        }
        Long thread;
        Long start;
        Long end;
    }

    public static void main(String[] args) throws IOException {
        new JobQueue().solve();
    }

    private void readData() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        jobs = new int[m];
        for (int i = 0; i < m; ++i) {
            Long duration = in.nextLong();
            if (c < n) {
                Long key = duration;
                pq.add(key);
                if (map.containsKey(key)) {
                    PriorityQueue<Long> q = map.get(key);
                    q.add(c);
                    mQueue.put(c, new Job(c, time, duration));
                    map.put(key, q);
                } else {
                    PriorityQueue<Long> q = new PriorityQueue<>();
                    q.add(c);
                    mQueue.put(c, new Job(c, time, duration));
                    map.put(key, q);
                }
                System.out.println(c + " " + 0);
            } else {
                PriorityQueue<Long> j = map.get(pq.remove());
                Job remove = mQueue.get(j.remove());                                          
                Long key = (remove.end + duration);
                pq.add(key);
                if(map.containsKey(key)){                  
                    PriorityQueue<Long> q = map.get(key); 
                    q.add(remove.thread);
                    mQueue.put(remove.thread, new Job(remove.thread, remove.end, remove.end + duration));
                    map.put(key, q);
                }else{
                    PriorityQueue<Long> q = new PriorityQueue<>();
                    q.add(remove.thread);
                    mQueue.put(remove.thread, new Job(remove.thread, remove.end, remove.end + duration));
                    map.put(key, q);
                }
                System.out.println(remove.thread + " " + (remove.end));
            }
            if (duration != 0) {
                c++;
            }
        }
    }

    public void solve() throws IOException {
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        readData();
//        while (pq.iterator().hasNext()) {
//                Queue<Long> j=map.get(pq.remove());
//                Job remove=mQueue.get(j.remove());
//                System.out.println(remove.thread+" "+remove.start);
//        }
        out.close();
    }

    static class FastScanner {

        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public Long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}
