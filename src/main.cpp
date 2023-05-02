#include "App.hpp"

#include <iostream>

#include "Core/Context.hpp"

int main(int, char **) {
    App app;
    Core::Context::Init();
    while (!Core::Context::GetExit()) {
        switch (app.GetCurrentState()) {
        case App::State::START:
            app.Start();
            break;

        case App::State::UPDATE:
            app.Update();
            break;

        case App::State::END:
            app.End();
            Core::Context::SetExit(true);
            break;
        }
        Core::Context::Update();
    }
    Core::Context::Quit();
}
