class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        HashSet<Integer> set = new HashSet<>();
        int n = grid.length;
        int sum=0;
        int[] ans=new int[2];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(set.contains(grid[i][j])){
                    ans[0]=grid[i][j];
                    sum-=grid[i][j];
                }
                set.add(grid[i][j]);
                sum+=grid[i][j];
            }
        }
        int expectedSum=((n*n)*((n*n)+1))/2;
        ans[1]=expectedSum-sum;
        return ans;
    }
}