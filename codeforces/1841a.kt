import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*
 
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()
 
fun main()
{
    var t = input.readLine().toInt()
    while(t-- > 0)
    {
        var n = input.readLine().toInt()
        when
        {
            (n <= 4) -> output.append("Bob\n")
            else -> output.append("Alice\n")
        }
    }
    print(output)
}
 
