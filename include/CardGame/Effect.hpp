#pragma once

struct Effect {
    int attackBuff{0};
    int turns{0};
    void tick() { if (turns>0) --turns; if (turns==0) attackBuff = 0; }
    bool active() const { return turns > 0; }
};
