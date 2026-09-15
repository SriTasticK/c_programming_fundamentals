#include <stdio.h>
#include <kv.h>
#include <stdlib.h>

int main() {
  kv_t *table = kv_init(65535);
  printf("%p\n", table);
  printf("%ld\n", table->capacity);
  kv_put(table, "hehe", "ranger");
  for (int i = 0; i < table->capacity; i++) {
    if (table->entries[i].key){
      printf("[%d] %s: %s\n",i, table->entries[i].key, table->entries[i].value);
    }
  }
  char *val = kv_get(table, "hehe");
  char *val2 = kv_get(table, "ranger");
  char *val3 = kv_get(table, "This doesn't exist");

  printf("%s %s %s\n", val, val2, val3);

  for (size_t i = 0; i < table->capacity; i++) {
    kv_entry_t *entry = &table->entries[i];

    if (entry->key != NULL) {
        free(entry->key);
        free(entry->value);
    }
  }

  free(table->entries);
  free(table);
  return 0;
}
