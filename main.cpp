
#include "graphics/Window.hpp"
#include "graphics/Sprite.hpp"
#include "graphics/projector/OrthographicProjector.hpp"
#include "graphics/pipeline/SpritePipeline.hpp"

int main(int ac, char **av) {

    showdown::graphics::Window window(800, 600, "WindowTest");
    showdown::graphics::Sprite sprite("../poyo.png");
    showdown::graphics::OrthographicProjector projector(800, 600);
    showdown::graphics::SpritePipeline pipeline("../shader.vs", "../shader.fs");

    window.usePipeline(pipeline);
    window.useProjector(projector);

    sprite.scale(16, 16);

    while (window.isOpen()) {
        window.clear();

        window.draw(sprite);

        window.display();
        window.pollEvents();
    }

}
