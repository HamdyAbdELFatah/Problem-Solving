import java.util.*


fun main(args: Array<String>) {
    val scanner = Scanner(System.`in`)
    val m = scanner.nextInt()
    val coins=intArrayOf(1,3,4)
    var arr = IntArray(m+1){m+1}
    arr[0]=0
    for (i in 1 until arr.size) {
       for(j in coins){
           if(j>i)
               break
           arr[i]=Math.min(arr[i-j]+1,arr[i])
       }
    }
    /*for (i in arr)
        println(i)*/
    println(arr.last())
}