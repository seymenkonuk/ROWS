// ============================================================================
// File:    MemoryPool.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stddef.h>
#include <stdint.h>

// CLASSES
template <size_t PoolSize> class MemoryPool {
public:
  MemoryPool() : offset(0) {
  }

  void reset() {
    offset = 0;
  }

  void *allocate(size_t size, size_t alignment = alignof(max_align_t)) {
    // Geçersiz Hizalama Değeri (Hizalama 2'nin Kuvveti Olmalı)
    if ((alignment == 0) || (alignment & (alignment - 1)))
      return nullptr;

    // Verinin Hangi Offsetten İtibaren Başlayabileceğini Bul
    size_t alignedOffset = (offset + alignment - 1) & ~(alignment - 1);

    // Hafıza Kalmadı
    if (alignedOffset + size > PoolSize)
      return nullptr;

    // Offset'i Güncelle
    offset = alignedOffset + size;

    // Adresi Dön
    return buffer + alignedOffset;
  }

  template <typename T> T *allocate() {
    return static_cast<T *>(allocate(sizeof(T), alignof(T)));
  }

  size_t used() const {
    return offset;
  }

  size_t remaining() const {
    return PoolSize - offset;
  }

  constexpr size_t capacity() const {
    return PoolSize;
  }

private:
  alignas(max_align_t) uint8_t buffer[PoolSize];
  size_t offset;
};
