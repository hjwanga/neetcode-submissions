class Solution {
    struct Point {
        Point(int x, int y): x(x), y(y){}
        int x = -1;
        int y = -1;
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<Point> points;
        Point tl(0,0);
        Point tr(0,n-1);
        Point bl(m-1,0);
        Point br(m-1,n-1);
        while (tl.y <= br.y && tl.x <= br.x) {
            // tl -> tr
            for (int y = tl.y; y <= tr.y; ++y) {
                points.emplace_back(tl.x, y);
            }
            // tr -> br
            for (int x = tr.x+1; x <= br.x; ++x) {
                points.emplace_back(x, tr.y);
            }
            // br -> bl
            if (br.x > tl.x) {
                for (int y = br.y-1; y >= bl.y; --y) {
                    points.emplace_back(br.x, y);
                }
            }
            if (br.y > tl.y) {
                // bl -> tl
                for (int x = bl.x-1; x >= tl.x+1; --x) {
                    points.emplace_back(x, bl.y);
                }
            }

            // shrink tl, tr, bl, br
            tl = Point(tl.x+1, tl.y+1);
            tr = Point(tr.x+1, tr.y-1);
            bl = Point(bl.x-1, bl.y+1);
            br = Point(br.x-1, br.y-1);
        }

        vector<int> result;
        for (const Point& p : points) {
            int x = p.x;
            int y = p.y;
            result.push_back(matrix[x][y]);
        }
        return result;
    }
};



// matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//  [1, 2, 3, 4]
//  [5, 6, 7, 8]
//  [9,10,11,12]
//  

//  tl  -   - tr
//   .         .
//   .         .
//  bl  -   - br