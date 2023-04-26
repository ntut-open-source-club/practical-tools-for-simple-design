#include "App.hpp"

#include <iostream>

#include "Core/Context.hpp"

int main(int argc, char *argv[]) {
    Core::Context context;

    App app;

    while (!context.GetExit()) {
        context.Update();
        if (context.GetExit()){
            app.End();
            break ;
        }
        switch (app.GetCurrentState()) {
        case App::State::START:
            app.Start();
            break;

        case App::State::UPDATE:
            app.Update();
            break;

//        case App::State::END:
//            app.End();
//            context.SetExit(true);
//            break;
        default:
            continue ;
        }
    }
}
