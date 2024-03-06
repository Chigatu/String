#include "tests.h"

int main() {
  Suite* all_suit[] = {
      test_memchr(),   test_memcmp(),   test_memcpy(),
      test_memset(),   test_strchr(),   test_strlen(),
      test_strcspn(),  test_strncmp(),  test_strncpy(),
      test_strerror(), test_strncat(),  test_strpbrk(),
      test_strrchr(),  test_strstr(),   test_strtok(),
      test_to_upper(), test_to_lower(), test_trim(),
      test_insert(),   test_sprintf(),  NULL,
  };

  for (Suite** suit = all_suit; *suit != NULL; suit++) {
    SRunner* sr = srunner_create(*suit);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }

  return 0;
}
