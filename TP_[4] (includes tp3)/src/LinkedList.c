#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node *pNode = NULL;
	int length = ll_len(this);

	if(this != NULL && nodeIndex > -1 && nodeIndex < length)
	{
		pNode = this->pFirstNode;

		for (int i = 0; i < nodeIndex; ++i)
		{
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodeAnterior = NULL;

    if(this != NULL && nodeIndex > -1 && nodeIndex < ll_len(this)+1)
    {

    	Node* pNode = (Node*) malloc(sizeof(Node));

    	if(pNode != NULL) {

    		pNode->pElement = pElement;

        	if(nodeIndex == 0)
        	{
        		pNode->pNextNode = this->pFirstNode;
        		this->pFirstNode = pNode;
        	}
        	else if(nodeIndex > 0 && nodeIndex < ll_len(this))
        	{
        		pNodeAnterior = getNode(this, nodeIndex-1);
        		pNode->pNextNode = pNodeAnterior->pNextNode;
        		pNodeAnterior->pNextNode = pNode;
        	}
        	else
        	{
        		pNode->pNextNode = NULL;
        		pNodeAnterior = getNode(this, nodeIndex-1);
        		pNodeAnterior->pNextNode = pNode;
        	}

        	this->size++;
        	returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam = ll_len(this);

    if(this != NULL)
    {
    	if(!addNode(this, tam, pElement))
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int tam = ll_len(this);
    Node* pNode = NULL;

    if(this != NULL && index > -1 && index < tam)
    {
    	pNode = getNode(this, index);
    	returnAux = pNode->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node *pNode = (Node*) malloc(sizeof(Node));

    if (this != NULL && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	pNode->pElement = pElement;
    	returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node *pNode = NULL;
    Node *pPreviousNode = NULL;
    int length =  ll_len(this);

    if(this != NULL && index > -1 && index < length)
    {
    	pNode = getNode(this, index);

    	if(index==0)
    	{
    		this->pFirstNode = pNode->pNextNode;
    		free(pNode);
    		pNode = NULL;
    	}
    	else if (index > 0 && index < length)
    	{
    		pPreviousNode = getNode(this, index-1);
    		pPreviousNode->pNextNode = pNode->pNextNode;
    		free(pNode);
    		pNode = NULL;
    	}
    	else
    	{
    		pPreviousNode = getNode(this, index-1);
    		free(pNode);
    		pNode = NULL;
    		pPreviousNode->pNextNode = NULL;
    	}

    	this->size--;
    	returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int length = ll_len(this);

    if(this != NULL)
    {
    	for (int i = 0; i < length; ++i)
    	{
			ll_remove(this, i);
		}

    	this->pFirstNode = NULL;
    	returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pElementAux = NULL;
    int length = ll_len(this);

    if(this != NULL)
    {
    	for (int i = 0; i < length; ++i)
    	{
    		pElementAux = ll_get(this, i);

    		if(pElement == pElementAux)
    		{
    			returnAux = i;
    			break;
    		}
		}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this->pFirstNode != NULL)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }


    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index > -1 && index < ll_len(this)+1)
    {
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this != NULL)
    {
    	index = ll_indexOf(this, pElement);

    	if(index != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement = NULL;
    int ret;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	for (int i = 0; i < ll_len(this2); ++i)
    	{
    		pElement = ll_get(this2, i);
     		ret = ll_contains(this, pElement);

     		if(!ret)
     		{
     			returnAux = 0;
     			break;
     		}
		}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
	int length = ll_len(this);
	void* pElement;

    if(this != NULL &&  from > -1 && to < length+1 && from < to)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for (int i = from ; i < to; ++i)
    		{
        		pElement = ll_get(this, i);
        		addNode(cloneArray, i, pElement);
    		}
    	}
    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int length = ll_len(this);

    if(this != NULL) {
    	cloneArray = ll_subList(this, 0, length);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementUno = NULL;
    void* pElementDos = NULL;
    void* auxElement = NULL;
    int flagSwap;
    int length = ll_len(this);


    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {

    	for (int i = 0; i < length-1; ++i)
    	{
    		pElementUno = ll_get(this, i);

    		for (int j = i+1; j < length; ++j)
    		{
    			pElementDos = ll_get(this, j);
    			flagSwap = pFunc(pElementUno, pElementDos);

    			if(order == 0)
    			{
    				if(flagSwap == -1)
    				{
    					auxElement = pElementUno;
    					pElementUno = pElementDos;
    					pElementDos = auxElement;
    				}
    			}
    			else
    			{
    				if(flagSwap == 1)
    				{
    					auxElement = pElementUno;
						pElementUno = pElementDos;
						pElementDos = auxElement;
    				}
    			}

    			ll_set(this, i, pElementUno);
    			ll_set(this, j, pElementDos);
    		}
    	}

    	returnAux = 0;
    }


    return returnAux;
}

