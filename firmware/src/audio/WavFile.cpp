// ============================================================================
// File:    WavFile.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "audio/WavFile.h"

#include "core/Logger.h"

bool WavFile::open(const char *path) {
  file = Filesystem::open(path, "r");
  // Dosya Açılamadı
  if (!file) {
    LOG_ERROR("Failed to open WAV file.");
    return false;
  }
  // Header'ı Oku
  return parseHeader();
}

void WavFile::close() {
  file.close();
}

void WavFile::rewind() {
  file.seek(sizeof(WavHeader));
}

bool WavFile::isFinished() {
  return !file || !file.available();
}

uint8_t WavFile::read() {
  return file.read();
}

bool WavFile::parseHeader() {
  size_t size = file.read((uint8_t *)&header, sizeof(WavHeader));
  if (size != sizeof(WavHeader)) {
    LOG_ERROR("Failed to parse WAV header.");
    return false;
  }
  return checkHeader();
}

bool WavFile::checkHeader() {
  // ChunkID "RIFF" Olmak Zorunda
  if (memcmp(header.chunkID, "RIFF", 4) != 0) {
    LOG_ERROR("Wav header check failed: ChunkID is not RIFF (%.4s)", header.chunkID);
    return false;
  }
  // Format "WAVE" Olmak Zorunda
  if (memcmp(header.format, "WAVE", 4) != 0) {
    LOG_ERROR("Wav header check failed: Format is not WAVE (%.4s)", header.format);
    return false;
  }
  // Subchunk1ID "fmt " Olmak Zorunda
  if (memcmp(header.subchunk1ID, "fmt ", 4) != 0) {
    LOG_ERROR("Wav header check failed: Subchunk1ID is not fmt (%.4s)", header.subchunk1ID);
    return false;
  }
  // Subchunk2ID "data" Olmak Zorunda
  if (memcmp(header.subchunk2ID, "data", 4) != 0) {
    LOG_ERROR("Wav header check failed: Subchunk2ID is not data (%.4s)", header.subchunk2ID);
    return false;
  }
  // Chunk Size
  // uint32_t expectedChunkSize = 36 + header.subchunk2Size;
  // if (header.chunkSize != expectedChunkSize) {
  //   LOG_ERROR("Wav header check failed: ChunkSize is %u (Expected: %u)", header.chunkSize, 36 + header.subchunk2Size);
  //   return false;
  // }
  // fmt Chunk Size
  if (header.subchunk1Size != 16) {
    LOG_ERROR("Wav header check failed: Subchunk1Size is %u (Expected: 16)", header.subchunk1Size);
    return false;
  }
  // PCM
  if (header.audioFormat != 1) {
    LOG_ERROR("Wav header check failed: AudioFormat is %u (Expected: 1)", header.audioFormat);
    return false;
  }
  // Mono
  if (header.numChannels != 1) {
    LOG_ERROR("Wav header check failed: NumChannels is %u (Expected: 1)", header.numChannels);
    return false;
  }
  // Byte Rate
  uint32_t expectedByteRate = header.sampleRate * header.numChannels * header.bitsPerSample / 8;
  if (header.byteRate != expectedByteRate) {
    LOG_ERROR("Wav header check failed: ByteRate is %u (Expected: %u)", header.byteRate, expectedByteRate);
    return false;
  }
  // Block Align
  uint16_t expectedBlockAlign = header.numChannels * header.bitsPerSample / 8;
  if (header.blockAlign != expectedBlockAlign) {
    LOG_ERROR("Wav header check failed: BlockAlign is %u (Expected: %u)", header.blockAlign, expectedBlockAlign);
    return false;
  }
  // Bits Per Sample
  if (header.bitsPerSample != 8) {
    LOG_ERROR("Wav header check failed: BitsPerSample is %u (Expected: 8)", header.bitsPerSample);
    return false;
  }
  // Her Şey Doğru
  return true;
}
