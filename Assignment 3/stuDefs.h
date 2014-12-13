typedef struct {
  char first[32];
  char last[32];
  int  age;
} PersonType;

typedef struct {
  PersonType basicInfo;
  char       stuNumber[12];
  float      gpa;
} StudentType;

