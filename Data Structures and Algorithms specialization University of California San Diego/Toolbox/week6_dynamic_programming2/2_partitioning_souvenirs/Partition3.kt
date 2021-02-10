import java.util.*

fun partition3(arr: IntArray): Int {
    val sum = arr.sum()
    val n=arr.size
    val status = Array(sum / 3 + 1) { BooleanArray(n + 1) }
    for (i in 0..n) {
        status[0][i] = true
    }
    for (i in 0.. sum / 3) {
        status[i][0] = false
    }
    for (i in 1..sum / 3) {
        for (j in 1..n) {
            status[i][j] = status[i][j - 1]
            if (i >= arr[j - 1])
                status[i][j] = status[i][j] || status[i - arr[j - 1]][j - 1]
        }
    }
    return if(status[sum / 3][n]) 1 else 0
}
fun main(args: Array<String>) {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()
    val arr = IntArray(n)
    var sum=0
    for (i in 0 until n) {
        arr[i] = scanner.nextInt()
        sum+=arr[i]
    }
    if(sum%3==0)
        println(partition3(arr))
    else
        println(0)
}