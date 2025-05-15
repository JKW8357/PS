#include <bits/stdc++.h>
#include "pancakecookie.h"
using namespace std;

PanCakeCookie::PanCakeCookie(int w, int h, int maxC, int u, int d)
    : w(w), h(h), x(0), y(0), t(0), score(0), maxC(maxC), curC(maxC), u(u), d(d) {
}

int PanCakeCookie::getX() { return this->x; }
int PanCakeCookie::getY() { return this->y; }
int PanCakeCookie::getU() { return this->u; }
int PanCakeCookie::getD() { return this->d; }
int PanCakeCookie::getScore() { return this->score; }
int PanCakeCookie::getC() { return this->curC; }

void PanCakeCookie::reset() {
    x = y = t = score = 0;
    curC = maxC;
}

void PanCakeCookie::setU(int x) {
    if (x < 1 || x > 1000) return;
    u = x;
    reset();
}

void PanCakeCookie::setD(int x) {
    if (x < 1 || x > 1000) return;
    d = x;
    reset();
}

void PanCakeCookie::setC(int x) {
    if (x < 1 || x > 1000) return;
    maxC = x;
    reset();
}

void PanCakeCookie::setT(int t) {
    if (t < 0 || t >= w) return;
    reset();

    x = this->t = t;
    for (int i = 1; i <= t; ++i) {
        if (curC > 0) {
            y = min(h, y + u);
            curC--;
        } 
        else {
            y = max(0, y - d);
            if (curC < maxC) curC++;
        }
        score += y;
    }
}