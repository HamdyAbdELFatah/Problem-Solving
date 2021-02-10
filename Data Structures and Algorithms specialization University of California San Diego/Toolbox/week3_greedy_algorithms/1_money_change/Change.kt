import java.util.*

fun getChange(m: Int): Int {
    var sum=0;var count=0;
    while(sum<m) {
        if (sum + 10 <= m)
            sum += 10;
        else if (sum + 5 <= m)
            sum += 5;
        else
            sum++
        count++
    }
    return count
}

fun main(args: Array<String>) {
    val scanner = Scanner(System.`in`)
    val m = scanner.nextInt()
    println(getChange(m))
}