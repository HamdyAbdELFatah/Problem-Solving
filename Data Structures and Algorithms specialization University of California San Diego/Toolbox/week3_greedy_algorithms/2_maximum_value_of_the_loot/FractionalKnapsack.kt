import java.util.*
fun main(args: Array<String>) {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt();var sum=0.0
    var capacity = scanner.nextInt()
    val loot = ArrayList<Loot>(n)
    for (i in 0 until n) {
        loot.add(Loot(scanner.nextInt(),scanner.nextInt()))
    }
    val sortedList = loot.sortedWith(compareBy { it.v*1.0/it.w })
    for (i in sortedList.size-1 downTo 0){
        if(capacity-(sortedList[i].w)>=0) {
            sum += sortedList[i].v
            capacity-=sortedList[i].w
            if(capacity==0)
                break
        }else {
            sum += (sortedList[i].v *capacity*1.0/sortedList[i].w  )
            break
        }
    }
    println(String.format("%.4f",sum))
}
class Loot(val v: Int,val w: Int)