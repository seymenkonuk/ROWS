// ============================================================================
// File:    Memory.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "core/Logger.h"
#include "core/system/MemoryPool.h"

// CLASSES
class Memory {
public:
  template <typename T, typename... Args> static T *create(Args &&...args) {
    // Alanı Tahsis Et
    void *mem = pool.allocate(sizeof(T), alignof(T));
    // Başarısız oldu
    if (!mem) {
      LOG_ERROR("Allocation failed.");
      return nullptr;
    }
    // O Alana Objeyi Oluştur
    return new (mem) T(args...);
  }

  template <typename T> static void destroy(T *obj) {
    if (obj)
      obj->~T();
  }

  static void reset() {
    pool.reset();
  }

  static size_t used() {
    return pool.used();
  }

  static size_t remaining() {
    return pool.remaining();
  }

  static size_t capacity() {
    return pool.capacity();
  }

private:
  static MemoryPool<2048> pool;
};
