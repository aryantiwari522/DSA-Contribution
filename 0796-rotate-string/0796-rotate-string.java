class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length()!=goal.length()) return false;
        String goal_new= goal + goal;
        if(goal_new.contains(s)) return true;
        return false;
    }
}