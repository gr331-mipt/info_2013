/*
 * main.c
 *
 *  Created on: 25 нояб. 2013 г.
 *      Author: ALTAIR
 */
/*
typedef struct List List;

struct List {
	int item;
	List *next;
};
//Первым параметром во все функции передаётся указатель на начало списка
//добавить элемент в начало списка
List *list_add(List *head, int item);
//добавить элемент в конец списка
List *list_append(List *head, int item);
//вставить элемент в позицию index
List *list_insert(List *head, unsigned index, int item);
//удалить элемент с номером index
List *list_delete(List *head, unsigned index);
//удалить первый элемент
List *list_delete_first(List *head);
//удалить последний элемент
List *list_delete_last(List *head);
//Все вышеперечисленные функции могут изменить голову списка,
//поэтому возвращают новое значение head (или NULL, если список пустой)

//получить элемент с номером index (если не найден, возвращается -1)
int list_get(List *head, unsigned index);
//изменить элемент с номером index
void list_set(List *head, unsigned index, int item);
//найти номер первого элемента, равного item (если не найден, возвращается -1)
int list_find(List *head, int item);
//длина списка
unsigned list_size(List *head);
//распечатать список (числа разделяются пробелами)
void list_print(List *head);
//распечатать список задом наперёд
void list_reverse_print(List *head);
//уничтожить список и освободить всю память
void list_destroy(List *head);
*/
int main() {
	List *head = NULL;
	List *tail = list_append(head, 5);
	head = tail;
	head = list_append(head, 6);
	head = list_append(head, 7);
	list_print(head);
	tail->next = head;
	list_print(head);
	tail->next = NULL;
	list_destroy(head);
	return 0;
}
