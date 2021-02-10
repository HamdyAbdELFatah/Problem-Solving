import java.util.*
fun main(args: Array<String>) {
    val scanner = Scanner(System.`in`)
    val d = scanner.nextInt();var count=0;var start=0
    val m = scanner.nextInt()
    val n = scanner.nextInt();
    val stop = IntArray(n)
    for (i in 0 until n)
        stop[i]= scanner.nextInt()
    if(n>1) {
        for (i in 0 until n - 1) {
            if (stop[i + 1] - start <= m)
                continue
            else {
                count++
                start = stop[i]
                if (start + m < stop[i + 1]) {
                    count = -1
                    break
                }
            }
        }
        if (start + m < d && count != -1) {
            start = stop[n - 1]
            if (start + m < d)
                count = -1
            else
                count++
        }
    }else{
        if (start + m >= stop[0] &&  m + stop[0]>=d)
                count++
         else
                count=-1

    }
    println(count)

}