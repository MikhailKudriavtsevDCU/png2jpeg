#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input.png output.jpg" << std::endl;
        return 1;
    }

    const char *inputFilename = argv[1];
    const char *outputFilename = argv[2];

    int width, height, channels;
    unsigned char *imageData = stbi_load(inputFilename, &width, &height, &channels, 0);
    if (!imageData) {
        std::cerr << "Failed to load the input PNG file." << std::endl;
        return 1;
    }

    if (stbi_write_jpg(outputFilename, width, height, channels, imageData, 100)) {
        std::cout << "Conversion completed. Image saved as " << outputFilename << std::endl;
    } else {
        std::cerr << "Failed to save the output JPEG file." << std::endl;
        return 1;
    }

    stbi_image_free(imageData);
    return 0;
}
