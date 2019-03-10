using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_CrackCode_01_07
{
    class Program
    {
        // Given an image represented by an N x N matrix, where each pixel in the image is 4 bytes
        // write a method to rotate the image by 90 degrees. Can you do this in place?

        static void Main(string[] args)
        {
            int n = 4;
            //int[,] matrix = new int[n, n];
            int[,] matrix = new int[,]
            { 
                { 1, 2, 3, 4 },
                { 5, 6, 7, 8},
                { 9, 10, 11, 12},
                { 13, 14, 15, 16}
            };
            bool successfulRotation = Rotate(matrix);
        }

        static bool Rotate(int[,] matrix)
        {
            if ((matrix.GetLength(0) != matrix.GetLength(1)) || matrix.GetLength(0) == 0 || matrix.GetLength(1) == 0)
            {
                return false;
            }

            for (int layer = 0; layer < matrix.GetLength(0) / 2; layer++)
            {
                int first = layer;
                int last = matrix.GetLength(0) - 1 - layer;
                for (int i = first; i < last; i++)
                {
                    int offset = i - first;
                    int top = matrix[first, i];

                    // assign left to top
                    matrix[first, i] = matrix[last - offset, first];

                    // assign bottom to left
                    matrix[last - offset, first] = matrix[last, last - offset];

                    // assign right to bottom
                    matrix[last, last - offset] = matrix[ i , last];

                    // assign top to right
                    matrix[i, last] = top;
                }
            }

            return true;
        }
    }
}
