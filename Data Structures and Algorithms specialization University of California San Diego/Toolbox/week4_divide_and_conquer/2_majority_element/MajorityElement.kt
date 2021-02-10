import java.io.BufferedReader
import java.io.IOException
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.LinkedHashMap

fun getMajorityElement(a: IntArray, left: Int, right: Int): Int {
    if (left == right) return -1
    if (left + 1 == right) return a[left]
    val m:LinkedHashMap<Int,Int> = LinkedHashMap()
    for(i in a.iterator()){
        if(m[i]?:0>0) {
            m[i] = m[i]!! + 1
        }
        else {
            m[i] = 1
        }

        if(m[i]!!>a.size/2)
            return 1
    }

    return -1
}

fun main(args: Array<String>) {
    val scanner = FastScanner(System.`in`)
    val n = scanner.nextInt()
    val a = IntArray(n)
    for (i in 0 until n) {
        a[i] = scanner.nextInt()
    }
    if (getMajorityElement(a, 0, a.size) != -1) {
        println(1)
    } else {
        println(0)
    }
}

class FastScanner(stream: InputStream) {
    var br: BufferedReader = BufferedReader(InputStreamReader(stream))
    var st: StringTokenizer? = null

    fun next(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            try {
                st = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }
        }
        return st!!.nextToken()
    }

    fun nextInt() = next().toInt()
}