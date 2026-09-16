class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // given  ---a-----b---------->target
        // time to target: t1 := b->target, t2 := a->target
        // If t2 <= t1, a must collide with b

        // <position, speed>
        int n = speed.size();
        using pii = pair<int, int>;
        vector<pii> cars(n, pii());
        for (int i = 0; i < n; ++i) {
            int pos = position[i];
            int spd = speed[i];
            cars[i] = make_pair(pos, spd);
        }
        // sort in decreasing order
        sort(cars.begin(), cars.end(), greater<pii>());

        stack<double> stk;
        stk.push((double)(target-cars[0].first)/cars[0].second);
        for (int i = 1; i < n; ++i) {
            auto [curr_pos, curr_speed] = cars[i];
            double curr_t = (double)(target-curr_pos)/curr_speed;
            if (curr_t <= stk.top()) {
                continue;
            }
            stk.push(curr_t);
        }
        return stk.size();
    }
};



// 1, 4, 7, 10
// 4, 6, 8, 10


// 4,6,8,10
// 1,3,5,7,9,10
// 0,1,2,3,4,5,6,7,8,9,10
// 7,8,9,10
