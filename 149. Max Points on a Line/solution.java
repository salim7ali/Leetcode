import java.util.HashMap;
import java.util.Set;

import jdk.internal.net.http.common.Pair;

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

class Solution {
    public int maxPoints(int[][] points) {
        HashMap<Pair<Integer, Integer>, Set<Pair<Integer, Integer>>> HM = new <Pair<Integer, Integer>, Set<Pair<Integer, Integer>>>();
        
        for(int i=0; i<points.length; i++){
            int x = points[i][0];
            int y = points[i][1];

            
        }
    }
}