#include <iostream>
#include <filesystem>
#include "../dependencies/lodepng/lodepng.h"

namespace fs = std::filesystem;

int main() {
    std::string filename = "../data/images/deslocamento.PNG";
    std::vector<unsigned char> buffer;
    std::vector<unsigned char> image;
    unsigned w, h;

    lodepng::load_file(buffer, filename); //load the image file with given filename

    lodepng::State state;

    unsigned error = lodepng::decode(image, w, h, state, buffer);

    if(error) {
        std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
        return 0;
    }

    std::cout << "Num pixels: " << w * h << std::endl;

    return 0;
}
