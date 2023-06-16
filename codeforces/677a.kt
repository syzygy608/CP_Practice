import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*
 
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()
 
fun main()
{
    var (n, h) = input.readLine().split(" ").map{it.toInt()}
    var a = input.readLine().split(" ").map{it.toInt()}
    var ans = 0
    for(i in 0..n-1)
    {
        if(a[i] > h)
            ans += 2
        else
            ans += 1
    }
    print(ans)
}
 
