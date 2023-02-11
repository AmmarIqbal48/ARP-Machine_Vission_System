#include <stdio.h>
#include <bmpfile.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

// Data structure for storing the bitmap file
bmpfile_t *bmp = NULL;
// Data type for defining pixel colors (BGRA)
rgb_pixel_t pixel = {0, 0, 255, 0};
int width = 0;
int height = 0;
int depth = 0;
int radius = 0;

if (argc < 3) {
printf("Please specify the output filename and the radius of the circle as arguments!\n");
return EXIT_FAILURE;
}

radius = atoi(argv[2]);
width = height = 2 * radius;
depth = 4;
bmp = bmp_create(width, height, depth);
if (bmp == NULL) {
printf("Error creating the bitmap file.\n");
return EXIT_FAILURE;
}

for(int x = 0; x < width; x++) {
for(int y = 0; y < height; y++) {
if((x - radius) * (x - radius) + (y - radius) * (y - radius) <= radius * radius) {
bmp_set_pixel(bmp, x, y, pixel);
}
}
}

if (bmp_save(bmp, argv[1]) != 0) {
printf("Error saving the bitmap file.\n");
bmp_destroy(bmp);
return EXIT_FAILURE;
}

bmp_destroy(bmp);
return EXIT_SUCCESS;
}
