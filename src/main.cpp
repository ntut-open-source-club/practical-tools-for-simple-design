#include "App.hpp"

#include <iostream>

#include "Core/Context.hpp"

int main() {
    Core::Context context;

    App app;

    while (!app.GetExit()) {
        switch (app.GetCurrentState()) {
        case App::State::START:
            app.Start();
            break;

        case App::State::UPDATE:
            app.Update();
            break;

        case App::State::END:
            app.End();
            break;
        }

        context.Update();
    }
}
