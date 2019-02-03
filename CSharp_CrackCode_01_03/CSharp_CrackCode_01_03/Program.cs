using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_CrackCode_01_03
{
    class Program
    {
        // Question: Write a method to replace all spaces in a string with '%20'. You may assume that the string
        // has sufficent space at the end to hold the additional characters, and that you are given the "True" 
        // length of the string. (Note: if implementing in java, please use a character array so that you can
        // perform this operationin place.)
        static void Main(string[] args)
        {
            string testString = "This is a test string.";
            char[] testStringCharAry = testString.ToCharArray();
            ReplaceSpacesWithChar(testStringCharAry, testString.Length);
        }

        static void ReplaceSpacesWithChar(char[] inputString, int lengthOfString)
        {
            int spaceCount = 0;

            if (lengthOfString > inputString.Length)
            {
                throw new Exception("Input string length doesn't match length of string passed to function.");
            }

            for (int i = 0; i < inputString.Length; i++)
            {
                if (inputString[i] == ' ')
                {
                    spaceCount++;
                }
            }

            int lengthOfNewString = inputString.Length - spaceCount + spaceCount * 3;

            char[] inputStringBackup = inputString;
            inputString = new char[lengthOfNewString];
            lengthOfNewString--;

            for (int i = inputStringBackup.Length - 1; i >= 0; i--)
            {
                if (inputStringBackup[i] == ' ')
                {
                    inputString[lengthOfNewString] = '0';
                    inputString[lengthOfNewString - 1] = '2';
                    inputString[lengthOfNewString - 2] = '%';
                    lengthOfNewString -= 3;
                }
                else
                {
                    inputString[lengthOfNewString] = inputStringBackup[i];
                    lengthOfNewString--;
                }
            }            
        }
    }
}
