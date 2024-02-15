
#include <iostream>
#include <stack>
#include <vector>

std::vector<std::stack<int>> tower(3);

int numOfMoves(int n) {
    return ((2^n) - 1);
}

enum rods {
    d_S=0,    // source
    d_A=1,    // auxillary
    d_D=2     // destination
};

void moveDisc(rods a, rods b) {
    if (tower[a].empty() || (tower[a].top() > tower[b].top())) {
        tower[a].push(tower[b].top()); 
        tower[b].pop();
    }
    else if (tower[b].empty() || (tower[a].top() < tower[b].top())) {
        tower[b].push(tower[a].top());
        tower[a].pop();
    }
}

void solve(int n) {
    // insert S tower
    for (int i{n}; i > 0; i--) {
        tower[d_S].push(i);
    }

    // solution
    for (int i{1}; i <= (numOfMoves(n)); i++) {
        std::cout << "On iteration: " << i << std::endl;
        if (i % 3 == 2) {
            moveDisc(d_S, d_D);
        }
        else if (i % 3 == 1) {
            moveDisc(d_S, d_A);
        }
        else if (i % 3 == 0) {
            moveDisc(d_A, d_D);
        }
    }
}

void printTowers(const std::vector<std::stack<int>>& towers) {
    for (std::stack<int> i : towers) {
        std::cout << "tower " << ": ";
        while (!i.empty()) {
            std::cout << i.top() << ' ';
            i.pop();
        }
        std::cout << std::endl;
    }
}

int main() {
    int numDiscs{3};

    solve(numDiscs);

    printTowers(tower);
    
    return 0;
}