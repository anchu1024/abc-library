// x,yで座標をもつ。
struct Point {
    long long x, y;
};

enum class Turn {
    LEFT = 1,     // 反時計回り(左折)
    RIGHT = -1,   // 時計回り(右折)
    STRAIGHT = 0  // まっすぐ
};

// 三点a,b,cを与えると、a->b->cという経路において、bでどちらの方向に曲がるかを計算する
// 10^18まで対応
Turn check_turn(Point a, Point b, Point c) {
    // 符号ありの __int128_t（または __int128）を使う
    // 引き算のオーバーフローも防ぐため、最初にキャストする
    __int128_t ab_x = (__int128_t)b.x - a.x;
    __int128_t ab_y = (__int128_t)b.y - a.y;
    __int128_t bc_x = (__int128_t)c.x - b.x;
    __int128_t bc_y = (__int128_t)c.y - b.y;

    __int128_t cross = ab_x * bc_y - ab_y * bc_x;

    if (cross > 0) return Turn::LEFT;
    if (cross < 0) return Turn::RIGHT;
    return Turn::STRAIGHT;
}
