#include "HelpState.h"

HelpState::HelpState(sf::RenderWindow &win, GameStateManager &gsmRef, int diff)
    : window(win), gsm(gsmRef), difficulty(diff), font("Fonts/Roboto-Black.ttf")
{
    std::string helpMessage =
        "CONTROALE:\n"
        "- Stanga / Dreapta: A / D\n"
        "- Saritura: Space / W\n"
        "- Dash: Dublu click A / D\n\n"
        "SCOR:\n"
        "- Scorul per nivel porneste de la 120 si scade cu timpul\n"
        "- Se inmulteste cu viata ramasa (ex: 80% viata -> x0.8)\n\n"
        "OBIECTIV:\n"
        "- Parcurge nivelurile pana la final cat de repede posibil si cu cat mai putine greseli\n\n"
        "Apasa ESC pentru a inchide jocul si ENTER in meniu pentru a te intoarce la pagina anterioara";

    helpText = std::make_unique<Texts>(helpMessage, font);
    helpText->setCharacterSize(24);
    helpText->setFillColor(sf::Color::White);
    helpText->setPosition({50.f, 50.f});
}

void HelpState::update(float) {}

void HelpState::render(sf::RenderWindow &target)
{
    target.draw(*helpText);
}

void HelpState::handleEvent(const sf::Event &event)
{
    if (const auto *key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Enter)
        {
            gsm.pop();
        }
    }
}
