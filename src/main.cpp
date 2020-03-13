#include <functional>
#include <iostream>

#include <spdlog/spdlog.h>


#include <docopt/docopt.h>

#include <iostream>


#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>


static constexpr auto USAGE =
  R"(Naval Fate.

    Usage:
          naval_fate ship new <name>...
          naval_fate ship <name> move <x> <y> [--speed=<kn>]
          naval_fate ship shoot <x> <y>
          naval_fate mine (set|remove) <x> <y> [--moored | --drifting]
          naval_fate (-h | --help)
          naval_fate --version
 Options:
          -h --help     Show this screen.
          --version     Show version.
          --speed=<kn>  Speed in knots [default: 10].
          --moored      Moored (anchored) mine.
          --drifting    Drifting mine.
)";

int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv)
{
//  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
//    { std::next(argv), std::next(argv, argc) },
//    true,// show help if requested
//    "Naval Fate 2.0");// version string
//
//  for (auto const &arg : args) {
//    std::cout << arg.first << arg.second << std::endl;
//  }

  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Staring ImGui + SFML");

  sf::RenderWindow window(sf::VideoMode(1024, 768), "ImGui + SFML = <3");
  window.setFramerateLimit(60);
  ImGui::SFML::Init(window);

  constexpr auto scale_factor = 2.0;
  ImGui::GetStyle().ScaleAllSizes(scale_factor);
  ImGui::GetIO().FontGlobalScale = scale_factor;

  bool state[11] = { false, };

  sf::Clock deltaClock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    ImGui::Begin("The Plan");
    ImGui::Checkbox("0: The Plan", &state[0]);
    ImGui::Checkbox("1: Getting Started", &state[1]);
    ImGui::Checkbox("2: C++ 20 So Far", &state[2]);
    ImGui::Checkbox("3: Reading SFML Input States", &state[3]);
    ImGui::Checkbox("4: Managing Game State", &state[4]);
    ImGui::Checkbox("5: Making Our Game Testable", &state[5]);
    ImGui::Checkbox("6: Making Game State Allocator Aware", &state[6]);
    ImGui::Checkbox("7: Add Logging To Game Engine", &state[7]);
    ImGui::Checkbox("8: Draw a Game map", &state[8]);
    ImGui::Checkbox("9: Dialog Trees", &state[9]);
    ImGui::Checkbox("10: Porting From SFML To SDL", &state[10]);
    ImGui::End();

    window.clear();
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();
  return 0;
}
