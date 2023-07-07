import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*
 
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()
 
fun main()
{
    repeat(input.readLine().toInt())
    {
        var n = input.readLine().toInt()
        if(n % 2 == 0)
        {
            for(i in 1..n step 2)
            {
                output.append(i + 1)
                output.append(" ")
                output.append(i)
                output.append(" ")
            }
        }
        else
        {
            output.append("3 1 2 ")
            for(i in 4..n step 2)
            {
                output.append(i + 1)
                output.append(" ")
                output.append(i)
                output.append(" ")
            }
        }
        output.append("\n")
        print(output)
        output.clear()
    }
}
 
