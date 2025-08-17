#pragma once

struct Energy {
    int current{10};
    int max{10};
    bool spend(int amount) {
        if (amount > current) return false;
        current -= amount;
        return true;
    }
    void refresh() { current = max; }
};
