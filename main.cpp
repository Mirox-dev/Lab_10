//
// Created by user on 22.02.2026.
//
#include <functional>
#include <iostream>

using namespace std;

template<typename T>
class MyPipeLine {
    struct Step {
        string name;
        function<T(T)> func;
    };
    vector<Step> steps;
public:
    MyPipeLine() = default;
    [[nodiscard]] size_t size() const { return steps.size(); }
    [[nodiscard]] bool empty() const { return steps.empty(); }
    void clear() { steps.clear(); }
    template<typename F>
    void addStep(const string& name, F func) {
        if (name.empty()) {
            throw invalid_argument("Name is empty");
        }
        steps.push_back(Step{name, function<T(T)>(func)});
    }
    void removeStep(size_t index) {
        if (index >= steps.size()) {
            throw out_of_range("Index out of range");
        }
        steps.erase(steps.begin() + index);
    }
    T run(T value) {
        for (auto& step : steps) {
            value = step.func(value);
        }
        return value;
    }
    vector<T> trace(T value) {
        vector<T> result;
        for (auto& step : steps) {
            value = step.func(value);
            result.push_back(value);
        }
        return result;
    }
    friend ostream& operator<<(ostream& os, const MyPipeLine<T>& pipeline) {
        os << "Number of steps: " << pipeline.size() << endl;
        for (size_t i = 0; i < pipeline.size(); ++i) {
            os << i + 1 << ") " << pipeline.steps[i].name << endl;
        }
        return os;
    }
};

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    MyPipeLine<int> intPipe;
    intPipe.addStep("Fibbonachi's number", [](int value) {return fibonacci(value);});
    intPipe.addStep("square", [](int value) {return value * value;});
    intPipe.addStep("mod 16", [](int value) {return value % 16;});
    cout << intPipe << endl;
    cout << intPipe.run(8) << endl << endl;
    auto tracer = intPipe.trace(8);
    for (auto& i : tracer) {
        cout << i << endl;
    }
    MyPipeLine<string> stringPipe;
    stringPipe.addStep("quadriple", [](string value){return value + value + value + value;});
    stringPipe.addStep("Remove A's", [](string value) {
        for (size_t i = 0; i < value.size(); ++i) {
            if (value[i] == 'a' or value[i] == 'A') {
                value.erase(i + value.begin());
                i -= 1;
            }
        }
        return value;
    });
    stringPipe.addStep("Upper", [](string value) {
        for (char& c : value) {
            c = toupper(static_cast<unsigned char>(c));
        }
        return value;
    });
    cout << endl << stringPipe.run("Abracadabra") << endl << endl;
    try {
        intPipe.removeStep(100);
    } catch (exception& e) {
        cout << e.what() << endl << endl;
    }
    try {
        stringPipe.addStep("", [](string value) {return value;});
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
