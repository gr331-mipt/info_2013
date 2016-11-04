#include "list.h"

int main() {
	List *list = NULL;
	list_print(list);
	list = list_append(list, 4);
	list_print(list);
	list = list_add(list, 2);
	list_print(list);
	list = list_append(list, 9);
	list_print(list);
	list = list_insert(list, 2, 3);
	list_print(list);
	list_set(list, 1, 7);
	list_print(list);
	list = list_delete(list, 2);
	list_print(list);
	list_destroy(list);
	getchar();
	return 0;
}
