// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Example 1:
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// Example 2:
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false

public class Search_a_2D_Matrix_II{
        public static boolean searchMatrix(int[][] matrix, int target) {
            int r=0;
            int c = matrix[0].length-1;
            while(r<matrix.length && c>=0)
            {
                if(matrix[r][c]==target) return true;
                if(matrix[r][c]<target) r++;
                else c--;
            }
            return false;
            
        }
    public static void main(String[] args) {
        
        int[][] matrix = {
            {1, 4, 7, 11},
            {2, 5, 8, 12},
            {3, 6, 9, 16},
            {10, 13, 14, 17}
        };

        int target1 = 5; 
        System.out.println(searchMatrix(matrix, target1));
        
    }


}