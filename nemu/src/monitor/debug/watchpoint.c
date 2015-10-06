#include "monitor/watchpoint.h"
#include "monitor/expr.h"

#define NR_WP 32

static WP wp_list[NR_WP];
static WP *head, *free_;

void init_wp_list() {
	int i;
	for(i = 0; i < NR_WP; i ++) {
		wp_list[i].NO = i;
		wp_list[i].exist = 0;
		wp_list[i].next = &wp_list[i + 1];
	}
	wp_list[NR_WP - 1].next = NULL;

	head = NULL;
	free_ = wp_list;
	/*
	WP *phead;
	int i;
	free_ = (WP *)malloc(sizeof(WP));
	head = free_;
	if(!free_) {
		printf("Error!");
	}
	for(i = 0; i < NR_WP; i++) {
		phead = (WP *)malloc(sizeof(WP));
		head->NO = i;
		head->exist = 1;
		head->next = phead;
		head = head->next;
	}
	head = NULL;
	*/
}

WP* get_wp_head() {
	return free_;
}

/* TODO: Implement the functionality of watchpoint */
