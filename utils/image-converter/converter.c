#include <stdio.h>
#include "data.c"

#define TRANSPARENT_R 0x52
#define TRANSPARENT_G 0x4f
#define TRANSPARENT_B 0x57

uint8_t new_data[WIDTH*HEIGHT*3];

void file_new_data() {
  FILE* dosya;
  dosya = fopen("IDLE", "wb");
  fwrite(new_data, sizeof(uint8_t), WIDTH*HEIGHT*3, dosya);
  fclose(dosya);
}

void calc_new_data() {
  int i;
  for (i=0; i<WIDTH*HEIGHT; i++) {
    uint8_t r = (data[0][i] << 24) >> 24;
    uint8_t g = (data[0][i] << 16) >> 24;
    uint8_t b = (data[0][i] << 8) >> 24;
    uint8_t a = (data[0][i] << 0) >> 24;
    
    // SAYDAM İSE 
    if (a == 0x00) {
      new_data[i*3+0] = TRANSPARENT_R;
      new_data[i*3+1] = TRANSPARENT_G;
      new_data[i*3+2] = TRANSPARENT_B;
    }
    // SAYDAM RENK İLE DENK GELİYORSA
    else if (r == TRANSPARENT_R && g == TRANSPARENT_G && b == TRANSPARENT_B) {
      new_data[i*3+0] = r;
      new_data[i*3+1] = g;
      new_data[i*3+2] = b-1;
    }
    // DİĞER TÜM DURUMLARDA
    else {
      new_data[i*3+0] = r;
      new_data[i*3+1] = g;
      new_data[i*3+2] = b;
    }
  }
}

int main() {
  calc_new_data();
  file_new_data();
  return 0;
}
