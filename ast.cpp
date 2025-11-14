#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>


class Node {
public:
    virtual ~Node() {} 
    virtual double evaluate(const std::vector<std::pair<std::string, double>>& context) const = 0; 
};

class NumberNode : public Node {
private:
    double value;
public:
    explicit NumberNode(double v = 0) : value(v) {}

    double evaluate(const std::vector<std::pair<std::string, double>>& context) const{
        return value;
    }
};


class VariableNode : public Node {
private:
    std::string name;
public:
    explicit VariableNode(const std::string& n = "") : name(n) {}

    double evaluate(const std::vector<std::pair<std::string, double>>& context) const {
        for (size_t i = 0; i < context.size(); i++) {
            if (context[i].first == name) {
                return context[i].second;
            }
        }
        throw std::runtime_error("Variable not found");
        return 0;
    }
};


class OperationNode : public Node {
private:
    std::string name;
    std::vector<Node*> prevNodes;
public:
    explicit OperationNode(const std::string& n = "") : name(n) {}
    
    OperationNode(const std::string& n, std::vector<Node*> p) : name(n), prevNodes(std::move(p)) {}

    std::string getName() const { 
        return name; 
    }

    double evaluate(const std::vector<std::pair<std::string, double>>& context) const {
       if(name == "add"){
            double sum = 0;
            for(size_t i = 0; i < prevNodes.size(); i++){
                sum += prevNodes[i]->evaluate(context);
            } 
            return sum;
       }

       else if(name == "subtract"){
            if(prevNodes.empty()){
                return 0;
            }

            double sum = prevNodes[0]->evaluate(context);
            for(size_t i = 0; i < prevNodes.size(); i++){
                sum -= prevNodes[i]->evaluate(context);
            } 
            return sum;
       }

       else if(name == "multiply"){
            double sum = 1;
            for(size_t i = 0; i < prevNodes.size(); i++){
                sum *= prevNodes[i]->evaluate(context);
            } 
            return sum;
       }

        else if(name == "divide"){
            if (prevNodes.size() < 2){
                return 0;
            }
            double sum = prevNodes[0]->evaluate(context);
            for (size_t i = 1; i < prevNodes.size(); i++) {
                double denom = prevNodes[i]->evaluate(context);
                if (denom == 0){
                    throw std::runtime_error("Division by zero");
                }
                sum /= denom;
            }
            return sum;
        }

        else if(name == "min"){
            if (prevNodes.empty()){
                throw std::runtime_error("bruh min takes 2 arguments");
            }
            double mini = prevNodes[0]->evaluate(context);
            for(size_t i = 0; i < prevNodes.size(); i++){
                mini = std::min(mini, prevNodes[i]->evaluate(context));
            } 
            return mini;
        }

        else if(name == "max"){
            if (prevNodes.empty()){
                throw std::runtime_error("bruh max takes 2 arguments");
            }
            double maxi = prevNodes[0]->evaluate(context);
            for(size_t i = 0; i < prevNodes.size(); i++){
                maxi = std::max(maxi, prevNodes[i]->evaluate(context));
            } 
            return maxi;
        }

        else if(name == "negate") {
            if(prevNodes.size() != 1){
                throw std::runtime_error("Negate takes one argument bruh");
            }
            return -prevNodes[0]->evaluate(context);
        }

        throw std::runtime_error("What da heck is that operation");
        return 0;
    }

    ~OperationNode() {
        for (size_t i = 0; i < prevNodes.size(); i++){
            delete prevNodes[i];
        }
    }

};


Node* parse(const std::string& expr){
    std::stack<OperationNode*> ops;
    std::stack<std::vector<Node*>> nodes;
    std::string token;

    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];

        if (c == ' ') {
            continue;
        }

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            token = "";
            while (i < expr.size() && ((expr[i] >= 'A' && expr[i] <= 'Z') 
                || (expr[i] >= 'a' && expr[i] <= 'z') || (expr[i] >= '0' && expr[i] <= '9'))){
                token += expr[i];
                i++;
            }
            i--; 

            if (i + 1 < expr.size() && expr[i + 1] == '(') {
                ops.push(new OperationNode(token));
                nodes.push({});
            } 
            else {
                if (nodes.empty()){
                    throw std::invalid_argument("Variable outside function yee yee");
                }
                nodes.top().push_back(new VariableNode(token));
            }
        }

        else if ((c >= '0' && c <= '9') || c == '.') {
            std::string num;
            while (i < expr.size() && ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.')){
                num += expr[i++];
            }
            i--;
            double val = std::stod(num);
            if (nodes.empty()){
                throw std::invalid_argument("Number outside function again bruh");
            }

            nodes.top().push_back(new NumberNode(val));
        }
       
        else if (c == '('){
            continue;
        }
     
        else if (c == ','){
            continue;
        }
        
        else if (c == ')'){
            if (ops.empty() || nodes.empty()){
                throw std::invalid_argument("Didn't close the paranthesis bruh");
            }
            OperationNode* finished = ops.top();
            ops.pop();

            std::vector<Node*> args = nodes.top();
            nodes.pop();

            OperationNode* complete = new OperationNode(finished->getName(), args);
            delete finished; 

            if (nodes.empty()){
                nodes.push({complete});
            } 
            else{
                nodes.top().push_back(complete);
            }
        }

        else{
            throw std::invalid_argument("Yee yee ahh character");
        }
    }


    if (nodes.size() != 1 || !ops.empty()){
        throw std::invalid_argument("invalid syntax");
    }

    if (nodes.top().size() != 1){
        throw std::invalid_argument("Lwk more arguments than needed");
    }

    return nodes.top()[0];
}

int main(){
        // Контекст с переменными
    std::vector<std::pair<std::string, double>> context = {
        {"x", 2.5},
        {"y", 12.0}
    };

    std::string expression = "multiply(add(x, 5.5), negate(max(y, 10, 4)))";

    try {
        // 1. Парсинг
        Node* ast = parse(expression);
        
        // 2. Вычисление
        double result = ast->evaluate(context);
        
        // Ожидаемый результат: -96.0
        // multiply(add(2.5, 5.5), negate(max(12.0, 10, 4)))
        // -> multiply(8.0, negate(12.0))
        // -> multiply(8.0, -12.0)
        // -> -96.0
        std::cout << "Result: " << result << std::endl;
        
        // 3. Очистка памяти
        delete ast; // Должен рекурсивно удалить все дочерние узлы

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
