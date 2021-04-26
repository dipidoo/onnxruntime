void* reallocarray(void* p, size_t item_count, size_t item_size) {
  size_t byte_count;
  if (__builtin_mul_overflow(item_count, item_size, &byte_count)) {
    errno = ENOMEM;
    return nullptr;
  }
  return realloc(p, byte_count);
}