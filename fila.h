/* FILA */

/**
 * Descritor: 
 * @var *array
 * @var inicio
 * @var tam
 * @var capacidade
 */
typedef struct fila{
	int *array;
	int inicio;
	int tam;
	int capacidade;
}FILA;

/**
 * @param cap
 * @return ref ou null
 */
struct fila *create_fila(int cap);

/**
 * @param *f
 * @return tamanho fila
 */
int tamanho_fila(FILA *f);

/**
 * @param *f
 * Exibe os elementos presentes na fila
 */
void exibirFila(FILA *f);

/**
 * @param *f
 * @param val
 * @return 1 se ok, 0 erro!
 */ 
int insereFila(FILA *f, int val);

/**
 * @param *f
 * @return 1 ok!, 0 erro!
 */
int excluirElemFila(FILA *f);

/**
 * Libera a memória da fila.
 */
void destroyFila(FILA *f);