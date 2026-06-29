class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        Set<Integer> rows = new HashSet<>();
        Set<Integer> cols = new HashSet<>();
        
        // Identify rows and columns that should be set to zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.add(i);  // Mark row i to be zeroed
                    cols.add(j);  // Mark column j to be zeroed
                }
            }
        }
        
        // Zero out the identified rows
        for (int row : rows) {
            for (int j = 0; j < n; j++) {
                matrix[row][j] = 0;
            }
        }
        
        // Zero out the identified columns
        for (int col : cols) {
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
    }
}