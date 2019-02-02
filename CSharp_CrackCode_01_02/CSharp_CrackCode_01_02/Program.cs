using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_CrackCode_01_02
{
    class Program
    {
        /* Given two strings. Write program to decide if one is permutation of another.        
         */
        static void Main(string[] args)
        {
            string originalString = string.Empty;
            string inputString = string.Empty;

            Console.WriteLine("Enter original string: ");
            originalString = Console.ReadLine();

            Console.WriteLine("Enter input string: ");
            inputString = Console.ReadLine();

            if (IsPermutationUsingHashTableLikeDS(originalString, inputString))
            {
                Console.WriteLine(inputString + " is permutation of " + originalString);
            }
            else
            {
                Console.WriteLine(inputString + " is NOT permutation of " + originalString);
            }

            Console.ReadKey();
        }

        static bool IsPermutationUsingSort(string originalString, string inputStringForCheck)
        {
            if (string.IsNullOrEmpty(originalString) || string.IsNullOrEmpty(inputStringForCheck))
            {
                return false;
            }

            if (originalString.Trim().Count() != inputStringForCheck.Trim().Count())
            {
                return false;
            }

            char[] originalStringChar = originalString.ToCharArray();
            char[] inputStringChar = inputStringForCheck.ToCharArray();
            Array.Sort(originalStringChar);
            Array.Sort(inputStringChar);

            for (int i = 0; i < originalStringChar.Length; i++)
            {
                if (originalStringChar[i] != inputStringChar[i])
                {
                    return false;
                }
            }

            return true;
        }

        static bool IsPermutationUsingHashTableLikeDS(string originalString, string inputStringForCheck)
        {
            if (string.IsNullOrEmpty(originalString) || string.IsNullOrEmpty(inputStringForCheck))
            {
                return false;
            }

            if (originalString.Trim().Count() != inputStringForCheck.Trim().Count())
            {
                return false;
            }

            int[] asciiCounter = new int[128];

            foreach (char c in originalString.Trim())
            {
                asciiCounter[(int)c]++;
            }

            foreach (char c in inputStringForCheck.Trim())
            {
                asciiCounter[(int)c]--;
                if (asciiCounter[(int)c] < 0)
                {
                    return false;
                }
            }

            return true;
        }

        /**************         Note            ***************
         * 1> Question to interview would be if case sensitivity will impact the IsPermutation function? i.e. God is permutation of dog? If case insensitive then TRUE.
         * 2> Also need to ask if whitespace should matter? E.g. "God      " is permutation of "dog"??? If whitespace and case won't matter then those words are permutation of each other.
         * 3> After trimming whitespace at the beginning and end, if two words are of different length then they are not permutation of each other.
         * 4> Basically there are two ways of implementating IsPermutation function:
         *      A> First sort both of the strings. And we know if they are permutation of each other then sorted version of each string will have sequence of characters in same order.
         *      B> Second, insert each character of original string in hashset then for second/input string, check if each characters are present in hashset. But need to consider duplicate characters.
         *      E.g. MAAAAAD is permuation of MMMAAAD? Definitely not. So slightly modify hashset to implement counter of each character in the strings.
         *****************************************************/
    }
}
