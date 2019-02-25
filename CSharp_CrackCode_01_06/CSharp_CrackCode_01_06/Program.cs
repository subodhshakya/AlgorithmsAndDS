using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_CrackCode_01_06
{
    class Program
    {
        // String compression: Implement a method to perform basic compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.
        // if the compressed string would not become smaller than the original string, your method should return the original string.
        // You can assume the string has only uppercase and lowercase letters (a-z).
        static void Main(string[] args)
        {
            Console.WriteLine("Enter string to compress:");
            string inputString = Console.ReadLine();

            Console.WriteLine("Compressed string: " + CompressString(inputString));
            Console.ReadKey();
        }

        static string CompressString(string inputString)
        {
            StringBuilder compressedString = new StringBuilder();
            char previousChar = inputString[0];
            int charCounter = 1;
            for (int i = 1; i < inputString.Length; i++)
            {
                if (inputString[i] != previousChar)
                {
                    compressedString.Append(previousChar + charCounter.ToString());
                    charCounter = 1;
                    previousChar = inputString[i];
                }
                else
                {
                    charCounter++;
                }
                if (i == (inputString.Length - 1))
                {
                    // append last character
                    compressedString.Append(previousChar + charCounter.ToString());
                }
                if (compressedString.Length > inputString.Length)
                {
                    return inputString;
                }
            }

            return compressedString.ToString();
        }
    }
}
