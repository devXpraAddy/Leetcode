class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        // Build an evaluation map for variables to numbers.
        unordered_map<string, int> eval;
        for (int i = 0; i < evalvars.size(); i++) {
            eval[evalvars[i]] = evalints[i];
        }
        
        // Tokenize the expression.
        // Tokens can be numbers, variables, or one of the symbols: +, -, *, (, )
        vector<string> tokens;
        for (int i = 0; i < expression.size(); ) {
            if (expression[i] == ' ') {
                i++;
            } else if (expression[i]=='+' || expression[i]=='-' || expression[i]=='*' ||
                       expression[i]=='(' || expression[i]==')') {
                tokens.push_back(string(1, expression[i]));
                i++;
            } else {
                int j = i;
                while (j < expression.size() && isalnum(expression[j])) j++;
                tokens.push_back(expression.substr(i, j - i));
                i = j;
            }
        }
        
        int pos = 0;
        Poly poly = parseExpr(tokens, pos, eval);
        
        // Convert the internal polynomial representation into the final result.
        // Each term is stored with a key (e.g. "a*b" for a term a*b) or "" for a constant.
        // We break each key into its list of variables (if non-empty) to use for sorting.
        vector<pair<vector<string>, int>> polyTerms;
        for (auto &term : poly) {
            if (term.second == 0)
                continue;
            vector<string> vars;
            if (!term.first.empty()) {
                int start = 0;
                for (int i = 0; i <= term.first.size(); i++) {
                    if (i == term.first.size() || term.first[i] == '*') {
                        vars.push_back(term.first.substr(start, i - start));
                        start = i + 1;
                    }
                }
            }
            polyTerms.push_back({vars, term.second});
        }
        
        // Sort: first by descending degree, then lexicographically by the variables.
        sort(polyTerms.begin(), polyTerms.end(), [](const pair<vector<string>, int>& a,
                                                      const pair<vector<string>, int>& b) {
            if (a.first.size() != b.first.size())
                return a.first.size() > b.first.size();
            return a.first < b.first;
        });
        
        vector<string> result;
        for (auto &p : polyTerms) {
            string termStr = to_string(p.second);
            for (auto &var : p.first) {
                termStr += "*" + var;
            }
            result.push_back(termStr);
        }
        
        return result;
    }
    
private:
    // Represent a polynomial as a map:
    // Key: a string representing sorted free variables (concatenated with '*' as separator), 
    //      with an empty string representing the constant term.
    // Value: the integer coefficient.
    using Poly = map<string, int>;
    
    // Helper: add two polynomials.
    Poly addPoly(const Poly &a, const Poly &b) {
        Poly res = a;
        for (auto &p : b) {
            res[p.first] += p.second;
            if (res[p.first] == 0)
                res.erase(p.first);
        }
        return res;
    }
    
    // Helper: subtract polynomial b from polynomial a.
    Poly subPoly(const Poly &a, const Poly &b) {
        Poly res = a;
        for (auto &p : b) {
            res[p.first] -= p.second;
            if (res[p.first] == 0)
                res.erase(p.first);
        }
        return res;
    }
    
    // Helper: multiply two polynomials.
    Poly mulPoly(const Poly &a, const Poly &b) {
        Poly res;
        for (auto &p : a) {
            for (auto &q : b) {
                int coeff = p.second * q.second;
                string key;
                if (p.first == "" && q.first == "") {
                    key = "";
                } else if (p.first == "") {
                    key = q.first;
                } else if (q.first == "") {
                    key = p.first;
                } else {
                    // Combine variables from both terms.
                    vector<string> vars;
                    splitKey(p.first, vars);
                    vector<string> vars2;
                    splitKey(q.first, vars2);
                    vars.insert(vars.end(), vars2.begin(), vars2.end());
                    sort(vars.begin(), vars.end());
                    key = join(vars, "*");
                }
                res[key] += coeff;
                if (res[key] == 0)
                    res.erase(key);
            }
        }
        return res;
    }
    
    // Splits a key string (e.g., "a*b*c") into its component variables.
    static void splitKey(const string &s, vector<string>& tokens) {
        string token;
        for (char c : s) {
            if (c == '*') {
                tokens.push_back(token);
                token.clear();
            } else {
                token.push_back(c);
            }
        }
        if (!token.empty()) tokens.push_back(token);
    }
    
    // Joins a list of strings using sep as the delimiter.
    static string join(const vector<string> &tokens, const string &sep) {
        string res;
        for (int i = 0; i < tokens.size(); i++) {
            if (i > 0)
                res += sep;
            res += tokens[i];
        }
        return res;
    }
    
    // parseExpr handles addition and subtraction.
    Poly parseExpr(const vector<string>& tokens, int &pos, unordered_map<string, int>& eval) {
        Poly poly = parseTerm(tokens, pos, eval);
        while (pos < tokens.size() && (tokens[pos] == "+" || tokens[pos] == "-")) {
            string op = tokens[pos++];
            Poly term = parseTerm(tokens, pos, eval);
            if (op == "+")
                poly = addPoly(poly, term);
            else
                poly = subPoly(poly, term);
        }
        return poly;
    }
    
    // parseTerm handles multiplication.
    Poly parseTerm(const vector<string>& tokens, int &pos, unordered_map<string, int>& eval) {
        Poly poly = parseFactor(tokens, pos, eval);
        while (pos < tokens.size() && tokens[pos] == "*") {
            pos++; // skip "*"
            Poly factor = parseFactor(tokens, pos, eval);
            poly = mulPoly(poly, factor);
        }
        return poly;
    }
    
    // parseFactor handles numbers, variables, and parenthesized expressions.
    Poly parseFactor(const vector<string>& tokens, int &pos, unordered_map<string, int>& eval) {
        Poly poly;
        string token = tokens[pos++];
        if (token == "(") {
            poly = parseExpr(tokens, pos, eval);
            pos++; // skip the corresponding ")"
        } else {
            if (isdigit(token[0])) {
                int val = stoi(token);
                poly[""] = val;
            } else {
                // Check if the variable has a substitution.
                if (eval.count(token)) {
                    int val = eval[token];
                    poly[""] = val;
                } else {
                    poly[token] = 1;
                }
            }
        }
        return poly;
    }
};
