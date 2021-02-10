import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class CharStack(val index:Int, val char:Char)

fun main(args: Array<String>) {
    val inputStream = InputStreamReader(System.`in`)
    val reader = BufferedReader(inputStream)
    val text = reader.readLine()
    val stack = Stack<CharStack>()
    for (element in text.indices) {
        val next = text[element]
        if (next == '(' || next == '[' || next == '{') {
            stack.push(CharStack(element+1, next))
        }
        if (next == ')' || next == ']' || next == '}') {
            if (stack.size > 0) {
                val char = stack.peek().char
                if ((char == '(' && next == ')') || (char == '[' && next == ']') || (char == '{' && next == '}')) {
                    stack.pop()
                } else {
                    stack.push(CharStack(element+1, next))
                    break
                }
            } else {
                stack.push(CharStack(element+1, next))
                break
            }
        }
    }

    if (stack.size > 0) {
        println(stack.peek().index)
    } else {
        println("Success")
    }

}
