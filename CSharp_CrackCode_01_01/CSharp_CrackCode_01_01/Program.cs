using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_CrackCode_01_01
{
    class Program
    {
        /*
        Implement an algorithm to determine if a string has all unique characters  What if you
        can not use additional data structures?
        --> What if you cannot use additional data structures? Solution on next project.
        */
        static void Main(string[] args)
        {
            Console.Write("Enter a word to test if it has all unique characters:");
            string inputString = Console.ReadLine();
            if (IsAllUniqueChar(inputString))
            {
                Console.WriteLine("All characters are unique!!!");
            }
            else
            {
                Console.WriteLine("All characters are NOT unique!!!");
            }
            Console.ReadKey();
        }

        static bool IsAllUniqueChar(string word)
        {
            HashSet<char> uniqueCharSet = new HashSet<char>();
            foreach (var c in word)
            {
                if (uniqueCharSet.Contains(c))
                {
                    return false;
                }
                uniqueCharSet.Add(c);
            }

            return true;
        }
    }
}
