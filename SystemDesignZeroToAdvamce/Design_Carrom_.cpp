#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

// =================== ENTITY CLASSES ===================

class Coin {
    string color;
    int points;
    bool pocketed;
public:
    Coin(string c, int p): color(c), points(p), pocketed(false) {}
    string getColor() const { return color; }
    int getPoints() const { return points; }
    bool isPocketed() const { return pocketed; }
    void pocket() { pocketed = true; }
};

class Player {
    string name;
    int score;
    vector<string> history;
public:
    Player(string n): name(n), score(0) {}
    string getName() const { return name; }
    int getScore() const { return score; }

    void addScore(int pts, const string &action) {
        score += pts;
        time_t now = time(0);
        char buf[30];
        strftime(buf, sizeof(buf), "%H:%M:%S", localtime(&now));
        history.push_back(string(buf) + " -> " + action);
    }

    void showHistory() const {
        cout << "\n📜 History of " << name << ":\n";
        for (auto &h : history) cout << "   " << h << "\n";
    }
};

// =================== CORE LOGIC CLASSES ===================

class Board {
    vector<Coin> coins;
public:
    Board() {
        for (int i = 0; i < 9; i++) coins.emplace_back("black", 10);
        for (int i = 0; i < 9; i++) coins.emplace_back("white", 20);
        coins.emplace_back("red", 50);
    }

    bool isEmpty() const {
        for (auto &c : coins) if (!c.isPocketed()) return false;
        return true;
    }

    int remainingCoins() const {
        int cnt = 0;
        for (auto &c : coins) if (!c.isPocketed()) cnt++;
        return cnt;
    }

    Coin* getRandomCoin() {
        vector<int> available;
        for (int i = 0; i < coins.size(); i++)
            if (!coins[i].isPocketed()) available.push_back(i);
        if (available.empty()) return nullptr;
        int idx = rand() % available.size();
        return &coins[idx];
    }
};

// =================== SERVICE CLASSES ===================

class ScoreManager {
public:
    static void pocketCoin(Player &p, Coin* coin) {
        if (!coin) return;
        coin->pocket();
        int pts = coin->getPoints();
        p.addScore(pts, "Pocketed " + coin->getColor() + " coin (+" + to_string(pts) + ")");
    }

    static void missShot(Player &p) {
        p.addScore(0, "Missed shot");
    }

    static Player getWinner(const vector<Player> &players) {
        return *max_element(players.begin(), players.end(),
                            [](const Player &a, const Player &b) {
                                return a.getScore() < b.getScore();
                            });
    }
};

// =================== ENGINE / MANAGER ===================

class GameEngine {
    vector<Player> players;
    Board board;
public:
    GameEngine(const vector<string> &names) {
        srand(time(0));
        for (auto &n : names) players.emplace_back(n);
    }

    void start() {
        cout << "\n🎯 Carom Game Started with " << players.size() << " players!\n";
        cout << "--------------------------------------\n";

        while (!board.isEmpty()) {
            for (auto &p : players) {
                if (board.isEmpty()) break;
                playTurn(p);
            }
        }
        showSummary();
    }

    void playTurn(Player &p) {
        cout << "\n👉 " << p.getName() << "'s turn (" << board.remainingCoins() << " coins left)\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        bool success = rand() % 2;
        Coin* coin = board.getRandomCoin();

        if (success && coin) {
            ScoreManager::pocketCoin(p, coin);
            cout << "✅ " << p.getName() << " pocketed " << coin->getColor() 
                 << " coin! (+" << coin->getPoints() << ")\n";
        } else {
            ScoreManager::missShot(p);
            cout << "❌ " << p.getName() << " missed the shot.\n";
        }
    }

    void showSummary() {
        cout << "\n🏁 Game Over! Final Scores:\n";
        for (auto &p : players)
            cout << " - " << p.getName() << ": " << p.getScore() << "\n";

        Player winner = ScoreManager::getWinner(players);
        cout << "\n🏆 WINNER: " << winner.getName() 
             << " with " << winner.getScore() << " points! 🎉\n";

        cout << "\n🧾 Player Histories:\n--------------------------------------\n";
        for (auto &p : players) {
            p.showHistory();
            cout << "--------------------------------------\n";
        }
    }
};

// =================== PRESENTATION / UI ===================

class GameUI {
public:
    static void run() {
        int n = 4;
        vector<string> names(n);
        cout << "Enter names of 4 players:\n";
        cin.ignore();
        for (int i = 0; i < n; i++) {
            cout << "Player " << i + 1 << ": ";
            getline(cin, names[i]);
        }
        GameEngine engine(names);
        engine.start();
        cout << "\nThanks for playing! 🥳\n";
    }
};

// =================== MAIN ===================

int main() {
    GameUI::run();
    return 0;
}
