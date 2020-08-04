#include <iostream>
#include <filesystem>
#include "../dependencies/lodepng/lodepng.h"

namespace fs = std::filesystem;

int main() {
    const std::string path = "../data/images/";
    std::string filename;

    /* Declaracao de variaveis necessarias para a funcao lodepng::decode*/
    std::vector<unsigned char> buffer;
    std::vector<unsigned char> image;
    unsigned w, h;

    /* Iteracao sobre todos os arquivos na pasta */
    for (const auto & entry : fs::directory_iterator(path)) {
        filename = entry.path().filename();
        lodepng::load_file(buffer, entry.path());

        /* Obtencao da largura(w) e da altura(h) atraves da decodificacao da imagem */
        unsigned error = lodepng::decode(image, w, h, buffer);

        /* Checagem de erro */
        if(error) {
            std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
            return 0;
        }

        /* Impressao dos resultados */
        std::cout << filename << " = " << w * h << std::endl;
    }
    return 0;
}
