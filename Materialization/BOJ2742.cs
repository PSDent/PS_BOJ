using System;
using System.Text;

namespace ACMICPC_CS
{
    class BOJ2742
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            StringBuilder sb = new StringBuilder();

            for (int i = n; i >= 1; --i)
                sb.AppendLine(i.ToString());
            Console.Write(sb.ToString());
        }
    }
}
