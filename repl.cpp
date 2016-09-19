#include <iostream>
#include <string>
#include <vector>
#include <regex>

class Reader {
    private:
        std::vector<std::string> tokens;
    public:
        Reader(std::vector<std::string> tokens) : tokens(tokens) {};
        std::string next();
        std::string peek();

};

std::vector<std::string> tokenizer(std::string s) {
    std::regex re("[\r\n\t\f,]*(~@|[\[]{}()'`~^@]|\"(?:\\.|[^\\\"])*\"|;.*|[^\r\n\t\f\[]{}('\"`,;)]*)");
    std::sregex_token_iterator it(s.begin(), s.end(), re, -1);
    std::sregex_token_iterator reg_end;

    std::vector<std::string> res;

    for (; it != reg_end; ++it) {
        res.push_back(it->str());
    }

    return res;

}

std::string READ(std::string arg) {
    return arg;
}

std::string EVAL(std::string arg) {
    return arg;
}

std::string PRINT(std::string arg) {
    return arg;
}

std::string rep(std::string arg) {
    return PRINT(EVAL(READ(arg)));
}

void read_list(Reader *reader) {
}

void read_atom(Reader *reader) {
}

void READ_FORM(Reader *reader) {
}

void read_str(std::string arg) {
    std::vector<std::string> tokens(tokenizer(arg));
    Reader *reader = new Reader(tokens);
    READ_FORM(reader);
}


int main() {
    while (true) {
        std::cout << "user> ";
        std::string input;
        std::getline(std::cin, input);
        std::cout << input << std::endl;
    }
    return 0;
};
