#include <iostream>
#include <filesystem>
#include "../dependencies/lodepng/lodepng.h"

namespace fs = std::filesystem;

int main() {
    const std::string path = "../data/images/";
    std::string filename;
    std::vector<unsigned char> buffer;
    std::vector<unsigned char> image;
    unsigned w, h;

    for (const auto & entry : fs::directory_iterator(path)) {
        filename = entry.path().filename();
        lodepng::load_file(buffer, entry.path());
        unsigned error = lodepng::decode(image, w, h, buffer);

        if(error) {
            std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
            return 0;
        }

        std::cout << filename << " = " << w * h << std::endl;
    }
    return 0;
}
