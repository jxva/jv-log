# A high-performance, simple, portable rbtree (Red-Black Tree) using ANSI C

A high-performance, simple, portable rbtree (Red-Black Tree) using ANSI C

## Features

- No dependence
- ~400 LOC
- Very easy to use
- Full interfaces

## Getting Started

### jv_rbtree_main.c

```c
#include <jv_rbtree.h>
int main(int argc, char *argv[]) {
  jv_rbtree_t *tree = jv_rbtree_create();
  jv_uint_t arr[] = { 6,3,2,5,3,5,1,2,4, 0 }; 
  jv_uint_t *a=arr;

  while (*a != 0) {
    jv_rbtree_data_t data;

    data.key = *a;
    data.value = (void *) *a;

    printf("insert value:%lu\n", data.key);
    jv_rbtree_insert(tree, &data);
    a++;
  }

  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  printf("depth:%lu\n", jv_rbtree_depth(tree->root, tree->sentinel));
  printf("length:%lu\n", tree->length);

  jv_rbtree_inorder(tree->root, tree->sentinel);

  jv_rbtree_remove(tree, jv_rbtree_get(tree, 7));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  jv_rbtree_destroy(tree);
  return 0;
}
```

## Build

    $ make

## Run

    $ ./jv_rbtree_main

## Out Print

```
insert value:6
insert value:3
insert value:2
insert value:5
insert value:3
insert value:5
insert value:1
insert value:2
insert value:4
min:1
max:6
depth:4
length:9
node's data:1 , left:-1, right:-1, parent:2 , color:red
node's data:2 , left:1 , right:2 , parent:3 , color:black
node's data:2 , left:-1, right:-1, parent:2 , color:red
node's data:3 , left:2 , right:5 , parent:-1, color:black
node's data:3 , left:-1, right:4 , parent:5 , color:black
node's data:4 , left:-1, right:-1, parent:3 , color:red
node's data:5 , left:3 , right:6 , parent:3 , color:red
node's data:5 , left:-1, right:-1, parent:6 , color:red
node's data:6 , left:5 , right:-1, parent:5 , color:black
node's data:1 , left:-1, right:-1, parent:2 , color:red
node's data:2 , left:1 , right:2 , parent:3 , color:black
node's data:2 , left:-1, right:-1, parent:2 , color:red
node's data:3 , left:2 , right:5 , parent:-1, color:black
node's data:3 , left:-1, right:4 , parent:5 , color:black
node's data:4 , left:-1, right:-1, parent:3 , color:red
node's data:5 , left:3 , right:6 , parent:3 , color:red
node's data:5 , left:-1, right:-1, parent:6 , color:red
node's data:6 , left:5 , right:-1, parent:5 , color:black
destroy node's data:3
destroy node's data:2
destroy node's data:1
destroy node's data:2
destroy node's data:5
destroy node's data:3
destroy node's data:4
destroy node's data:6
destroy node's data:5
```

## License

This project is under MIT License. See the [LICENSE](LICENSE) file for the full license text.

