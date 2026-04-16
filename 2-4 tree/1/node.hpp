struct node {
	node* parent;
	int keys[4];
	node** children;
	int size = 0;
};