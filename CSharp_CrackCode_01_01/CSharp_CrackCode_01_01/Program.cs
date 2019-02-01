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
            if (IsAllUniqueCharApproach2(inputString))
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

        static bool IsAllUniqueCharApproach2(string word)
        {
            bool[] charactersFlag = new bool[255];
            foreach (char c in word)
            {
                int asciiVal = (int)c;
                if (!charactersFlag[asciiVal])
                {
                    charactersFlag[asciiVal] = true;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }


        /**
         If you are not allowed to use additional data structures then you can do either of the following:
        a> Compare each character with other character. O(n^2) solution.
        b> Modify input string: Sort input string and then compare each character with next. Sort O(nLogn) and unique function O(n).
         */
    }
}
