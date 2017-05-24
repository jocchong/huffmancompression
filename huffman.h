# ifndef _HUFFMAN_H
# define _HUFFMAN_H
# include <stdint.h>
# include <stdbool.h>

# ifndef NIL
# define NIL (void *) 0
# endif

typedef struct DAH treeNode; 

struct DAH
{
	uint8_t uint64_t bool treeNode
	symbol;
	count;
	leaf;
	*left, *right;
}; 

// New node, with symbols, leaf or not, a count associated with it
treeNode *newNode(uint8_t s, bool l, uint64_t c);

// Delete a single node
treeNode *delNode(treeNode *t);

// Delete a tree
treeNode *delTree(treeNode *t);

// Dump a Huffman tree onto a file
void dumpTree(treeNode *t, int file);

// Build a tree from the saved tree
treeNode *loadTree(uint8_t savedTree[]);

// Step through a tree following the code
int32_t *stepTree(treeNode *root, treeNode *t, uint32_t code);

// Parse a Huffman tree to build codes
void buildCode(treeNode *t, code s, code table[256]);

static inline void delNode(treeNode *h) { free(h); return; }

static inline bool compare(treeNode *l, treeNode *r)
{
	return l->count - r->count; // l < r if negative, l = r if 0, ...
}

treeNode *join(treeNode *l, treeNode *r); // Join two subtrees

# endif