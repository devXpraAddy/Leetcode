#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        // Step 1: Build the evaluation map
        unordered_map<string, int> evalMap;
        for (int i = 0; i < evalvars.size(); ++i) {
            evalMap[evalvars[i]] = evalints[i];
        }

        // Step 2: Parse the expression into tokens
        vector<string> tokens = parseExpression(expression);

        // Step 3: Evaluate the expression using a stack-based approach
        vector<string> result = evaluate(tokens, evalMap);

        return result;
    }

private:
    // Struct to represent a term in the polynomial
    struct Term {
        int coefficient; // Coefficient of the term
        vector<string> variables; // Variables in the term, sorted lexicographically

        // Constructor for a constant term
        Term(int coeff) : coefficient(coeff) {}

        // Constructor for a term with variables
        Term(int coeff, const vector<string>& vars) : coefficient(coeff), variables(vars) {}

        // Compare two terms for sorting
        bool operator<(const Term& other) const {
            if (variables.size() != other.variables.size()) {
                return variables.size() > other.variables.size(); // Larger degree first
            }
            return variables < other.variables; // Lexicographical order
        }

        // Multiply two terms
        Term multiply(const Term& other) const {
            vector<string> newVars = variables;
            newVars.insert(newVars.end(), other.variables.begin(), other.variables.end());
            sort(newVars.begin(), newVars.end());
            return Term(coefficient * other.coefficient, newVars);
        }

        // Format the term as a string
        string toString() const {
            if (coefficient == 0) return "";
            string result = to_string(coefficient);
            for (const string& var : variables) {
                result += "*" + var;
            }
            return result;
        }
    };

    // Helper function to parse the expression into tokens
    vector<string> parseExpression(const string& expression) {
        vector<string> tokens;
        string token;
        for (char c : expression) {
            if (c == ' ') continue; // Skip spaces
            if (isdigit(c) || islower(c)) {
                token += c; // Build numbers or variables
            } else {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
                tokens.push_back(string(1, c)); // Add operators or parentheses
            }
        }
        if (!token.empty()) tokens.push_back(token); // Add the last token
        return tokens;
    }

    // Helper function to evaluate the tokens with the given evaluation map
    vector<string> evaluate(const vector<string>& tokens, const unordered_map<string, int>& evalMap) {
        stack<vector<Term>> operands; // Stack for operands (polynomials)
        stack<char> operators;       // Stack for operators

        auto applyOperator = [&](char op) {
            vector<Term> b = operands.top(); operands.pop();
            vector<Term> a = operands.top(); operands.pop();
            if (op == '+') {
                a = addPolynomials(a, b);
            } else if (op == '-') {
                a = subtractPolynomials(a, b);
            } else if (op == '*') {
                a = multiplyPolynomials(a, b);
            }
            operands.push(a);
        };

        for (const string& token : tokens) {
            if (isNumber(token)) {
                operands.push({Term(stoi(token))});
            } else if (isVariable(token)) {
                if (evalMap.count(token)) {
                    operands.push({Term(evalMap.at(token))});
                } else {
                    operands.push({Term(1, {token})});
                }
            } else if (token == "(") {
                operators.push('(');
            } else if (token == ")") {
                while (operators.top() != '(') {
                    applyOperator(operators.top());
                    operators.pop();
                }
                operators.pop(); // Pop the '('
            } else { // Operator (+, -, *)
                while (!operators.empty() && precedence(operators.top()) >= precedence(token[0])) {
                    applyOperator(operators.top());
                    operators.pop();
                }
                operators.push(token[0]);
            }
        }

        while (!operators.empty()) {
            applyOperator(operators.top());
            operators.pop();
        }

        // Convert the final polynomial to the output format
        return formatPolynomial(operands.top());
    }

    // Helper function to determine operator precedence
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*') return 2;
        return 0;
    }

    // Helper function to add two polynomials
    vector<Term> addPolynomials(const vector<Term>& a, const vector<Term>& b) {
        map<vector<string>, int> terms;
        for (const Term& term : a) terms[term.variables] += term.coefficient;
        for (const Term& term : b) terms[term.variables] += term.coefficient;
        return buildPolynomialFromMap(terms);
    }

    // Helper function to subtract two polynomials
    vector<Term> subtractPolynomials(const vector<Term>& a, const vector<Term>& b) {
        map<vector<string>, int> terms;
        for (const Term& term : a) terms[term.variables] += term.coefficient;
        for (const Term& term : b) terms[term.variables] -= term.coefficient;
        return buildPolynomialFromMap(terms);
    }

    // Helper function to multiply two polynomials
    vector<Term> multiplyPolynomials(const vector<Term>& a, const vector<Term>& b) {
        map<vector<string>, int> terms;
        for (const Term& t1 : a) {
            for (const Term& t2 : b) {
                Term product = t1.multiply(t2);
                terms[product.variables] += product.coefficient;
            }
        }
        return buildPolynomialFromMap(terms);
    }

    // Helper function to build a polynomial from a map
    vector<Term> buildPolynomialFromMap(const map<vector<string>, int>& terms) {
        vector<Term> result;
        for (const auto& [vars, coeff] : terms) {
            if (coeff != 0) result.emplace_back(Term(coeff, vars));
        }
        sort(result.begin(), result.end());
        return result;
    }

    // Helper function to format the polynomial as a vector of strings
    vector<string> formatPolynomial(const vector<Term>& polynomial) {
        vector<string> result;
        for (const Term& term : polynomial) {
            string formatted = term.toString();
            if (!formatted.empty()) result.push_back(formatted);
        }
        return result;
    }

    // Helper function to check if a string is a number
    bool isNumber(const string& s) {
        for (char c : s) {
            if (!isdigit(c)) return false;
        }
        return !s.empty();
    }

    // Helper function to check if a string is a variable
    bool isVariable(const string& s) {
        for (char c : s) {
            if (!islower(c)) return false;
        }
        return !s.empty();
    }
};