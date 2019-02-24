using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_CrackCode_01_05
{
    class Program
    {
        // One Away: There are three types of edits that can be performed on strings:
        // Insert a character
        // Remove a character
        // Replace a character
        // Given two strings, write a function to check if they are one edit (or zero edits) away.

        // Example:
        // pale, ple -> true
        // pales, pale -> true
        // pale, bale -> true
        // pale, bae -> false

        static void Main(string[] args)
        {
            Console.WriteLine("Enter first word:");
            string firstWord = Console.ReadLine();
            Console.WriteLine("Enter second word:");
            string secondWord = Console.ReadLine();
            Console.WriteLine(OneAway(firstWord, secondWord));
            Console.ReadKey();
        }

        static bool OneAway(string firstWord, string secondWord)
        {
            if (firstWord.Length == secondWord.Length)
            {
                return OneEditReplace(firstWord, secondWord);
            }
            else if ((firstWord.Length + 1) == secondWord.Length)
            {
                // means secondWord is longer in length
                return OneEditInsert(firstWord, secondWord);
            }
            else if ((secondWord.Length + 1) == firstWord.Length)
            {
                // means firstWord is longer in length
                return OneEditInsert(secondWord, firstWord);
            }
            return false;
        }

        static bool OneEditReplace(string firstWord, string secondWord)
        {
            bool foundDifference = false;
            for (int i = 0; i < firstWord.Length; i++)
            {
                if (firstWord[i] != secondWord[i])
                {
                    // This check means a difference is already found and if there is second difference then two words are more than one edit away--return false!!!
                    if (foundDifference)
                    {
                        return false;
                    }
                    else
                    {
                        foundDifference = true;
                    }
                }
            }
            return true;            
        }

        static bool OneEditInsert(string firstWord, string secondWord)
        {
            int index1 = 0;
            int index2 = 0; // index2 is for string secondWord which is longer in length than firstWord

            while (index2 < secondWord.Length && index1 < firstWord.Length)
            {
                if (firstWord[index1] != secondWord[index2])
                {
                    if (index1 != index2) // meaning for character to be inserted in secondWord, index1 and index2 are same only value are different.
                    {
                        return false;
                    }
                    index2++; // meaning there is a character insertion in secondWord so skip it and move to next one.
                }
                else
                {
                    index1++;
                    index2++;
                }
            }

            return true;
        }
    }
}
