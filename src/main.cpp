#include "App.hpp"

#include <iostream>

#include "Core/Context.hpp"

int main() {
    Core::Context context;

    App app;

    while (!context.GetExit()) {
        switch (app.GetCurrentState()) {
        case App::State::START:
            app.Start();
            break;

        case App::State::UPDATE:
            app.Update();
            break;

        case App::State::END:
            app.End();
            context.SetExit(true);
            break;
        }

        context.Update();
    }
}
