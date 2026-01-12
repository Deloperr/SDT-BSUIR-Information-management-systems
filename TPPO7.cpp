#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

class AngleModel {
public:
    AngleModel(float value = 0.0f, bool isDegrees = true) {
        if (isDegrees) {
            setDegrees(value);
        }
        else {
            setRadians(value);
        }
    }

    float getDegrees() const {
        return _degrees;
    }

    float getRadians() const {
        return _degrees * (M_PI / 180.0f);
    }

    void setDegrees(float degrees) {
        _degrees = degrees;
    }

    void setRadians(float radians) {
        _degrees = radians * (180.0f / M_PI);
    }

private:
    float _degrees;
};

class ConsoleView {
public:
    ConsoleView(AngleModel* model) : _model(model) {}

    void display() {
        std::cout << "Degrees: " << _model->getDegrees() << "\n";
        std::cout << "Radians: " << _model->getRadians() << " rad\n";
    }

    void promptForInput() {
        std::cout << "Enter angle value: ";
    }

    void promptForUnit() {
        std::cout << "Is this in (d)egrees or (r)adians? ";
    }

private:
    AngleModel* _model;
};


class Controller {
public:
    Controller(AngleModel* model, ConsoleView* view) : _model(model), _view(view) {}

    void start() {
        char unit;
        float value;

        while (true) {
            _view->promptForInput();
            std::cin >> value;

            if (value == 0) break; 

            _view->promptForUnit();
            std::cin >> unit;

            if (unit == 'd' || unit == 'D') {
                _model->setDegrees(value);
            }
            else if (unit == 'r' || unit == 'R') {
                _model->setRadians(value);
            }
            else {
                std::cout << "Invalid input. Please enter 'd' for degrees or 'r' for radians.\n";
                continue;
            }

            _view->display();
        }
    }

private:
    AngleModel* _model;
    ConsoleView* _view;
};

int main() {
    AngleModel model;                 
    ConsoleView view(&model);        
    Controller controller(&model, &view); 

    controller.start();              

    return 0;
}
