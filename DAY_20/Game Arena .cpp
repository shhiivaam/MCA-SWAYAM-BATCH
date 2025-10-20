#include <bits/stdc++.h>
using namespace std;

class Gladiator {
public:
    string name;
    int rank;
    int stamina;
    int wins;
    bool isChampion;

    Gladiator(const string& n) : name(n), rank(1), stamina(100), wins(0), isChampion(false) {}
};

class Weapon {
public:
    string name;
    int power;
    int level;
    unsigned int day;

    Weapon() : name(""), power(0), level(1), day(0) {}
    Weapon(const string& n, unsigned int d) : name(n), level(1), day(d) { power = 10 * level; }

    int upgradeCost() const { return 20 * level; }

    void upgrade() { level += 1; power = 10 * level; }
};

class Team {
public:
    string name;
    int maxMembers;
    deque<Gladiator> gladiators;
    map<unsigned int, Weapon> weaponsByDay;
    int score;
    int gold;

    Team() : name(""), maxMembers(5), score(0), gold(0) {}
    Team(const string& n) : name(n), maxMembers(5), score(0), gold(0) {}

    void reset() {
        gladiators.clear();
        weaponsByDay.clear();
        score = 0;
        gold = 0;
    }

    int totalStamina() const {
        int total = 0;
        for (const auto& g : gladiators) total += g.stamina;
        return total;
    }

    int totalWeaponPower() const {
        int total = 0;
        for (const auto& p : weaponsByDay) total += p.second.power;
        return total;
    }
};

class Arena {
    map<string, Team> teams;

public:
    bool enrollGladiator(const string& teamName, const string& name) {
        if (!teams.count(teamName)) teams.emplace(teamName, Team(teamName));
        Team &team = teams[teamName];
        if ((int)team.gladiators.size() >= team.maxMembers) return false;
        for (const auto& g : team.gladiators) if (g.name == name) return false;
        team.gladiators.emplace_back(name);
        return true;
    }

    void addWeapon(const string& teamName, const string& weaponName, unsigned int day) {
        if (!teams.count(teamName)) teams.emplace(teamName, Team(teamName));
        Team &team = teams[teamName];
        if (team.weaponsByDay.count(day)) return;
        Weapon w(weaponName, day);
        team.weaponsByDay[day] = w;
    }

    void conductBattle(const string& team1, const string& team2) {
        if (!teams.count(team1) || !teams.count(team2)) return;
        Team &A = teams[team1];
        Team &B = teams[team2];
        int powerA = A.totalWeaponPower();
        int powerB = B.totalWeaponPower();
        if (powerA == powerB) return;
        Team *winner = (powerA > powerB) ? &A : &B;
        Team *loser  = (powerA > powerB) ? &B : &A;
        winner->score += 50;
        winner->gold  += 50;
        for (auto &g : winner->gladiators) g.wins += 1;
        for (auto &g : loser->gladiators) g.stamina -= 20;
        if (loser->totalStamina() < 50) loser->reset();
    }

    bool upgradeWeapon(const string& teamName, const string& weaponName) {
        if (!teams.count(teamName)) return false;
        Team &team = teams[teamName];
        for (auto &p : team.weaponsByDay) {
            Weapon &w = p.second;
            if (w.name == weaponName) {
                int cost = w.upgradeCost();
                if (team.gold >= cost) {
                    team.gold -= cost;
                    w.upgrade();
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    void promoteChampion(const string& teamName) {
        if (!teams.count(teamName)) return;
        Team &team = teams[teamName];
        for (auto &g : team.gladiators) {
            if (!g.isChampion) {
                g.isChampion = true;
                break;
            }
        }
    }

    void exileGladiator(const string& teamName, const string& byName, const string& targetName) {
        if (!teams.count(teamName)) return;
        Team &team = teams[teamName];
        bool byIsChampion = false;
        for (const auto &g : team.gladiators) if (g.name == byName && g.isChampion) { byIsChampion = true; break; }
        if (!byIsChampion) return;
        for (auto it = team.gladiators.begin(); it != team.gladiators.end(); ++it) {
            if (it->name == targetName && !it->isChampion) {
                team.gladiators.erase(it);
                return;
            }
        }
    }

    void showTeamStats() const {
        cout << "\n=== TEAM STATS ===\n";
        for (const auto &kv : teams) {
            const Team &team = kv.second;
            cout << "Team: " << team.name
                 << " | Gladiators: " << team.gladiators.size()
                 << " | Score: " << team.score
                 << " | Gold: " << team.gold
                 << " | Weapons Learned: " << team.weaponsByDay.size();
            string top = "None";
            int maxWins = -1;
            for (const auto &g : team.gladiators) {
                if (g.wins > maxWins) { maxWins = g.wins; top = g.name; }
            }
            cout << " | Top Ranker: " << top << "\n";
        }
    }

    void showWeapons(unsigned int startDay, unsigned int endDay) const {
        cout << "\n=== WEAPONS LEARNED FROM DAY " << startDay << " TO " << endDay << " ===\n";
        for (const auto &kv : teams) {
            const Team &team = kv.second;
            cout << "Team " << team.name << ":\n";
            bool any = false;
            for (const auto &p : team.weaponsByDay) {
                unsigned int day = p.first;
                const Weapon &w = p.second;
                if (day >= startDay && day <= endDay) {
                    any = true;
                    cout << "  Day " << day << " - " << w.name << " (Power: " << w.power << ", Level: " << w.level << ")\n";
                }
            }
            if (!any) cout << "  None\n";
        }
    }

    void showLeaderboard() const {
        cout << "\n=== LEADERBOARD ===\n";
        vector<pair<string, double>> list;
        for (const auto &kv : teams) {
            const Team &team = kv.second;
            double avgRank = 0.0;
            if (!team.gladiators.empty()) {
                for (const auto &g : team.gladiators) avgRank += g.rank;
                avgRank /= team.gladiators.size();
            }
            double rankScore = team.score + (avgRank * 10.0);
            list.emplace_back(team.name, rankScore);
        }
        sort(list.begin(), list.end(), [](const auto &a, const auto &b){
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        for (const auto &p : list) {
            cout << "Team: " << p.first << " | Leaderboard Score: " << p.second << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Arena a;
    a.enrollGladiator("Titans", "Maximus");
    a.enrollGladiator("Titans", "Leonidas");
    a.addWeapon("Titans", "Spear", 1);
    a.addWeapon("Titans", "Sword", 2);

    a.enrollGladiator("Spartans", "Ajax");
    a.addWeapon("Spartans", "Axe", 1);

    a.conductBattle("Titans", "Spartans");

    bool upgraded = a.upgradeWeapon("Titans", "Sword");
    if (upgraded) cout << "\nSword upgraded successfully for Titans.\n";
    else cout << "\nSword upgrade failed for Titans (insufficient gold or not found).\n";

    a.promoteChampion("Titans");
    a.exileGladiator("Titans", "Maximus", "Leonidas");

    a.showTeamStats();
    a.showWeapons(1, 3);
    a.showLeaderboard();

    return 0;
}
