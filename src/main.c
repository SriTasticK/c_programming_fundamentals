#include <stdio.h>
#include <kv.h>

int main() {
  kv_t *table = kv_init(7);
  printf("%p\n", table);
  printf("%ld", table->capacity);
}
