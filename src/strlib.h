int str_length(const char *s);

char *str_at(int index, const char *src, char *dest);

char str_char_at(int index, const char *s);

char *str_concat(const char *src, char *dest);

int str_ends_with(const char *src, const char *end);

int str_includes(const char *src, const char *sub);

int str_index_of(const char *src, const char *sub);

int str_last_index_of(const char *src, const char *sub);

int str_locale_compare(const char *src, const char *sub);

char *str_pad_end(const char *src, int len, char pad, char *dest);

char *str_pad_start(const char *src, int len, char pad, char *dest);

char *str_repeat(const char *src, int count, char *dest);

char *str_slice(const char *src, int start, int end, char *dest);

int str_starts_with(const char *src, const char *start);

char *str_substring(const char *src, int start, int end, char *dest);

char *str_to_lower(const char *src, char *dest);

char *str_to_upper(const char *src, char *dest);

char *str_trim(const char *src, char *dest);

char *str_trim_end(const char *src, char *dest);

char *str_trim_start(const char *src, char *dest);

int str_value_of(const char *src);
