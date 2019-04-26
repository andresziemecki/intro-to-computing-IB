#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "trie.h"

/////////////////////////////////////////////////////////////////////////////////////
// main de prueba (faltan las funciones solicitadas)
/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Trie_t* pTrie=trieCreate();

    FILE *stream = fopen("calles.txt", "r");
    assert(stream != NULL);

    char str[128]={0};

    while (fscanf(stream, "%s", str) == 1) {
        printf(">>%s<<\n", str);
        trieInsertKey(pTrie, str);
    }

    fclose(stream);

    printf("Chequeo: %d\n", trieCheck(pTrie));

    ListWord_t l = trieGetKeys(pTrie, "M");
    printf("\nclaves con M =====>\n");
    listPrint(l);
    listDestroy(l);

    l = trieGetKeys(pTrie, "MO");
    printf("\nclaves con MO =====>\n");
    listPrint(l);
    listDestroy(l);

    l = trieGetKeys(pTrie, "MOR");
    printf("\nclaves con MOR =====>\n");
    listPrint(l);
    listDestroy(l);

    trieDestroy(pTrie);


    return 0;
}


