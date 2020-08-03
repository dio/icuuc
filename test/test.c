#include <stdio.h>
#include <stdlib.h>

#include <unicode/utf8.h>

int main() {
  UBool err = FALSE;
  uint8_t bytes[4] = {0};
  int32_t written = 0;
  int32_t i = 0;
  char *parsed;

  UChar32 c = strtol("1F41A", &parsed, 16);

  U8_APPEND(bytes, written, 4, c, err);
  if (err == TRUE) {
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < written; ++i) {
    printf("%2x", bytes[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
