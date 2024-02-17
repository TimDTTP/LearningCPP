
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

std::vector<std::stack<int>> tower(3);

int numOfMoves(int n) {
    return (static_cast<int>(std::pow(2, n)) - 1);
}

enum rods {
    d_S=0,    // source
    d_A=1,    // auxillary
    d_D=2     // destination
};

void moveDisc(rods a, rods b) {
    if (tower[a].empty()) {
        tower[a].push(tower[b].top()); 
        tower[b].pop();
    }
    else if (tower[b].empty()) {
        tower[b].push(tower[a].top());
        tower[a].pop();
    }
    else if (tower[a].top() > tower[b].top()) {
        tower[a].push(tower[b].top()); 
        tower[b].pop();
    }
    else if (tower[a].top() < tower[b].top()) {
        tower[b].push(tower[a].top());
        tower[a].pop();
    }
}

void printTowers(std::vector<std::stack<int>> towers) {
    for (int i{0}; i < 3; i++) {
        std::cout << "Tower " << i + 1 << ": ";
        while (!towers[i].empty()) {
            std::cout << towers[i].top() << ' ';
            towers[i].pop();
        }
        std::cout << std::endl;
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
        printTowers(tower);
        if (i % 3 == 2) {
            moveDisc(d_S, d_A);
        }
        else if (i % 3 == 1) {
            moveDisc(d_S, d_D);
        }
        else if (i % 3 == 0) {
            moveDisc(d_A, d_D);
        }
    }
}

int main() {
    int numDiscs{3};

    solve(numDiscs);

    printTowers(tower);
    
    return 0;
}