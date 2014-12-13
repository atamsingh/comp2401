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

typedef struct{
  int a;
  double b;
  long c;
} A;

typedef struct{
  int a;
  char b;
  short c;
}B;

typedef struct{
  char a[10];
  unsigned char b;
  long d;
}C;