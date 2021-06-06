# Dynamic-Programming-With-BenchMarking
This project shows the example of dynamic prgramming with memoization.
Here I have taken a famous example of fibonacci series and tries to solve it using dynamic programming.
I have created a `Timer` class which will help me in benchmarking the various approaches.

In this example I have used __3 approaches__ to solve fibonacci series.<br>
The first approach I have used is __simple non-optimized recursive__ approach.<br>
When I run the code to get the fibonacci number of upto 5 elements, the program got completed in `0.0013ms`.<br>
Thats pretty fast huh!!<br>
Now the same programm I run it for upto 20 elements. That also got completed in `0.0067ms`.<br>
Thats also fast.<br>
Now when I tried to run it for 50 elements. The programm took more than `20sec`.<br>
Wait What!!? more than 20sec.<br>
Shocked!!!!<br>
That's because we are unnecessarily evaluating the same item again and again.<br>

Now let's see the 2nd approach. __The memoization__.<br>
In this approach we are storing the result once we calculate it. In this way we don't need to calculate the same thing again.
If the value is already there, just use it.<br>
So when I run it to get the fibonacci number of upto 5 elements, the program got completed in `0.0004ms`.<br>
Pretty fast HUH!!. Obviously it will be fast.<br>
Then I run it to get the number for upto 20 elements, and the programm got completed in `0.0009ms`.<br>
It's almost the same.<br>
Now I tried to run it to get the number upto 100 element. The programm took `0.0157ms`.<br>
Amazing, isn't it?<br>
The same program would have took more than few minutes if we have used the non-optimized way.<br>

The 3rd approach I have is the __bottoms-up approach__, where I have used simple integer array to store the values.
The performance of this approach is similar to the 2nd approach.


Here is the time taken comparision of upto 35 elements.
You can see the non-optimized took __11ms__ where as the optimised one took __0.0007ms__ maximum.


>Program Started!
>
>======== NonOptimized Recursive =====
>
>Result of Fibonacci upto 35 = 9227465
>Completed in 11.8849 ms
>
>======== Recursive with memoization =====
>
>Result of Fibonacci upto 35 = 9227465
>Completed in 0.0004 ms
>
>======== Bottoms-Up Approach =========
>
>Result of Fibonacci upto 35 = 9227465
>Completed in 0.0007 ms
>Program Finished!
