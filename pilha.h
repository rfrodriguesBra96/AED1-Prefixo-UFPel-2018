/* Pilha */

/**
 * @var topo
 * @var capacidae
 * @var *array
 */
typedef struct stack{
	int topo;
	int capacidade;
	int *array;
}STACK;

/**
 * @param tam
 * @return ponteiro ou null
 */
struct stack *create_stack(int tam);

/**
 * @param *s
 * @return 1 se pilha eh vazia 0 erro!
 */
int stackIsEmpty(struct stack *s);

/**
 * @param *s
 * @return 1 se pilha eh full 0 se erro
 */
int isFull(struct stack *s);

/**
 * @param *s
 * @return topo da pilha, 0 se erro
 */
int peek(struct stack *s);

/**
 * @param *s
 * @return 1 se ok, 0 se erro
 */
int pop(struct stack *s);

/**
 * @param val
 * @param *s
 * @return 1 se ok, 0 se erro
 */
int push(struct stack *s, int val);