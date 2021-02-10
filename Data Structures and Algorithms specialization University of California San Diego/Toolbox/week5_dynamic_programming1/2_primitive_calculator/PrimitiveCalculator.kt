import java.util.*
import kotlin.collections.ArrayList
fun main() {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()
    val values =Array(n+1){n+1}
    val sequence =Array(n+1){n+1}
    values[1]=0
    for(i in 1 until values.size){
        if(values[i-1]<values[i]) {
            values[i] = values[i - 1] + 1
        }
        if(i%2==0)
            if(values[i/2]<values[i]) {
                values[i] = values[i/2] + 1
            }
        if(i%3==0)
            if(values[i/3]<values[i]) {
                values[i] = values[i/3] + 1
            }
        sequence[values[i]] = i

    }
    println(values.last())
    for(i in 0 ..  values.last() )
        print("${sequence[i]} ")
}
