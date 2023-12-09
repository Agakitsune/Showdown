
#pragma once

#include "math/math.hpp"

namespace showdown::graphics {

    using color = math::vec4uc;

    // Misc
    static const color black = color(0, 0, 0, 255);
    static const color white = color(255, 255, 255, 255);
    static const color transparent = color(255, 255, 255, 0);
    static const color grey = color(128, 128, 128, 255);
    static const color darkGrey = color(64, 64, 64, 255);
    static const color lightGrey = color(191, 191, 191, 255);

    // Primary
    static const color red = color(255, 0, 0, 255);
    static const color green = color(0, 255, 0, 255);
    static const color blue = color(0, 0, 255, 255);

    // Secondary
    static const color cyan = color(0, 255, 255, 255);
    static const color magenta = color(255, 0, 255, 255);
    static const color yellow = color(255, 255, 0, 255);

    // Ternary
    static const color azure = color(0, 128, 255, 255);
    static const color violet = color(128, 0, 255, 255);
    static const color chartreuse = color(128, 255, 0, 255);
    static const color spring = color(0, 255, 128, 255);
    static const color rose = color(255, 0, 128, 255);
    static const color orange = color(255, 128, 0, 255);

    // Quaternary
    static const color vermillion = color(255, 64, 0, 255);
    static const color amber = color(255, 191, 0, 255);
    static const color harlequin = color(64, 255, 0, 255);
    static const color lime = color(191, 255, 0, 255);
    static const color erin = color(0, 255, 64, 255);
    static const color aquamarine = color(0, 255, 191, 255);
    static const color capri = color(0, 191, 255, 255);
    static const color cerulean = color(0, 64, 255, 255);
    static const color indigo = color(64, 0, 255, 255);
    static const color purple = color(191, 0, 255, 255);
    static const color cerise = color(255, 0, 191, 255);
    static const color crimson = color(255, 0, 64, 255);

    // Quintenary
    static const color scarlet = color(255, 32, 0, 255);
    static const color persimmon = color(255, 96, 0, 255);
    static const color orangePeel = color(255, 160, 0, 255);
    static const color goldenYellow = color(255, 224, 0, 255);
    static const color lemon = color(224, 255, 0, 255);
    static const color springBud = color(160, 255, 0, 255);
    static const color brightGreen = color(96, 255, 0, 255);
    static const color neonGreen = color(32, 255, 0, 255);
    static const color jade = color(0, 255, 32, 255);
    static const color emerald = color(0, 255, 96, 255);
    static const color mint = color(0, 255, 160, 255);
    static const color turquoise = color(0, 255, 224, 255);
    static const color skyBlue = color(0, 224, 255, 255);
    static const color cornflower = color(0, 160, 255, 255);
    static const color cobalt = color(0, 96, 255, 255);
    static const color sapphire = color(0, 32, 255, 255);
    static const color iris = color(32, 0, 255, 255);
    static const color veronica = color(96, 0, 255, 255);
    static const color amethyst = color(160, 0, 255, 255);
    static const color phlox = color(224, 0, 255, 255);
    static const color fuschia = color(255, 0, 224, 255);
    static const color deepPink = color(255, 0, 160, 255);
    static const color raspberry = color(255, 0, 96, 255);
    static const color amaranth = color(255, 0, 32, 255);

}
