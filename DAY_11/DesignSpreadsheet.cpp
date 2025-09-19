class Spreadsheet {
 public:
  Spreadsheet(int rows) {}

  void setCell(string cell, int value) {
    spreadsheet[cell] = value;
  }

  void resetCell(string cell) {
    spreadsheet[cell] = 0;
  }

  int getValue(string formula) {
    const int i = formula.find('+');
    return getToken(formula.substr(1, i - 1)) + getToken(formula.substr(i + 1));
  }

 private:
  unordered_map<string, int> spreadsheet;

  int getToken(const string& token) {
    return isdigit(token[0])
               ? stoi(token)
               : (spreadsheet.contains(token) ? spreadsheet[token] : 0);
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
