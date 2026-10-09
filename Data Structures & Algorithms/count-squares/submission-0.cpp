class CountSquares {
    // grid[r][c] = # of points
    int grid[1001][1001]{};

    int get_max_search_len(int r, int c) {
        int max_r = max(r, 1000-r);
        int max_c = max(c, 1000-c);
        return max(max_r, max_c);
    }

    bool is_valid_rc(int r, int c) {
        return r >= 0 && r <= 1000 && c >= 0 && c <= 1000;
    }



    //  1 -- 2 -- 3
    //  |    |    |
    //  4    pt   6
    //  |    |    |
    //  7 -- 8 -- 9
    // 1: r-len, c+len
    // 2:     r, c+len
    // 3: r+len, c+len
    // 4: r-len, c
    // 6: r+len, c
    // 7: r-len, c-len
    // 8:     r, c-len
    // 9: r+len, c-len

    int get_squares(int r, int c, int len) {
        int result = 0;
        // top left
        // 1: r-len, c+len
        // 2:     r, c+len
        // 4: r-len, c
        if (is_valid_rc(r-len, c+len) && is_valid_rc(r,c+len) && is_valid_rc(r-len,c)) {
            result += grid[r-len][c+len]*grid[r][c+len]*grid[r-len][c];
        }


        // top right
        // 2:     r, c+len
        // 3: r+len, c+len
        // 6: r+len, c
        if (is_valid_rc(r,c+len) && is_valid_rc(r+len,c+len) && is_valid_rc(r+len,c)) {
            result += grid[r][c+len]*grid[r+len][c+len]*grid[r+len][c];
        }

        // bottom right
    // 6: r+len, c
    // 8:     r, c-len
    // 9: r+len, c-len
        if (is_valid_rc(r+len,c) && is_valid_rc(r,c-len) && is_valid_rc(r+len,c-len)) {
            result += grid[r+len][c]*grid[r][c-len]*grid[r+len][c-len];
        }

        // bottom left
    // 4: r-len, c
    // 7: r-len, c-len
    // 8:     r, c-len
        if (is_valid_rc(r-len,c) && is_valid_rc(r-len,c-len) && is_valid_rc(r,c-len)) {
            result += grid[r-len][c]*grid[r-len][c-len]*grid[r][c-len];
        }
        return result;
    }
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int r = point[0];
        int c = point[1];
        grid[r][c]++;
    }
    
    int count(vector<int> point) {
        int r = point[0];
        int c = point[1];
        int max_search_len = get_max_search_len(r, c);
        int result = 0;
        for (int len = 1; len <= max_search_len; ++len) {
            result += get_squares(r, c, len);
        }
        return result;
    }
};

// square
//  A----B
//  |    |
//  D----C ---- E
//       |      |
//       G ---- F

// count = #of(A) * #of(B) * #of(C) * #of(D) + #of(C) * #of(E) * #of(F) * #of(G)