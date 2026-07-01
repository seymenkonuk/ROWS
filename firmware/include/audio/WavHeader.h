// ============================================================================
// File:    WavHeader.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stdint.h>

// STRUCTURES
typedef struct __attribute__((packed)) {
  // RIFF Chunk Descriptor
  char chunkID[4];    // "RIFF"
  uint32_t chunkSize; // 36 + SubChunk2Size
  char format[4];     // "WAVE"

  // fmt Subchunk
  char subchunk1ID[4];    // "fmt "
  uint32_t subchunk1Size; // 16 for PCM
  uint16_t audioFormat;   // PCM = 1
  uint16_t numChannels;   // 1 = mono, 2 = stereo
  uint32_t sampleRate;    // 44100, 48000 etc.
  uint32_t byteRate;      // sampleRate * numChannels * bitsPerSample/8
  uint16_t blockAlign;    // numChannels * bitsPerSample/8
  uint16_t bitsPerSample; // 8, 16, 24, 32

  // data Subchunk
  char subchunk2ID[4];    // "data"
  uint32_t subchunk2Size; // data size in bytes

} WavHeader;
