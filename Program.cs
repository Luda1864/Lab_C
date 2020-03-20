using System;


namespace zad3
{
    class Program
    {
        static void Main(string[] args)
        {
            /*Console.WriteLine("Задание 1");
            Console.Write("x=");
            float x = float.Parse(Console.ReadLine());
            Console.Write("y=");
            float y = float.Parse(Console.ReadLine());
            if (x > y) Console.WriteLine("max = "+x);
            else Console.WriteLine("max = "+y);*/

            /*Console.WriteLine("Задание 2");
            int Ball = 0;
            Console.Write("x = ");
            float x = float.Parse(Console.ReadLine());
            Console.Write("y = ");
            float y = float.Parse(Console.ReadLine());
            if (x * x + y * y <= 1) Ball = 10;
            else if (x * x + y * y <= 4) Ball = 5;
            else if (x * x + y * y <= 9) Ball = 1;
            Console.WriteLine("Ball = "+Ball);*/

            /*Console.WriteLine("Задание 3");
            Console.Write("OPER = ");
            char oper = char.Parse(Console.ReadLine());
            bool ok = true;
            Console.Write("A = ");
            int a = int.Parse(Console.ReadLine());
            Console.Write("B = ");
            int b = int.Parse(Console.ReadLine());
            float res = 0;
            switch (oper)
            {  case '+': res = a + b; goto case '-';   //1
               case '-': res = a - b; break;
               case '*': res = a * b; break;
               case ':': if (b != 0)
                   {
                   res = (float)a / b; break;
                   }
                   else goto default;
               default: ok = false; break;
            }
            if (ok == true)
            {
            Console.WriteLine("{0} {1} {2} = {3}", a, oper, b, res);
            }
            else
            {
            Console.WriteLine("error");
            }*/

            /*Console.WriteLine("Задание 4 - числа вводились в обратном порядке");
            Console.Write("N = ");
            int n = int.Parse(Console.ReadLine());
            int i = 1;
            while (n>=i)          
            Console.Write(" " + n--); */

            /*Console.WriteLine("Задание 4 - только нечетные");
            Console.Write("N = ");
            int n = int.Parse(Console.ReadLine());
            int i = 1;
            while (n >= i)
            {  if (n % 2 == 1)
                {
                    Console.Write(" " + n);
                }
                n--;
            }*/

            /*Console.WriteLine("Задание 5 - в обратном порядке");
            Console.Write("N = ");
            int n = int.Parse(Console.ReadLine());
            int i = n;
            do
               Console.Write(" " +i--); 
            while (i > 0); */

            /*Console.WriteLine("Задание 5 - четные числа");
            Console.Write("N = ");
            int n = int.Parse(Console.ReadLine());
            int i = n;
            do
                if (i % 2 == 0)
                    Console.Write(" " + i--);
                else i--;
            while (i > 0);*/

            /*Console.WriteLine("Задание 6 - обратный порядок");
            Console.Write("N = ");
            int n = int.Parse(Console.ReadLine());
            for (int i = n; i > 0;)       
            Console.Write(" " +i--);*/

            /*Console.WriteLine("Задание 6 - квадраты чисел");
            Console.Write("N = ");
            int n = int.Parse(Console.ReadLine());
            for (int i = n; i > 0;i--)
            Console.Write(" " + i*i);*/

            Console.WriteLine("Задание 7");
            Console.Write("N = ");
            int n = int.Parse(Console.ReadLine());
            Console.Write("M = ");
            int m = int.Parse(Console.ReadLine());
            for (int i = 1; i <= n; ++i, Console.WriteLine())  //строки
                for (int j = 1; j <= m; ++j) //столбцы
                    Console.Write(" " + 2);/**/
        }
    }
}
