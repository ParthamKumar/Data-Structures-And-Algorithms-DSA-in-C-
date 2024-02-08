#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Node {
public:
    char data;
    Node* next;
    Node(char c) : data(c), next(NULL) {}
};
class LinkedListStack {
private:
    Node* top;
public:
LinkedListStack() {
    top = NULL;
}
    void push(char data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (is_empty()) {
            cerr << "Stack underflow\n";
            return '\0';
        }
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    bool is_empty() {
        return top == NULL;
    }
    char peek() {
        if (is_empty()) {
            cerr << "Stack is empty\n";
            return '\0';
        }
        return top->data;
    }
};
bool isOperator(char c) {
    if (c =='+'||c =='-'||c =='*'||c=='/'||c=='^'){
        return true;
    }
    return false;
}
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
string infixToPrefix(LinkedListStack& s, const string& infix) {
    string prefix;
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

for (int i = 0; i < reversedInfix.length(); ++i){
    char& c = reversedInfix[i];
    if (c == '(') {
        c = ')';
    }
    else if (c == ')') {
        c = '(';
    }
}
for (int i = 0; i < reversedInfix.length(); ++i) {
    char c = reversedInfix[i];
    if (isalnum(c)) {
        prefix += c;
    }
    else if (c == '(') {
        s.push(c);
    }
    else if (c == ')') {
        while (!s.is_empty() && s.peek() != '(') {
            prefix += s.pop();
        }
        if (!s.is_empty() && s.peek() == '(') {
            s.pop();
        }
        else {
            cerr << "Mismatched parentheses\n";
            exit(1);
        }
    }
    else if (isOperator(c)) {
        if (s.is_empty()) {
            s.push(c);
        }
        else {
            if (precedence(c) > precedence(s.peek())) {
                s.push(c);
            }
            else if (precedence(c) == precedence(s.peek()) && c == '^') {
                while (precedence(c) == precedence(s.peek()) && c == '^') {
                    prefix += s.pop();
                }
                s.push(c);
            }
            else if (precedence(c) == precedence(s.peek())) {
                s.push(c);
            }
            else {
                while (!s.is_empty() && precedence(c) < precedence(s.peek())) {
                    prefix += s.pop();
                }
                s.push(c);
            }
        }
    }
    else {
        cerr << "Invalid character in the expression\n";
        exit(1);
    }
}
    while (!s.is_empty()) {
        prefix += s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main() {
    string infix, prefix;
    cout << "Enter an Infix Expression: " << endl;
    cin >> infix;
    LinkedListStack stack;
    cout << "INFIX EXPRESSION: " << infix << endl;
    prefix = infixToPrefix(stack, infix);
    cout << "PREFIX EXPRESSION: " << prefix << endl;
    return 0;
}
