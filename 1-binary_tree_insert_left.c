#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 * another in a binary tree
 * @parent: a pointer to the nodeto insert left-child
 * @value: The value to store in the new node
 * Return: NULL if parent is NULL or an error occurs
 * Description: If parent already has a left-child, the new node
 * takes its place and the old left-child is set as the left-child
 * of the new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
    if (parent == NULL) {
        return NULL; // Return NULL if parent is NULL
    }

    binary_tree_t *new_node = binary_tree_node(parent, value);

    if (new_node == NULL) {
        return NULL; // Return NULL on failure to allocate memory
    }

    if (parent->left != NULL) {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }

    parent->left = new_node;

    return new_node;
}
