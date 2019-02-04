using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_CrackCode_01_04
{
    class Program
    {
        // Palindrome permutation
        // Given a string, write a function to check if it is palindrome permutation
        // permutation word dont have to be English word. It can be any word.
        // Input: Tact Coa
        // Output: True (permutation: "taco cat","atco cta"
        static void Main(string[] args)
        {
            IsPalindromePermutationApproach1_UsingDictionary("Tact Coa");
        }

        static bool IsPalindromePermutationApproach1_UsingDictionary(string inputString)
        {
            // check if length of word is odd or even

            // if even, count of each characters is even

            // if odd, count of each characters is even and one of the character count is odd, meaning only one character is allowed to have odd count

            Dictionary<char, int> characterToCountMap = new Dictionary<char, int>();

            foreach (var c in inputString)
            {
                if (c != ' ')
                {
                    char lowerChar = char.ToLower(c);
                    if (characterToCountMap.ContainsKey(lowerChar))
                    {
                        characterToCountMap[lowerChar] += 1;
                    }
                    else
                    {
                        characterToCountMap[lowerChar] = 1;
                    }
                }                
            }

            int oddCounter = 0;

            foreach (var key in characterToCountMap.Keys)
            {
                if (characterToCountMap[key] % 2 != 0)
                {
                    oddCounter++;
                }
            }

            if (oddCounter > 1)
                return false;
            else
                return true;
        }

        // There are two more solution, if you are interested, go through Crack book!!!
    }
}
