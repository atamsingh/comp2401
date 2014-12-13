#define MAX_BLK 16
#define MAX_STR 32
#define C_TRUE  1
#define C_FALSE 0

typedef struct {
  int  rsv;
  void *addr;
  int   size;
  char  tag[MAX_STR];
} BlockType;

typedef struct {
  int numBlocks;
  BlockType *blocks;
} HeapType;

void  mh_init(HeapType*);
void  mh_cleanup(HeapType*);
void* mh_alloc(HeapType*, int, char*);
void  mh_dealloc(HeapType*, void*);
int   mh_count(HeapType*);
void  mh_dump(HeapType*);
void  mh_collect(HeapType*);

