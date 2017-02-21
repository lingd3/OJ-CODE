//插入排序 O(n^2)稳定
//数组版
template <class Record>
void Sortable_list<Record>::insertion_sort() {
	int first_unsorted;
	int position;
	Record current;
	for (first_unsorted = 1; first_unsorted < count; first_unsorted++) {
		if (entry[first_unsorted] < entry[first_unsorted-1]) {
			position = first_unsorted;
			current = entry[first_unsorted];
			do {
				entry[position] = entry[position-1];
				position--;
			} while (position > 0 && entry[position-1] > current);
			entry[position] = current;
		}
	}
}
//链式版
template <class Record>
void Sortable_list<Record>::insertion_sort() {
	Node<Record>* first_unsorted,
				* last_sorted,
				* current,
				* trailing;
	if (head != NULL) {
		last_sorted = head;
		while (last_sorted-> next != NULL) {
			first_unsorted = last_sorted->next;
			if (first_unsorted->entry < head->entry) {
				last_sorted->next = first_unsorted->next;
				first_unsorted->next = head;
				head = first_unsorted;
			}
			else {
				trailing = head;
				current = trailing->next;
				while (first_unsorted->entry > current->entry) {
					trailing = current;
					current = trailing->next;
				}
				if (first_unsorted == current) last_sorted = first_unsorted;
				else {
					last_sorted->next = first_unsorted->next;
					first_unsorted->next = current;
					trailing->next = first_unsorted;
				}
			}
		}
	}
}

//选择排序 O(n^2)
//顺序实现
template <class Record>
void Sortable_list<Record>::selection_sort() {
	for (int position = count-1; position > 0; position--) {
		int max = max_key(0, position);
		swap(max, position);
	}
}
template <class Record>
void Sortable_list<Record>::max_key(int low, int high) {
	int largest, current;
	largest = low;
	for (current = low+1; current <= high; current++) {
		if (entry[largest] < entry[current]) largest = current;
	}
	return largest;
}
template <class Record>
void Sortable_list<Record>::swap(int low, int high) {
	Record temp;
	temp = entry[low];
	entry[low] = entry[high];
	entry[high] = temp;
}

//希尔排序 n^1.25 ~ 1.6n^1.25
template <class Record>
void Sortable_list<Record>::shell_sort() {
	int increment, start;
	increment = count;
	do {
		increment = increment/3+1;
		for (start = 0; start < increment; start++) {
			sort_interval(start, increment); //插入排序 
		}
	} while (increment > 1);
} 

//归并排序 O(nlgn) 稳定
//链表
template <class Record>
void Sortable_list<Record>::merge_sort() {
	recursive_merge_sort(head);
}
template <class Record>
void Sortable_list<Record>::recursive_merge_sort(Node<Record>* &sub_list) {
	if (sub_list != NULL && sub_list->next != NULL) {
		Node<Record>* second_half = divide_from(sub_list);
		recursive_merge_sort(sub_list);
		recursive_merge_sort(second_half);
		sub_list = merge(sub_list, second_half);
	}
}
//将一个链表分成两半
template <class Record>
void Sortable_list<Record>::divide_from(Node<Record>* sub_list) {
	Node<Record>* position,
				* midpoint,
				*second_half;
	if ((midpoint = sub_list) == NULL) return NULL;
	position = midpoint->next;
	while (position != NULL) {
		position = position->next;
		if (position != NULL) {
			midpoint = midpoint->next;
			position = position->next;
		}
	}
	second_half = midpoint->next;
	midpoint->next = NULL;
	return second_half;
}
//归并两个已排序的链表
template <class Record>
void Sortable_list<Record>::merge(Node<Record>* first, Node<Record>* second) {
	Node<Record>* last_sorted;
	Node<Record> combined;
	last_sorted = &combined;
	while (first != NULL && second != NULL) {
		if (first->entry <= second->entry) {
			last_sorted->next = first;
			last_sorted = first;
			first = first->next;
		}
		else {
			last_sorted->next = second;
			last_sorted = second;
			second = second->next;
		}
	}
	if (first == NULL) last_sorted->next = second;
	else last_sorted->next = first;
	return combined->next;
}

//快速排序 O(nlgn)
template <class Record>
void Sortable_list<Record>::quick_sort() {
	recursive_quick_sort(0, count-1);
}
template <class Record>
void Sortable_list<Record>::recursive_quick_sort(int low, int high) {
	int pivot_position;
	if (low < high) {
		pivot_position = partition(low, high);
		recursive_quick_sort(low, pivot_position-1);
		recursive_quick_sort(pivot_position+1, high);
	}
}
template <class Record>
void Sortable_list<Record>::partition(int low, int high) {
	Record pivot;
	int i, last_small;
	swap(low, (low+high)/2);
	pivot = entry[low];
	last_small = low;
	for (i = low+1; i < high; i++) {
		if (entry[i] < pivot) {
			last_small = last_small+1;
			swap(last_small, i);
		}
	}
	swap(low, last_small);
	return last_small;
}

//堆排序 O(nlgn)
//只适用于顺序表
template <class Record>
void Sortable_list<Record>::heap_sort() {
	Record current;
	int last_unsorted;
	build_heap();
	for (last_unsorted = count-1; last_unsorted > 0; last_unsorted--) {
		current = entry[last_unsorted];
		entry[last_unsorted] = entry[0];
		insert_heap(current, 0, last_unsorted-1);
	}
}
template <class Record>
void Sortable_list<Record>::insert_heap(const Record &current, int low, int high) {
	int large;
	large = 2*low+1;
	while (large <= high) {
		if (large < high && entry[large] < entry[large+1]) large++;
		if (current >= entry[large]) break;
		else {
			entry[low] = entry[large];
			low = large;
			large = 2*low+1;
		}
	}
	entry[low] = current;
}
template <class Record>
void Sortable_list<Record>::build_heap() { //建立初始的堆
	int low;
	for (low = count/2-1; low >= 0; low--) {
		Record current = entry[low];
		insert_heap(current, low, count-1);
	}
}

//冒泡排序 O(n^2)
void bubble_sort(int[] unsorted) {
	for (int i = 0; i < unsorted.Length; i++) {
		for (int j = i; j < unsorted.Length; j++) {
			if (unsorted[i] > unsorted[j]) {
				int temp = unsorted[i];
				unsorted[i] = unsorted[j];
				unsorted[j] = temp;
			}
		}
	}
}
